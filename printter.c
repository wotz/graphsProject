#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "headers/printter.h"
#include "headers/grafo.h"
#define INFINITO INT_MAX/2.0f

//---Printters (Hp, é claro)---//
    
    void imprimeGrafo(Grafo* grafo){
        for (int i = 0; i < grafo->size; i++) {
            for(int j = 0; j < getGrau(grafo, i); j++){
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
        printf("Origem: %d ", a + 1);
        printf("destino: %d ", grafo->vertice[a].listaAresta[n].destino + 1);
        printf("peso: %.2f ", grafo->vertice[a].listaAresta[n].peso);
        if(grafo->vertice[a].ant + 1 == 0){
            printf("vertice inicial\n");
            return;
        }
        printf("Anterior: %d ", grafo->vertice[a].ant + 1);
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

    void resultadoDijkstra(Grafo* grafo, float* d, int origem, int destino){
        int size = getSize(grafo);
        int i, j = size - 1;
        int back[size];
        float peso = 0.0f;
        origem--;
        destino--;
        
        if (d[destino] == INFINITO){
            printf("O vértice %d não é alcançável a partir de %d ", destino + 1, origem + 1);
            return;
        }

        for(int cont = 0; cont < size; cont++){
            back[cont] = -1;
        }

        back[j] = destino;
        j--;
        for(i = destino;  i != origem; ){
            i = grafo->vertice[i].ant;
            back[j] = i;
            j --;
        }

        for(j = j + 1; j < size - 1; j++){
            int temp = buscaVerticeAdj(grafo, back[j], back[j+1]);
            peso += grafo->vertice[back[j]].listaAresta[temp].peso;
            imprimeAresta(grafo, back[j], temp);
        }
        printf("O custo total para ir de %d à %d é %.2f\n", origem + 1, destino + 1, peso);
    }