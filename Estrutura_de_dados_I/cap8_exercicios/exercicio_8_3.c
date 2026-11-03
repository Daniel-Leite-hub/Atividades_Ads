/*
 * ==============================================================================
 * EXERCICIO 8.3
 * ==============================================================================
 * ENUNCIADO:
 * Usando a funcao empurra(), que move o item maximo de um vetor para sua ultima
 * posicao, crie a funcao recursiva bubbleSort(v, n), que ordena um vetor v com
 * n numeros inteiros.
 *
 * RESPOSTA E EXPLICACAO:
 * 1. Funcionamento de empurra(v, n):
 *    No codigo fornecido pelo enunciado:
 *        void empurra(int v[], int n) {
 *            for(int i = 0; i < n; i++)
 *                if(v[i] > v[i+1])
 *                    troca(v[i], v[i+1]);
 *        }
 *    O laco compara v[i] com v[i+1]. Quando passamos o argumento (n - 1), o indice
 *    'i' varia de 0 ate n - 2, acessando pares ate (v[n-2], v[n-1]). Dessa forma,
 *    o maior elemento entre v[0..n-1] e deslocado sucessivamente ("empurrado")
 *    para a posicao final v[n-1].
 *
 * 2. Estrutura recursiva de bubbleSort(v, n):
 *    - Caso Base: se n <= 1, o vetor contem 0 ou 1 elemento e ja esta ordenado.
 *    - Passo Indutivo:
 *      1. Executa empurra(v, n - 1), garantindo que o maior elemento fique em v[n-1].
 *      2. Faz a chamada recursiva bubbleSort(v, n - 1) para ordenar os n - 1
 *         primeiros elementos restantes (indices 0 ate n - 2).
 * ==============================================================================
 */

#include <stdio.h>

#define troca(a, b) { int x = a; a = b; b = x; }

/*
 * empurra: funcao fornecida no enunciado.
 * Desloca o maior elemento do intervalo ate a posicao limite indicada.
 */
void empurra(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] > v[i + 1]) {
            troca(v[i], v[i + 1]);
        }
    }
}

/*
 * bubbleSort: versao recursiva do algoritmo bubble sort.
 * Ordena os n primeiros elementos do vetor v.
 */
void bubbleSort(int v[], int n) {
    /* Caso base: vetores de tamanho 0 ou 1 ja estao ordenados */
    if (n <= 1) return;

    /* Passo 1: empurra o maior item entre v[0..n-1] para a posicao v[n-1] */
    empurra(v, n - 1);

    /* Passo 2: ordena recursivamente o restante do vetor (tamanho n - 1) */
    bubbleSort(v, n - 1);
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
    int v[] = {46, 28, 51, 33, 72, 15, 69};
    int n = sizeof(v) / sizeof(v[0]);

    printf("--- Exercicio 8.3: Bubble Sort Recursivo ---\n");
    printf("Vetor original: ");
    imprime_vetor(v, n);

    bubbleSort(v, n);

    printf("Vetor ordenado: ");
    imprime_vetor(v, n);

    return 0;
}
