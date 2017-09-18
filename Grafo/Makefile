cc = gcc
cflags = -Wall -Wextra

all: grafo

grafo: main.o
	$(cc) -o grafo.exe main.o

main.o: main.c
	$(cc) $(cflags) -c main.c

teste: all
	drmemory -batch grafo.exe

clean:
	-del *.gch
	-del *.o
	-del *.exe
