CFLAGS+=-Os -Wall -I. -ffunction-sections -fdata-sections -fvisibility=hidden
LDFLAGS+=-s -Wl,--gc-sections
LIBS=md5.o rmd160.o

lanauth: lanauth.o $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) lanauth.o -o lanauth $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o lanauth

romfs:
	$(ROMFSINST) lanauth /usr/sbin/lanauth
