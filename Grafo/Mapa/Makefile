cc = gcc
cflags = -Wall -Wextra

all: grafo

grafo: main.o grafo.o
	$(cc) -o grafo.exe main.o grafo.o

main.o: main.c
	$(cc) $(cflags) -c main.c

grafo.o: grafo.c
	$(cc) $(cflags) -c grafo.c

teste: all
	drmemory -batch grafo.exe

clean:
	-del *.gch
	-del *.o
	-del *.exe
