#ifndef PRINTTER_H_INCLUDED
#define PRINTTER_H_INCLUDED
#include "grafo.h"
<<<<<<< HEAD
#include "mst.h"
=======
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e

//---Printters (Hp, é claro)---//
    
    void imprimeGrafo(Grafo* grafo);
    
    void imprimeAresta(Grafo* grafo, int a, int n);
    
    void imprimeDistancia(float* d, int size);
<<<<<<< HEAD
    
    void imprimeMST(Grafo* grafo, Aresta* mstArestas);
=======

    void resultadoDijkstra(Grafo* grafo, float* d,int origem, int destino);
    
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e
#endif