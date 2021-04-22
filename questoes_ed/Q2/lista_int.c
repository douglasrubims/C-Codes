#include <stdio.h>
#include "lista_int.h"

struct lista {
    int elementos[MAX_ITENS];
    int prox;
};

Lista criar_lista() {
	Lista L;
	L.prox = 0;
	return L;
}

int esta_cheia(Lista L) {
	if(L.prox == MAX_ITENS) return 1;
	return 0;
}

int esta_vazia(Lista L) {
	if(L.prox == 0) return 1;
	return 0;
}

int esvaziar(Lista *L) {
	L->prox = 0;
	return 1;
}

int inserir_fim(Lista *L, int e) {
	if(esta_cheia(*L)) return 0;
	L->elementos[L->prox] = e;
	L->prox = L->prox + 1;
	return 1;
}

void imprimir(Lista L) {
	int i;
	for(i = 0; i < L.prox; i++)
		printf("%d ", L.elementos[i]);
}

int remover_fim(Lista *L) {
	if(esta_vazia(*L)) return 0;
	L->prox = L->prox - 1;
	return 1;
}

int tamanho(Lista L) {
	return L.prox;
}

int inserir_meio(Lista *L, int e) {
	if(esta_cheia(*L)) return 0;
	int i, pos_meio = L->prox / 2, aux = L->elementos[pos_meio], aux2;
	L->elementos[pos_meio] = e;
	for(i = pos_meio + 1; i < L->prox + 1; i++) {
		aux2 = L->elementos[i];
		L->elementos[i] = aux;
		aux = aux2;
	}
	L->prox = L->prox + 1;
	return 1;
}

int remover_meio(Lista *L) {
	if(esta_vazia(*L)) return 0;
	int i, pos_meio = L->prox / 2;
	for(i = pos_meio; i < L->prox; i++) L->elementos[i] = L->elementos[i + 1];
	L->prox = L->prox - 1;
	return 1;
}

int buscar_elemento(Lista L, int e) {
	if(esta_vazia(L)) return 0;
	int i;
	for(i = 0; i < L.prox; i++) if(L.elementos[i] == e) return 1;
	return 0;
}