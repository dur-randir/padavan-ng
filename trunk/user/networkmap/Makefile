USERDIR = $(ROOTDIR)/user
SHDIR = $(ROOTDIR)/user/shared

EXEC = networkmap
OBJS = function.o networkmap.o

CFLAGS  += -ffunction-sections -fdata-sections -fvisibility=hidden -Wall -I. -I$(SHDIR) -I$(SHDIR)/include
CFLAGS  += -s -DNO_PARALLEL
#CFLAGS  += -DDEBUG -DDEBUG_MORE

LDFLAGS += -Wl,--gc-sections -L$(SHDIR) -lshared

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

romfs:
	$(ROMFSINST) /usr/sbin/$(EXEC)

clean: 
	rm -rf *.o $(EXEC) *~

