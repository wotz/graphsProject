#ifndef MST_H_INCLUDED
#define MST_H_INCLUDED

typedef struct aresta{
    int a;
    int b;
    float peso;
}Aresta;

void mstPrim(Grafo* grafo, int r);
Grafo* mstKruskal(Grafo* grafo);
void inicializaMST(Grafo* tree);
int minimum(Vertice* lista, int V);
#endif//! MST_H_INCLUDED