/*
 * ==============================================================================
 * EXERCICIO 8.8
 * ==============================================================================
 * ENUNCIADO:
 * A ordenacao por particao, tambem chamada quick sort, e considerada um dos mais
 * eficientes algoritmos de ordenacao. Dado um vetor v, indexado de p ate u, esse
 * algoritmo usa o item x = v[p] como pivo para particionar o vetor v em dois
 * subvetores indexados de p ate m e de m + 1 ate u, respectivamente, de modo que
 * todo item com indice no intervalo [p..m] seja menor ou igual a x e todo item
 * com indice no intervalo [m + 1..u] seja maior ou igual a x. Em seguida, cada
 * subvetor e ordenado recursivamente, como indicado a seguir:
 *
 * int particiona(int v[], int p, int u) {
 *     int x = v[p];
 *     p--;
 *     u++;
 *     while( p < u ) {
 *         do u--; while( v[u]>x );
 *         do p++; while( v[p]<x );
 *         if( p < u ) troca(v[p], v[u]);
 *     }
 *     return u;
 * }
 *
 * void quick_sort(int v[], int p, int u) {
 *     if( p >= u ) return;
 *     int m = particiona(v, p, u);
 *     quick_sort(v, p, m);
 *     quick_sort(v, m+1, u);
 * }
 *
 * (a) Simule a execucao de quick_sort() para v = {72, 69, 51, 46, 33, 28, 15}.
 * (b) Simule a execucao de quick_sort() para v = {46, 28, 51, 33, 72, 15, 69}.
 * (c) Mostre que, no pior caso, a complexidade de quick_sort() e O(n^2).
 * (d) Mostre que, no melhor caso, a complexidade de quick_sort() e O(n lg n).
 *
 * ==============================================================================
 * RESPOSTAS COMENTADAS DOS ITENS TEORICOS (c) e (d):
 * ==============================================================================
 *
 * ITEM (c) - PIOR CASO: O(n^2)
 * ----------------------------
 * 1. O procedimento 'particiona' percorre os limites com os ponteiros 'p' e 'u'
 *    realizando comparacoes lineares em relacao ao tamanho da particao k = u - p + 1.
 *    Portanto, o custo de particionamento e Theta(k).
 * 2. O pior caso ocorre quando o pivo escolhido em cada chamada e sempre o item
 *    extremo (o menor ou o maior elemento do subvetor). Isso acontece, por exemplo,
 *    quando o vetor de entrada ja se encontra em ordem decrescente (como no item a)
 *    ou crescente.
 * 3. Nesse cenario desbalanceado, a particao divide o vetor de tamanho n em dois
 *    subvetores de tamanhos 1 e n - 1 (ou 0 e n - 1). A relacao de recorrencia e:
 *        T(n) = T(n - 1) + T(1) + c*n
 *    Como T(1) = O(1), temos:
 *        T(n) = T(n - 1) + c*n
 * 4. Expandindo a recorrencia:
 *        T(n) = c*n + c*(n - 1) + c*(n - 2) + ... + c*2 + T(1)
 *             = c * sum_{i=2}^{n} i + T(1)
 *             = c * [ n*(n + 1)/2 - 1 ] + T(1)
 *             = (c/2)*n^2 + (c/2)*n - c + T(1)
 *             = O(n^2)
 *    Logo, no pior caso, a complexidade e quadratica: O(n^2).
 *
 * ITEM (d) - MELHOR CASO: O(n lg n)
 * ---------------------------------
 * 1. O melhor caso ocorre quando a particao divide o vetor repetidamente em duas
 *    metades balanceadas, cada uma com aproximadamente metade dos elementos:
 *    tamanhos floor(n/2) e ceil(n/2).
 * 2. A relacao de recorrencia e:
 *        T(n) = 2 * T(n/2) + c*n
 *    com caso base T(1) = O(1).
 * 3. Analise pela Arvore de Recursao:
 *    - Nivel 0 (raiz): 1 problema de tamanho n        -> Custo = c*n
 *    - Nivel 1:        2 problemas de tamanho n/2      -> Custo = 2 * c*(n/2) = c*n
 *    - Nivel 2:        4 problemas de tamanho n/4      -> Custo = 4 * c*(n/4) = c*n
 *    - Nivel k:        2^k problemas de tamanho n/2^k  -> Custo = 2^k * c*(n/2^k) = c*n
 *    Como o tamanho do vetor e dividido por 2 a cada nivel, a altura da arvore e:
 *        n / 2^h = 1  =>  2^h = n  =>  h = lg n (logaritmo na base 2).
 * 4. Somando o trabalho constante c*n por nivel ao longo de todos os (lg n + 1) niveis:
 *        T(n) = c * n * (lg n + 1) = O(n lg n).
 *    (Pelo Teorema Mestre: a=2, b=2, f(n)=Theta(n). Como n^{log_b a} = n^1, recai
 *    no Caso 2, onde T(n) = Theta(n lg n) = O(n lg n)).
 *
 * ==============================================================================
 * RESUMO DAS SIMULACOES DOS ITENS (a) E (b):
 * ==============================================================================
 *
 * SIMULACAO (a) para v = {72, 69, 51, 46, 33, 28, 15}:
 * 1. quick_sort(v, 0, 6): pivo x = v[0] = 72.
 *    Troca v[0] (72) com v[6] (15) -> v = {15, 69, 51, 46, 33, 28, 72}.
 *    Ponteiros se cruzam com u = 5, retorna m = 5. Subvetores: [0..5] e [6..6].
 * 2. quick_sort(v, 0, 5): pivo x = v[0] = 15.
 *    u recua ate 0. Retorna m = 0. Subvetores: [0..0] e [1..5].
 * 3. quick_sort(v, 1, 5): pivo x = v[1] = 69.
 *    Troca v[1] (69) com v[5] (28) -> v = {15, 28, 51, 46, 33, 69, 72}.
 *    Retorna m = 4. Subvetores: [1..4] e [5..5].
 * 4. quick_sort(v, 1, 4): pivo x = v[1] = 28.
 *    u recua ate 1. Retorna m = 1. Subvetores: [1..1] e [2..4].
 * 5. quick_sort(v, 2, 4): pivo x = v[2] = 51.
 *    Troca v[2] (51) com v[4] (33) -> v = {15, 28, 33, 46, 51, 69, 72}.
 *    Retorna m = 3. Subvetores: [2..3] e [4..4].
 * 6. quick_sort(v, 2, 3): pivo x = v[2] = 33.
 *    u recua ate 2. Retorna m = 2. Subvetores: [2..2] e [3..3].
 * Resultado final: {15, 28, 33, 46, 51, 69, 72}.
 *
 * SIMULACAO (b) para v = {46, 28, 51, 33, 72, 15, 69}:
 * 1. quick_sort(v, 0, 6): pivo x = v[0] = 46.
 *    Troca v[0] (46) com v[5] (15) -> {15, 28, 51, 33, 72, 46, 69}
 *    Troca v[2] (51) com v[3] (33) -> {15, 28, 33, 51, 72, 46, 69}
 *    Retorna m = 2. Subvetores: [0..2] e [3..6].
 * 2. quick_sort(v, 0, 2): pivo x = v[0] = 15.
 *    Retorna m = 0. Subvetores: [0..0] e [1..2].
 * 3. quick_sort(v, 1, 2): pivo x = v[1] = 28.
 *    Retorna m = 1. Subvetores: [1..1] e [2..2].
 * 4. quick_sort(v, 3, 6): pivo x = v[3] = 51.
 *    Troca v[3] (51) com v[5] (46) -> {15, 28, 33, 46, 72, 51, 69}
 *    Retorna m = 3. Subvetores: [3..3] e [4..6].
 * 5. quick_sort(v, 4, 6): pivo x = v[4] = 72.
 *    Troca v[4] (72) com v[6] (69) -> {15, 28, 33, 46, 69, 51, 72}
 *    Retorna m = 5. Subvetores: [4..5] e [6..6].
 * 6. quick_sort(v, 4, 5): pivo x = v[4] = 69.
 *    Troca v[4] (69) com v[5] (51) -> {15, 28, 33, 46, 51, 69, 72}
 *    Retorna m = 4. Subvetores: [4..4] e [5..5].
 * Resultado final: {15, 28, 33, 46, 51, 69, 72}.
 * ==============================================================================
 */

