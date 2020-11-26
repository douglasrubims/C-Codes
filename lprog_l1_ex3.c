#include <stdio.h>

int main() {
	float val1, val2, result;
	int error = 0;
	char carac;
	printf("Digite o primeiro número: ");
	scanf("%f", &val1);
	printf("Digite o segundo número: ");
	scanf("%f", &val2);
	printf("Digite o caractere correspondente à operação que deseja fazer (+ - * /): ");
	fflush(stdin);
	scanf("%c", &carac);
	if(carac == '+') result = val1 + val2;
	else if(carac == '-') result = val1 - val2;
	else if(carac == '*') result = val1 * val2;
	else if(carac == '/')
		if(val2 != 0) result = val1 / val2;
		else {
			error = 1;
			printf("Não existe divisão por zero.");
		}
	else {
		error = 1;
		printf("Caractere inválido.");
	}
	if(error == 0) printf("Resultado da operação %.2f %c %.2f = %.2f", val1, carac, val2, result);
}