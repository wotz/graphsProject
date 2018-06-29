#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
#include "headers/data.h"
#include "headers/mst.h"
#include "headers/dijkstra.h"
#include "headers/printter.h"
#include <limits.h>

int main(int argc, char* argv[]){
    Grafo* grafoIn = recebeDados(argc, argv);
    imprimeGrafo(grafoIn);

    float* d = dijkstra(grafoIn, 4);
    resultadoDijkstra(grafoIn,d, 4, 0);

    return 0;
}