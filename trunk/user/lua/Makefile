PKG_VERSION=5.1.5
SRC_NAME=lua-$(PKG_VERSION)

CFLAGS += -ffunction-sections -fdata-sections -fPIC -DLUA_USE_LINUX -std=gnu99
LDFLAGS += -Wl,--gc-sections

all:
	$(MAKE) -j$(HOST_NCPU) -C $(SRC_NAME) CC="$(CC)" AR="$(AR) rcu" RANLIB="$(RANLIB)" CFLAGS="$(CFLAGS)" MYLDFLAGS="$(LDFLAGS)" PKG_VERSION=$(PKG_VERSION) linux
	cp -fP $(SRC_NAME)/src/lua.h $(STAGEDIR)/include/
	cp -fP $(SRC_NAME)/src/lualib.h $(STAGEDIR)/include/
	cp -fP $(SRC_NAME)/src/luaconf.h $(STAGEDIR)/include/
	cp -fP $(SRC_NAME)/src/lauxlib.h $(STAGEDIR)/include/
	cp -fP $(SRC_NAME)/src/lnum_config.h $(STAGEDIR)/include/
	cp -fP $(SRC_NAME)/src/liblua.a $(STAGEDIR)/lib/
	cp -fP $(SRC_NAME)/src/liblua.so* $(STAGEDIR)/lib/
	cp -fP $(SRC_NAME)/etc/lua.pc $(STAGEDIR)/lib/pkgconfig/
	sed -i 's,/usr/local,$(STAGEDIR),g' $(STAGEDIR)/lib/pkgconfig/lua.pc

clean:
	$(MAKE) -C $(SRC_NAME) clean

romfs:
	$(ROMFSINST) $(SRC_NAME)/src/liblua.so.$(PKG_VERSION) /lib/liblua.so.$(PKG_VERSION)
	$(ROMFSINST) -s liblua.so.$(PKG_VERSION) /lib/liblua.so
	$(ROMFSINST) $(SRC_NAME)/src/lua /bin/lua
