#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
//Getters
    int getSize(Grafo* grafo){
        return grafo->size;
    }
    int getGrau(Grafo* grafo, int v){
        return grafo->vertice[v].grau;
    }

//Setters
    void setGrau(Grafo* grafo, int v, int grau){
        grafo->vertice[v].grau =  grau;
    }
    void nextGrau(Grafo* grafo, int v){
        grafo->vertice[v].grau++;
    }


//Funções de manipulação avançada de Vertices
    void criaAresta(Grafo* grafo, int origem, int destino, float peso){

        // Se o gráfico não passar na validação feche na ignorância o programa
        if (!validaGrafo(grafo, origem, destino, peso)) {
            printf("Com grandes poderes vem grandes responsabilidades, tome cuidado ao passar coisas zoadas pro meu grafo\n");
            exit(1);
        }
        if (getGrau(grafo, origem) == 0) {
            primeiraAresta(grafo, origem, destino, peso);
        }   
        nextGrau(grafo, origem);
    }

// Gria crafos gom n vertiges
    Grafo* criaGrafo(int n){
        
        //Aloca grafo e vetor de vertices
        Grafo* grafo  = (Grafo*)malloc(sizeof(Grafo));
        Vertice* v = (Vertice*)malloc(n*sizeof(Vertice));
        grafo->size = n;

        //Inicializa o grau dos vertices como 0
        for (int i =0; i < n; i++) {
            v[i].grau  = 0;
        }
        grafo->vertice = v;
        return grafo;
    }


//Printters 
    void imprimeGrafo(Grafo* grafo){
        for (int i = 0; i < grafo->size; i++) {
            printf("i: %d grau: %d\n", i,grafo->vertice[i].grau);
        }
    }
    void imprimeAresta(Grafo* grafo, int origem, int n){
        if (n >= getGrau(grafo, origem)) {
            printf("Estou evitando um nullpointer: voce esta imprimindo uma aresta que não existe, se liga.\n");
            exit(1);
        }
             
        printf("Size: %d ", grafo->vertice[origem].listaAresta[n].size);
        printf("Origem: %d ", origem);
        printf("Destino: %d ", grafo->vertice[origem].listaAresta[n].destino);
        printf("Peso: %.2f ", grafo->vertice[origem].listaAresta[n].peso);
        printf("\n");
    }

//Lixo: Funções de Validação e alocação de memória
    
    int validaGrafo(Grafo* grafo, int origem, int destino, float peso){
        if (origem == destino) {
            return 0;
        }
        
        if (origem < 0 || origem >= getSize(grafo)) {
            return 0;
        }
        
        if (destino < 0 || destino >= getSize(grafo)) {
            return 0;
        }
        
        if (peso < 0) {
            return 0;
        }

        return 1;    
    }

    void primeiraAresta(Grafo* grafo, int origem, int destino, float peso){
        grafo->vertice[origem].listaAresta = (Adjacencia*)malloc(sizeof(Adjacencia));
        grafo->vertice[origem].listaAresta[0].size = 1;
        grafo->vertice[origem].listaAresta[0].destino = destino;
        grafo->vertice[origem].listaAresta[0].peso = peso;
    }
