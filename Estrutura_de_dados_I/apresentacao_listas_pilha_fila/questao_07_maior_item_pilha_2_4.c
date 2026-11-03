/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 7 (LIVRO PÁG 32, QUESTÃO 2.4)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 2.4 Crie a função maior(P), que recebe como entrada uma pilha P e devolve como 
 *     saída o maior item existente em P. Após a execução da função, a pilha P 
 *     deve estar da mesma forma que ela estava antes de a função ser executada. 
 *     Dica: use a macro max(), definida em minmax.h.
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Em uma pilha, só temos acesso ao elemento que está no topo.
 * - Para encontrar o maior elemento, precisamos desempilhar sucessivamente cada item de P, 
 *   atualizando o valor máximo encontrado e guardando os itens em uma pilha auxiliar (Paux).
 * - Após esvaziar P e encontrar o maior valor, transferimos todos os elementos de volta 
 *   de Paux para P.
 * - Duas operações consecutivas de transferência entre pilhas preservam a ordem original, 
 *   garantindo que P retorne exatamente ao seu estado inicial.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Macro max sugerida no livro */
#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return (p->topo == -1);
}

void empilha(int x, Pilha *p) {
    if (p->topo < MAX - 1) {
        p->itens[++p->topo] = x;
    }
}

int desempilha(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    fprintf(stderr, "[ERRO] Pilha vazia!\n");
    exit(EXIT_FAILURE);
}

/**
 * Função solicitada pelo Exercício 2.4:
 * Encontra e devolve o maior item de P, restaurando P ao seu estado original.
 */
int maior(Pilha *P) {
    if (vazia(P)) {
        fprintf(stderr, "[ERRO] Pilha vazia nao possui elemento maximo!\n");
        exit(EXIT_FAILURE);
    }

    Pilha Paux;
    inicializa(&Paux);

    // Inicializa o maior com o primeiro elemento retirado
    int primeiro = desempilha(P);
    int m = primeiro;
    empilha(primeiro, &Paux);

    // Desempilha o restante de P para Paux procurando o maior
    while (!vazia(P)) {
        int item = desempilha(P);
        m = max(m, item);
        empilha(item, &Paux);
    }

    // Restaura P desempilhando de Paux
    while (!vazia(&Paux)) {
        empilha(desempilha(&Paux), P);
    }

    return m;
}

void exibirPilha(Pilha *P) {
    printf("Topo -> ");
    for (int i = P->topo; i >= 0; i--) {
        printf("[%d] ", P->itens[i]);
    }
    printf("(Base)\n");
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 7 - LIVRO PAG. 32, EXERCICIO 2.4\n");
    printf("MAIOR ITEM DA PILHA COM PRESERVACAO DO ESTADO ORIGINAL\n");
    printf("============================================================\n\n");

    Pilha P;
    inicializa(&P);

    /* Inserindo valores diversos na pilha */
    empilha(15, &P);
    empilha(82, &P);
    empilha(43, &P);
    empilha(99, &P);
    empilha(27, &P);

    printf("Estado da pilha ANTES da funcao maior(P):\n");
    exibirPilha(&P);

    int max_valor = maior(&P);

    printf("\nResultado da funcao maior(&P): %d\n", max_valor);

    printf("\nEstado da pilha APOS a funcao maior(P) (totalmente preservada):\n");
    exibirPilha(&P);

    return 0;
}
