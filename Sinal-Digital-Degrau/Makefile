cc = gcc
cflags = -Wall -Wextra

all: a

a: main.o
	$(cc) -o a.exe main.o

main.o: main.c
	$(cc) $(cflags) -c main.c

teste: all
	a.exe 1 0 1 0 1 0 1 0 1 0 1 0
	
clean:
	-del main.o
	-del a.exe