#include <stdio.h>
#include <stdlib.h>
#include "digrafo_mat_adj.h"
#include "digrafo_mat_adj.c"

/* Função principal para teste da estrutura de dados. */
int main() {
	digrafo g = criar_digrafo(9);
	inserir_aresta(g, 0, 1, 6);
	inserir_aresta(g, 0, 2, 3);
	inserir_aresta(g, 0, 3, 5);
	inserir_aresta(g, 1, 0, 6);
	inserir_aresta(g, 1, 4, 12);
	inserir_aresta(g, 1, 5, 12);
	inserir_aresta(g, 1, 6, 7);
	inserir_aresta(g, 1, 7, 8);
	inserir_aresta(g, 1, 8, 5);
	inserir_aresta(g, 2, 0, 3);
	inserir_aresta(g, 2, 4, 7);
	inserir_aresta(g, 2, 5, 7);
	inserir_aresta(g, 2, 6, 6);
	inserir_aresta(g, 2, 7, 7);
	inserir_aresta(g, 2, 8, 8);
	inserir_aresta(g, 3, 0, 5);
	inserir_aresta(g, 3, 4, 4);
	inserir_aresta(g, 3, 5, 6);
	inserir_aresta(g, 3, 6, 5);
	inserir_aresta(g, 3, 7, 10);
	inserir_aresta(g, 3, 8, 12);
	inserir_aresta(g, 4, 1, 12);
	inserir_aresta(g, 4, 2, 7);
	inserir_aresta(g, 4, 3, 4);
	inserir_aresta(g, 5, 1, 12);
	inserir_aresta(g, 5, 2, 7);
	inserir_aresta(g, 5, 3, 6);
	inserir_aresta(g, 6, 1, 7);
	inserir_aresta(g, 6, 2, 6);
	inserir_aresta(g, 6, 3, 5);
	inserir_aresta(g, 7, 1, 8);
	inserir_aresta(g, 7, 2, 7);
	inserir_aresta(g, 7, 3, 10);
	inserir_aresta(g, 8, 1, 5);
	inserir_aresta(g, 8, 2, 8);
	inserir_aresta(g, 8, 3, 12);
	printf("Arvore original\n");
	imprimir(g);
	printf("\n");
	algPrim(g);
	printf("\nArvore Geradora Minima\n");
	imprimir(g);
	return 0;
}