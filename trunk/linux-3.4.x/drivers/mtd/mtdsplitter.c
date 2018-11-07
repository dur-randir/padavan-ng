#include <linux/module.h>
#include <linux/init.h>
#include <linux/magic.h>
#include <linux/mtd/mtd.h>
#include <linux/slab.h>
#include <linux/mtd/partitions.h>

static char rootfs_name[] = "RootFS";
static char kernel_name[] = "Kernel";
static char storage_name[] = "Storage";
static char firmware_name[] = "Firmware";
static char fwstub_name[] = "Firmware_Stub";

struct part_desc {
	char *name;
	uint32_t offset;
	uint32_t size;
	bool read_only;
};

static struct part_desc partition_table[] = {
#include "mtdsplitter_parts.h"
,{ name:	NULL, }
};

#define MIN_ROOTFS_OFFSET	0x60000

/* common routines */
struct firmware_info {
	uint32_t kernel_offset;
	uint32_t kernel_size;
	uint32_t rootfs_offset;
	uint32_t rootfs_size;
};

static inline uint64_t mtd_rounddown_to_eb(uint64_t sz, struct mtd_info *mtd)
{
	if (mtd_mod_by_eb(sz, mtd) == 0)
		return sz;

	/* Round down to the start of the current erase block */
	return (mtd_div_by_eb(sz, mtd)) * mtd->erasesize;
}

#define UBI_EC_MAGIC		0x55424923	/* UBI# */

enum mtdsplit_part_type {
	MTDSPLIT_PART_TYPE_UNK = 0,
	MTDSPLIT_PART_TYPE_SQUASHFS,
	MTDSPLIT_PART_TYPE_JFFS2,
	MTDSPLIT_PART_TYPE_UBI,
};

int mtd_check_rootfs_magic(struct mtd_info *mtd, size_t offset,
							enum mtdsplit_part_type *type)
{
	u32 magic;
	size_t retlen;
	int ret;

	ret = mtd_read(mtd, offset, sizeof(magic), &retlen,
				(unsigned char *) &magic);
	if (ret)
		return ret;

	if (retlen != sizeof(magic))
		return -EIO;

	if (le32_to_cpu(magic) == SQUASHFS_MAGIC) {
		if (type)
			*type = MTDSPLIT_PART_TYPE_SQUASHFS;
		return 0;
	} else if (magic == 0x19852003) {
		if (type)
			*type = MTDSPLIT_PART_TYPE_JFFS2;
		return 0;
	} else if (be32_to_cpu(magic) == UBI_EC_MAGIC) {
		if (type)
			*type = MTDSPLIT_PART_TYPE_UBI;
		return 0;
	}

	return -EINVAL;
}

static ssize_t mtd_next_eb(struct mtd_info *mtd, size_t offset)
{
	return mtd_rounddown_to_eb(offset, mtd) + mtd->erasesize;
}

int mtd_find_rootfs_from(struct mtd_info *mtd,
						size_t from,
						size_t limit,
						size_t *ret_offset,
						enum mtdsplit_part_type *type)
{
	size_t offset;
	int err;

	for (offset = from; offset < limit; offset = mtd_next_eb(mtd, offset)) {
		err = mtd_check_rootfs_magic(mtd, offset, type);
		if (err)
			continue;

		*ret_offset = offset;
		return 0;
	}

	return -ENODEV;
}

/* tplink-fw parse code */
#define MD5SUM_LEN	16

struct fw_v1 {
	char		vendor_name[24];
	char		fw_version[36];
	uint32_t	hw_id;		/* hardware id */
	uint32_t	hw_rev;	 /* hardware revision */
	uint32_t	unk1;
	uint8_t		md5sum1[MD5SUM_LEN];
	uint32_t	unk2;
	uint8_t		md5sum2[MD5SUM_LEN];
	uint32_t	unk3;
	uint32_t	kernel_la;	/* kernel load address */
	uint32_t	kernel_ep;	/* kernel entry point */
	uint32_t	fw_length;	/* total length of the firmware */
	uint32_t	kernel_ofs;	/* kernel data offset */
	uint32_t	kernel_len;	/* kernel data length */
	uint32_t	rootfs_ofs;	/* rootfs data offset */
	uint32_t	rootfs_len;	/* rootfs data length */
	uint32_t	boot_ofs;	/* bootloader data offset */
	uint32_t	boot_len;	/* bootloader data length */
	uint8_t		pad[360];
} __attribute__ ((packed));

