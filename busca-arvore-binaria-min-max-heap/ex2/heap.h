#ifndef HEAP_H
#define HEAP_H

typedef struct heap Heap;

Heap* criar_heap();
int esta_cheia(Heap* h);
int esta_vazia(Heap* h);
int esvaziar(Heap* l);
int inserir_fim(Heap* h, unsigned int v);
void liberar(Heap** l);
int remover_meio(Heap* l, unsigned int k);
int remover_fim(Heap* h);
int tamanho(Heap* l);
int inserir_heap(Heap *h, int v);
void max_heapify(Heap *h, int p);
int remover_max(Heap *h);
int pai(Heap *h, int f);
int filho1(Heap *h, int p);
int filho2(Heap *h, int p);
int inserir(Heap *h, int v);
void exibir_heap(Heap *h);
void troca(Heap *h, int p1, int p2);
void controi_heap_de_vetor(Heap *h, int* vetor, int n);

#endif //HEAP_H