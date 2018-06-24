all: 
	gcc -c grafo.c -o bin/grafo.o
	gcc -c main.c -o bin/main.o
	gcc -c dijkstra.c -o bin/dijkstra.o
	gcc -c printter.c -o bin/printter.o
	gcc bin/* -o exit
