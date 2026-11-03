/*
 * Capitulo 8 - Ordenacao e Busca
 * Resolucao dos exercicios 8.1 a 8.8
 *
 * Compilar: gcc -Wall -o exercicios_cap8 exercicios_cap8.c
 * Executar: ./exercicios_cap8
 */

#include <stdio.h>
#include <string.h>

#define troca(a, b) { int x_ = a; a = b; b = x_; }

/* ======================= Exercicio 8.1 =======================
 * bubble_sort() para vetores de numeros reais.
 */
#define trocaf(a, b) { float x_ = a; a = b; b = x_; }

void bubble_sort(float v[], int n) {
    for (int i = 1; i <= n - 1; i++)
        for (int j = 0; j < n - i; j++)
            if (v[j] > v[j + 1])
                trocaf(v[j], v[j + 1]);
}

/* ======================= Exercicio 8.2 =======================
 * insertion_sort() para vetores de cadeias.
 */
#define TAM_MAX 100

void insere_str(char x[], char v[][TAM_MAX], int n) {
    while (n > 0 && strcmp(x, v[n - 1]) < 0) {
        strcpy(v[n], v[n - 1]);
        n--;
    }
    strcpy(v[n], x);
}

void insertion_sort_str(char v[][TAM_MAX], int n) {
    char aux[TAM_MAX];
    for (int i = 0; i < n; i++) {
        strcpy(aux, v[i]);
        insere_str(aux, v, i);
    }
}

/* ======================= Exercicio 8.3 =======================
 * bubbleSort() recursivo usando empurra().
 */
void empurra(int v[], int n) {
    for (int i = 0; i < n; i++)
        if (v[i] > v[i + 1])
            troca(v[i], v[i + 1]);
}

void bubbleSort(int v[], int n) {
    if (n <= 1) return;
    empurra(v, n - 1);      /* leva o maximo para v[n-1] */
    bubbleSort(v, n - 1);
}

/* ======================= Exercicio 8.4 =======================
 * selectionSort() recursivo usando seleciona() (Figura 8.9).
 */
int seleciona(int v[], int n) {
    int m = 0;
    for (int i = 1; i < n; i++)
        if (v[i] > v[m]) m = i;
    return m;
}

void selectionSort(int v[], int n) {
    if (n <= 1) return;
    int m = seleciona(v, n);
    troca(v[m], v[n - 1]);
    selectionSort(v, n - 1);
}

/* ======================= Exercicio 8.5 =======================
 * insertionSort() recursivo usando insere() (Figura 8.11).
 */
void insere(int x, int v[], int n) {
    while (n > 0 && x < v[n - 1]) {
        v[n] = v[n - 1];
        n--;
    }
    v[n] = x;
}

void insertionSort(int v[], int n) {
    if (n <= 1) return;
    insertionSort(v, n - 1);
    insere(v[n - 1], v, n - 1);
}

/* ======================= Exercicio 8.6 =======================
 * Busca linear recursiva. Devolve 1 se encontrar, 0 caso contrario.
 */
int linearSearch(int x, int v[], int n) {
    if (n <= 0) return 0;
    if (v[n - 1] == x) return 1;
    return linearSearch(x, v, n - 1);
}

/* ======================= Exercicio 8.7 =======================
 * Busca binaria recursiva em v[p..u] (vetor ordenado).
 */
int binarySearch(int x, int v[], int p, int u) {
    if (p > u) return 0;
    int m = (p + u) / 2;
    if (x == v[m]) return 1;
    if (x < v[m]) return binarySearch(x, v, p, m - 1);
    return binarySearch(x, v, m + 1, u);
}

/* ======================= Exercicio 8.8 =======================
 * quick_sort() com rastreamento para simular os itens (a) e (b).
 */
int TAM_SIM;   /* tamanho do vetor sendo simulado (para impressao) */

void mostra(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) printf("%d%s", v[i], i < n - 1 ? ", " : "");
    printf("}\n");
}

