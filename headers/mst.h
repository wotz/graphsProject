#ifndef MST_H_INCLUDED
#define MST_H_INCLUDED

<<<<<<< HEAD
typedef struct aresta{
    int a;
    int b;
    float peso;
}Aresta;

void mstPrim(Grafo* grafo, int r);
Grafo* mstKruskal(Grafo* grafo);
void inicializaMST(Grafo* tree);
int minimum(Vertice* lista, int V);
=======
Grafo* mstPrim(Grafo* grafo, int r);
void inicializaMST(Grafo* tree);
int minimum(Vertice* lista, int V);
void imprimeMST(int parent[], int n, Grafo* grafo);
>>>>>>> 61a9ba5200b4949d160827bbda36775115340a0e
#endif//! MST_H_INCLUDED