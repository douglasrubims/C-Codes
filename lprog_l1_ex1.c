#include <stdio.h>
#define PI 3.14159265358979323846

int main() {
	float r, h;
	printf("Digite o raio da base do cilindro: ");
	scanf("%f", &r);
	printf("Digite a altura do cilindro: ");
	scanf("%f", &h);
	printf("O volume da lata de óleo cilíndrica é: %.2f", PI * r * r * h);
	return 0;
}