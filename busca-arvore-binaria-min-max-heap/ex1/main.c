#include <stdio.h>
#include "arvore_enc.h"

int main() {
	Tad* t = criar_no(7);
	// printf("Fatorial de: %d, valor: %d\n", 6, fibonacci_no(6));
	adicionar_no(t, 13);
	adicionar_no(t, 12);
	adicionar_no(t, 11);
	adicionar_no(t, 5);
	adicionar_no(t, 0);
	adicionar_no(t, 1);
	adicionar_no(t, 2);
	adicionar_no(t, 6);
	adicionar_no(t, 8);
	busca_largura(t);
	pre_ordem(t);
	printf("O no %d existe? %s\n", 1, busca_no(t, 1) ? "Sim" : "Nao");
	printf("O no %d existe? %s\n", 9, busca_no(t, 9) ? "Sim" : "Nao");
	return 0;
}