#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
#include "headers/dijkstra.h"
#include <limits.h>






int main(){
    Grafo* grafo = criaGrafo(5);
    adicionaAresta(grafo, 0, 1, 0.1f);
    adicionaAresta(grafo, 1, 4, 0.2f);
    adicionaAresta(grafo, 4, 2, 5.0f);
    adicionaAresta(grafo, 2, 3, 9.5f);
    adicionaAresta(grafo, 3, 4, 2.3f);
    adicionaAresta(grafo, 0, 4, 1.0f);
    // float d[5];
    // incializaD(grafo, d, 0);
    // relaxa(grafo, d, 0, 1);
    // imprimeDistancia(d, 5);
    // imprimeGrafo(grafo);
    dijkstra(grafo, 0);
    return 0;
}