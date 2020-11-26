#include <stdio.h>
#define TAM 15

int main() {
	int i;
	float altura, maior, menor;
	for(i = 0; i < TAM; i++) {
		printf("Digite a altura da pessoa %d: ", i + 1);
		scanf("%f", &altura);
		if(i == 0) {
			maior = altura;
			menor = altura;
		} else {
			if(altura > maior) maior = altura;
			if(altura < menor) menor = altura;
		}
	}
	printf("A maior altura eh: %.2f\nA menor altura eh: %.2f", maior, menor);
	return 0;
}