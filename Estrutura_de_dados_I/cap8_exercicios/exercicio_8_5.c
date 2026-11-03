/*
 * ==============================================================================
 * EXERCICIO 8.5
 * ==============================================================================
 * ENUNCIADO:
 * Usando a funcao insere(), definida na Figura 8.11, crie a funcao recursiva
 * insertionSort(v, n), que ordena um vetor v com n numeros inteiros.
 *
 * RESPOSTA E EXPLICACAO:
 * 1. Funcionamento de insere(x, v, n) (Figura 8.11 do livro):
 *    A funcao assume que o prefixo v[0..n-1] esta ordenado. Ela desloca para a
 *    direita todos os elementos maiores que x e coloca x na posicao correta
 *    dentro de v[0..n]:
 *        void insere(int x, int v[], int n) {
 *            while( n>0 && x<v[n-1] ) {
 *                v[n] = v[n-1];
 *                n--;
 *            }
 *            v[n] = x;
 *        }
 *
 * 2. Estrutura recursiva de insertionSort(v, n):
 *    - Caso Base: se n <= 1, um vetor com 0 ou 1 elemento ja esta ordenado.
 *    - Passo Indutivo:
 *      1. Primeiro, ordenamos recursivamente os n - 1 primeiros elementos:
 *         insertionSort(v, n - 1);
 *      2. Agora que o subvetor v[0..n-2] esta ordenado, o n-esimo elemento (que
 *         esta em v[n-1]) precisa ser inserido na sua posicao correta dentro
 *         desse subvetor. Chamamos entao:
 *         insere(v[n - 1], v, n - 1);
 * ==============================================================================
 */

#include <stdio.h>

/*
 * insere: definida na Figura 8.11 do livro.
 * Insere o valor 'x' na posicao correta dentro de v[0..n], considerando que
 * v[0..n-1] ja se encontra ordenado.
 */
void insere(int x, int v[], int n) {
    while (n > 0 && x < v[n - 1]) {
        v[n] = v[n - 1];
        n--;
    }
    v[n] = x;
}

/*
 * insertionSort: versao recursiva do insertion sort.
 * Ordena recursivamente o prefixo de tamanho n - 1 e depois insere o elemento
 * v[n - 1] na posicao correta.
 */
void insertionSort(int v[], int n) {
    /* Caso base */
    if (n <= 1) return;

    /* Passo 1: ordena recursivamente os n - 1 primeiros elementos (indices 0..n-2) */
    insertionSort(v, n - 1);

    /* Passo 2: insere o n-esimo elemento (indice n-1) no prefixo ordenado */
    insere(v[n - 1], v, n - 1);
}

/* Funcao auxiliar para imprimir o vetor */
void imprime_vetor(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1) ? ", " : "");
    }
    printf("}\n");
}

int main(void) {
    int v[] = {51, 33, 72, 15, 69, 46, 28};
    int n = sizeof(v) / sizeof(v[0]);

    printf("--- Exercicio 8.5: Insertion Sort Recursivo ---\n");
    printf("Vetor original: ");
    imprime_vetor(v, n);

    insertionSort(v, n);

    printf("Vetor ordenado: ");
    imprime_vetor(v, n);

    return 0;
}
