/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 8 (LIVRO PÁG 32, QUESTÃO 2.5)
 * ============================================================================
 * 
 * ENUNCIADO DO LIVRO:
 * 2.5 Digite e teste o programa a seguir e, depois, explique o que ele faz 
 *     (consulte o sistema de ajuda do Pelles C para obter informações sobre as 
 *     funções que você desconhece).
 * 
 * ============================================================================
 * EXPLICAÇÃO COMPLETA DO QUE O PROGRAMA FAZ:
 * ============================================================================
 * 1. O programa gera uma ANIMAÇÃO GRÁFICA NO TERMINAL de "estrelas piscando".
 * 
 * 2. São criadas duas pilhas: 'px' (para coordenadas horizontais X) e 'py' 
 *    (para coordenadas verticais Y).
 * 
 * 3. FASE DE DESENHO (for de 0 a MAX-1):
 *    - Sorteia coordenadas aleatórias x (coluna 1 a 40) e y (linha 1 a 20).
 *    - Posiciona o cursor do console em (x, y) com a função _gotoxy(x, y).
 *    - Seleciona uma cor de texto aleatória com _textcolor(...).
 *    - Imprime um asterisco '*' representando uma estrela.
 *    - Pausa brevemente por 0.05 segundos para efeito visual de animação.
 *    - EMPILHA a coordenada x em 'px' e a coordenada y em 'py'.
 * 
 * 4. FASE DE APAGAMENTO (while !vaziap(px)):
 *    - Desempilha a última coordenada (x, y) inserida.
 *    - Posiciona o cursor de volta nessa coordenada e imprime um espaço em branco ' ', 
 *      apagando a estrela da tela.
 *    - Pausa por 0.02 segundos.
 * 
 * 5. PAPEL FUNDAMENTAL DA ESTRUTURA PILHA (LIFO):
 *    - Como a pilha opera no regime Last-In, First-Out, as estrelas são APAGADAS 
 *      EXATAMENTE NA ORDEM INVERSA EM QUE FORAM DESENHADAS!
 *    - A última estrela a surgir na tela é a primeira a ser apagada.
 * 
 * 6. O laço externo continua executando repetidamente esse ciclo até que o 
 *    usuário pressione qualquer tecla no teclado (detectado por _kbhit()).
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30

/* Implementação de Pilha Sequencial */
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

int vaziap(Pilha *p) {
    return (p->topo == -1);
}

void empilha(int x, Pilha *p) {
    if (p->topo < MAX - 1) {
        p->itens[++p->topo] = x;
    }
}

int desempilha(Pilha *p) {
    if (!vaziap(p)) {
        return p->itens[p->topo--];
    }
    return 0;
}

/* Função pausa portável usando clock() */
void pausa(float tempo) {
    float duracao, inicio = (float)clock();
    do {
        duracao = ((float)clock() - inicio) / CLOCKS_PER_SEC;
    } while (duracao < tempo);
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 8 - LIVRO PAG. 32, EXERCICIO 2.5\n");
    printf("ANIMACAO GRÁFICA COM DUAS PILHAS (ORDEM INVERSA LIFO)\n");
    printf("============================================================\n\n");

    printf("Explicacao teorica detalhada no cabecalho do codigo.\n");
    printf("Abaixo, uma demonstracao textual simulada do comportamento LIFO:\n\n");

    Pilha px, py;
    inicializa(&px);
    inicializa(&py);

    srand((unsigned int)time(NULL));

    printf(">>> FASE 1: DESENHANDO ESTRELAS E EMPILHANDO COORDENADAS (X, Y) <<<\n");
    for (int i = 0; i < 5; i++) {
        int x = rand() % 40 + 1;
        int y = rand() % 20 + 1;
        printf("  [Desenho #%d] Estrela '*' plotada em (%02d, %02d) -> EMPILHADA\n", i + 1, x, y);
        empilha(x, &px);
        empilha(y, &py);
    }

    printf("\n>>> FASE 2: APAGANDO ESTRELAS DESEMPILHANDO (ORDEM LIFO INVERSA) <<<\n");
    int passo = 1;
    while (!vaziap(&px)) {
        int y = desempilha(&py);
        int x = desempilha(&px);
        printf("  [Apagamento #%d] Desempilhado (%02d, %02d) -> Espaco ' ' impresso\n", passo++, x, y);
    }

    printf("\nObserve como a 5a estrela desenhada foi a 1a estrela apagada!\n");
    return 0;
}
