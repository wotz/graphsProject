#include <stdlib.h>
#include <stdio.h>
#include "headers/grafo.h"
#include "headers/data.h"

Grafo* recebeDados(int argc, char **argv){
    int numVertices;
    int aresta1,aresta2;
    double weight;
    int linha = 1;
    Grafo* grafo  = (Grafo*)malloc(sizeof(Grafo));

    FILE *arqGrafo = fopen(argv[1], "r");
    if(arqGrafo == NULL){
        printf("\nERRO 2: Não foi possível abrir o arquivo de grafo\n");
        exit(1);
    }
    else{
        fscanf(arqGrafo, "%d\n",&numVertices);
        grafo = criaGrafo(numVertices);

        while(fscanf(arqGrafo, "%d %d %lf\n", &aresta1, &aresta2, &weight)!=EOF){
            linha++;
            //printf("%d %d %lf\n",aresta1,aresta2,weight);

            //QUESTÃO DA INDEXAÇÃO
            adicionaAresta(grafo,aresta1-1,aresta2-1,weight);
            if(weight < 0){
                printf("ERRO 3: peso de aresta negativo\n");
                printf("Este algoritmo não funciona com valores negativos para pesos de arestas,\npor favor altere a linha %d do arquivo %s\n",linha,argv[1]);
                exit(1);
            }
<<<<<<< HEAD
            
        }
        setEdge(grafo,linha - 1);
=======
            //Guardar os valores na estrutura
        }
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e
    }
    fclose(arqGrafo);

    return grafo;
}