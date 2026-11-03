/*
 * ==============================================================================
 * EXERCICIO 8.7
 * ==============================================================================
 * ENUNCIADO:
 * Crie a funcao recursiva binarySearch(x, v, p, u), que faz uma busca binaria
 * para verificar se o numero inteiro x esta no vetor v, indexado de p ate u.
 *
 * RESPOSTA E EXPLICACAO:
 * 1. A busca binaria pressupoe que o vetor 'v' esteja em ordem crescente.
 *    O intervalo atual de busca e delimitado pelo primeiro indice 'p' e pelo
 *    ultimo indice 'u'.
 *
 * 2. Estrutura recursiva:
 *    - Caso Base 1 (intervalo invalido/vazio): se p > u, o item nao esta
 *      no vetor -> retorna 0.
 *    - Calculo do ponto medio: m = (p + u) / 2.
 *    - Caso Base 2 (sucesso): se x == v[m], o item foi encontrado no meio
 *      -> retorna 1.
 *    - Passo Indutivo:
 *      * Se x < v[m]: o item (se existir) so pode estar a esquerda de m.
 *        Chamada recursiva: binarySearch(x, v, p, m - 1);
 *      * Se x > v[m]: o item (se existir) so pode estar a direita de m.
 *        Chamada recursiva: binarySearch(x, v, m + 1, u);
 *
 * Complexidade de tempo:
 *   A cada passo, o tamanho do intervalo de busca e dividido por 2.
 *   - Melhor caso: O(1) (quando o item procurado esta exatamente no primeiro ponto medio).
 *   - Pior caso: O(lg n) (quando o item nao existe ou esta nos extremos).
 * ==============================================================================
 */

#include <stdio.h>

/*
 * binarySearch: busca binaria recursiva de x no subvetor v[p..u].
 * Retorna 1 se x estiver presente, ou 0 se nao for encontrado.
 */
int binarySearch(int x, int v[], int p, int u) {
    /* Caso base 1: intervalo vazio (p cruzou u), x nao encontrado */
    if (p > u) return 0;

    /* Ponto medio do intervalo */
    int m = (p + u) / 2;

    /* Caso base 2: x encontrado na posicao m */
    if (x == v[m]) return 1;

    /* Passo recursivo a esquerda */
    if (x < v[m]) {
        return binarySearch(x, v, p, m - 1);
    }
    /* Passo recursivo a direita */
    else {
        return binarySearch(x, v, m + 1, u);
    }
}

int main(void) {
    /* Vetor ordenado para busca binaria */
    int v[] = {15, 28, 33, 46, 51, 69, 72};
    int n = sizeof(v) / sizeof(v[0]);

    printf("--- Exercicio 8.7: Busca Binaria Recursiva ---\n");
    printf("Vetor ordenado: {15, 28, 33, 46, 51, 69, 72}\n\n");

    int buscas[] = {15, 33, 51, 72, 10, 50, 80};
    int total_buscas = sizeof(buscas) / sizeof(buscas[0]);

    for (int i = 0; i < total_buscas; i++) {
        int alvo = buscas[i];
        int resultado = binarySearch(alvo, v, 0, n - 1);
        if (resultado) {
            printf("Item %2d: ENCONTRADO (retorno = %d)\n", alvo, resultado);
        } else {
            printf("Item %2d: NAO ENCONTRADO (retorno = %d)\n", alvo, resultado);
        }
    }

    return 0;
}
