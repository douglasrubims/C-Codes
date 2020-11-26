#include <stdio.h>

int main() {
	int qtd_alunos, i;
	float nota, maior_nota, menor_nota, media_aritmetica = 0;
	printf("Digite a quantidade de alunos em sua sala: ");
	scanf("%d", &qtd_alunos);
	printf("\nDigite as notas do primeiro bimestre de cada um dos %d alunos em sua sala:\n", qtd_alunos);
	for(i = 0; i < qtd_alunos; i++) {
		printf("Nota do %d aluno: ", i + 1);
		scanf("%f", &nota);
		if(i == 0) {
			maior_nota = nota;
			menor_nota = nota;
		} else {
			if(nota > maior_nota) maior_nota = nota;
			if(nota < menor_nota) menor_nota = nota;
		}
		media_aritmetica += nota;
	}
	media_aritmetica /= qtd_alunos;
	printf("\n\tInformacoes sobre o primeiro bimestre da turma:\n-> Maior nota: %.2fpts\n-> Menor nota: %.2fpts\n-> Media aritmetica: %.2fpts\n", maior_nota, menor_nota, media_aritmetica);
	return 0;
}