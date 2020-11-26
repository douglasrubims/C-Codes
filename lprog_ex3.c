#include <stdio.h>

int main() {
	int turma = 0;
	float nota1 = 0.0, nota2 = 0.0, media = 0.0;
	printf("Digite o número da turma: ");
	scanf("%d", &turma);
	printf("Digite a nota do trabalho: ");
	scanf("%f", &nota1);
	printf("Digite a nota da prova: ");
	scanf("%f", &nota2);
	media = (nota1 + nota2) / 2;
	if(turma == 1) {
		if(media >= 8) printf("APROVADO");
		else if(media < 6) printf("REPROVADO");
		else printf("PROVA FINAL");
	} else if(turma == 2) {
		if(media >= 7) printf("APROVADO");
		else if(media < 5) printf("REPROVADO");
		else printf("PROVA FINAL");
	} else printf("TURMA INVÁLIDA");
	return 0;
}