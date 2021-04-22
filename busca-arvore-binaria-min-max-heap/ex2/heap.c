#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define N 100
#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct heap {
	unsigned int qtde;
	unsigned int dados[N];
};

Heap *criar_heap() {
	Heap* h = (Heap*) malloc(sizeof(Heap));
	if (h == NULL) return NULL;
	h->qtde=0;
	return h;
}

int esvaziar(Heap* h) {
	if(h == NULL) return FALSO;
	h->qtde = 0;
	return VERDADEIRO;
}

void liberar(Heap** h) {
	free(*h);
	*h = NULL;
}

int tamanho(Heap* h) {
	if(h == NULL) return FLAG_ERRO;
	return h->qtde;
}

int esta_cheia(Heap* h) {
	if(h == NULL) return FALSO;
	return h->qtde == N;
}

int esta_vazia(Heap* h) {
	if(h == NULL) return FALSO;
	return h->qtde == 0;
}

int inserir_fim(Heap* h, unsigned int v) {
	if (h == NULL || esta_cheia(h)) return FALSO;
	h->dados[h->qtde] = v;
	h->qtde++;
	return VERDADEIRO;
}

int remover_fim(Heap* h) {
	if(h == NULL || esta_vazia(h)) return FALSO;
	h->qtde--;
	return VERDADEIRO;
}

int pai(Heap *h, int f) {
	if (f <= 0) return -1;
	return (f-1)/2;
}

int filho1 (Heap *h, int p) {
	int f1 = 2*p+1;
	if(f1 >= h->qtde) return -1;
	return f1;
}

int filho2 (Heap *h, int p) {
	int f2 = 2*p+2;
	if(f2 >= h->qtde) return -1;
	return f2;
}

int inserir_heap(Heap *h, int v) {
	if(!inserir_fim(h, v)) return FALSO;
	int p_v = h->qtde-1;
	while(h->dados[p_v] > h->dados[pai(h, p_v)] && pai(h, p_v) >= 0) {
		troca(h, p_v, pai(h, p_v));
		p_v = pai(h, p_v);
	}
	return VERDADEIRO;
}

int remover_max(Heap *h) {
	if(h == NULL) return FALSO;
	troca(h, 0, h->qtde-1);
	remover_fim(h);
	int p_v = h->qtde-1;
	while(pai(h, p_v) >= 0) {
		if(h->dados[p_v] > h->dados[pai(h, p_v)]) troca(h, p_v, pai(h, p_v));
		p_v = pai(h, p_v);
	}
	return VERDADEIRO;
}

void troca(Heap *h, int p1, int p2) {
	int aux = h->dados[p1];
	h->dados[p1] = h->dados[p2];
	h->dados[p2] = aux;
}

void exibir_heap(Heap *h) {
	int i;
	int nvl = 1;
	for(i = 1; i <= h->qtde; i ++) {
		if(i == nvl) {
			printf("\n");
			nvl = 2*(i);
		}
		printf("%d ", h->dados[i-1]);
	}
}

void controi_heap_de_vetor(Heap *h, int* vetor, int n) {
	int i;
	for(i = 0; i < n; i++) inserir_heap(h,vetor[i]);
}