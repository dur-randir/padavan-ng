TARGET=Linux
CFLAGS += -I$(STAGEDIR)/include -L$(STAGEDIR)/lib
CFLAGS += -D_GNU_SOURCE -DADB_HOST=1 -DHAVE_FORKEXEC=1 -DHAVE_OFF64_T=1
CFLAGS += -Isrc -Iinclude
CFLAGS += -ffunction-sections -fdata-sections -fvisibility=hidden
LDFLAGS += -Wl,--gc-sections

SRCS += src/adb.c \
	src/adb_auth_host.c \
	src/adb_client.c \
	src/commandline.c \
	src/console.c \
	src/fdevent.c \
	src/file_sync_client.c \
	src/get_my_path_linux.c \
	src/services.c \
	src/sockets.c \
	src/transport.c \
	src/transport_local.c \
	src/transport_usb.c \
	src/usb_linux.c \
	libcutils/load_file.c \
	libcutils/socket_inaddr_any_server.c \
	libcutils/socket_local_client.c \
	libcutils/socket_local_server.c \
	libcutils/socket_loopback_client.c \
	libcutils/socket_loopback_server.c \
	libcutils/socket_network_client.c \
	libzipfile/centraldir.c \
	libzipfile/zipfile.c

OBJS = $(SRCS:.c=.o)

all: adb

adb: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(OBJS) -lcrypto -lpthread -lz

romfs:
	$(ROMFSINST) adb /bin/adb

clean:
	rm -f adb $(OBJS)
