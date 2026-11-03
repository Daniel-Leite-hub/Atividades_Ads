/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 6 (LIVRO PÁG 32, QUESTÃO 2.3)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 2.3 Usando pilha, crie a função inverte(s), que inverte a ordem dos caracteres 
 *     na cadeia s dada como entrada.
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - A Pilha é uma estrutura LIFO (Last-In, First-Out).
 * - Quando empilhamos caracteres de uma string da esquerda para a direita e, em seguida, 
 *   os desempilhamos escrevendo de volta na string, o último caractere empilhado 
 *   é o primeiro a ser retirado.
 * - Isso inverte a string de forma simples, elegante e eficiente.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Definição de Pilha de caracteres */
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return (p->topo == -1);
}

void empilha(char c, Pilha *p) {
    if (p->topo < MAX - 1) {
        p->itens[++p->topo] = c;
    }
}

char desempilha(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0';
}

/**
 * Função solicitada pelo Exercício 2.3:
 * Inverte a cadeia de caracteres 's' utilizando uma pilha auxiliar.
 */
void inverte(char *s) {
    Pilha p;
    inicializa(&p);

    int tam = strlen(s);

    // Passo 1: Empilha todos os caracteres de s
    for (int i = 0; i < tam; i++) {
        empilha(s[i], &p);
    }

    // Passo 2: Desempilha escrevendo de volta em s
    for (int i = 0; i < tam; i++) {
        s[i] = desempilha(&p);
    }
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 6 - LIVRO PAG. 32, EXERCICIO 2.3\n");
    printf("INVERSAO DE CADEIA DE CARACTERES COM PILHA\n");
    printf("============================================================\n\n");

    char texto1[] = "ESTRUTURA DE DADOS";
    char texto2[] = "IFPI 2026";
    char texto3[] = "ROMA ME TEM AMOR";

    printf("Texto 1 original : \"%s\"\n", texto1);
    inverte(texto1);
    printf("Texto 1 invertido: \"%s\"\n\n", texto1);

    printf("Texto 2 original : \"%s\"\n", texto2);
    inverte(texto2);
    printf("Texto 2 invertido: \"%s\"\n\n", texto2);

    printf("Texto 3 original : \"%s\"\n", texto3);
    inverte(texto3);
    printf("Texto 3 invertido: \"%s\" (palindromo!)\n", texto3);

    return 0;
}
