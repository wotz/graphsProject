#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
#include "headers/data.h"
#include "headers/mst.h"
#include "headers/dijkstra.h"
#include "headers/printter.h"
#include <limits.h>

int main(int argc, char* argv[]){
<<<<<<< HEAD
    Grafo* grafoIn = recebeDados(argc,argv);
=======
    // Grafo* grafoIn = recebeDados(argc,argv);
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e
    Grafo* grafo = criaGrafo(5);
    adicionaAresta(grafo, 0, 1, 0.1f);
    adicionaAresta(grafo, 1, 4, 0.2f);
    adicionaAresta(grafo, 4, 2, 5.0f);
    adicionaAresta(grafo, 2, 3, 9.5f);
    adicionaAresta(grafo, 3, 4, 2.3f);
    adicionaAresta(grafo, 0, 4, 1.0f);

<<<<<<< HEAD
    imprimeGrafo(grafoIn);
=======
    // imprimeGrafo(grafoIn);
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e

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
    
    Grafo* grafoC = criaGrafo(8);
    adicionaAresta(grafoC, 0, 1, 6.0f);
    adicionaAresta(grafoC, 0, 2, 5.0f);
    adicionaAresta(grafoC, 0, 3, 14.0f);
    adicionaAresta(grafoC, 0, 4, 10.0f);
    adicionaAresta(grafoC, 3, 4, 3.0f);
    adicionaAresta(grafoC, 1, 2, 4.0f);
    adicionaAresta(grafoC, 2, 5, 2.0f);
    adicionaAresta(grafoC, 4, 5, 8.0f);
    adicionaAresta(grafoC, 2, 6, 9.0f);
    adicionaAresta(grafoC, 5, 7, 15.0f);
<<<<<<< HEAD

    mstPrim(grafoC,0);

    float* d = dijkstra(grafoIn, 2);
    //imprimeDistancia(d, getSize(grafoIn));
=======
    float* d = dijkstra(grafo, 0);
    // imprimeGrafo(grafo);
    
    resultadoDijkstra(grafo, d, 1, 3);
    // Grafo* tree = mstPrim(grafoIn,0);

    // float* d = dijkstra(grafoIn, 2);
    // imprimeDistancia(d, getSize(grafoIn));
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e
    //printf("\n\n");
    //d = dijkstra(grafB,  0);
    //imprimeDistancia(d, getSize(grafB));

    return 0;
}