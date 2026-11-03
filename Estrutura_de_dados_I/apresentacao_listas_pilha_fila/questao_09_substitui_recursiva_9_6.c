/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 9 (LIVRO PÁG 103, QUESTÃO 9.6)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 9.6 Crie a função recursiva substitui(x, y, L), que substitui toda ocorrência 
 *     do item x pelo item y na lista L. Por exemplo, se L aponta a lista [b, o, b, o], 
 *     após a chamada substitui('o', 'a', L), L deverá apontar a lista [b, a, b, a].
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - A definição recursiva de percurso em lista encadeada possui:
 *   * CASO BASE: Lista vazia (L == NULL). Nenhuma substituição a fazer, a função simplesmente retorna.
 *   * PASSO RECURSIVO: 
 *     1. Se o item do nó atual for igual a x (L->item == x), atualiza-o para y (L->item = y).
 *     2. Chama recursivamente a função para o restante da lista: substitui(x, y, L->prox).
 * - A modificação ocorre diretamente no campo 'item' do nó existente, preservando todos os 
 *   ponteiros 'prox' intactos.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct no {
    Item item;
    struct no *prox;
} No;

typedef No* Lista;

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
 * Função recursiva que substitui toda ocorrência de x por y na lista L.
 */
void substitui(Item x, Item y, Lista L) {
    if (L == NULL) return; // Caso base: lista vazia ou fim da lista

    if (L->item == x) {
        L->item = y; // Substituição no nó corrente
    }

    substitui(x, y, L->prox); // Chamada recursiva para a cauda da lista
}

void exibe(Lista L) {
    printf("[ ");
    for (Lista p = L; p != NULL; p = p->prox) {
        printf("%c ", p->item);
    }
    printf("]\n");
}

void libera(Lista *L) {
    while (*L != NULL) {
        Lista temp = *L;
        *L = temp->prox;
        free(temp);
    }
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 9 - LIVRO PAG. 103, EXERCICIO 9.6\n");
    printf("FUNCAO RECURSIVA SUBSTITUI(x, y, L)\n");
    printf("============================================================\n\n");

    /* Cria a lista do exemplo do livro: ['b', 'o', 'b', 'o'] */
    Lista L = no('b', no('o', no('b', no('o', NULL))));

    printf("Lista original L:\n");
    exibe(L);

    printf("\nChamando substitui('o', 'a', L)...\n");
    substitui('o', 'a', L);

    printf("Lista L apos a substituicao recursiva:\n");
    exibe(L);

    libera(&L);
    return 0;
}
