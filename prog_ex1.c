#include <stdio.h>
#define TAM 1
#define STRTAM 1000

typedef struct {
    char nome[STRTAM];
    float media;
    int idade;
} DadosAluno;

int main() {
    int i, mediaIdades = 0;
    float mediaNotas = 0;
    DadosAluno alunos[TAM];
    for(i = 0; i < TAM; i++) {
        printf("Aluno %d:\n\tNome: ", i + 1);
        fflush(stdin);
        scanf("%[^\n]s", alunos[i].nome);
        printf("\tMedia: ");
        fflush(stdin);
        scanf("%f", &alunos[i].media);
        printf("\tIdade: ");
        fflush(stdin);
        scanf("%d", &alunos[i].idade);
        mediaNotas += alunos[i].media;
        mediaIdades += alunos[i].idade;
    }
    mediaNotas /= TAM;
    mediaIdades /= TAM;
    printf("\nDados dos alunos:\n\n");
    for(i = 0; i < TAM; i++) printf("Aluno %d:\n\tNome: %s\n\tMedia: %.2f\n\tIdade: %d\n", i + 1, alunos[i].nome, alunos[i].media, alunos[i].idade);
    printf("\n\t--> Media geral de notas: %.2f\n\t--> Media geral de idades: %d", mediaNotas, mediaIdades);
    return 0;
}