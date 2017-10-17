cc = gcc
cflags = -Wall -Wextra

all: hash

hash: main.o hash.o
	$(cc) -o hash.exe main.o hash.o

main.o: main.c
	$(cc) $(cflags) -c main.c

hash.o: hash.c
	$(cc) $(cflags) -c hash.c

teste: all
	drmemory -batch hash.exe

clean:
	-del *.o
	-del *.exe