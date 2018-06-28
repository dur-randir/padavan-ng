CFLAGS  += -Wall
CFLAGS  += -I$(STAGEDIR)/include -L$(STAGEDIR)/lib
CFLAGS  += -ffunction-sections -fdata-sections
CPPFLAGS += -fno-exceptions -fno-rtti
CPPFLAGS += -I$(STAGEDIR)/include -L$(STAGEDIR)/lib
CPPFLAGS += -ffunction-sections -fdata-sections
LDFLAGS += -Wl,--gc-sections

SRC = \
	main.cpp \
	soap.cpp \
	mem.cpp \
	mcast.cpp \
	luaxlib.cpp \
	luaxcore.cpp \
	luajson.cpp \
	luajson_parser.cpp

embedded:
	$(CC) $(CFLAGS) -c -o md5.o md5c.c
	$(CC) -Os $(CPPFLAGS) $(LDFLAGS) -DWITH_URANDOM -o xupnpd $(SRC) md5.o -llua -lm -ldl -lssl -lcrypto

clean:
	rm -f md5.o
	rm -f xupnpd
