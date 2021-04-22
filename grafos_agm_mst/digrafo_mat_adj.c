#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"
#include "heap.c"
#include "digrafo_mat_adj.h"

#define VERDADEIRO 1
#define FALSO 0

struct digrafo {
	int v;
	int a;
	int **m_adj;
};

int **matriz(int n, int valor) {
	int **m = (int**) calloc(n, sizeof(int*));
	for (vertice i = 0; i < n; ++i)
		m[i] = (int*) calloc(n, sizeof(int));

	if(valor != 0)
		for (vertice i = 0; i < n; ++i)
			for (vertice j = 0; j < n; ++j)
				m[i][j] = valor;

	return m;
}

digrafo criar_digrafo(int v) {
	digrafo G = (struct digrafo*) malloc(sizeof(digrafo));
	G->v = v;
	G->a = 0;
	G->m_adj = matriz(v, 0);
	return G;
}

int inserir_aresta(digrafo G, vertice v, vertice w, int peso) {
	if (G->m_adj[v][w] == 0) {
		G->m_adj[v][w] = peso;
		G->a++;
		return VERDADEIRO;
	}
	return FALSO;
}

int remover_aresta(digrafo G, vertice v, vertice w) {
	if (G->m_adj[v][w] > 0) {
		G->m_adj[v][w] = 0;
		G->a--;
		return VERDADEIRO;
	}
	return FALSO;
}

void imprimir(digrafo G) {
	for (vertice v = 0; v < G->v; v++) {
		int existe = 0;
		for (vertice w = 0; w < G->v; w++) {
			if(G->m_adj[v][w] > 0) {
				existe = 1;
				break;
			}
		}
		if (existe) printf("%2d:", v);
		for (vertice w = 0; w < G->v; w++)
			if(G->m_adj[v][w] > 0)
				printf(" %2d", w);
		if (existe) printf("\n");
	}
}

void algPrim(digrafo G) {
	int chave[G->v], orig[G->v], peso = 0;
	printf("Atribuindo infinito para as chaves (pesos) e -1 para as origens\n");
	for (vertice v = 0; v < G->v; v++) {
		chave[v] = INT_MAX;
		orig[v] = -1;
	}
	printf("Criando e inserindo todos os vertices na min-heap\n");
	Heap* h = criar_heap();
	for (vertice v = 0; v < G->v; v++) inserir_heap(h, v);
	while(!esta_vazia(h)) {
		int u = h->dados[0];
		printf("Fixando e removendo o menor vértice (%d)\n", u);
		remover_min(h);
		printf("\tPercorrendo todas as arestas\n");
		for (vertice v = 0; v < G->v; v++) {
			if (G->m_adj[u][v] != 0) {
				printf("\t\tVertice (%d)\n\t\t\tVerificando se existe dentro da fila de prioridade\n", v);
				if (existe(h, v)) {
					printf("\t\t\tVerificando se o peso da chave e maior que o peso do vertice\n");
					if (chave[v] > G->m_adj[u][v]) {
						printf("\t\t\tAtribuindo peso %d e origem %d para o vertice %d\n", G->m_adj[u][v], u, v);
						chave[v] = G->m_adj[u][v];
						orig[v] = u;
					}
				}
			}
		}
	}
	printf("Removendo arestas excedentes aa arvore geradora minima\n");
	for (vertice v = 0; v < G->v; v++) for (vertice w = 0; w < G->v; w++) if(G->m_adj[v][w] != 0 && orig[w] != v) {
		printf("\tRemovendo aresta %d de peso %d do vertice %d\n", w, G->m_adj[v][w], v);
		remover_aresta(G, v, w);
	}
	printf("Calculando peso total da arvore geradora minima\n");
	for (vertice v = 0; v < G->v; v++) if(chave[v] != INT_MAX) peso += chave[v];
	printf("Peso total: %d\n", peso);
}