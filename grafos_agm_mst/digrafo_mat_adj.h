#ifndef GRAFO_MAT_ADJ_H
#define GRAFO_MAT_ADJ_H

typedef int vertice;
typedef struct digrafo * digrafo;

int **matriz(int n, int valor);
digrafo criar_digrafo(int v);
int inserir_aresta(digrafo G, vertice v, vertice w, vertice peso);
int remover_aresta(digrafo G, vertice v, vertice w);
void imprimir(digrafo G);
void algPrim(digrafo G);

#endif // GRAFO_MAT_ADJ_H