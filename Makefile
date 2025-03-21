CC = gcc
CFLAGS = -g

.PHONY: all clean

all: mySimpleComputer.a myTerm.a myBigChars.a myReadkey.a

mySimpleComputer.a:
	cd mySimpleComputer && $(MAKE)

myTerm.a:
	cd myTerm && $(MAKE)

myBigChars.a:
	cd myBigChars && $(MAKE)

myReadkey.a:
	cd myReadkey && $(MAKE)

clean:
	cd mySimpleComputer && $(MAKE) clean
	cd myTerm && $(MAKE) clean
	cd myBigChars && $(MAKE) clean
	cd myReadkey && $(MAKE) clean
	rm -f *.a
