/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 3 (LIVRO PÁG 103, QUESTÃO 9.10)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 9.10 Na implementação dinâmica encadeada de fila, os itens são mantidos numa 
 *      lista circular (com um ponteiro F para o último nó inserido na lista, 
 *      que aponta o primeiro), as inserções são feitas no final na lista e 
 *      as remoções são feitas no início da lista. Crie as funções enfileira(x, &F) 
 *      e desenfileira(&F), para filas dinâmicas encadeadas, e faça um programa para testá-las.
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Em uma lista simplesmente encadeada comum, para manter operações O(1) de 
 *   inserção no fim e remoção no início, seriam necessários 2 ponteiros (inicio e fim).
 * - O uso engenhoso de uma LISTA CIRCULAR permite fazer tudo com APENAS 1 PONTEIRO (*F):
 *   * *F aponta para o ÚLTIMO nó inserido (o final da fila).
 *   * Como a lista é circular, (*F)->prox aponta diretamente para o PRIMEIRO nó da fila!
 * - enfileira(x, &F):
 *   * Se fila vazia (*F == NULL): cria nó apontando para si mesmo (novo->prox = novo; *F = novo).
 *   * Senão: o novo nó passa a apontar para o primeiro (novo->prox = (*F)->prox), o antigo
 *     último aponta para o novo ((*F)->prox = novo) e atualiza *F = novo.
 *   * Tempo constante O(1).
 * - desenfileira(&F):
 *   * O primeiro nó é (*F)->prox.
 *   * Se tinha apenas 1 elemento ((*F)->prox == *F), após a remoção *F = NULL.
 *   * Senão: pula o primeiro ((*F)->prox = primeiro->prox).
 *   * Libera o nó removido e retorna o item. Tempo constante O(1).
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

/* Função auxiliar para alocação do nó */
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
 * Enfileira 'x' no final da fila circular apontada por *F.
 * O novo nó se torna o novo *F, mantendo o anel circular fechado.
 */
void enfileira(Item x, Lista *F) {
    Lista novo = no(x, NULL);
    if (*F == NULL) {
        novo->prox = novo; // Único nó aponta para si mesmo em círculo
    } else {
        novo->prox = (*F)->prox; // O novo último aponta para o primeiro nó
        (*F)->prox = novo;       // O antigo último aponta para o novo último
    }
    *F = novo; // F passa a apontar para o novo último nó
    printf("[ENFILEIRA] Elemento '%c' inserido no final da fila.\n", x);
}

/**
 * Desenfileira o primeiro elemento da fila circular apontada por *F.
 * O primeiro elemento é sempre (*F)->prox.
 */
Item desenfileira(Lista *F) {
    if (*F == NULL) {
        fprintf(stderr, "[ERRO] Tentativa de desenfileirar de fila vazia!\n");
        exit(EXIT_FAILURE);
    }
    Lista primeiro = (*F)->prox; // Primeiro nó da fila
    Item valor = primeiro->item;

    if (primeiro == *F) {
        // A fila tinha apenas 1 único elemento
        *F = NULL;
    } else {
        // O último (*F) agora passa a apontar para o segundo nó da fila
        (*F)->prox = primeiro->prox;
    }

    free(primeiro); // Libera o nó removido
    return valor;
}

/**
 * Verifica se a fila circular está vazia.
 */
int vaziaf(Lista F) {
    return (F == NULL);
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 3 - LIVRO PAG. 103, EXERCICIO 9.10\n");
    printf("FILA DINAMICA ENCADEADA CIRCULAR (FIFO)\n");
    printf("============================================================\n\n");

    Lista F = NULL; // Fila inicialmente vazia

    printf("1. Enfileirando itens: 'a', 'b', 'c'\n");
    enfileira('a', &F);
    enfileira('b', &F);
    enfileira('c', &F);

    printf("\n2. Desenfileirando itens (devem sair na ordem de chegada: 'a', 'b', 'c'):\n");
    printf("Saida: ");
    while (!vaziaf(F)) {
        printf("%c ", desenfileira(&F));
    }
    printf("\n");

    printf("\n3. Verificando se a fila circular esta vazia: %s\n", vaziaf(F) ? "SIM (Vazia)" : "NAO");

    return 0;
}
