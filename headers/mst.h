#ifndef MST_H_INCLUDED
#define MST_H_INCLUDED

Grafo* mstPrim(Grafo* grafo, int r);
void inicializaMST(Grafo* tree);
int minimum(Vertice* lista, int V);
void imprimeMST(int parent[], int n, Grafo* grafo);
#endif//! MST_H_INCLUDED