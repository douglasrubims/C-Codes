#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "arvore_enc.h"
#include "lista_tad.h"

struct tad {
	int x;
	Tad *esq;
	Tad *dir;
};

Tad *criar_no(int x) {
	Tad *t =(Tad*) malloc(sizeof(Tad));
	if(t == NULL) return NULL;
	t->x = x;
	t->dir = NULL;
	t->esq = NULL;
	return t;
}

int adicionar_no(Tad* t, int x) {
	while(t != NULL) {
		if(x < t->x) {
			if(t->esq == NULL) {
				t->esq = criar_no(x);
				if(t->esq != NULL) return 1;
				else return 0;
			} else t = t->esq;
		} else {
			if(t->dir == NULL) {
				t->dir = criar_no(x);
				if(t->dir != NULL) return 1;
				else return 0;
			} else t = t->dir;
		}
	}
	return 0;
}

void busca_largura(Tad* t) {
	Lista* fila = criar_lista();
	inserir_inicio(fila, t);
	Tad* temp;
	while(!esta_vazia(fila)) {
		temp = get_primeiro(fila);
		remover_fim(fila);
		if(temp->esq != NULL) inserir_inicio(fila, temp->esq);
		if(temp->dir != NULL) inserir_inicio(fila, temp->dir);
		printf("no: %p, valor: %d\n", temp, temp->x);
	}
}

// n! = n * (n-1)!
// 0! = 1
int fatorial_no(int n) {
	if(n == 0) return 1;
	else return n * fatorial_no(n-1);
}

//  n  0 1 2 3 4 5 6  7  8  9
//f(n) 0 1 1 2 3 5 8 13 21 34
// n == 0 -> f(n) = 0
// n == 1 -> f(n) = 1
// caso contrario -> f(n) = f(n-1) + f(n-2)
int fibonacci_no(int n) {
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return fibonacci_no(n-1)+fibonacci_no(n-2);
}

//nó sae sad
//em ordem: sae nó sad
void pre_ordem(Tad *t) {
	if(t == NULL) return;
	else {
		printf("no %d\n", t->x);
		pre_ordem(t->esq);
		pre_ordem(t->dir);
	}
}

int busca_no(Tad* t, int x) {
	if(t == NULL) return 0;
	if(t->x == x) {
		printf("X -> %d\n", t->x);
		return 1;
	}
	if(t->x > x) return busca_no(t->esq, x);
	return busca_no(t->dir, x);
}