#ifndef __RALINK_FLASH_H__
#define __RALINK_FLASH_H__

#define BOOT_FROM_NOR	0
#define BOOT_FROM_NAND	2
#define BOOT_FROM_SPI	3

extern int ra_check_flash_type(void);
extern int ra_mtd_write_nm(char *name, loff_t to, size_t len, const unsigned char *buf);
extern int ra_mtd_read_nm(char *name, loff_t from, size_t len, unsigned char *buf);

#endif
