GCCFLAGS = -g 

# simple e1 makefile

# The first target is always the default target. When you type
# "make" on the command line with no arguments, this is the target
# that will be built.

#The target below
# attempts to build e1 by linking together the three object files 
e1:  sphere.o cube.o main.o 
	gcc $(GCCFLAGS) main.o  sphere.o cube.o  -o e1

# if any of the files listed after the : are newer than 
# main.o, then execute the gcc command below. The other
# targets work similarly.   
main.o: main.c sphere.c cube.c  sphere.h cube.h
	gcc $(GCCFLAGS) -c main.c
	
sphere.o: sphere.c sphere.h main.c
	gcc $(GCCFLAGS) -c sphere.c
	
cube.o: cube.c cube.h main.c
	gcc $(GCCFLAGS) -c cube.c

# this target is special. You use it by typing "make clean" on the
# command line. It then executes the rm command to delete any
# intermediate files, so you can start fresh.	
clean:
	rm -f *.o e1
