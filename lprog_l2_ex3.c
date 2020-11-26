#include <stdio.h>

int main() {
	int N, i, primeiroM = 0, primeiroF = 0, qtdM = 0, qtdF = 0;
	char letra, sexo;
	float salario, maiorM = 0, maiorF = 0, mediaM = 0, mediaF = 0;
	printf("Digite a quantidade de funcionarios: ");
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		printf("\n\tDados do %d funcionario:\nPrimeira letra do nome: ", i + 1);
		fflush(stdin);
		scanf("%c", &letra);
		printf("Sexo (M ou F): ");
		fflush(stdin);
		scanf("%c", &sexo);
		printf("Salario: R$");
		scanf("%f", &salario);
		if(sexo == 'M') {
			if(primeiroM == 0) {
				maiorM = salario;
				primeiroM = 1;
			} else if(salario > maiorM) maiorM = salario;
			mediaM += salario;
			qtdM++;
		} else if(sexo == 'F') {
			if(primeiroF == 0) {
				maiorF = salario;
				primeiroF = 1;
			} else if(salario > maiorF) maiorF = salario;
			mediaF += salario;
			qtdF++;
		}
	}
	if(qtdM != 0) mediaM /= qtdM;
	if(qtdF != 0) mediaF /= qtdF;
	printf("\nMaior salario masculino: R$%.2f\nMaior salario feminino: R$%.2f\nMedia salarial masculina: R$%.2f\nMedia salarial feminina: R$%.2f\n", maiorM, maiorF, mediaM, mediaF);
	return 0;
}