#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

//---Lista.h---///
//---Structs---///
    typedef struct adjacencia{
        int size;
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

//---Getter e Setters e Semelhantes---///
    int getSize(Grafo* grafo);
    int getGrau(Grafo* grafo, int v);
    void setGrau(Grafo* grafo, int v, int grau);
    void nextGrau(Grafo* grafo, int v);

//---Creators(Gods)---///
    void criaAresta(Grafo* grafo, int origem, int destino, float peso);
    Grafo* criaGrafo(int n);
    void primeiraAresta(Grafo* grafo, int origem, int destino, float peso);         
    void pushAresta(Grafo* grafo, int origem, int destino, float peso);
    
//---Printters---///
    void imprimeGrafo(Grafo* grafo);   
    void imprimeAresta(Grafo* grafo, int origem, int n);

//---Trash---///
    int validaGrafo(Grafo* grafo, int origem, int destino, float peso);
        
#endif //!GRAFO_H_INCLUDED