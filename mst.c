#include "headers/printter.h"
#include "headers/grafo.h"
#include "headers/mst.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//#define INFINITO INT_MAX/2.0f

Grafo* mstPrim(Grafo* grafo, int r){
    int atribui;
    Vertice* lista = (Vertice*)malloc(getSize(grafo)*sizeof(Vertice));

    int vertAdj;
    float key[getSize(grafo)];
    int i, u, indAdj;

    for (int i = 0; i<getSize(grafo); i++){
        lista[i] = grafo->vertice[i];
        lista[i].valor = 2147483648;
        lista[i].statusMST = 0;
        grafo->vertice[i].statusMST = 0;
    }
    
    lista[r].valor = 0;
    
    while(atribui){
        atribui = 0;
        int u = minimum(lista,getSize(grafo));
        printf("Obtendo o mínimo: %d\n",u);
        lista[u].statusMST = 1;
        
        for(indAdj=0; indAdj < getGrau(grafo,u); indAdj++){//Adjacentes de 0 até grau do vértice                
            printf("Analisando vertice %d e seu %dº adjacente\n",u,indAdj+1);
            printf("--------------------\n");
            for ( i = 0; i < getSize(grafo); i++){
                printf("%lf (%d)\n",lista[i].valor,lista[i].statusMST);
            }   
            printf("--------------------\n");

            vertAdj = lista[u].listaAresta[indAdj].destino;
            printf("Vetice u: %d\n",u);
            printf("Vertice adj: %d\n",vertAdj);
            printf("Peso entre %d - %d: %f\n",u,vertAdj,getPeso(grafo,u,indAdj));
            if (lista[vertAdj].statusMST == 0 && getPeso(grafo,u,indAdj) < lista[vertAdj].valor){
                lista[vertAdj].valor = getPeso(grafo,u,indAdj);
                atribui = 1;
            }
                
            //getchar();
        }
        
    }

    return grafo;
}

int minimum(Vertice* lista, int V){
    double min = 2147483648;
    int minInd;;
    int i,indAdj;
    
    for(int indAdj = 0; indAdj < V; indAdj++){
        if(lista[indAdj].valor < min && lista[indAdj].statusMST == 0){
            min = lista[indAdj].valor;
            minInd = indAdj;
        }
    }

    return minInd;
}

void imprimeMST(int parent[], int n, Grafo* grafo){
    for (int i = 0; i < getSize(grafo); i++){
        printf("%d - %d    %f \n", parent[i], i, getPeso(grafo,parent[i],i));
    }
}