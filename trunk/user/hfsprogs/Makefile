SRC_NAME=hfsprogs-332.XX

CFLAGS+=$(COPT) -ffunction-sections -fdata-sections -fvisibility=hidden
LDFLAGS += -Wl,--gc-sections

all:
	$(MAKE) -j$(HOST_NCPU) -C $(SRC_NAME) -f Makefile.lnx all

clean:
	$(MAKE) -j$(HOST_NCPU) -C $(SRC_NAME) -f Makefile.lnx clean

romfs:
	$(ROMFSINST) $(SRC_NAME)/fsck_hfs.tproj/fsck_hfs /sbin/fsck.hfsplus
	$(ROMFSINST) $(SRC_NAME)/newfs_hfs.tproj/newfs_hfs /sbin/mkfs.hfsplus
	$(ROMFSINST) -s fsck.hfsplus /sbin/fsck.hfs
	$(ROMFSINST) -s mkfs.hfsplus /sbin/mkfs.hfs
