/*
 * ==============================================================================
 * EXERCICIO 8.6
 * ==============================================================================
 * ENUNCIADO:
 * Crie a funcao recursiva linearSearch(x, v, n), que faz uma busca linear para
 * verificar se o item x esta no vetor v, que contem n numeros inteiros.
 *
 * RESPOSTA E EXPLICACAO:
 * 1. A busca linear verifica se o elemento x ocorre em alguma posicao de v[0..n-1].
 *    A convencao adotada no livro (Figura 8.17) e retornar 1 se o item for
 *    encontrado e 0 caso contrario.
 *
 * 2. Estrutura recursiva:
 *    - Caso Base 1 (nao encontrado): se n <= 0, o vetor esta vazio, logo o
 *      elemento nao existe -> retorna 0.
 *    - Caso Base 2 (encontrado): se o ultimo elemento do subvetor for igual a x
 *      (v[n - 1] == x), encontramos o item -> retorna 1.
 *    - Passo Indutivo: se v[n - 1] != x, procuramos x recursivamente nos n - 1
 *      elementos anteriores: return linearSearch(x, v, n - 1).
 *
 * Complexidade de tempo:
 *   - Melhor caso: O(1) (quando o item esta na primeira posicao inspecionada).
 *   - Pior caso: O(n) (quando o item nao esta no vetor ou esta no primeiro indice).
 * ==============================================================================
 */

#include <stdio.h>

/*
 * linearSearch: busca linear recursiva de x em v[0..n-1].
 * Retorna 1 se x estiver presente, ou 0 se x nao for encontrado.
 */
int linearSearch(int x, int v[], int n) {
    /* Caso base 1: subvetor vazio, x nao foi encontrado */
    if (n <= 0) return 0;

    /* Caso base 2: o elemento na posicao atual e igual a x */
    if (v[n - 1] == x) return 1;

    /* Passo recursivo: continua a busca no subvetor restante de tamanho n - 1 */
    return linearSearch(x, v, n - 1);
}

int main(void) {
    int v[] = {46, 28, 51, 33, 72, 15, 69};
    int n = sizeof(v) / sizeof(v[0]);

    printf("--- Exercicio 8.6: Busca Linear Recursiva ---\n");
    printf("Vetor: {46, 28, 51, 33, 72, 15, 69}\n\n");

    int buscas[] = {33, 72, 15, 100, 28, 42};
    int total_buscas = sizeof(buscas) / sizeof(buscas[0]);

    for (int i = 0; i < total_buscas; i++) {
        int alvo = buscas[i];
        int resultado = linearSearch(alvo, v, n);
        if (resultado) {
            printf("Item %d: ENCONTRADO (retorno = %d)\n", alvo, resultado);
        } else {
            printf("Item %d: NAO ENCONTRADO (retorno = %d)\n", alvo, resultado);
        }
    }

    return 0;
}
