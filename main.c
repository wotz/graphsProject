#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"

int main(){
    Grafo* grafo = criaGrafo(10);
    imprimeGrafo(grafo);
    criaAresta(grafo, 0, 2, 0.1f);
    printf("\n");
    imprimeGrafo(grafo);
    imprimeAresta(grafo,0,0);    
    return 0;
}