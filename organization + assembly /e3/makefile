# Makefile for csci 223 Exercise 3


# We'll make sure to compile with -g, so we 
# can use gdb, the GNU debugger
GCCFLAGS = -g

e3: main.o CacheBlock.o Cache.o 
	gcc $(GCCFLAGS) main.o CacheBlock.o Cache.o -o e3
	
main.o:
	# main.o should have been copied from ~csci223/public/e3.
	# attempting to recopy.
	cp ~csci223/public/e3/main.o .
	
Cache.o: Cache.h Cache.c CacheBlock.h
	gcc $(GCCFLAGS) -c Cache.c

CacheBlock.o: 
	# CacheBlock.o should have been copied from ~csci223/public/e3.
	# attempting to recopy.
	cp ~csci223/public/e3/CacheBlock.o .

clean:
	rm Cache.o e3

