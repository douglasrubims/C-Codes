#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

#define ARQUIVO "labirinto2.txt"    // troque o nome do arquivo para testar outros labirintos

typedef struct {
	int l, c;   // l: linha; c: coluna
} posicao;

// Funções implementadas
void mostrar_labirinto(int tam, int **lab);
void preencher_labirinto(string nome_arquivo, int **lab);
int verificar_tam(string nome_arquivo);
void anotar(int **lab);
void extrair(int **lab);
bool existe(stack<posicao> pilha, posicao x);

int main() {
	int N = verificar_tam(ARQUIVO);     // labirinto N x N

	// Criação do labirinto (matriz que representa o labirinto)
	int **lab = (int**) malloc(N * sizeof(int*));
	for(int linha = 0; linha < N; linha++)
		lab[linha] = (int *) malloc(N * sizeof(int));

	preencher_labirinto(ARQUIVO, lab);
	mostrar_labirinto(N, lab);
	cout << endl;
	anotar(lab);
	mostrar_labirinto(N, lab);
	cout << endl;
	extrair(lab);

	// continua...

	return 0;
}

void mostrar_labirinto(int tam, int **lab) {
	int n = tam;
	for(int linha = 0; linha < n; linha++) {
		for(int coluna = 0; coluna < n; coluna++)
			if(lab[linha][coluna] == INT_MAX)
				printf("%3c", '#');
			else
				if(lab[linha][coluna] != 0)
					printf("%3d", lab[linha][coluna]);
				else
					printf("%3c", ' ');
		cout << endl;
	}
}

void preencher_labirinto(string nome_arquivo, int **lab) {
	FILE *f = fopen(nome_arquivo.c_str(), "r"); // abre o arquivo para leitura
	int n = verificar_tam(nome_arquivo);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			lab[i][j] = ((getc(f) == '#') ? INT_MAX : 0);
		getc(f);    // descarta o '\n' do final de cada linha
	}
	fclose(f);              // fecha o arquivo para liberar o recurso
}

int verificar_tam(string nome_arquivo) {
	FILE *f = fopen(nome_arquivo.c_str(), "r"); // abre o arquivo para leitura
	char c;
	int n = 0;
	do {
		c = getc(f);        // faz a leitura do caracter no arquivo apontado por pont_arq
		n++;                // incrementa uma unidade no número de caracteres lidos
	} while (c != '\n');
	fclose(f);              // fecha o arquivo para liberar o recurso
	return --n;             // decrementa uma unidade para ajustar o número
}

void anotar(int **lab) {
	int n = verificar_tam(ARQUIVO);
	lab[1][1] = 1;
	queue<posicao> fila;
	posicao x;
	x.l = 1;
	x.c = 1;
	fila.push(x);
	while(fila.size() != 0) {
		x = fila.front();
		fila.pop();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == x.l && j == x.c) {
					if(lab[i+1][j] == 0) {
						lab[i+1][j] = lab[i][j]+1;
						x.l = i+1;
						x.c = j;
						fila.push(x);
					}
					if(lab[i][j+1] == 0) {
						lab[i][j+1] = lab[i][j]+1;
						x.l = i;
						x.c = j+1;
						fila.push(x);
					}
					if(lab[i-1][j] == 0) {
						lab[i-1][j] = lab[i][j]+1;
						x.l = i-1;
						x.c = j;
						fila.push(x);
					}
					if(lab[i][j-1] == 0) {
						lab[i][j-1] = lab[i][j]+1;
						x.l = i;
						x.c = j-1;
						fila.push(x);
					}
				}
			}
		}
	}
}

void extrair(int **lab) {
	int n = verificar_tam(ARQUIVO);
	if(lab[n-2][n-2] == 0) return;
	stack<posicao> pilha;
	posicao x;
	x.l = n-2;
	x.c = n-2;
	pilha.push(x);
	while(!(x.l == 1 && x.c == 1)) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(lab[i][j] == lab[x.l][x.c]-1 &&
				((i+1 == x.l && j == x.c) ||
				(i == x.l && j+1 == x.c) ||
				(i-1 == x.l && j == x.c) ||
				(i == x.l && j-1 == x.c))) {
					x.l = i;
					x.c = j;
					pilha.push(x);
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			x.l = i;
			x.c = j;
			if(lab[i][j] == INT_MAX) printf("%3c", '#');
			else if(existe(pilha, x)) printf("%3c", 'X');
			else printf("%3c", ' ');
		}
		printf("\n");
	}
}

bool existe(stack<posicao> pilha, posicao x) {
	stack<posicao> pilha_aux;
	bool existe = false;
	while(pilha.size() != 0) {
		posicao p = pilha.top();
		pilha.pop();
		pilha_aux.push(p);
		if(x.l == p.l && x.c == p.c) existe = true;
	}
	return existe;
}