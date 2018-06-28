BINS	= mktplinkfw2
OBJS	= mktplinkfw2.o

#
# Use native tools and options
#
CPPFLAGS   = -idirafter -DUSE_HOSTCC -fgnu89-inline
CFLAGS     = $(HOST_CFLAGS) $(CPPFLAGS) -O
AFLAGS	   = -D__ASSEMBLY__ $(CPPFLAGS)
MAKEDEPEND = makedepend
CC	   = gcc
STRIP	   = strip

all:	.depend $(BINS)

mktplinkfw2: mktplinkfw2.o mktplinkfw-lib.o md5.o
	$(CC) $(CFLAGS) $(HOST_LDFLAGS) -o $@ $^
	$(STRIP) $@

mktplinkfw-lib.o: mktplinkfw-lib.c
	$(CC) $(CFLAGS) -c $<

md5.0: md5.c
	$(CC) $(CFLAGS) -c $<

mktplinkfw2.o: mktplinkfw2.c
	$(CC) $(CFLAGS) -c $<

.depend: Makefile $(OBJS:.o=.c)
	$(CC) -M $(HOST_CFLAGS) $(CPPFLAGS) $(OBJS:.o=.c) > $@

clean:
	rm -f *.o mktplinkfw2
