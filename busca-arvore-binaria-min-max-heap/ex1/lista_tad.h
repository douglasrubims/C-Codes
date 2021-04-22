#include "arvore_enc.h"

#ifndef LISTA_TAD_H

typedef struct lista Lista;

Lista* criar_lista();
int esta_cheia(Lista* l);
int esta_vazia(Lista* l);
int esvaziar(Lista* l);
void exibir(Lista* l);
int inserir_inicio(Lista* l, Tad* v);
void liberar(Lista** l);
int remover_fim(Lista* l);
int tamanho(Lista* l);
Tad* get_primeiro(Lista* l);
int get_qtde();

#endif // LISTA_TAD_H