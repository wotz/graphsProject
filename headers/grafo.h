#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

//---Lista.h---//
//---Structs---//
    typedef struct adjacencia{
        int destino;
        float peso;
    }Adjacencia;

    typedef struct vertice{
        int ant;
        int grau;
        double valor;
        int statusMST;
        Adjacencia* listaAresta;
    }Vertice;

    typedef struct grafo{
        int size;
        Vertice* vertice;
    }Grafo;

//---Getter e Setters e Semelhantes---//

    int getSize(Grafo* grafo);

    int getGrau(Grafo* grafo, int v);

    float getPeso(Grafo* grafo, int v, int a); 

    void setGrau(Grafo* grafo, int v, int grau);

    void nextGrau(Grafo* grafo, int v);

//---Creators(Gods)---//

    void criaAresta(Grafo* grafo, int origem, int destino, float peso);
    
    Grafo* criaGrafo(int n);

    Grafo* copiaGrafo(Grafo* grafo);

    void primeiraAresta(Grafo* grafo, int origem, int destino, float peso);  

    void pushAresta(Grafo* grafo, int origem, int destino, float peso);
    
//---Funções de Validação---//

    int validaGrafo(Grafo* grafo, int a, int b, float peso);

//---Funções de Adição de Arestas---//

    void adicionaAresta(Grafo* grafo, int a, int b, float peso);

    void add(Grafo* grafo, int a, int b, float peso);

    void addAlocando(Grafo* grafo, int a, int b, float peso);

    void addRealocando(Grafo* grafo, int a, int b, float peso);
    
//---Utils---//
    int buscaVerticeAdj(Grafo* grafo, int u, int v);   
#endif // LISTA_H_INCLUDED