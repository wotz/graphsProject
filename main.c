#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
#include "headers/dijkstra.h"
#include "headers/printter.h"
#include <limits.h>






int main(){
    Grafo* grafo = criaGrafo(5);
    adicionaAresta(grafo, 0, 1, 0.1f);
    adicionaAresta(grafo, 1, 4, 0.2f);
    adicionaAresta(grafo, 4, 2, 5.0f);
    adicionaAresta(grafo, 2, 3, 9.5f);
    adicionaAresta(grafo, 3, 4, 2.3f);
    adicionaAresta(grafo, 0, 4, 1.0f);
    Grafo* grafB = criaGrafo(5);
    adicionaAresta(grafB, 0, 1, 0.1f);
    adicionaAresta(grafB, 0, 2, 0.99f);
    adicionaAresta(grafB, 0, 3, 0.12f);
    adicionaAresta(grafB, 0, 4, 0.27f);
    adicionaAresta(grafB, 1, 2, 0.5f);
    adicionaAresta(grafB, 1, 3, 0.89f);
    adicionaAresta(grafB, 1, 4, 0.39f);
    adicionaAresta(grafB, 2, 3, 0.85f);
    adicionaAresta(grafB, 2, 4, 0.34f);
    adicionaAresta(grafB, 3, 4, 0.47f);
    
    

    float* d = dijkstra(grafB, 2);
    imprimeDistancia(d, getSize(grafB));
    printf("\n\n");
    d = dijkstra(grafB,  0);
    imprimeDistancia(d, getSize(grafB));


    
    return 0;
}