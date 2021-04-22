// Nome: Douglas Rubim Sabino
// Deixei alguns códigos comentados neste arquivo, pois após muitas tentativas,
// acredito que o problema no meu código seja a estrutura de dados disponibilizada.
// Se vc descomentar todas as linhas de código da função extrair, vc vai ver que o que
// o meu loop pega não é totalmente armazenado dentro da pilha, e, portanto, acredito
// que minha lógica esteja correta. Até tentei modificar algumas coisas na estrutura
// disponibilizada, mas não obtive sucesso.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

#define ARQUIVO "labirinto2.txt"

void mostrar_labirinto(int tam, int **lab);
void preencher_labirinto(char *nome_arquivo, int **lab);
int verificar_tam(char *nome_arquivo);
void anotar(int **lab);
void extrair(int **lab);
int existe(lista* l, posicao x);

int main() {
	int N = verificar_tam(ARQUIVO);
	int **lab = (int**) malloc(N * sizeof(int*));
	for(int linha = 0; linha < N; linha++) lab[linha] = (int *) malloc(N * sizeof(int));
	preencher_labirinto(ARQUIVO, lab);
	mostrar_labirinto(N, lab);
	printf("\n");
	anotar(lab);
	mostrar_labirinto(N, lab);
	printf("\n");
	extrair(lab);
	return 0;
}

void mostrar_labirinto(int tam, int **lab) {
	int n = tam;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(lab[i][j] == INT_MAX) printf("%3c", '#');
			else if(lab[i][j] != 0) printf("%3d", lab[i][j]);
			else printf("%3c", ' ');
		}
		printf("\n");
	}
}

void preencher_labirinto(char* nome_arquivo, int **lab) {
	FILE *f = fopen(nome_arquivo, "r");
	if(!f) {
		puts(strerror(errno));
		printf("Arquivo invalido\n");
		exit(EXIT_FAILURE);
	}
	int n = verificar_tam(nome_arquivo);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) lab[i][j] = ((fgetc(f) == '#') ? INT_MAX : 0);
		fgetc(f);
	}
	fclose(f);
}

int verificar_tam(char *nome_arquivo) {
	FILE *f = fopen(nome_arquivo, "r");
	if(!f) {
		puts(strerror(errno));
		printf("Arquivo invalido\n");
		exit(EXIT_FAILURE);
	}
	char c;
	int n = 0;
	do {
		c = fgetc(f);
		n++;
	} while (c != '\n');
	fclose(f);
	return --n;
}

void anotar(int **lab) {
	int n = verificar_tam(ARQUIVO);
	lab[1][1] = 1;
	lista *fila = criar_lst(n);
	posicao p;
	p.linha = 1;
	p.coluna = 1;
	push_lst(fila, p);
	while(tamanho_lst(fila) != 0) {
		posicao x = front_lst(fila);
		dequeue_lst(fila, &x);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == x.linha && j == x.coluna) {
					if(lab[i+1][j] == 0) {
						lab[i+1][j] = lab[i][j]+1;
						p.linha = i+1;
						p.coluna = j;
						push_lst(fila, p);
					}
					if(lab[i][j+1] == 0) {
						lab[i][j+1] = lab[i][j]+1;
						p.linha = i;
						p.coluna = j+1;
						push_lst(fila, p);
					}
					if(lab[i-1][j] == 0) {
						lab[i-1][j] = lab[i][j]+1;
						p.linha = i-1;
						p.coluna = j;
						push_lst(fila, p);
					}
					if(lab[i][j-1] == 0) {
						lab[i][j-1] = lab[i][j]+1;
						p.linha = i;
						p.coluna = j-1;
						push_lst(fila, p);
					}
				}
			}
		}
	}
}

void extrair(int **lab) {
	int n = verificar_tam(ARQUIVO);
	if(lab[n-2][n-2] == 0) return;
	lista *pilha = criar_lst(n);
	posicao topo;
	topo.linha = n-2;
	topo.coluna = n-2;
	push_lst(pilha, topo);
	// printf("Procurando caminho e adicionando na pilha:\n(%d, %d)\n", topo.linha, topo.coluna);
	while(!(topo.linha == 1 && topo.coluna == 1)) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(lab[i][j] == lab[topo.linha][topo.coluna]-1 &&
				((i+1 == topo.linha && j == topo.coluna) ||
				(i == topo.linha && j+1 == topo.coluna) ||
				(i-1 == topo.linha && j == topo.coluna) ||
				(i == topo.linha && j-1 == topo.coluna))) {
					topo.linha = i;
					topo.coluna = j;
					push_lst(pilha, topo);
					// printf("(%d, %d)\n", topo.linha, topo.coluna);
				}
			}
		}
	}
	// printf("\nPosicoes armazenadas na pilha:\n");
	// while(!esta_vazia_lst(pilha)) {
	// 	printf("(%d, %d)\n", topo.linha, topo.coluna);
	// 	pop_lst(pilha, &topo);
	// 	topo = top_lst(pilha);
	// }
	// printf("\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			topo.linha = i;
			topo.coluna = j;
			if(lab[i][j] == INT_MAX) printf("%3c", '#');
			else if(existe(pilha, topo)) printf("%3c", 'X');
			else printf("%3c", ' ');
		}
		printf("\n");
	}
}

int existe(lista* l, posicao x) {
	int n = verificar_tam(ARQUIVO);
	lista *pilha_aux = criar_lst(n);
	int existe = 0;
	while(!esta_vazia_lst(l)) {
		posicao p = top_lst(l);
		pop_lst(l, &p);
		push_lst(pilha_aux, p);
		if(x.linha == p.linha && x.coluna == p.coluna) existe = 1;
	}
	while(!esta_vazia_lst(pilha_aux)) {
		posicao p = top_lst(pilha_aux);
		pop_lst(pilha_aux, &p);
		push_lst(l, p);
	}
	return existe;
}