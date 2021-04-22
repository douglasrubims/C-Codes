#ifndef HEAP_H
#define HEAP_H

typedef struct heap Heap;

Heap* criar_heap();
int esta_cheia(Heap* h);
int esta_vazia(Heap* h);
int inserir_fim(Heap* h, unsigned int v);
int remover_fim(Heap* h);
int inserir_heap(Heap *h, int v);
int remover_min(Heap *h);
int pai(Heap *h, int f);
void troca(Heap *h, int p1, int p2);
void exibir_heap(Heap *h);
int existe(Heap *h, int valor);

#endif //HEAP_H