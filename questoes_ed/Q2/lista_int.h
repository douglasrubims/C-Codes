#define MAX_ITENS 100

typedef struct lista Lista;

Lista criar_lista();
int esta_cheia(Lista L);
int esta_vazia(Lista L);
int esvaziar(Lista *L);
int inserir_fim(Lista *L, int e);
void imprimir(Lista L);
int remover_fim(Lista *L);
int tamanho(Lista L);
int inserir_meio(Lista *L, int e);
int remover_meio(Lista *L);
int buscar_elemento(Lista L, int e);