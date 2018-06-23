#include <stdio.h>
#include <stdlib.h>
#include "headers/grafo.h"
//Getters
    int getSize(Grafo* grafo){
        return grafo->size;
    }
    int getGrau(Grafo* grafo, int a){
        return grafo->vertice[a].grau;
    }

//Setters

    void setGrau(Grafo* grafo, int a, int grau){
        grafo->vertice[a].grau =  grau;
    }

    void nextGrau(Grafo* grafo, int a){
        grafo->vertice[a].grau++;
    }



//Funções de manipulação avançada de Vertices
    void adicionaAresta(Grafo* grafo, int a, int b, float peso){
        a--;
        b--;
        // Se o gráfico não passar na validação feche na ignorância o programa
        if (!validaGrafo(grafo, a, b, peso)) {
            printf("Com grandes poderes vem grandes responsabilidades, tome cuidado ao passar coisas zoadas pro meu grafo\n");
            exit(1);
        }
        add(grafo, a, b, peso);
        nextGrau(grafo, a);
        nextGrau(grafo, b);
        
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
            for(int j = 0; j < getGrau(grafo, i); j++){
                imprimeAresta(grafo, i, j);
            }
            printf("\n");
        }
    }
    void imprimeAresta(Grafo* grafo, int a, int n){
        if (n >= getGrau(grafo, a)) {
            printf("Estou evitando um nullpointer: voce esta imprimindo uma aresta que não existe, se liga.\n");
            exit(1);
        }
        printf("origem: %d ", a + 1);
        printf("destino: %d ", grafo->vertice[a].listaAresta[n].destino + 1);
        printf("Peso: %.2f ", grafo->vertice[a].listaAresta[n].peso);
        printf("\n");
    }

//Funções de Validação
    int validaGrafo(Grafo* grafo, int a, int b, float peso){
        if (a == b) {
            return 0;
        }
        
        if (a < 0 || a >= getSize(grafo)) {
            return 0;
        }
        
        if (b < 0 || b >= getSize(grafo)) {
            return 0;
        }
        
        if (peso < 0) {
            return 0;
        }

        return 1;    
    }

//Funções de Adição de Arestas: se estivessemos em uma linguagem oo essas funções seriam privadas pra evitar m3rD45
    void add(Grafo* grafo, int a, int b, float peso){
        int grauA = getGrau(grafo, a);
        int grauB = getGrau(grafo, b);
        
        // aloque a e aloque b
        if(grauA == 0 && grauB == 0){
            addAlocando(grafo, a, b, peso);
            addAlocando(grafo, b, a, peso);
            return;
        }

        // aloque a e realoque b
        if(grauA == 0 && grauB > 0){
            addAlocando(grafo, a, b, peso);
            addRealocando(grafo, b, a, peso);
            return;
        
        }

        // realoque b e aloque a
        if(grauA > 0 && grauB == 0){
            addRealocando(grafo, a, b, peso);
            addAlocando(grafo, b, a, peso);
            return;
        }

        // realoque b e realoque a
        addRealocando(grafo, a, b, peso);
        addRealocando(grafo, b, a, peso);

    } 

    // Adiciona aresta no vértice v alocando
    void addAlocando(Grafo* grafo, int a, int b, float peso){
        grafo->vertice[a].listaAresta = (Adjacencia*)malloc(sizeof(Adjacencia));
        grafo->vertice[a].listaAresta[0].destino = b;
        grafo->vertice[a].listaAresta[0].peso = peso;
    }

    // Adiciona aresta no vértice v realocando
    void addRealocando(Grafo* grafo, int a, int b, float peso){
        int n = getGrau(grafo, a) + 1;
        grafo->vertice[a].listaAresta = realloc(grafo->vertice[a].listaAresta, n * sizeof(Adjacencia));
        grafo->vertice[a].listaAresta[n - 1].destino = b;
        grafo->vertice[a].listaAresta[n - 1].peso = peso;
    }