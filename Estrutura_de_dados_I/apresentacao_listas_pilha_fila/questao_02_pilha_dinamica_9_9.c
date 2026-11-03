/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 2 (LIVRO PÁG 103, QUESTÃO 9.9)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 9.9 Na implementação dinâmica encadeada de pilha, os itens são mantidos numa 
 *     lista (com um ponteiro P para seu início) e as inserções e remoções são 
 *     feitas no início dessa lista. Crie as funções empilha(x, &P) e 
 *     desempilha(&P), para pilhas dinâmicas encadeadas, e faça um programa para testá-las.
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Em uma pilha dinâmica encadeada, o topo da pilha corresponde exatamente à 
 *   cabeça da lista encadeada (*P).
 * - empilha(x, &P): Aloca um novo nó contendo 'x', faz novo->prox apontar para o antigo 
 *   topo (*P) e atualiza *P = novo. Executa em tempo constante O(1).
 * - desempilha(&P): Salva o item do topo (*P)->item, avança o ponteiro *P para (*P)->prox, 
 *   libera o nó desempilhado com free() e retorna o item. Executa em tempo constante O(1).
 * - Pilha vazia é representada por P == NULL.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef char Item; // Permite testar com caracteres ('a', 'b', 'c') ou inteiros

typedef struct no {
    Item item;
    struct no *prox;
} No;

typedef No* Lista;

/* Função auxiliar para criar nó */
Lista no(Item x, Lista p) {
    Lista novo = (Lista)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    novo->item = x;
    novo->prox = p;
    return novo;
}

/**
 * Insere um novo item no topo da pilha dinâmica (*P).
 * Equivale a inserir no início da lista encadeada.
 */
void empilha(Item x, Lista *P) {
    *P = no(x, *P);
    printf("[EMPILHA] Inserido '%c' no topo da pilha.\n", x);
}

/**
 * Remove e retorna o item que está no topo da pilha dinâmica (*P).
 * Equivale a remover do início da lista encadeada.
 */
Item desempilha(Lista *P) {
    if (*P == NULL) {
        fprintf(stderr, "[ERRO] Tentativa de desempilhar de uma pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    Lista topo_removido = *P;
    Item valor = topo_removido->item;
    *P = topo_removido->prox; // O próximo nó passa a ser o novo topo
    free(topo_removido);       // Libera a memória do nó desempilhado
    return valor;
}

/**
 * Verifica se a pilha está vazia.
 */
int vaziap(Lista P) {
    return (P == NULL);
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 2 - LIVRO PAG. 103, EXERCICIO 9.9\n");
    printf("PILHA DINAMICA ENCADEADA (LIFO)\n");
    printf("============================================================\n\n");

    Lista P = NULL; // Pilha inicialmente vazia

    printf("1. Empilhando itens: 'a', 'b', 'c'\n");
    empilha('a', &P);
    empilha('b', &P);
    empilha('c', &P);

    printf("\n2. Desempilhando itens (devem sair na ordem inversa: 'c', 'b', 'a'):\n");
    printf("Saida: ");
    while (!vaziap(P)) {
        printf("%c ", desempilha(&P));
    }
    printf("\n");

    printf("\n3. Verificando se a pilha esta vazia: %s\n", vaziap(P) ? "SIM (Vazia)" : "NAO");

    return 0;
}
