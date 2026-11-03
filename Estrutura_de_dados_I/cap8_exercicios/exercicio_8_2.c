/*
 * ==============================================================================
 * EXERCICIO 8.2
 * ==============================================================================
 * ENUNCIADO:
 * Altere insertion_sort(), para ordenar vetores de cadeias.
 * Dica: (a) use as funcoes strcmp() e strcpy(), declaradas em string.h, para
 * comparar e copiar cadeias e (b) copie v[i] para um vetor de caracteres aux
 * e chame insere(aux, v, i).
 *
 * RESPOSTA E EXPLICACAO:
 * 1. Em C, cadeias de caracteres sao vetores de 'char' terminados em '\0'.
 *    Um vetor de cadeias e modelado como uma matriz bidimensional 'char v[][TAM_MAX]'
 *    onde cada linha v[i] representa uma cadeia de caracteres.
 * 2. Operador de comparacao: em vez de 'x < v[n-1]', usamos 'strcmp(x, v[n-1]) < 0'.
 *    Se strcmp devolver valor negativo, a cadeia x precede lexicograficamente v[n-1].
 * 3. Operador de atribuicao: em vez de 'v[n] = v[n-1]', usamos 'strcpy(v[n], v[n-1])'.
 * 4. Na funcao principal de ordenacao, salvamos a string corrente em 'aux' usando
 *    'strcpy(aux, v[i])' antes de invocar 'insere(aux, v, i)'.
 * ==============================================================================
 */

#include <stdio.h>
#include <string.h>

#define TAM_MAX 100 /* Comprimento maximo de cada cadeia de caracteres */

/*
 * insere: insere a cadeia 'x' na posicao correta dentro do subvetor ordenado v[0..n-1],
 * deslocando as cadeias maiores para a direita.
 */
void insere(char x[], char v[][TAM_MAX], int n) {
    /* Enquanto houver itens a esquerda e 'x' for lexicograficamente menor que v[n-1] */
    while (n > 0 && strcmp(x, v[n - 1]) < 0) {
        strcpy(v[n], v[n - 1]); /* Desloca v[n-1] para v[n] */
        n--;
    }
    strcpy(v[n], x); /* Insere 'x' na posicao encontrada */
}

/*
 * insertion_sort: ordena n cadeias de caracteres em ordem alfabetica crescente.
 */
void insertion_sort(char v[][TAM_MAX], int n) {
    char aux[TAM_MAX];
    for (int i = 0; i < n; i++) {
        /* Copia v[i] para aux conforme a dica (b) */
        strcpy(aux, v[i]);
        /* Insere o item na porcao ja ordenada v[0..i-1] */
        insere(aux, v, i);
    }
}

/* Funcao auxiliar para exibir o vetor de cadeias */
void imprime_cadeias(char v[][TAM_MAX], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"%s", v[i], (i < n - 1) ? ", " : "");
    }
    printf("}\n");
}

int main(void) {
    char palavras[][TAM_MAX] = {
        "laranja", "banana", "abacaxi", "uva", "morango", "cereja"
    };
    int n = sizeof(palavras) / sizeof(palavras[0]);

    printf("--- Exercicio 8.2: Insertion Sort com Cadeias de Caracteres ---\n");
    printf("Vetor original:\n  ");
    imprime_cadeias(palavras, n);

    insertion_sort(palavras, n);

    printf("Vetor ordenado lexicograficamente:\n  ");
    imprime_cadeias(palavras, n);

    return 0;
}
