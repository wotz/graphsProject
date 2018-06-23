#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"

int main(){
    Grafo* grafo = criaGrafo(5);
    adicionaAresta(grafo, 1, 2, 0.1f);
    adicionaAresta(grafo, 2, 5, 0.2f);
    adicionaAresta(grafo, 5, 3, 5.0f);
    adicionaAresta(grafo, 3, 4, 9.5f);
    adicionaAresta(grafo, 4, 5, 2.3f);
    adicionaAresta(grafo, 1, 5, 1.0f);
    imprimeGrafo(grafo);
    
    
    return 0;
}