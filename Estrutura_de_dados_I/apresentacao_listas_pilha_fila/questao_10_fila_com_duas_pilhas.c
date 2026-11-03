/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 10
 * ============================================================================
 * 
 * ENUNCIADO:
 * 10. Desenvolva os procedimentos de entrar e sair de uma fila a partir dos 
 *     procedimentos empilhar, desempilhar de uma pilha. Utilize 2 (duas) pilhas.
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Uma fila segue a disciplina FIFO (primeiro a entrar, primeiro a sair).
 * - Uma pilha segue a disciplina LIFO (último a entrar, primeiro a sair).
 * - Ao empilhar elementos em uma pilha (P1) e depois transferi-los todos para outra 
 *   pilha (P2), a ordem dos elementos é invertida.
 * - Ao desempilhar de P2, obtemos exatamente a ordem original de chegada (FIFO)!
 * 
 * ESTRATÉGIA AMORTIZADA EFICIENTE:
 * - Usamos duas pilhas: 'p_entrada' e 'p_saida'.
 * - entrar(x): empilha diretamente em 'p_entrada' -> O(1).
 * - sair(): 
 *   * Se 'p_saida' não estiver vazia, apenas desempilha dela -> O(1).
 *   * Se 'p_saida' estiver vazia, transfere todos os elementos de 'p_entrada' 
 *     para 'p_saida' (invertendo a ordem) e então desempilha de 'p_saida'.
 *   * Complexidade amortizada de cada operação: O(1).
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

void empilhar(int x, Pilha *p) {
    if (p->topo < MAX - 1) {
        p->itens[++p->topo] = x;
    }
}

int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[p->topo--];
    }
    fprintf(stderr, "[ERRO] Pilha vazia!\n");
    exit(EXIT_FAILURE);
}

/* Estrutura da Fila baseada em duas pilhas */
typedef struct {
    Pilha p_entrada;
    Pilha p_saida;
} FilaDuasPilhas;

void inicializaFila(FilaDuasPilhas *f) {
    inicializaPilha(&f->p_entrada);
    inicializaPilha(&f->p_saida);
}

bool filaVazia(FilaDuasPilhas *f) {
    return (pilhaVazia(&f->p_entrada) && pilhaVazia(&f->p_saida));
}

/**
 * Procedimento de ENTRAR na fila (enqueue):
 * Sempre empilha na pilha de entrada.
 */
void entrar(int x, FilaDuasPilhas *f) {
    empilhar(x, &f->p_entrada);
    printf("[ENTRAR] Elemento %d enfileirado.\n", x);
}

/**
 * Procedimento de SAIR da fila (dequeue):
 * Desempilha da pilha de saida. Se ela estiver vazia, transfere tudo da entrada.
 */
int sair(FilaDuasPilhas *f) {
    if (filaVazia(f)) {
        fprintf(stderr, "[ERRO] Tentativa de desenfileirar de fila vazia!\n");
        exit(EXIT_FAILURE);
    }

    if (pilhaVazia(&f->p_saida)) {
        // Transfere todos os elementos de p_entrada para p_saida
        while (!pilhaVazia(&f->p_entrada)) {
            empilhar(desempilhar(&f->p_entrada), &f->p_saida);
        }
    }

    return desempilhar(&f->p_saida);
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 10 - FILA IMPLEMENTADA A PARTIR DE DUAS PILHAS\n");
    printf("============================================================\n\n");

    FilaDuasPilhas fila;
    inicializaFila(&fila);

    printf("1. Inserindo elementos: 10, 20, 30, 40\n");
    entrar(10, &fila);
    entrar(20, &fila);
    entrar(30, &fila);
    entrar(40, &fila);

    printf("\n2. Removendo dois elementos (devem sair 10 e 20 na ordem FIFO):\n");
    printf("Saiu: %d\n", sair(&fila));
    printf("Saiu: %d\n", sair(&fila));

    printf("\n3. Inserindo mais um elemento: 50\n");
    entrar(50, &fila);

    printf("\n4. Esvaziando a fila restante (devem sair 30, 40 e 50):\n");
    while (!filaVazia(&fila)) {
        printf("Saiu: %d\n", sair(&fila));
    }

    return 0;
}
