#ifndef ARVORE_ENC_H // include guard

typedef struct tad Tad;

Tad* criar_no(int x);
void liberar_tad(Tad** p);
int adicionar_no(Tad* t, int x);
void pre_ordem(Tad  *t);
void em_ordem(Tad  *t); //sae, visitar no, sad
void exibir_arvore(Tad* p);
void busca_largura(Tad* t);
int fatorial_no(int n);
int fibonacci_no (int n);
int busca_no(Tad* t, int x);
#endif // ARVORE_ENC_H