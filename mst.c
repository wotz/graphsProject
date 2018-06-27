#include "headers/printter.h"
#include "headers/grafo.h"
#include "headers/mst.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//#define INFINITO INT_MAX/2.0f

void mstPrim(Grafo* grafo, int r){
    int atribui = 1;
    Vertice* lista = (Vertice*)malloc(getSize(grafo)*sizeof(Vertice));
    Aresta* mstArestas = (Aresta*)malloc(getSize(grafo)*sizeof(Aresta));
    int vertAdj;
    float pesoMST;
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
        int u = minimum(lista,getSize(grafo));//talvez possa melhorar aplicando um min-heap
        //printf("EXTRAI: %d\n",u+1);
        //printf("Marca %d como integrante da MST\n",u+1);
        lista[u].statusMST = 1;
        /*for ( i = 0; i < getSize(grafo); i++){
                printf("%lf (%d)\n",lista[i].valor,lista[i].statusMST);
            }   
            printf("--------------------\n");
        */
        
        for(indAdj=0; indAdj < getGrau(grafo,u); indAdj++){//Adjacentes de 0 até grau do vértice                
            vertAdj = lista[u].listaAresta[indAdj].destino;
            //printf("Vetice u: %d\n",u);
            //printf("Vertice adj: %d\n",vertAdj);
            //printf("Peso entre %d - %d: %f\n",u,vertAdj,getPeso(grafo,u,indAdj));
            if (lista[vertAdj].statusMST == 0 && getPeso(grafo,u,indAdj) < lista[vertAdj].valor){
                lista[vertAdj].valor = getPeso(grafo,u,indAdj);
                //printf("Salvando %d %d\n",u,indAdj);
                mstArestas[lista[u].listaAresta[indAdj].destino].a = u + 1;
                mstArestas[lista[u].listaAresta[indAdj].destino].b = lista[u].listaAresta[indAdj].destino + 1;
                mstArestas[lista[u].listaAresta[indAdj].destino].peso = getPeso(grafo,u,indAdj);
                atribui = 1;
            }   
            /*
            printf("Analisando vertice %d e seu %dº adjacente (%d): peso = %f\n",u+1,indAdj+1,lista[u].listaAresta[indAdj].destino+1,getPeso(grafo,u,indAdj));
            printf("--------------------\n");
            for ( i = 0; i < getSize(grafo); i++){
                printf("%lf (%d)\n",lista[i].valor,lista[i].statusMST);
            }   
            printf("--------------------\n");
            */
        }
    }
    imprimeMST(grafo,mstArestas);
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

Grafo* mstKruskal(Grafo* grafo){
    Aresta *mst = (Aresta*) malloc ((grafo->size)*sizeof(Aresta));
    int E = grafo->edge/2;
    Aresta *e = (Aresta*)malloc((E+1)*sizeof(Aresta));
    int *ch = (int*)malloc((E+1)*sizeof(int));
    int *sz = (int*)malloc((E+1)*sizeof(int));


    return grafo;
}

void arestaGrafo(Grafo* grafo, int V, Aresta* e){
    int i =1;
    for(int v=0;v<getSize(grafo);v++){
        int c = 0;
    }
}