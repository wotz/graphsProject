#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "headers/printter.h"
#include "headers/grafo.h"
#include "headers/mst.h"
#define INFINITO INT_MAX/2.0f

//---Printters (Hp, é claro)---//
    
    void imprimeGrafo(Grafo* grafo){
        for (int i = 0; i < grafo->size; i++) {
            for(int j = 0; j < getGrau(grafo, i); j++){
                printf("Imp: %d %d\n",i,j);
                imprimeAresta(grafo, i, j);
            }
            printf("\n");
        }
    }

    void imprimeAresta(Grafo* grafo, int a, int n){
        if (n >= getGrau(grafo, a)) {
            printf("Aresta Inexixtente!\n");
            exit(1);
        }
        printf("origem: %d ", a + 1);
        printf("destino: %d ", grafo->vertice[a].listaAresta[n].destino + 1);
        printf("Peso: %.2f ", grafo->vertice[a].listaAresta[n].peso);
        printf("\n");
    }
    
    void imprimeDistancia(float* d, int size){
        for(int i = 0; i < size; i++){
            if(d[i] == INFINITO){
                printf("%d: Infinito\n", i);
            } else {
                printf(("%d: %.2f\n"),i,d[i]);
            }
        }
    }

    void imprimeMST(Grafo* grafo, Aresta* mstArestas){
        float pesoMST = 0;
        printf("%d\n",getSize(grafo)-1);
        for(int u = 0;u < getSize(grafo); u++){
            pesoMST += mstArestas[u].peso;
            if(mstArestas[u].peso != 0.0)
                printf("%d %d %f\n",mstArestas[u].a,mstArestas[u].b,mstArestas[u].peso);
        }
        printf("%f\n",pesoMST);
    }