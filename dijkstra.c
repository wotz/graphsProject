#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "headers/grafo.h"
#include "headers/dijkstra.h"
#define INFINITO (float)INT_MAX/2.0f


//---Dijkstra e Auxiliares---//

    // Por enquanto gera uma lista de distância dos vértices apartir de s
    float* dijkstra(Grafo* grafo, int s){
        int size = getSize(grafo);
        float* d = (float*)malloc(size*sizeof(float));
        bool aberto[size];
        incializaD(grafo, d, 0);
        incializaAberto(aberto, size);

        while(existeAberto(aberto, size)){

            // Seleciona o vértice de menor distância até o momento
            int u = menorDist(grafo, aberto, d);
            
            // Fecha o vértice selecionado
            aberto[u] = false;
            
            // Percorre a lista de adjacencia de u relaxando as arestas
            for(int i = 0; i < getGrau(grafo, u); i++){
                relaxa(grafo, d, u, grafo->vertice[u].listaAresta[i].destino, i);
            }
        }    
        return d;
    }

    // Atualiza na lista de distâncias as passíveis de serem atualizadas
    void relaxa(Grafo* grafo, float* distancia, int u, int v, int i){
        
        /*
            Verifica se o peso atual para alcanaçar a aresta v é maior que
            o peso da aresta u mais o peso de u para v 
        */ 
        if(distancia[v] > distancia[u] + getPeso(grafo, u, i)){
            distancia[v] = distancia[u] + getPeso(grafo, u, i);
        }
    }

    /*
        Retorna o índice do vertice com menor distância na lista d
     */
    int menorDist(Grafo* g, bool* aberto, float* d){
        int  i;
        for(i=0; i < g->size; i++){
            if(aberto[i]){
                break;
            }
        }
        if(i == g->size){
            return -1;
        }
        int menor = i;
        for(i = i +1; i < g->size; i++){
            if(aberto[i] && (d[menor]) > d[i]){
                menor = i;
            }
        }
        return menor;
    }

    // Existe aberto?
    bool existeAberto(bool* aberto, int size){
        for(int i = 0; i < size; i++){
            if(aberto[i]){
                return true;
            }
        }
        return false;
    }


//---To Inicializar---//

    // Inicializa lista de distâncias com valor infinito, exceto s
    void incializaD(Grafo* grafo, float* distancia, int s){
       
        for(int v = 0; v < grafo->size; v++){
            distancia[v] = INFINITO;
        }

        // s recebe zero pois ele é o ponto de partida
        distancia[s] =0.0f;
    }

    // Inicializa lista de aberto: default = true    
    void incializaAberto(bool* aberto, int size){
        for(int i=0; i< size;i++){
            aberto[i] = true;
        }
    }










