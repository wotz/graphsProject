#ifndef PRINTTER_H_INCLUDED
#define PRINTTER_H_INCLUDED
#include "grafo.h"

//---Printters (Hp, é claro)---//
    
    void imprimeGrafo(Grafo* grafo);
    
    void imprimeAresta(Grafo* grafo, int a, int n);
    
    void imprimeDistancia(float* d, int size);
    
#endif