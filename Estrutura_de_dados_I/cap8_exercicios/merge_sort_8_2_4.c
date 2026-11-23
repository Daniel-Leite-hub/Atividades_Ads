/*
 * ==============================================================================
 * CAPITULO 8 - SECAO 8.2.4: ORDENACAO POR INTERCALACAO (MERGE SORT)
 * ==============================================================================
 * REFERENCIA NO LIVRO:
 * Paginas 89 a 91 (Figuras 8.12, 8.13, 8.14, 8.15 e 8.16)
 *
 * NOTA SOBRE OS EXERCICIOS DO CAPITULO 8:
 * Na secao de Exercicios (paginas 92 e 93), o livro cobra implementacoes
 * recursivas para Bubble Sort (8.3), Selection Sort (8.4), Insertion Sort (8.5),
 * Busca Linear (8.6), Busca Binaria (8.7) e a simulacao do Quick Sort (8.8),
 * porque o Merge Sort ja foi apresentado nativamente na sua forma recursiva
 * na Secao 8.2.4 (Figuras 8.13 e 8.16).
 *
 * Este arquivo contem:
 * 1. A implementacao completa de intercala() (Figura 8.13) e merge_sort() (Figura 8.16).
 * 2. A explicacao detalhada do funcionamento (Fase de Divisao e Fase de Intercalacao).
 * 3. A demonstracao da complexidade de tempo O(n lg n) e de espaco O(n).
 * 4. Simulacao passo a passo com os vetores das Figuras 8.14 e 8.15 do livro,
 *    alem dos mesmos vetores de teste do Exercicio 8.8 para comparacao direta.
 *
 * ==============================================================================
 * EXPLICACAO TEORICA E COMPLEXIDADE:
 * ==============================================================================
 * 1. CONCEITO DE INTERCALACAO (Funcao intercala - Figura 8.13):
 *    Combina dois subvetores contiguos ja ordenados v[p..m] e v[m+1..u] em um
 *    unico vetor ordenado v[p..u], utilizando um vetor auxiliar dinamico 'w'
 *    de tamanho (u - p + 1):
 *    - Enquanto nenhum dos dois subvetores estiver vazio (i <= m && j <= u),
 *      compara v[i] com v[j] e copia o menor para w[k++].
 *    - Quando um dos subvetores termina, copia os elementos restantes do outro
 *      subvetor diretamente para 'w'.
 *    - Ao final, transfere todos os elementos ordenados de 'w' de volta para
 *      v[p..u] e libera a memoria de 'w' com free(w).
 *
 * 2. ESTRATEGIA RECURSIVA (Funcao merge_sort - Figura 8.16):
 *    Segue o paradigma Dividir para Conquistar:
 *    - Base da recursao: Se p == u (ou p >= u), o subvetor tem apenas 1 item
 *      e, portanto, ja esta ordenado.
 *    - Passo recursivo (se p < u):
 *      a) Calcula o indice do meio: m = (p + u) / 2.
 *      b) Ordena recursivamente a metade esquerda: merge_sort(v, p, m).
 *      c) Ordena recursivamente a metade direita:  merge_sort(v, m + 1, u).
 *      d) Intercala as duas metades ordenadas:     intercala(v, p, m, u).
 *
 * 3. ANALISE DE COMPLEXIDADE DE TEMPO: O(n lg n)
 *    - Seja n = u - p + 1 o tamanho do vetor.
 *    - A cada nivel de divisao, o tamanho do vetor e reduzido exatamente a metade:
 *      n -> n/2 -> n/2^2 -> n/2^3 -> ... -> n/2^k.
 *    - A divisao atinge o caso base quando resta 1 elemento por subvetor:
 *          n / 2^k = 1  <=>  2^k = n  <=>  k = lg n (logaritmo na base 2).
 *    - Portanto, a arvore de recursao possui O(lg n) niveis de divisao/intercalacao.
 *    - Como em cada nivel sao intercalados, no total, n elementos (custo linear O(n)
 *      por nivel), a complexidade total de tempo do Merge Sort — tanto no melhor
 *      caso, quanto no caso medio e no pior caso — e:
 *          T(n) = O(n lg n).
 *
 * 4. COMPLEXIDADE DE ESPACO (MEMORIA): O(n)
 *    - Diferente do Quick Sort (que particiona in-place), o Merge Sort aloca o
 *      vetor auxiliar 'w' de tamanho proporcional a n na funcao intercala(),
 *      exigindo O(n) de memoria auxiliar.
 * ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Variavel auxiliar apenas para identar e mostrar o passo a passo na tela */
static int EXIBIR_PASSOS = 1;

/* Funcao auxiliar para imprimir um trecho do vetor v[p..u] */
void imprime_subvetor(int v[], int p, int u) {
    printf("{");
    for (int i = p; i <= u; i++) {
        printf("%d%s", v[i], (i < u) ? ", " : "");
    }
    printf("}");
}

