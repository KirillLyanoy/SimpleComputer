CC = gcc
CFLAGS = -g -Wall

SRCS = mt_clrscr.c mt_getscreensize.c mt_gotoXY.c mt_setbgcolor.c mt_setfgcolor.c

OBJS = $(SRCS:.c=.o)

LIBRARY = myTerm.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(LIBRARY)
