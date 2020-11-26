#include <stdio.h>

float media_aritmetica(float x1, float x2, float x3) {
	return (x1 + x2 + x3) / 3;
}

int main() {
	float x1, x2, x3;
	printf("Digite 3 valores para fazer a media aritmetica:\n");
	scanf("%f%f%f", &x1, &x2, &x3);
	printf("Media aritmetica de %.2f, %.2f e %.2f: %.2f\n", x1, x2, x3, media_aritmetica(x1, x2, x3));
	printf("Media aritmetica de 2.00, 6.00 e 7.00: %.2f\n", media_aritmetica(2, 6, 7));
	return 0;
}