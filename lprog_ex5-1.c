#include <stdio.h>
#define MAX 10

int main() {
	int i, cont_negativos = 0;
	float numeros[MAX], soma_positivos = 0;
	printf("Digite 10 numeros reais:\n");
	for(i = 0; i < MAX; i++) {
		scanf("%f", &numeros[i]);
		if(numeros[i] >= 0) soma_positivos += numeros[i];
		else cont_negativos++;
	}
	printf("Quantidade de numeros negativos: %d\nSoma dos numeros positivos: %.2f\n", cont_negativos, soma_positivos);
	return 0;
}