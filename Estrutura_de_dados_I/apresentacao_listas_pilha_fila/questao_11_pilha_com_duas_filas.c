/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 11
 * ============================================================================
 * 
 * ENUNCIADO:
 * 11. Desenvolva os procedimentos de empilhar e desempilhar de uma pilha a 
 *     partir dos procedimentos add_fila, remove_fila, de uma fila. Utilize 2 (duas) filas.
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Em uma pilha, o último a entrar deve ser o primeiro a sair (LIFO).
 * - Em uma fila, o primeiro a entrar é o primeiro a sair (FIFO).
 * - Para que uma fila se comporte como uma pilha, o elemento mais recentemente 
 *   inserido deve ser mantido sempre na FRENTE da fila principal (f1).
 * 
 * ALGORITMO COM DUAS FILAS (f1 e f2):
 * - empilhar(x):
 *   1. Transfere todos os elementos de f1 para a fila auxiliar f2.
 *   2. Insere o novo elemento 'x' na fila f1 (ele fica sozinho na frente).
 *   3. Transfere todos os elementos de f2 de volta para f1 (enfileirando-os atrás de 'x').
 *   Dessa forma, o topo da pilha está sempre na frente de f1!
 * 
 * - desempilhar():
 *   * Simplesmente chama remove_fila(&f1) em tempo O(1).
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

/* Implementação de Fila Circular Sequencial */
typedef struct {
    int itens[MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

void inicializaFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

bool fila_vazia(Fila *f) {
    return (f->tamanho == 0);
}

void add_fila(int x, Fila *f) {
    if (f->tamanho < MAX) {
        f->tras = (f->tras + 1) % MAX;
        f->itens[f->tras] = x;
        f->tamanho++;
    }
}

int remove_fila(Fila *f) {
    if (!fila_vazia(f)) {
        int val = f->itens[f->frente];
        f->frente = (f->frente + 1) % MAX;
        f->tamanho--;
        return val;
    }
    fprintf(stderr, "[ERRO] Fila vazia!\n");
    exit(EXIT_FAILURE);
}

/* Estrutura de Pilha baseada em duas filas */
typedef struct {
    Fila f1;
    Fila f2;
} PilhaDuasFilas;

void inicializaPilha(PilhaDuasFilas *p) {
    inicializaFila(&p->f1);
    inicializaFila(&p->f2);
}

bool pilha_vazia(PilhaDuasFilas *p) {
    return fila_vazia(&p->f1);
}

/**
 * Operação empilhar:
 * Mantém o último elemento inserido sempre na frente de f1.
 */
void empilhar(int x, PilhaDuasFilas *p) {
    // 1. Move tudo de f1 para f2
    while (!fila_vazia(&p->f1)) {
        add_fila(remove_fila(&p->f1), &p->f2);
    }

    // 2. Insere x em f1
    add_fila(x, &p->f1);

    // 3. Devolve tudo de f2 para f1
    while (!fila_vazia(&p->f2)) {
        add_fila(remove_fila(&p->f2), &p->f1);
    }

    printf("[EMPILHAR] Elemento %d empilhado no topo.\n", x);
}

/**
 * Operação desempilhar:
 * Retira diretamente da frente de f1 em O(1).
 */
int desempilhar(PilhaDuasFilas *p) {
    if (pilha_vazia(p)) {
        fprintf(stderr, "[ERRO] Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return remove_fila(&p->f1);
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 11 - PILHA IMPLEMENTADA A PARTIR DE DUAS FILAS\n");
    printf("============================================================\n\n");

    PilhaDuasFilas pilha;
    inicializaPilha(&pilha);

    printf("1. Empilhando itens: 10, 20, 30, 40\n");
    empilhar(10, &pilha);
    empilhar(20, &pilha);
    empilhar(30, &pilha);
    empilhar(40, &pilha);

    printf("\n2. Desempilhando elementos (devem sair na ordem LIFO: 40, 30, 20, 10):\n");
    while (!pilha_vazia(&pilha)) {
        printf("Desempilhado: %d\n", desempilhar(&pilha));
    }

    return 0;
}
