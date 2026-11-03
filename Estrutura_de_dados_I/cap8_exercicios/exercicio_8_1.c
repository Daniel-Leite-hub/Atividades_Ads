/*
 * ==============================================================================
 * EXERCICIO 8.1
 * ==============================================================================
 * ENUNCIADO:
 * Altere bubble_sort(), para ordenar vetores de numeros reais.
 *
 * RESPOSTA E EXPLICACAO:
 * Na implementacao original para inteiros (Figura 8.7 do livro), o vetor recebia
 * o tipo 'int' e a macro 'troca' usava uma variavel auxiliar de tipo 'int':
 *     #define troca(a,b) { int x=a; a=b; b=x; }
 *     void bubble_sort(int v[], int n) { ... }
 *
 * Para ordenar numeros reais:
 * 1. Mudamos o tipo dos elementos do vetor 'v' para 'float' (ou 'double').
 * 2. Adaptamos a macro de troca para usar uma variavel auxiliar do tipo 'float'.
 * 3. O algoritmo mantem a logica de comparar elementos adjacentes (v[j] > v[j+1])
 *    e trocar suas posicoes ate que o maior elemento flutue para o final.
 * Complexidade de tempo: O(n^2) no pior caso.
 * ==============================================================================
 */

#include <stdio.h>

/* Macro de troca ajustada para tipo float (numeros reais) */
#define trocaf(a, b) { float x = a; a = b; b = x; }

/*
 * bubble_sort: ordena um vetor de numeros reais de tamanho n em ordem crescente.
 */
void bubble_sort(float v[], int n) {
    /* i representa a rodada (varredura). Sao necessarias n-1 varreduras */
    for (int i = 1; i <= n - 1; i++) {
        /* A cada varredura i, o limite superior diminui porque os maiores itens
           ja estao posicionados no final do vetor */
        for (int j = 0; j < n - i; j++) {
            if (v[j] > v[j + 1]) {
                trocaf(v[j], v[j + 1]);
            }
        }
    }
}

/* Funcao auxiliar para exibir o vetor de reais */
void imprime_vetor(float v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%.2f%s", v[i], (i < n - 1) ? ", " : "");
    }
    printf("}\n");
}

int main(void) {
    float numeros[] = {3.14f, -1.50f, 2.71f, 0.00f, -4.20f, 1.61f};
    int n = sizeof(numeros) / sizeof(numeros[0]);

    printf("--- Exercicio 8.1: Bubble Sort com Numeros Reais ---\n");
    printf("Vetor original: ");
    imprime_vetor(numeros, n);

    bubble_sort(numeros, n);

    printf("Vetor ordenado: ");
    imprime_vetor(numeros, n);

    return 0;
}
