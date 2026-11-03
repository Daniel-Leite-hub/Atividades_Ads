/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 4 (LIVRO PÁG 102, QUESTÃO 9.4)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 9.4 Crie a função iterativa inversa(L), que devolve a lista inversa de L. 
 *     Por exemplo, para L apontando a lista [7, 9, 2], a função deve devolver [2, 9, 7].
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - A função iterativa percorre a lista original L da esquerda para a direita.
 * - Conforme cada item de L é visitado, ele é inserido na CABEÇA (início) da nova lista:
 *       resultado = no(p->item, resultado);
 * - Como a inserção na cabeça inverte naturalmente a ordem dos elementos, quando o 
 *   percurso termina, a nova lista gerada contém exatamente os itens em ordem reversa.
 * - A lista original L permanece intacta.
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
 * Função iterativa que gera e devolve uma nova lista com os itens invertidos.
 */
Lista inversa(Lista L) {
    Lista resultado = NULL;
    for (Lista p = L; p != NULL; p = p->prox) {
        resultado = no(p->item, resultado); // Insere sempre na frente
    }
    return resultado;
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
    printf("QUESTAO 4 - LIVRO PAG. 102, EXERCICIO 9.4\n");
    printf("FUNCAO ITERATIVA INVERSA(L)\n");
    printf("============================================================\n\n");

    /* Cria a lista de teste do livro: [7, 9, 2] */
    Lista L = no(7, no(9, no(2, NULL)));

    printf("Lista original L:\n");
    exibe(L);

    /* Chama a função inversa */
    Lista R = inversa(L);

    printf("\nLista inversa gerada R:\n");
    exibe(R);

    printf("\nComprovando que L original permanece inalterada:\n");
    exibe(L);

    /* Libera a memória alocada */
    libera(&L);
    libera(&R);

    return 0;
}
