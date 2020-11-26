#include <stdio.h>

int main() {
	float produto;
	printf("Digite o valor do produto: ");
	scanf("%f", &produto);
	if(produto > 0) {
		if(produto <= 2) produto += 0.15;
		else if(produto > 2 && produto <= 5) produto += produto * 0.02;
		else if(produto > 5 && produto <= 20) produto += produto * 0.1;
		else produto += produto * 0.08;
		printf("Novo valor do produto: R$%.2f", produto);
	} else printf("O produto não pode ter preço negativo.");
	return 0;
}