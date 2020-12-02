#include <stdio.h >
#include <string.h >
#define TAM 100
#define MAX 2

typedef struct {
	int numeroConta[TAM], numeroContaTamanho;
	char nomeCompleto[TAM];
	float valores[1][2];
} ClientePremium;

int main() {
	int i, j, posicao;
	float maiorSaldo = -1;
	char nomeMaiorSaldo[TAM];
	ClientePremium clientes[MAX];
	for (i = 0; i < MAX; i++) {
		printf("Digite os dados da pessoa %d:\nNumero da conta: (Digite um numero negativo para finalizar)\n", i + 1);
		fflush(stdin);
		for (j = 0; j < TAM; j++) {
			scanf("%d", &clientes[i].numeroConta[j]);
			if (clientes[i].numeroConta[j] < 0) break;
		}
		clientes[i].numeroContaTamanho = j;
		printf("Nome completo: ");
		fflush(stdin);
		gets(clientes[i].nomeCompleto);
		printf("Saldo: R$");
		fflush(stdin);
		scanf("%f", &clientes[i].valores[0][0]);
		printf("Limite: R$");
		fflush(stdin);
		scanf("%f", &clientes[i].valores[0][1]);
		if (maiorSaldo < clientes[i].valores[0][0]) {
			maiorSaldo = clientes[i].valores[0][0];
			strcpy(nomeMaiorSaldo, clientes[i].nomeCompleto);
		}
	}
	printf("\nCliente com maior saldo: %s\n\nDados dos clientes com saldo menor que R$10.000,00:\n\n", nomeMaiorSaldo);
	for (i = 0; i < MAX; i++) {
		if (clientes[i].valores[0][0] < 10000) {
			printf("Numero da conta: ");
			for (j = 0; j < clientes[i].numeroContaTamanho; j++) printf("%d", clientes[i].numeroConta[j]);
			printf("\nNome completo: %s\nSaldo: R$%.2f\nLimite: R$%.2f\n\n", clientes[i].nomeCompleto, clientes[i].valores[0][0], clientes[i].valores[0][1]);
		}
	}
	return 0;
}