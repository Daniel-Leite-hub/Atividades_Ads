/*
 * ==============================================================================
 * EXERCICIO 8.4
 * ==============================================================================
 * ENUNCIADO:
 * Usando a funcao seleciona(), definida na Figura 8.9, crie a funcao recursiva
 * selectionSort(v, n), que ordena um vetor v com n numeros inteiros.
 *
 * RESPOSTA E EXPLICACAO:
 * 1. Funcionamento de seleciona(v, n) (Figura 8.9 do livro):
 *    A funcao percorre o vetor v[0..n-1] procurando o indice do maior elemento:
 *        int seleciona(int v[], int n) {
 *            int i = 0;
 *            for(int j=1; j<n; j++)
 *                if( v[i]<v[j] ) i = j;
 *            return i;
 *        }
 *
 * 2. Estrutura recursiva de selectionSort(v, n):
 *    - Caso Base: se n <= 1, o vetor ja esta ordenado (retorna sem acao).
 *    - Passo Indutivo:
 *      1. Encontra o indice do elemento maximo do intervalo v[0..n-1]:
 *         int i = seleciona(v, n);
 *      2. Troca o elemento maximo encontrado v[i] com o elemento da ultima posicao
 *         v[n-1]: troca(v[i], v[n-1]);
 *      3. Chama recursivamente selectionSort(v, n - 1) para ordenar os primeiros
 *         n - 1 elementos restantes.
 * ==============================================================================
 */

#include <stdio.h>

#define troca(a, b) { int x = a; a = b; b = x; }

/*
 * seleciona: definida na Figura 8.9 do livro.
 * Retorna o indice do maior elemento em v[0..n-1].
 */
int seleciona(int v[], int n) {
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (v[i] < v[j]) {
            i = j;
        }
    }
    return i;
}

/*
 * selectionSort: versao recursiva do algoritmo selection sort.
 * A cada chamada, coloca o maior elemento em sua posicao definitiva v[n-1]
 * e delega o restante a chamada recursiva.
 */
void selectionSort(int v[], int n) {
    /* Caso base */
    if (n <= 1) return;

    /* Encontra o indice do elemento maximo em v[0..n-1] */
    int i = seleciona(v, n);

    /* Troca o maximo com a ultima posicao disponivel v[n-1] */
    troca(v[i], v[n - 1]);

    /* Ordena recursivamente os n - 1 elementos anteriores */
    selectionSort(v, n - 1);
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
    int v[] = {72, 15, 69, 28, 51, 33, 46};
    int n = sizeof(v) / sizeof(v[0]);

    printf("--- Exercicio 8.4: Selection Sort Recursivo ---\n");
    printf("Vetor original: ");
    imprime_vetor(v, n);

    selectionSort(v, n);

    printf("Vetor ordenado: ");
    imprime_vetor(v, n);

    return 0;
}
