CC = gcc
CFLAGS = -g -Wall -I../include

SRCS = sc_regSet.c sc_regInit.c sc_regGet.c sc_memorySet.c sc_memorySave.c sc_memoryLoad.c sc_memoryInit.c sc_memoryGet.c sc_commandEncode.c sc_commandDecode.c sc_variables.c sc_cpuCacheInit.c

OBJS = $(SRCS:.c=.o)

LIBRARY = libmySimpleComputer.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(LIBRARY)
	rm -f *.o
