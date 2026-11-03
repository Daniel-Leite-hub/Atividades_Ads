/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 3
 * ============================================================================
 * 
 * ENUNCIADO:
 * Sobre o código abaixo, qual das opções representa corretamente a operação 
 * de inserção do valor inteiro 10 em uma pilha implementada com vetor em C?
 * 
 * ANÁLISE COMPARATIVA DAS ALTERNATIVAS:
 * 
 * a.( ) int push(int stack[], int *top, int value) { ... }
 *       main() { push(stack, top, 10); }
 *       -> INCORRETO: A função espera 'int *top' (um ponteiro para int), mas a 
 *          chamada em main passa 'top' por valor (um inteiro simples). Isso gera 
 *          erro ou incompatibilidade de tipos de ponteiro.
 * 
 * b.( x ) int push(int stack[], int *top, int value) {
 *             if (*top >= MAX - 1) return -1; // Verifica se a pilha está cheia
 *             stack[++(*top)] = value;        // Incrementa o topo e insere o valor
 *             return 0;
 *         }
 *         main() {
 *             push(stack, &top, 10);
 *         }
 *       -> CORRETO! Em C, para que uma função altere uma variável da função chamadora 
 *          (como o índice 'top'), devemos passar seu endereço de memória (&top). 
 *          A função recebe 'int *top', desreferencia com '*top' e atualiza a variável original.
 * 
 * c.( ) int push(int stack[], int top, int value) {
 *             if (top >= MAX - 1) return -1;
 *             stack[++(top)] = value;
 *             return 0;
 *         }
 *         main() {
 *             push(stack, top, 10);
 *         }
 *       -> INCORRETO: Como 'top' é passado por valor (cópia), o incremento '++(top)' 
 *          modifica apenas a cópia local dentro da função push. Na função main(), 
 *          a variável 'top' continuaria valendo -1 (nunca seria atualizada).
 * 
 * d.( ) NDA
 * 
 * ============================================================================
 * ALTERNATIVA CORRETA: B
 * ============================================================================
 */

#include <stdio.h>

#define MAX 100

/* Função correta conforme a Alternativa B */
int push(int stack[], int *top, int value) {
    if (*top >= MAX - 1) {
        return -1; // Pilha cheia
    }
    stack[++(*top)] = value; // Pré-incrementa a variável original apontada por top e armazena
    return 0;                // Sucesso
}

int main() {
    int stack[MAX]; // Vetor que representa a pilha
    int top = -1;   // Índice do topo da pilha, começa em -1 indicando pilha vazia

    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 3:\n");
    printf("GABARITO: ALTERNATIVA B\n");
    printf("============================================================\n\n");

    printf("Estado antes do push: top = %d\n", top);

    /* Chamada correta: passando o endereco de memoria '&top' */
    int status = push(stack, &top, 10);

    if (status == 0) {
        printf("Push realizado com sucesso!\n");
        printf("Estado apos o push: top = %d, stack[top] = %d\n", top, stack[top]);
    } else {
        printf("Falha no push: pilha cheia.\n");
    }

    /* Mais um teste para demonstrar que o ponteiro persiste as alteracoes */
    push(stack, &top, 25);
    printf("Apos segundo push:  top = %d, stack[top] = %d\n", top, stack[top]);

    return 0;
}
