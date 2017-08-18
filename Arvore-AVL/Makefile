cc = gcc
cflags = -Wall -Wextra

all: bst

bst: main.o bst.o
	$(cc) -o bst.exe main.o bst.o

main.o: main.c
	$(cc) $(cflags) -c main.c

bst.o: bst.c bst.h
	$(cc) $(cflags) -c bst.c bst.h

teste: all
	drmemory -batch bst.exe

clean:
	-del *.gch
	-del *.o
	-del *.exe
