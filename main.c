#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/grafo.h"
#include "headers/mst.h"
#include "headers/data.h"
#include "headers/dijkstra.h"
#include "headers/printter.h"
#include <limits.h>

int main(int argc, char* argv[]){
    //ENTRADA
    Grafo* grafoIn = recebeDados(argc, argv);
    if(argc == 2){
        //PROCESSAMENTO
        Aresta* mstArestas = mstPrim(grafoIn,0);
        float* d = dijkstra(grafoIn, 0);
        
        //SAIDA
        saidaPadrao(grafoIn,mstArestas,d);
    }
    else if(!strcmp(argv[2],"1")){
        abreMenu(grafoIn);
    }
    return 0;
}