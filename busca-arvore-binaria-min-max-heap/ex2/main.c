#include <stdio.h>
#include <locale.h>
#include "heap.h"

int main() {
	printf("------ TESTE BASICO ------\n");
	int i;
	int vetor[] = {50, 29, 33, 21, 11, 78, 66, 99};
	Heap* h = criar_heap();
	if(h == NULL) return 0;

	printf("> Inicio\n");
	for(i = 1; i <= 15; i++) inserir_heap(h, i);
	exibir_heap(h);
	printf("\n\n> REMOVE 15 (MAX)\n");
	remover_max(h);
	exibir_heap(h);

	printf("\n> Constroi de Vetor \n");
	Heap* h2 = criar_heap();
	controi_heap_de_vetor(h2, vetor, 8);
	exibir_heap(h2);

	return 0;
}