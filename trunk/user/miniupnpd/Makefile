SRC_NAME=miniupnpd-2.X

# reference to iptables package
IPT_VERSION:=iptables-1.4.16.3

# disable support IPv6 yet, because no profit w/o IGDv2
# e.g. Windows not supported IGDv2 and UPnP not worked
ENABLE_IPV6:=0

IPTABLESPATH=$(ROOTDIR)/user/iptables/$(IPT_VERSION)

all:
	cd $(SRC_NAME) && ./genconfig.sh
	$(MAKE) -j$(HOST_NCPU) -f Makefile.linux -C $(SRC_NAME) IPTABLESPATH=$(IPTABLESPATH) ENABLE_IPV6=$(ENABLE_IPV6)

clean:
	$(MAKE) -f Makefile.linux -C $(SRC_NAME) clean

romfs:
	$(ROMFSINST) $(SRC_NAME)/miniupnpd /usr/bin/miniupnpd
