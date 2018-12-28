CFLAGS += -Os -ffunction-sections -fdata-sections -fvisibility=hidden
LDFLAGS += -Wl,--gc-sections

all: eoip-ctl

eoip-ctl: eoipcr.o libnetlink.o
	$(CC) $(LDFLAGS) -o eoip-ctl eoipcr.o libnetlink.o

eoipcr.o: eoipcr.c
	$(CC) $(CFLAGS) -fno-strict-aliasing -Wall -c eoipcr.c

libnetlink.o: libnetlink.c libnetlink.h
	$(CC) $(CFLAGS) -fno-strict-aliasing -Wall -c libnetlink.c

clean:
	rm -f eoip-ctl eoipcr.o libnetlink.o

romfs:
	$(ROMFSINST) eoip-ctl /usr/bin/eoip-ctl
