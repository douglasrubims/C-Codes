// Nome: Douglas Rubim Sabino
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

#define FLAG_ERRO -1

struct lst {
	unsigned int qtde;
	unsigned int capacidade;
	posicao* dados;
};

lista* criar_lst(int n) {
	lista *l = (lista *) malloc(sizeof(lista));
	l->dados = (posicao*) malloc(n * sizeof(posicao));
	if(l == NULL || l->dados == NULL)
		return NULL;
	l->capacidade = n;
	l->qtde = 0;
	return l;
}

int dequeue_lst(lista* l, posicao *p) {
	if(l == NULL || esta_vazia_lst(l))
		return FALSO;
	int i;
	*p = l->dados[0];
	for(i = 1; i < l->qtde; i++)
		l->dados[i-1] = l->dados[i];
	l->qtde--;
	return VERDADEIRO;
}

int esta_cheia_lst(lista* l) {
	if(l == NULL)
		return FLAG_ERRO;
	return l->qtde == l->capacidade;
}

int esta_vazia_lst(lista* l) {
	if(l == NULL)
		return FLAG_ERRO;
	return l->qtde == 0;
}

int esvaziar_lst(lista* l) {
	if(l == NULL)
		return FALSO;
	l->qtde = 0;
	return VERDADEIRO;
}

void exibir_lst(lista* l) {
	if(l == NULL)
		return;
	int i;
	for(i = 0; i < l->qtde; i++)
		printf("(%d, %d) ", l->dados[i].linha, l->dados[i].coluna);
}

posicao front_lst(lista* l) {
	return l->dados[0];
}

void liberar_lst(lista** l) {
	free((*l)->dados);
	free(*l);
	*l = NULL;
}

int pop_lst(lista* l, posicao *p) {
	if(l == NULL || esta_vazia_lst(l))
		return FALSO;
	l->qtde--;
	*p = l->dados[l->qtde];
	return VERDADEIRO;
}

int push_lst(lista* l, posicao p) {
	if(l == NULL || esta_cheia_lst(l))
		return FALSO;
	l->dados[l->qtde] = p;
	l->qtde++;
	return VERDADEIRO;
}

int tamanho_lst(lista* l) {
	if(l == NULL)
		return 0;
	return l->qtde;
}

posicao top_lst(lista* l) {
	return l->dados[l->qtde-1];
}