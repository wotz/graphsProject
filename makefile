all: 
	gcc -c grafo.c -o bin/grafo.o
	gcc -c main.c -o bin/main.o
	gcc bin/main.o bin/grafo.o -o exit