int particiona(int v[], int p, int u) {
    int x = v[p];
    p--;
    u++;
    while (p < u) {
        do u--; while (v[u] > x);
        do p++; while (v[p] < x);
        if (p < u) {
            troca(v[p], v[u]);
            printf("      troca v[%d] <-> v[%d]: ", p, u);
            mostra(v, TAM_SIM);
        }
    }
    return u;
}

void quick_sort(int v[], int p, int u) {
    if (p >= u) return;
    printf("  quick_sort(v, %d, %d), pivo = %d\n", p, u, v[p]);
    int m = particiona(v, p, u);
    printf("    -> m = %d\n", m);
    quick_sort(v, p, m);
    quick_sort(v, m + 1, u);
}

/*
 * 8.8 (c) Pior caso O(n^2):
 *   Quando o pivo e sempre o menor ou o maior elemento (ex.: vetor ja
 *   ordenado ou invertido), a particao gera subvetores de tamanhos 1 e n-1.
 *   Como particiona() custa c*n:
 *       T(n) = T(n-1) + c*n
 *            = c*(n + (n-1) + ... + 2) + T(1)
 *            = c*(n(n+1)/2 - 1) + T(1)  =  O(n^2)
 *
 * 8.8 (d) Melhor caso O(n lg n):
 *   Quando o pivo divide sempre o vetor ao meio:
 *       T(n) = 2*T(n/2) + c*n
 *   A arvore de recursao tem lg n niveis, cada um com custo total c*n:
 *       T(n) = c*n*(lg n + 1) = O(n lg n)
 *   (Teorema Mestre, caso 2: a = 2, b = 2, f(n) = Theta(n).)
 */

/* ============================ main ============================ */
int main(void) {
    /* 8.1 */
    float r[] = {3.5f, -1.2f, 7.0f, 0.5f, 2.25f};
    bubble_sort(r, 5);
    printf("8.1 bubble_sort (reais): ");
    for (int i = 0; i < 5; i++) printf("%.2f ", r[i]);
    printf("\n");

    /* 8.2 */
    char s[][TAM_MAX] = {"uva", "banana", "maca", "abacaxi", "laranja"};
    insertion_sort_str(s, 5);
    printf("8.2 insertion_sort (cadeias): ");
    for (int i = 0; i < 5; i++) printf("%s ", s[i]);
    printf("\n");

    /* 8.3 */
    int a[] = {46, 28, 51, 33, 72, 15, 69};
    bubbleSort(a, 7);
    printf("8.3 bubbleSort recursivo: ");    mostra(a, 7);

    /* 8.4 */
    int b[] = {46, 28, 51, 33, 72, 15, 69};
    selectionSort(b, 7);
    printf("8.4 selectionSort recursivo: "); mostra(b, 7);

    /* 8.5 */
    int c[] = {46, 28, 51, 33, 72, 15, 69};
    insertionSort(c, 7);
    printf("8.5 insertionSort recursivo: "); mostra(c, 7);

    /* 8.6 */
    int d[] = {46, 28, 51, 33, 72, 15, 69};
    printf("8.6 linearSearch: 33 -> %d, 99 -> %d\n",
           linearSearch(33, d, 7), linearSearch(99, d, 7));

    /* 8.7 */
    printf("8.7 binarySearch: 51 -> %d, 50 -> %d\n",
           binarySearch(51, c, 0, 6), binarySearch(50, c, 0, 6));

    /* 8.8 (a) */
    int qa[] = {72, 69, 51, 46, 33, 28, 15};
    TAM_SIM = 7;
    printf("\n8.8 (a) simulacao com "); mostra(qa, 7);
    quick_sort(qa, 0, 6);
    printf("  resultado: "); mostra(qa, 7);

    /* 8.8 (b) */
    int qb[] = {46, 28, 51, 33, 72, 15, 69};
    printf("\n8.8 (b) simulacao com "); mostra(qb, 7);
    quick_sort(qb, 0, 6);
    printf("  resultado: "); mostra(qb, 7);

    return 0;
}
