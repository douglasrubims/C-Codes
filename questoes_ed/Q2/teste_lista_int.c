#include <stdio.h>
#include <stdlib.h>
#include "lista_int.h"
#include "lista_int.c"

int main() {
	Lista lista = criar_lista();
	printf(">> Informacoes <<\n");
	printf("\nTamanho da lista: %d\n", tamanho(lista));
	printf("Esta cheia? %s\n", esta_cheia(lista) ? "Sim" : "Nao");
	printf("Esta vazia? %s\n", esta_vazia(lista) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);

	printf("\n>> Insercao <<");
	int i;
	for(i = 1; i <= 6; i++) printf("\nValor %d inserido? %s", i, inserir_fim(&lista, i) ? "Sim" : "Nao");
	printf("\n");

	printf("\n>> Insercao no meio <<\n");
	printf("\nValor %d inserido no meio? %s", 25, inserir_meio(&lista, 25) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");

	printf("\n>> Remocao no meio <<\n");
	printf("\nElemento no meio removido? %s", remover_meio(&lista) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");

	printf("\n>> Buscar elemento <<\n");
	printf("\nValor %d existe? %s", 25, buscar_elemento(lista, 25) ? "Sim" : "Nao");
	printf("\nValor %d existe? %s", 3, buscar_elemento(lista, 3) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");

	printf("\n>> Informacoes <<\n");
	printf("\nTamanho da lista: %d\n", tamanho(lista));
	printf("Esta cheia:? %s\n", esta_cheia(lista) ? "Sim" : "Nao");
	printf("Esta vazia? %s\n", esta_vazia(lista) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");

	printf("\n>> Remocao <<");
	printf("\nElemento removido? %s", remover_fim(&lista) ? "Sim" : "Nao");

	printf("\n");
	printf("\n>> Informacoes <<\n");
	printf("\nTamanho da lista: %d\n", tamanho(lista));
	printf("Esta cheia? %s\n", esta_cheia(lista) ? "Sim" : "Nao");
	printf("Esta vazia? %s\n", esta_vazia(lista) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");

	printf("\n>> Remocao <<");
	printf("\nElemento removido? %s", remover_fim(&lista) ? "Sim" : "Nao");

	printf("\n>> Informacoes <<\n");
	printf("\nTamanho da lista: %d\n", tamanho(lista));
	printf("Esta cheia? %s\n", esta_cheia(lista) ? "Sim" : "Nao");
	printf("Esta vazia? %s\n", esta_vazia(lista) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");

	printf("\n>> Esvaziar Lista <<\n");
	esvaziar(&lista);
	
	printf("\n>> Informacoes <<\n");
	printf("\nTamanho de lista: %d\n", tamanho(lista));
	printf("Esta cheia? %s\n", esta_cheia(lista) ? "Sim" : "Nao");
	printf("Esta vazia? %s\n", esta_vazia(lista) ? "Sim" : "Nao");
	printf("\n>> Impressao <<\n");
	imprimir(lista);
	printf("\n");
	return 0;
}