cc = gcc
cflags = -Wall -Wextra

all: bst

bst: main.o bst.o
	$(cc) -o bst.exe main.o bst.o

main.o: main.c
	$(cc) $(cflags) -c main.c

bst.o: bst.c bst.h
	$(cc) $(cflags) -c bst.c bst.h

teste.o: teste.c
	$(cc) $(cflags) -c teste.c

teste: all
	drmemory -batch -show_reachable bst.exe

clean:
	-del *.gch
	-del *.o
	-del *.exe
