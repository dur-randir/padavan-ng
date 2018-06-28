DESTDIR = $(INSTROOT)/usr
BINDIR = $(DESTDIR)/sbin
MANDIR = $(DESTDIR)/share/man/man8

COPTS = -O2
CFLAGS= $(COPTS) -I../include/net
OBJS = pppdump.o bsd-comp.o deflate.o zlib.o

INSTALL= install

all:	pppdump

pppdump: $(OBJS)
	$(CC) -o pppdump $(LDFLAGS) $(OBJS)

clean:
	rm -f pppdump $(OBJS) *~

install:
	mkdir -p $(BINDIR) $(MANDIR)
	$(INSTALL) -s -c pppdump $(BINDIR)
	$(INSTALL) -c -m 444 pppdump.8 $(MANDIR)