struct fw_v2 {
	char		fw_version[48]; /* 0x04: fw version string */
	uint32_t	hw_id;		/* 0x34: hardware id */
	uint32_t	hw_rev;	 /* 0x38: FIXME: hardware revision? */
	uint32_t	unk1;		/* 0x3c: 0x00000000 */
	uint8_t		md5sum1[MD5SUM_LEN]; /* 0x40 */
	uint32_t	unk2;		/* 0x50: 0x00000000 */
	uint8_t		md5sum2[MD5SUM_LEN]; /* 0x54 */
	uint32_t	unk3;		/* 0x64: 0xffffffff */

	uint32_t	kernel_la;	/* 0x68: kernel load address */
	uint32_t	kernel_ep;	/* 0x6c: kernel entry point */
	uint32_t	fw_length;	/* 0x70: total length of the image */
	uint32_t	kernel_ofs;	/* 0x74: kernel data offset */
	uint32_t	kernel_len;	/* 0x78: kernel data length */
	uint32_t	rootfs_ofs;	/* 0x7c: rootfs data offset */
	uint32_t	rootfs_len;	/* 0x80: rootfs data length */
	uint32_t	boot_ofs;	/* 0x84: FIXME: seems to be unused */
	uint32_t	boot_len;	/* 0x88: FIXME: seems to be unused */
	uint16_t	unk4;		/* 0x8c: 0x55aa */
	uint8_t		sver_hi;	/* 0x8e */
	uint8_t		sver_lo;	/* 0x8f */
	uint8_t		unk5;		/* 0x90: magic: 0xa5 */
	uint8_t		ver_hi;	 /* 0x91 */
	uint8_t		ver_mid;	/* 0x92 */
	uint8_t		ver_lo;	 /* 0x93 */
	uint8_t		pad[364];
} __attribute__ ((packed));

struct tplink_fw_header {
	uint32_t version;
	union {
		struct fw_v1 v1;
		struct fw_v2 v2;
	};
};

static int parse_tplink(struct mtd_info *m, size_t firmware_offset, size_t firmware_size, struct firmware_info *split_info)
{
	int err;
	struct tplink_fw_header hdr;
	size_t hdr_len, retlen, rootfs_offset, kernel_size;

	hdr_len = sizeof(hdr);
	if (firmware_size < hdr_len || firmware_size < MIN_ROOTFS_OFFSET)
		return -EINVAL;
	err = mtd_read(m, firmware_offset, hdr_len, &retlen, (void *) &hdr);
	if (err)
		return err;
	if (retlen != hdr_len)
		return -EIO;
	switch(le32_to_cpu(hdr.version)) {
	case 1:
		if (be32_to_cpu(hdr.v1.kernel_ofs) != hdr_len)
			return -EINVAL;

		kernel_size = be32_to_cpu(hdr.v1.kernel_len);
		rootfs_offset = be32_to_cpu(hdr.v1.rootfs_ofs);
		break;
	case 2:
	case 3:
		if (be32_to_cpu(hdr.v2.kernel_ofs) != hdr_len)
			return -EINVAL;

		kernel_size = be32_to_cpu(hdr.v2.kernel_len);
		rootfs_offset = be32_to_cpu(hdr.v2.rootfs_ofs);
		break;
	default:
		return -EINVAL;
	}

	kernel_size += hdr_len;
	if (kernel_size > firmware_size)
		return -EINVAL;

	rootfs_offset += firmware_offset;
	/* Find the rootfs */
	err = mtd_check_rootfs_magic(m, rootfs_offset, NULL);
	if (err) {
		/*
		 * The size in the header might cover the rootfs as well.
		 * Start the search from an arbitrary offset.
		 */
		err = mtd_find_rootfs_from(m, firmware_offset + MIN_ROOTFS_OFFSET,
					firmware_size - MIN_ROOTFS_OFFSET, &rootfs_offset, NULL);
		if (err)
			return err;
	}
	split_info->kernel_offset = firmware_offset;
	split_info->kernel_size = kernel_size;

	split_info->rootfs_offset = rootfs_offset;
	split_info->rootfs_size = firmware_offset + firmware_size - rootfs_offset;
	return 0;
}

/* original-fw parse code */
struct uimage_mod_fw_header {
	uint8_t unused[60];
	uint32_t ih_ksz;
} __attribute__ ((packed));

