#include <stdlib.h>
#include <stdio.h>
#include "headers/grafo.h"
#include "headers/dijkstra.h"
#include "headers/mst.h"
#include "headers/printter.h"
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

            adicionaAresta(grafo,aresta1-1,aresta2-1,weight);
            if(weight < 0){
                printf("ERRO 3: peso de aresta negativo\n");
                printf("Este algoritmo não funciona com valores negativos para pesos de arestas,\npor favor altere a linha %d do arquivo %s\n",linha,argv[1]);
                exit(1);
            }
            if(aresta1 == aresta2){
                printf("AVISO 1: ciclos não serão considerados neste programa.\n");
                printf("Verifique que existe um ciclo na linha %d do arquivo %s\n",linha,argv[1]);
            }
            //Guardar os valores na estrutura
        }
        setEdge(grafo,linha - 1);
    }
    fclose(arqGrafo);

    return grafo;
}

void saidaPadrao(Grafo* grafoIn, Aresta* mstArestas, float* d){
    imprimeMST(grafoIn,mstArestas);
    printf("\n");

    if(getSize(grafoIn) >= 10){
        resultadoDijkstra(grafoIn,d, 0, 9);//menor caminho entre o vértice 1 e 10
        printf("\n");
    }
    if(getSize(grafoIn) >= 100){
        resultadoDijkstra(grafoIn,d, 0, 99);//menor caminho entre o vértice 1 e 100
        printf("\n");
    }
    if(getSize(grafoIn) >= 1000){
        resultadoDijkstra(grafoIn,d, 0, 999);//menor caminho entre o vértice 1 e 1000
        printf("\n");
    }
    if(getSize(grafoIn) >= 10000){
        resultadoDijkstra(grafoIn,d, 0, 9999);//menor caminho entre o vértice 1 e 10000
        printf("\n");
    }
    
}

void abreMenu(Grafo* grafoIn){
    int opcao = -1;
    int raiz;
    int verticeOrigem, verticeDestino;
    float* d;

    printf("Você é livre para realizar operações sobre o grafo\nMENU:\n");
    do{
        printf("1 - MST\n");
        printf("2 - Menor caminho entre dois vértices\n");
        printf("0 - Sair\n");
        scanf("%d",&opcao);
        
        switch (opcao){
            case 0:
                break;
            
            case 1:
                printf("\nO grafo tem tamanho %d:\n",getSize(grafoIn));
                printf("Digite o número do vértice raiz a partir do qual a MST é gerada:\n");
                printf("OBS.: Deve estar no intervalo fechado [1,%d]\n",getSize(grafoIn));
                scanf("%d",&raiz);
                if(1<= raiz && raiz <= getSize(grafoIn)){
                    Aresta* mstArestas = mstPrim(grafoIn,raiz - 1);
                    imprimeMST(grafoIn, mstArestas);
                    printf("\n");
                }
                else{
                    printf("ERRO: Vértice raiz inválido. Para o grafo inserido de tamanho %d insira um vértice raiz \n com valor entre 1 e %d\n",getSize(grafoIn),getSize(grafoIn));
                }
                break;
            
            case 2:
                printf("\nO grafo tem tamanho %d:\n",getSize(grafoIn));
                printf("Digite os números do vértice origem e do vértice destino:\n");
                printf("OBS.: Ambos os vértices devem estar no intervalo fechado [1,%d]\n",getSize(grafoIn));
                printf("Insira o vértice origem: ");
                scanf("%d",&verticeOrigem);
                printf("Insira o vértice destino: ");
                scanf("%d",&verticeDestino);
                printf("\n");
                
                d = dijkstra(grafoIn, verticeOrigem - 1);
                resultadoDijkstra(grafoIn,d, verticeOrigem - 1, verticeDestino - 1);//menor caminho entre o vértice 1 e 10000
                printf("\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }while(opcao != 0);
    
    return;
}