CC = gcc
CFLAGS = -g -Wall -I../include

SRCS = rk_mytermregime.c rk_mytermrestore.c rk_mytermsave.c rk_variables.c rk_readkey.c

OBJS = $(SRCS:.c=.o)

LIBRARY = libmyReadkey.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(LIBRARY)
	rm -f *.o