static int parse_original(struct mtd_info *m, size_t firmware_offset, size_t firmware_size, struct firmware_info *split_info)
{
	int err;
	struct uimage_mod_fw_header hdr;
	size_t hdr_len, retlen, rootfs_offset, kernel_size;

	hdr_len = sizeof(hdr);
	if (firmware_size < hdr_len || firmware_size < MIN_ROOTFS_OFFSET)
		return -EINVAL;
	err = mtd_read(m, firmware_offset, hdr_len, &retlen, (void *) &hdr);
	if (err)
		return err;
	if (retlen != hdr_len)
		return -EIO;
	kernel_size = be32_to_cpu(hdr.ih_ksz);
	if (kernel_size == 0 || kernel_size > firmware_size)
		return -EINVAL;

	rootfs_offset = firmware_offset + kernel_size;
	/* Find the rootfs */
	err = mtd_check_rootfs_magic(m, rootfs_offset, NULL);
	if (err) {
		/*
		 * The size in the header might cover the rootfs as well.
		 * Start the search from an arbitrary offset.
		 */
		err = mtd_find_rootfs_from(m, firmware_offset + MIN_ROOTFS_OFFSET,
					firmware_size - MIN_ROOTFS_OFFSET, &rootfs_offset, NULL);
		if (err)
			return err;
	}
	split_info->kernel_offset = firmware_offset;
	split_info->kernel_size = kernel_size;

	split_info->rootfs_offset = rootfs_offset;
	split_info->rootfs_size = firmware_offset + firmware_size - rootfs_offset;
	return 0;
}

static int create_mtd_partitions(struct mtd_info *m,
				struct mtd_partition **pparts,
				struct mtd_part_parser_data *data)
{
	int s_idx, t_idx, firmware_idx = -1, storage_idx = -1, nr_parts = 0;
	struct mtd_partition *parts;
	const char *s;
	struct firmware_info split_info;
	// calculate partitions count and search for RootFS, Kernel and Firmware_Stub
	while(partition_table[nr_parts].name != NULL) {
		s = partition_table[nr_parts].name;
 		if (strcmp(s, firmware_name) == 0) {
			firmware_idx = nr_parts;
		} else if (strcmp(s, storage_name) == 0) {
			storage_idx = nr_parts;
		} else if (strcmp(s, kernel_name) == 0 || strcmp(s, rootfs_name) == 0) {
			/* no kernel or rootfs for new partition definion
			 * only Firmware partition
			 */
			return -EINVAL;
		}
		nr_parts++;
	}
	// check conditions
	if (firmware_idx == -1 ||
		storage_idx == -1 ||
		nr_parts == 0) {
		pr_err("Partition table error. Firmware or Storage partitions are absent.");
		return 0;
	}
	// try split kernel and rootfs
	if (parse_tplink(m, partition_table[firmware_idx].offset, partition_table[firmware_idx].size, &split_info) &&
		parse_original(m, partition_table[firmware_idx].offset, partition_table[firmware_idx].size, &split_info)) {
		pr_err("%s: error parsing %s partition\n", m->name, partition_table[firmware_idx].name);
		return -EINVAL;
	}
	// allocate memory for partition table.
	parts = kzalloc((nr_parts + 2) * sizeof(*parts), GFP_KERNEL);
	if (!parts)
		return -ENOMEM;
	// Firmware_Stub always must be last in the partition table
	s_idx = t_idx = 0;
	while(s_idx < nr_parts) {
		if (s_idx == firmware_idx) {
			// fill kernel partition
			parts[t_idx].name = kernel_name;
			parts[t_idx].offset = split_info.kernel_offset;
			parts[t_idx].size = split_info.kernel_size;
			parts[t_idx].mask_flags = MTD_WRITEABLE;
			t_idx++;
			// fill rootfs partition
			parts[t_idx].name = rootfs_name;
			parts[t_idx].offset = split_info.rootfs_offset;
			parts[t_idx].size = split_info.rootfs_size;
			parts[t_idx].mask_flags = MTD_WRITEABLE;
		} else {
			parts[t_idx].name = partition_table[s_idx].name;
			parts[t_idx].offset = partition_table[s_idx].offset;
			parts[t_idx].size = partition_table[s_idx].size;
			if (partition_table[s_idx].read_only)
				parts[t_idx].mask_flags = MTD_WRITEABLE;
		}
		s_idx++;
		t_idx++;
	}
	// fill Firmware_Stub partition
	parts[t_idx].name = fwstub_name;
	parts[t_idx].offset = partition_table[firmware_idx].offset;
	parts[t_idx].size = partition_table[firmware_idx].size;
	// Allow crossing "Firmware_Stub" over "Storage" for <= 8 MB flash
	if (m->size <= 0x800000 && storage_idx == (firmware_idx + 1)) {
		parts[t_idx].size += partition_table[storage_idx].size;
	}
	*pparts = parts;
	return t_idx + 1;
}

static struct mtd_part_parser mtdsplitter_parser = {
	.owner = THIS_MODULE,
	.parse_fn = create_mtd_partitions,
	.name = "mtdsplitter",
};

static int __init mtdsplitter_parser_init(void)
{
	return register_mtd_parser(&mtdsplitter_parser);
}

module_init(mtdsplitter_parser_init);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MTD splitter for Padavan's firmware");
MODULE_AUTHOR("Maxim Anisimov");
