/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 12
 * ============================================================================
 * 
 * ENUNCIADO:
 * 12. Escreva um programa para verificar se uma expressão tem seus delimitadores 
 *     agrupados de forma correta, isto é:
 *     Ex.: while (m < (n[8]+p))
 *     O algoritmo de casamento de delimitador deve ler o caractere e o estocar 
 *     em uma pilha se ele for um delimitador de abertura. Se um delimitador de 
 *     fechamento for encontrado, ele é comparado ao delimitador que está no topo 
 *     da pilha. Se eles casam, o elemento é desempilhado e o processamento 
 *     continua, senão, o processamento é interrompido, assinalando um erro.
 * 
 * CASOS DE TESTE ESPECIFICADOS NO ENUNCIADO:
 * - Ex1: ((A+B) ou A+B(                 ==> ERRO (delimitador de abertura sem fechamento)
 * - Ex2: {)A+B( - C ou (A+B))} - (C + D ==> ERRO (fechamento incorreto ou desbalanceado)
 * - Ex3: {m +(x+5)+3}                   ==> CORRETO
 * - Ex4: m +x+5+3}                      ==> ERRO (fechamento sem abertura correspondente)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 500

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

bool vazia(Pilha *p) {
    return (p->topo == -1);
}

void empilha(char c, Pilha *p) {
    if (p->topo < MAX - 1) {
        p->itens[++p->topo] = c;
    }
}

char desempilha(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0';
}

char topo(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo];
    }
    return '\0';
}

/* Verifica se dois delimitadores formam um par valido */
bool casam(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

/**
 * Validador de delimitadores:
 * Retorna true se a expressao estiver corretamente agrupada, false se houver erro.
 */
bool verificarExpressao(const char *expr) {
    Pilha p;
    inicializa(&p);

    int tam = strlen(expr);
    for (int i = 0; i < tam; i++) {
        char c = expr[i];

        // Se for delimitador de abertura, empilha
        if (c == '(' || c == '[' || c == '{') {
            empilha(c, &p);
        }
        // Se for delimitador de fechamento, compara com o topo
        else if (c == ')' || c == ']' || c == '}') {
            if (vazia(&p)) {
                return false; // Erro: fechamento sem nenhuma abertura anterior
            }
            char abertura = desempilha(&p);
            if (!casam(abertura, c)) {
                return false; // Erro: fechamento incompativel com o topo
            }
        }
    }

    // Se ao final a pilha estiver vazia, todos foram devidamente fechados
    return vazia(&p);
}

void testar(const char *expr) {
    bool resultado = verificarExpressao(expr);
    printf("Expressao: %-32s ==> %s\n", expr, resultado ? "CORRETO" : "ERRO");
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 12 - VERIFICADOR DE DELIMITADORES AGRUPADOS\n");
    printf("============================================================\n\n");

    printf("--- TESTES EXATOS DO ENUNCIADO ---\n");
    testar("((A+B)");
    testar("A+B(");
    testar("{)A+B( - C");
    testar("(A+B))} - (C + D");
    testar("{m +(x+5)+3}");
    testar("m +x+5+3}");

    printf("\n--- TESTE DO EXEMPLO INICIAL (while (m < (n[8]+p))) ---\n");
    testar("while (m < (n[8]+p))");

    return 0;
}
