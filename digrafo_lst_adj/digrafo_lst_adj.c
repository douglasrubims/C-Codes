#include <stdio.h>
#include <stdlib.h>
#include "digrafo_lst_adj.h"

// Grafo direcionado (digrafo) representado por listas de adjacências

// Estrutura para armazenar as listas de adjacência do grafo
// Representação de um nó da lista de adjacência
struct no {
    int dest;           // vértice destino
    struct no* prox;
};

// Estrutura para armazenar o grafo
struct digrafo {
    // Array de ponteiros para "no" (listas de adjacências)
    no** vet;
};

// Função para criar e inicializar o digrafo
digrafo* criar_digrafo(int n) {
    // aloca memoria para o grafo
    digrafo* G = (digrafo*) calloc(1, sizeof(digrafo));
    G->vet = (no**) calloc(n, sizeof(no*));
    int i;
    for(i = 0; i < n; i++)
        G->vet[i] = NULL;

    return G;
}

void imprimir(digrafo* G, int n) {
    bool tem_aresta;
    vertice origem;

    // percorre as listas dos vértices 0 a n-1 (origem)
    for (origem = 0; origem < n; origem++) {
        tem_aresta = FALSO;
        no* temp = G->vet[origem];
        while (temp != NULL) {
            // imprime as arestas (origem, destino) :: destino => temp->dest
            printf("[%d -> %2d]  ", origem, temp->dest);
            temp = temp->prox;
            tem_aresta = VERDADEIRO;
        }
        if(tem_aresta)
            printf("\n");
    }
}

bool inserir_aresta(digrafo *G, vertice v, vertice w) {
    // aloca novo nó da lista de adjacência (de orig para dest)
    no* novo1 = (no*) malloc(sizeof(no));
    novo1->dest = w;
    no* novo2 = (no*) malloc(sizeof(no));
    novo2->dest = v;

    // insere o novo nó no início da lista
    novo1->prox = G->vet[v];
    G->vet[v] = novo1;
    novo2->prox = G->vet[w];
    G->vet[w] = novo2;
}

void liberar(digrafo** G, int n) {
    if(*G == NULL)
        return;

    vertice origem;
    for(origem = 0; origem < n; origem++) {
        no *temp = (*G)->vet[origem], *temp_p;
        while (temp != NULL) {
            // desaloca memória dos nós
            printf("[%d -> %d] ", origem, temp->dest);
            temp_p = temp;
            temp = temp->prox;
            free(temp_p);   
        }
    }
    free((*G)->vet);
    *G = NULL;
}

bool remover_aresta(digrafo *G, vertice v, vertice w) {
    no* temp1 = G->vet[v];
    no* temp2 = G->vet[w];
    if(temp1->dest == w) {
        G->vet[v] = temp1->prox;
        temp1->prox = NULL;
        free(temp1);
    }
    if(temp2->dest == v) {
        G->vet[w] = temp2->prox;
        temp2->prox = NULL;
        free(temp2);
    }

    no* anterior1 = temp1;
    no* anterior2 = temp2;
    temp1 = temp1->prox;
    temp2 = temp2->prox;
    while(temp1 != NULL) {
        if(temp1->dest == w) {
            anterior1->prox = temp1->prox;
            temp1->prox = NULL;
            free(temp1);
        }
        anterior1 = temp1;
        temp1 = temp1->prox;
    }
    while(temp2 != NULL) {
        if(temp2->dest == v) {
            anterior2->prox = temp2->prox;
            temp2->prox = NULL;
            free(temp2);
        }
        anterior2 = temp2;
        temp2 = temp2->prox;
    }
}