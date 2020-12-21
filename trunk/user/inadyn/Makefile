SRC_NAME="inadyn-2.7"

SHAREDIR = $(ROOTDIR)/user/shared
CFLAGS += -Os -ffunction-sections -fdata-sections -I.
CFLAGS	+= -I$(SHAREDIR)
LDFLAGS	+= -Wl,--gc-sections -L. -L$(SHAREDIR) -lshared

ifeq ($(CONFIG_FIRMWARE_INCLUDE_DDNS_SSL),y)
SSLFLAG=--enable-openssl
else
SSLFLAG=--disable-openssl
endif

THISDIR = $(shell pwd)

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
	export PKG_CONFIG_PATH=$(STAGEDIR)/lib/pkgconfig ; \
	autoreconf -vif && \
	./configure --without-systemd \
		$(SSLFLAG) \
		confuse_CFLAGS="-I$(STAGEDIR)/include" \
		confuse_LIBS="-L$(STAGEDIR)/lib" \
		OpenSSL_CFLAGS="-I$(STAGEDIR)/include" \
		OpenSSL_LIBS="-L$(STAGEDIR)/lib -lssl -lcrypto" \
		--host=$(HOST_TARGET) \
		--build=$(HOST_BUILD) ; \
	)

clean:
	if [ -f $(SRC_NAME)/Makefile ] ; then \
		$(MAKE) -C $(SRC_NAME) distclean ; \
	fi; \
	rm -f config_done
	rm -f inadyn

romfs:
	cp $(SRC_NAME)/src/inadyn .
	$(STRIP) inadyn
	$(ROMFSINST) /bin/inadyn
