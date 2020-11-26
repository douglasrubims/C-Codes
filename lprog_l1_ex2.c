#include <stdio.h>

int main() {
	float atual, porc, aumento;
	printf("Digite o salário atual: ");
	scanf("%f", &atual);
	printf("Digite a porcentagem de aumento: ");
	scanf("%f", &porc);
	aumento = atual * porc / 100;
	printf("Valor do aumento: R$%.2f\nNovo salário: R$%.2f", aumento, atual + aumento);
}