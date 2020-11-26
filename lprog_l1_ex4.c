#include <stdio.h>

int main() {
	float x, y, z;
	printf("Digite os comprimentos para verificar se forma um triângulo: ");
	scanf("%f %f %f", &x, &y, &z);
	if(x < y + z && y < x + z && z < x + y) printf("Forma um triângulo.");
	else printf("Não forma um triângulo.");
}