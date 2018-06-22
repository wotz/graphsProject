#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
#include "headers/data.h"

int main(int argc, char *argv[]){
	/*
    long int timeInput = 0, timeLogic = 0, timeOutput = 0;
	struct timeval inputStart, inputEnd;
	struct timeval logicStart, logicEnd;
	struct timeval outputStart, outputEnd;
    */
    Grafo* grafo = recebeDados(argc,argv);

    //imprimeGrafo(grafo);
    //criaAresta(grafo, 0, 2, 0.1f);
    printf("\n");
    imprimeGrafo(grafo);
    imprimeAresta(grafo,0,1);    
    return 0;
}