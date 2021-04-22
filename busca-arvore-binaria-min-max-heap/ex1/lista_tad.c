#include <stdio.h>
#include <stdlib.h>
#include "lista_tad.h"
#include "arvore_enc.h"

#define N 100
#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct lista {
	unsigned int qtde;
	Tad* dados[N];
};

Lista* criar_lista() {
	Lista* l = (Lista*) malloc(sizeof(Lista));
	if(l == NULL) return NULL;
	l->qtde = 0;
	return l;
}

Tad* get_primeiro(Lista* l) {
	return l->dados[l->qtde-1];
}

int get_qtde(Lista* l) {
	return l->qtde;
}

int esta_cheia(Lista* l) {
	if(l == NULL) return FALSO;
	return l->qtde == N;
}

int esta_vazia(Lista* l) {
	if(l == NULL) return FALSO;
	return l->qtde == 0;
}

int esvaziar(Lista* l) {
	if(l == NULL) return FALSO;
	l->qtde = 0;
	return VERDADEIRO;
}

int inserir_inicio(Lista* l, Tad* v) {
	if(l == NULL || esta_cheia(l)) return FALSO;
	int i;
	for(i = l->qtde; i > 0; i--) l->dados[i] = l->dados[i-1];
	l->dados[0] = v;
	l->qtde++;
	return VERDADEIRO;
}

void liberar(Lista** l) {
	free(*l);
	*l = NULL;
}

int remover_fim(Lista* l) {
	if(l == NULL) return FALSO;
	l->qtde--;
	return VERDADEIRO;
}

int tamanho(Lista* l) {
	if(l == NULL) return FLAG_ERRO;
	return l->qtde;
}