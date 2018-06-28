CCFLAGS+=-Os -Wall -I. -ffunction-sections -fdata-sections $(CFLAGS)
LDFLAGS+=-s -Wl,--gc-sections
LIBS=md5.o rmd160.o

lanauth: lanauth.o $(LIBS)
	$(CC) $(CCFLAGS) $(LDFLAGS) lanauth.o -o lanauth $(LIBS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o lanauth

romfs:
	$(STRIP) lanauth
	$(ROMFSINST) /usr/sbin/lanauth
