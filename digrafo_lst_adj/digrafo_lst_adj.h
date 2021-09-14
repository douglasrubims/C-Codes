#ifndef DIGRAFO_LST_ADJ_H
#define DIGRAFO_LST_ADJ_H

// Grafo direcionado (digrafo) representado por listas de adjacências

// Representação de um tipo booleano
typedef enum {FALSO, VERDADEIRO} bool;

// Estrutura para armazenar as listas de adjacência do grafo
typedef struct no no;

// Representação de um vértice do grafo
typedef int vertice;

// Representação do grafo direcionado (ponteiro)
typedef struct digrafo digrafo;

/*
 * Função para criar e inicializar o digrafo
 *
 * Entrada: quantidade de vértices no grafo
 * Saída: ponteiro para o grafo criado
 */
digrafo* criar_digrafo(int n);

/*
 * Função para imprimir o grafo (representação por listas de adjacências)
 *
 * Entrada: grafo G a ser impresso; n - quantidade de vértices no grafo
 * Saída: Não tem
 */
void imprimir(digrafo* G, int n);

/*
 * Insere uma aresta (v, w) no grafo G.
 * Supõe-se que v e w são distintos, positivos e menores que G->v.
 *
 * Entrada: v - vértice origem; w - vértice destino
 * Saída: sucesso ou não na inserção
 */
bool inserir_aresta(digrafo *G, vertice v, vertice w);

/*
 * Função para liberar a memória alocada para o grafo
 *
 * Entrada: grafo G a ser liberado; n - quantidade de vértices no grafo
 * Saída: Não tem
 */
void liberar(digrafo** G, int n);

/*
 * Remove do grafo G a aresta (v, w).
 * Supõe-se que v e w são distintos, positivos e menores que o número do maior
 * vértice do grafo.
 * Se não existe a aresta (v, w), a função não faz nada.
 *
 * Entrada: grafo G a ser impresso; n - quantidade de vértices no grafo
 * Saída: sucesso ou não na remoção
 */
bool remover_aresta(digrafo *G, vertice v, vertice w);

#endif // DIGRAFO_LST_ADJ_H
