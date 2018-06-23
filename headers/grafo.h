#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//---Lista.h---//
//---Structs---//
    typedef struct adjacencia{
        int destino;
        float peso;
    }Adjacencia;

    typedef struct vertice{
        int grau;
        Adjacencia* listaAresta;
    }Vertice;

    typedef struct grafo{
        int size;
        Vertice* vertice;
    }Grafo;

//---Getter e Setters e Semelhantes---//
    int getSize(Grafo* grafo);
    int getGrau(Grafo* grafo, int v);
    void setGrau(Grafo* grafo, int v, int grau);
    void nextGrau(Grafo* grafo, int v);

//---Creators(Gods)---//
    void criaAresta(Grafo* grafo, int origem, int destino, float peso);
    Grafo* criaGrafo(int n);
    void primeiraAresta(Grafo* grafo, int origem, int destino, float peso);         
    void pushAresta(Grafo* grafo, int origem, int destino, float peso);
    
//---Printters---//
    void imprimeGrafo(Grafo* grafo);   
    void imprimeAresta(Grafo* grafo, int origem, int n);

//---Trash---///
    int validaGrafo(Grafo* grafo, int origem, int destino, float peso);

//--- Funções de manipulação avançada de Vertices---//
    void adicionaAresta(Grafo* grafo, int a, int b, float peso);
//---Funções de Validação---//
    int validaGrafo(Grafo* grafo, int a, int b, float peso);
//---Funções de Adição de Arestas---//
    void add(Grafo* grafo, int a, int b, float peso);
    void addAlocando(Grafo* grafo, int a, int b, float peso);
    void addRealocando(Grafo* grafo, int a, int b, float peso);
    
       
#endif // LISTA_H_INCLUDED