/*
 * intercala: Figura 8.13 do livro (pagina 89).
 * Combina os subvetores ordenados v[p..m] e v[m+1..u] deixando v[p..u] ordenado.
 */
void intercala(int v[], int p, int m, int u) {
    /* Aloca vetor auxiliar w com a quantidade exata de elementos (u - p + 1) */
    int *w = (int *)malloc((u - p + 1) * sizeof(int));
    if (w == NULL) abort();

    int i = p;      /* Indice atual do primeiro subvetor (p..m) */
    int j = m + 1;  /* Indice atual do segundo subvetor (m+1..u) */
    int k = 0;      /* Indice atual do vetor auxiliar w */

    /* Enquanto nenhum dos dois subvetores estiver esgotado, copia o menor item */
    while (i <= m && j <= u) {
        if (v[i] < v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }

    /* Copia os itens restantes do primeiro subvetor (se houver) */
    while (i <= m)
        w[k++] = v[i++];

    /* Copia os itens restantes do segundo subvetor (se houver) */
    while (j <= u)
        w[k++] = v[j++];

    /* Transfere os elementos intercalados de w de volta para o vetor original v */
    for (k = 0; k <= u - p; k++)
        v[p + k] = w[k];

    /* Libera a memoria do vetor auxiliar */
    free(w);
}

/*
 * merge_sort: Figura 8.16 do livro (pagina 90).
 * Ordena recursivamente o vetor v no intervalo de indices [p..u].
 */
void merge_sort(int v[], int p, int u) {
    if (p == u) return; /* Caso base: subvetor com 1 unico item ja esta ordenado */

    int m = (p + u) / 2; /* Ponto medio para dividir o vetor em duas metades */

    merge_sort(v, p, m);     /* Ordena a metade esquerda v[p..m] */
    merge_sort(v, m + 1, u); /* Ordena a metade direita v[m+1..u] */
    intercala(v, p, m, u);   /* Intercala as duas metades ordenadas */

    if (EXIBIR_PASSOS) {
        printf("  [intercala] p=%d, m=%d, u=%d -> v[%d..%d] = ", p, m, u, p, u);
        imprime_subvetor(v, p, u);
        printf("\n");
    }
}

int main(void) {
    /*
     * TESTE 1: Vetor da Figura 8.14 do livro (pagina 90)
     * v = {63, 27, 46, 38, 19, 82, 75, 51}
     */
    printf("===============================================================\n");
    printf("1. SIMULACAO DA FIGURA 8.14 DO LIVRO (8 elementos)\n");
    printf("===============================================================\n");
    int v1[] = {63, 27, 46, 38, 19, 82, 75, 51};
    int n1 = sizeof(v1) / sizeof(v1[0]);

    printf("Vetor inicial: ");
    imprime_subvetor(v1, 0, n1 - 1);
    printf("\n\nPasso a passo das intercalacoes (bottom-up na arvore):\n");
    merge_sort(v1, 0, n1 - 1);
    printf("\nVetor final ordenado: ");
    imprime_subvetor(v1, 0, n1 - 1);
    printf("\n\n");

    /*
     * TESTE 2: Vetor da Figura 8.15 do livro (pagina 90)
     * v = {38, 31, 96, 52, 45, 19, 68, 70, 29, 90}
     */
    printf("===============================================================\n");
    printf("2. SIMULACAO DA FIGURA 8.15 DO LIVRO (10 elementos)\n");
    printf("===============================================================\n");
    int v2[] = {38, 31, 96, 52, 45, 19, 68, 70, 29, 90};
    int n2 = sizeof(v2) / sizeof(v2[0]);

    printf("Vetor inicial: ");
    imprime_subvetor(v2, 0, n2 - 1);
    printf("\n\nPasso a passo das intercalacoes:\n");
    merge_sort(v2, 0, n2 - 1);
    printf("\nVetor final ordenado: ");
    imprime_subvetor(v2, 0, n2 - 1);
    printf("\n\n");

    /*
     * TESTE 3: Comparacao usando os vetores do Exercicio 8.8
     */
    printf("===============================================================\n");
    printf("3. TESTE COM OS VETORES DO EXERCICIO 8.8 (a) e (b)\n");
    printf("===============================================================\n");
    int va[] = {72, 69, 51, 46, 33, 28, 15};
    printf("Vetor (a) inicial: ");
    imprime_subvetor(va, 0, 6);
    printf("\n");
    merge_sort(va, 0, 6);
    printf("Vetor (a) ordenado: ");
    imprime_subvetor(va, 0, 6);
    printf("\n\n");

    int vb[] = {46, 28, 51, 33, 72, 15, 69};
    printf("Vetor (b) inicial: ");
    imprime_subvetor(vb, 0, 6);
    printf("\n");
    merge_sort(vb, 0, 6);
    printf("Vetor (b) ordenado: ");
    imprime_subvetor(vb, 0, 6);
    printf("\n");

    return 0;
}
