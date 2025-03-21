CC = gcc
CFLAGS = -g -Wall -I../include

SRCS = bc_bigcharread.c bc_bigcharwrite.c bc_box.c bc_getbigcharpos.c bc_printA.c bc_printbigchar.c bc_setbigcharpos.c

OBJS = $(SRCS:.c=.o)

LIBRARY = myBigChars.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(LIBRARY)
