/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 5
 * ============================================================================
 * 
 * ENUNCIADO:
 * 5. Inversão na própria lista (variação das questões, falamos sobre isso em sala de aula).
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Na Questão 4 (Exercício 9.4 do livro), a inversão gerava uma NOVA lista, alocando 
 *   novos nós na memória via malloc.
 * - Na INVERSÃO NA PRÓPRIA LISTA (in-place reversal), NÃO há nenhuma nova alocação de memória!
 *   Modificam-se diretamente os ponteiros 'prox' dos nós existentes, fazendo-os apontar 
 *   para o sentido contrário.
 * - Para realizar a inversão com segurança sem perder referências, usamos 3 ponteiros:
 *   1. anterior: aponta para o nó anterior (inicialmente NULL).
 *   2. atual: nó sendo processado no momento (inicialmente *L).
 *   3. proximo: armazena temporariamente atual->prox antes de redirecioná-lo.
 * 
 * Algoritmo:
 *   while (atual != NULL) {
 *       proximo = atual->prox;    // Salva o próximo
 *       atual->prox = anterior;   // Inverte a direção da flecha
 *       anterior = atual;         // Avança o anterior
 *       atual = proximo;          // Avança o atual
 *   }
 *   *L = anterior;                // A cabeça agora é o antigo último nó
 * 
 * Complexidade de Tempo: O(n)
 * Complexidade de Espaço: O(1) (sem memória extra)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

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
 * Inverte os ponteiros da própria lista in-place (sem alocação de novos nós).
 */
void inverte_na_propria_lista(Lista *L) {
    Lista anterior = NULL;
    Lista atual = *L;
    Lista proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;   // Guarda quem vinha depois
        atual->prox = anterior;  // Aponta o nó atual de volta para o anterior
        anterior = atual;        // O anterior avança para o atual
        atual = proximo;         // O atual avança para o próximo
    }

    *L = anterior; // A cabeça da lista passa a ser o antigo último nó
}

void exibe(Lista L) {
    printf("[ ");
    for (Lista p = L; p != NULL; p = p->prox) {
        printf("%d ", p->item);
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
    printf("QUESTAO 5 - INVERSAO NA PROPRIA LISTA (IN-PLACE REVERSAL)\n");
    printf("============================================================\n\n");

    /* Cria a lista: [10, 20, 30, 40, 50] */
    Lista L = no(10, no(20, no(30, no(40, no(50, NULL)))));

    printf("Lista original L:\n");
    exibe(L);

    printf("\nExecutando inversao in-place (reorientando os ponteiros prox):\n");
    inverte_na_propria_lista(&L);

    printf("Lista L apos a inversao na propria estrutura:\n");
    exibe(L);

    libera(&L);
    return 0;
}
