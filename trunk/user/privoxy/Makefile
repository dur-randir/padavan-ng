SRC_NAME=privoxy-3.0.XX

CFLAGS +=$(COPT) -ffunction-sections -fdata-sections -fvisibility=hidden
LDFLAGS += -Wl,--gc-sections

all: config_test
	$(MAKE) -j$(HOST_NCPU) -C $(SRC_NAME)

config_test:
	( if [ -f ./config_done ]; then \
		echo "the same configuration"; \
	else \
		make configure && touch config_done; \
	fi )

configure:
	( cd $(SRC_NAME) ; \
	autoheader; \
	autoconf; \
	CPPFLAGS="-I$(STAGEDIR)/include" \
	./configure \
		--prefix=/usr \
		--sysconfdir=/etc/storage/privoxy \
		$(if $(CONFIG_IPV6),--enable-ipv6-support,--disable-ipv6-support) \
		--host=$(HOST_TARGET) \
		--build=$(HOST_BUILD); \
	)

clean:
	if [ -f $(SRC_NAME)/Makefile ] ; then \
		$(MAKE) -C $(SRC_NAME) distclean ; \
	fi ; \
	rm -rf config_done configs

romfs:
	$(ROMFSINST) $(SRC_NAME)/privoxy /usr/sbin/privoxy
	$(ROMFSINST) /usr/bin/privoxy.sh
	mkdir -p $(INSTALLDIR)/usr/share/privoxy/templates
	$(ROMFSINST) $(SRC_NAME)/templates /usr/share/privoxy/templates
	rm -rf configs
	mkdir -p configs
	cp -af $(SRC_NAME)/config \
		$(SRC_NAME)/default.filter \
	 	$(SRC_NAME)/user.filter \
		$(SRC_NAME)/default.action \
		$(SRC_NAME)/match-all.action \
		$(SRC_NAME)/user.action \
		configs
	cp -af $(SRC_NAME)/trust configs/user.trust
	sed -i '/^##/d;/^#\s/d;/^#$$/d' configs/*
	sed -i 's/^\(logfile.*\)/#\1/;s/^logdir.*/logdir \/tmp/;s/^confdir.*/confdir \/etc\/storage\/privoxy/;s/^#trustfile.*/#trustfile user.trust/;s/^enable-edit-actions.*/enable-edit-actions 1/' configs/config
	echo -e "\n## Forward to TOR\n#forward-socks5t / 127.0.0.1:9050 .\n#forward-socks5t .onion 127.0.0.1:9050 .\n#forward 192.168.*.*/ .\n#forward 10.*.*.*/ .\n" >>configs/config
	sed -i "s/^-e*//" configs/config
	mkdir -p $(INSTALLDIR)/usr/share/privoxy/privoxy
	ln -s /usr/share/privoxy/templates $(INSTALLDIR)/usr/share/privoxy/privoxy/templates
	$(ROMFSINST) configs /usr/share/privoxy/privoxy
