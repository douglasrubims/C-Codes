// Nome: Douglas Rubim Sabino
#ifndef LISTA_INTEIROS_H    // INCLUDE GUARD
#define LISTA_INTEIROS_H

#define VERDADEIRO 1
#define FALSO 0

typedef struct posicao {
	int linha, coluna;
} posicao;

typedef struct lst lista;

lista* criar_lst(int n);
int dequeue_lst(lista* l, posicao *p);
int esta_cheia_lst(lista* l);
int esta_vazia_lst(lista* l);
int esvaziar_lst(lista* l);
void exibir_lst(lista* l);
posicao front_lst(lista* l);
void liberar_lst(lista** l);
int push_lst(lista* l, posicao p);
int pop_lst(lista* l, posicao *p);
int tamanho_lst(lista* l);
posicao top_lst(lista* l);

#endif // LISTA_INTEIROS_H