#include <stdio.h>

#define troca(a, b) { int x_aux = a; a = b; b = x_aux; }

static int TAM_GLOBAL = 7;

/* Imprime o vetor completo com formatacao */
void imprime_vetor_completo(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1) ? ", " : "");
    }
    printf("}\n");
}

/*
 * particiona: particionamento pelo esquema de Hoare (Figura 8.8 do livro).
 * Instrumentada com mensagens para exibir cada passo da simulacao.
 */
int particiona(int v[], int p, int u) {
    int x = v[p]; /* Pivo e o primeiro elemento v[p] */
    printf("    [particiona] Subvetor v[%d..%d], Pivo x = %d\n", p, u, x);
    p--;
    u++;
    while (p < u) {
        do u--; while (v[u] > x);
        do p++; while (v[p] < x);
        if (p < u) {
            printf("      -> Troca v[%d]=%d com v[%d]=%d | Vetor: ", p, v[p], u, v[u]);
            troca(v[p], v[u]);
            imprime_vetor_completo(v, TAM_GLOBAL);
        }
    }
    printf("      -> Parada: retorna m = %d (subvetores: [%s], [%s])\n",
           u, "p..m", "m+1..u");
    return u;
}

/*
 * quick_sort: implementacao conforme apresentada no livro.
 */
void quick_sort(int v[], int p, int u) {
    if (p >= u) return; /* Caso base: subvetor com 0 ou 1 item */

    printf("  quick_sort(v, p=%d, u=%d)\n", p, u);
    int m = particiona(v, p, u);

    /* Chamadas recursivas para as duas particoes */
    quick_sort(v, p, m);
    quick_sort(v, m + 1, u);
}

int main(void) {
    printf("===============================================================\n");
    printf("EXERCICIO 8.8 (a): Simulacao com vetor em ordem decrescente\n");
    printf("===============================================================\n");
    int va[] = {72, 69, 51, 46, 33, 28, 15};
    TAM_GLOBAL = 7;
    printf("Vetor inicial: ");
    imprime_vetor_completo(va, 7);
    quick_sort(va, 0, 6);
    printf("Vetor final ordenado: ");
    imprime_vetor_completo(va, 7);

    printf("\n===============================================================\n");
    printf("EXERCICIO 8.8 (b): Simulacao com vetor desordenado\n");
    printf("===============================================================\n");
    int vb[] = {46, 28, 51, 33, 72, 15, 69};
    TAM_GLOBAL = 7;
    printf("Vetor inicial: ");
    imprime_vetor_completo(vb, 7);
    quick_sort(vb, 0, 6);
    printf("Vetor final ordenado: ");
    imprime_vetor_completo(vb, 7);

    return 0;
}
