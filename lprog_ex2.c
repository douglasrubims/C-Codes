#include <stdio.h>

int main() {
	float kw;
	printf("Digite o número de kW consumido para calcular o valor a ser pago de energia elétrica: ");
	scanf("%f", &kw);
	printf("Valor a ser pago: R$%.2f", kw*0.1416);
	return 0;
}