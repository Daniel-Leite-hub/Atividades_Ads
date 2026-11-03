/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 7
 * ============================================================================
 * 
 * ENUNCIADO:
 * Sobre o código abaixo, marque o que será impresso ao final do programa.
 * 
 * ANÁLISE DA ESTRUTURA:
 * - A estrutura possui dois índices:
 *     f: índice da frente (front), inicializado em 0.
 *     t: índice da cauda/topo (tail), inicializado em -1.
 * - metodo1: Insere no final (enfileira / enqueue):
 *     p->itens[++p->t] = valor;
 * - metodo2: Remove do início (desenfileira / dequeue):
 *     return p->itens[p->f++];
 * - Trata-se de uma FILA linear (FIFO - First In, First Out).
 * 
 * RASTREAMENTO PASSO A PASSO DA FUNÇÃO MAIN():
 * 1. inicializar(&x)  => f = 0, t = -1
 * 2. metodo1(&x, 10)  => t incrementado para 0, itens[0] = 10
 * 3. metodo1(&x, 20)  => t incrementado para 1, itens[1] = 20
 * 4. metodo1(&x, 30)  => t incrementado para 2, itens[2] = 30
 * 5. metodo1(&x, 40)  => t incrementado para 3, itens[3] = 40
 * 
 * 6. Primeira chamada de metodo2(&x):
 *    - Retorna itens[f], ou seja, itens[0] = 10.
 *    - Pós-incrementa f de 0 para 1.
 *    - Imprime: "Elemento: 10"
 * 
 * 7. Segunda chamada de metodo2(&x):
 *    - Retorna itens[f], ou seja, itens[1] = 20.
 *    - Pós-incrementa f de 1 para 2.
 *    - Imprime: "Elemento: 20"
 * 
 * 8. Fim da execução (não há mais chamadas de impressão no código).
 * 
 * SAÍDA PRODUZIDA:
 * Elemento: 10
 * Elemento: 20
 * 
 * ============================================================================
 * ALTERNATIVA CORRETA: B
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int f, t;
} estrutura;

void inicializar(estrutura *p) {
    p->f = 0;
    p->t = -1;
}

int estaVazia(estrutura *p) {
    return p->f > p->t;
}

int estaCheia(estrutura *p) {
    return p->t == MAX - 1;
}

void metodo1(estrutura *p, int valor) {
    if (estaCheia(p)) {
        printf("cheio\n");
    } else {
        p->itens[++p->t] = valor;
    }
}

int metodo2(estrutura *p) {
    if (estaVazia(p)) {
        printf("vazia\n");
        return -1;
    } else {
        return p->itens[p->f++];
    }
}

int main() {
    estrutura x;
    inicializar(&x);

    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 7:\n");
    printf("GABARITO: ALTERNATIVA B\n");
    printf("============================================================\n\n");

    /* Insercoes (enfileiramentos) */
    metodo1(&x, 10);
    metodo1(&x, 20);
    metodo1(&x, 30);
    metodo1(&x, 40);

    printf("Saida oficial gerada pelo programa:\n");
    /* Duas remocoes e impressoes apenas */
    printf("Elemento: %d\n", metodo2(&x));
    printf("Elemento: %d\n", metodo2(&x));

    return 0;
}
