SRC_NAME=rp-l2tp-0.5-rtn

CFLAGS  += -I$(KERNEL_HEADERS_PATH) -DPPPOL2TP_V1
CFLAGS  += -ffunction-sections -fdata-sections
LDFLAGS += -Wl,--gc-sections

all: config_test
	$(MAKE) -C $(SRC_NAME)

config_test:
	( if [ -f ./config_done ]; then \
		echo "the same configuration"; \
	else \
		make configure && touch config_done; \
	fi )

configure:
	( cd $(SRC_NAME) ; \
	./configure \
		--prefix=/usr \
		--sysconfdir=/etc \
		--host=$(HOST_TARGET) \
		--build=$(HOST_BUILD) ; \
	)

clean:
	if [ -f $(SRC_NAME)/Makefile ] ; then \
		$(MAKE) -C $(SRC_NAME) distclean ; \
	fi ; \
	rm -f config_done

romfs:
	mkdir -p $(INSTALLDIR)/usr/lib/l2tp
	$(ROMFSINST) $(SRC_NAME)/l2tpd /usr/sbin/l2tpd
	$(ROMFSINST) $(SRC_NAME)/handlers/l2tp-control /usr/sbin/l2tp-control
	$(ROMFSINST) $(SRC_NAME)/handlers/cmd.so /usr/lib/l2tp/cmd.so
	$(ROMFSINST) $(SRC_NAME)/handlers/sync-pppd.so /usr/lib/l2tp/sync-pppd.so
