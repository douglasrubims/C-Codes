#include <stdio.h>
#define TAM 5

float somarNotas(float notas[TAM]) {
	int i;
	float soma = 0;
	for(i = 0; i < TAM; i++) soma += notas[i];
	return soma;
}

void exibeMedia(float soma) {
	printf("Media das notas: %.2f\n", soma / TAM);
}

int main() {
	int i;
	float notas[TAM], somaDasNotas;
	printf("Digite %d notas:\n", TAM);
	for(i = 0; i < TAM; i++) scanf("%f", &notas[i]);
	somaDasNotas = somarNotas(notas);
	exibeMedia(somaDasNotas);
	return 0;
}