ifndef ROOTDIR
ROOTDIR=../..
endif

USERDIR = $(ROOTDIR)/user
SHDIR = $(ROOTDIR)/user/shared

include $(SHDIR)/boards.mk
include $(SHDIR)/cflags.mk

CFLAGS += -fPIC -ffunction-sections -fdata-sections
CFLAGS += -I. -I$(SHDIR) -I$(SHDIR)/include

LDFLAGS += -Wl,--gc-sections -L$(SHDIR) -lshared

OBJS = dev_info.o disk_io_tools.o disk_initial.o disk_share.o
ifdef CONFIG_USB_SUPPORT
OBJS += usb_info.o
endif

all: libdisk.so test_share

libdisk.so: $(OBJS) $(SHDIR)/shutils.o
	$(LD) -shared -o $@ $^

test_share: test_share.o libdisk.so
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

romfs:
	$(ROMFSINST) /lib/libdisk.so
	if [ "$(CONFIG_FIRMWARE_INCLUDE_SMBD)" = "y" ] || [ "$(CONFIG_FIRMWARE_INCLUDE_FTPD)" = "y" ] ; then \
		$(ROMFSINST) /sbin/test_share ; \
	fi;

clean:
	rm -f *.o libdisk.so test_share
