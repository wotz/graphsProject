#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
#include "headers/data.h"
#include "headers/mst.h"
#include "headers/dijkstra.h"
#include "headers/printter.h"
#include <limits.h>

int main(int argc, char* argv[]){
    Grafo* grafoIn = recebeDados(argc,argv);
    //imprimeGrafo(grafoIn);
    
    mstPrim(grafoIn,0);
    //float* d = dijkstra(grafoIn, 0);
    printf("Dijkstra\n");
    //resultadoDijkstra(grafoIn, d, 1, 2);

    // float* d = dijkstra(grafoIn, 2);
    // imprimeDistancia(d, getSize(grafoIn));
    //printf("\n\n");
    //d = dijkstra(grafB,  0);
    //imprimeDistancia(d, getSize(grafB));
    return 0;
}