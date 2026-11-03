/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 2
 * ============================================================================
 * 
 * ENUNCIADO:
 * Sobre uma estrutura de dados tipo "pilha", verifique as afirmações 
 * (Verdadeiras ou Falsas) e escolha a alternativa correta:
 * 
 * A. ( V ) É uma estrutura linear de dados que pode ser acessada somente por uma 
 *          de suas extremidades para armazenar e recuperar dados. A recuperação 
 *          da informação na extremidade da estrutura é executada através de um 
 *          único acesso (em tempo constante).
 *          -> VERDADEIRA: O acesso ao elemento do topo é direto indexado por t (tempo O(1)).
 * 
 * B. ( F ) É uma estrutura linear de dados que pode ser acessada somente por uma 
 *          de suas extremidades para armazenar e recuperar dados. A recuperação 
 *          da informação na extremidade da estrutura é executada através de n 
 *          acessos a estrutura (onde n é o valor da quantidade de elementos).
 *          -> FALSA: Não são necessários n acessos; o topo é acessado diretamente em 1 passo.
 * 
 * C. ( V ) No caso de uma implementação usando um vetor, a função que verifique 
 *          se a pilha está vazia pode ser feita da seguinte forma:
 *          // considere t o tamanho da pilha
 *          // considere o primeiro índice do vetor igual a 0
 *          bool isEmpty() { 
 *              return (t < 0);
 *          }
 *          Esta função é executada em tempo constante. Ou seja, não muda, 
 *          independente do tamanho t da pilha.
 *          -> VERDADEIRA: A expressão de comparação (t < 0) é uma única operação aritmética O(1).
 * 
 * D. ( V ) No caso de uma implementação usando um vetor, a função "push" da pilha 
 *          pode ser feita da seguinte forma:
 *          // considere N o tamanho máximo permitido no vetor S
 *          // considere x o novo valor a ser inserido 
 *          void push(x) {
 *              if (S.size() == N) 
 *                  return Error;
 *              S[++t] = x;
 *          }
 *          Esta função é executada em tempo constante. Ou seja, não muda, 
 *          independente do tamanho t da pilha.
 *          -> VERDADEIRA: Testar a capacidade e atribuir em S[++t] não depende de laços, executando em O(1).
 * 
 * E. ( F ) No caso de uma implementação usando um vetor, a função "push" da pilha 
 *          pode ser feita da seguinte forma:
 *          ...
 *          Esta função tem o seu tempo de execução dependendo do tamanho t da 
 *          estrutura. Ela vai executar N vezes, onde N é a quantidade de elementos da pilha.
 *          -> FALSA: O push NÃO possui laço 'for' ou 'while' e NÃO executa N vezes.
 * 
 * ============================================================================
 * CLASSIFICAÇÃO: A-V, B-F, C-V, D-V, E-F
 * ALTERNATIVA CORRETA: C
 * ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>

#define N 5 // Capacidade máxima do vetor da pilha

int S[N];
int t = -1; // Topo inicializado em -1 (pilha vazia com índices de 0 a N-1)

/* Implementação do item C: isEmpty() em O(1) */
bool isEmpty() {
    return (t < 0);
}

/* Implementação do item D: push() em O(1) */
bool push(int x) {
    if (t == N - 1) { // Pilha cheia
        printf("[ERRO] Pilha Cheia! Nao foi possivel inserir %d\n", x);
        return false;
    }
    S[++t] = x;
    printf("[PUSH] Inserido %d no topo (indice %d) em tempo O(1)\n", x, t);
    return true;
}

/* Operação pop em O(1) */
int pop() {
    if (isEmpty()) {
        printf("[ERRO] Pilha Vazia!\n");
        return -1;
    }
    int val = S[t--];
    printf("[POP] Removido %d do topo em tempo O(1)\n", val);
    return val;
}

int main() {
    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 2:\n");
    printf("CLASSIFICACAO: A-V, B-F, C-V, D-V, E-F\n");
    printf("GABARITO: ALTERNATIVA C\n");
    printf("============================================================\n\n");

    printf("1. Verificando estado inicial da pilha:\n");
    printf("   isEmpty()? %s (Tempo constante O(1))\n\n", isEmpty() ? "TRUE (Vazia)" : "FALSE");

    printf("2. Realizando operacoes push (sempre em O(1)):\n");
    push(10);
    push(20);
    push(30);

    printf("\n3. Verificando se esta vazia apos insercoes:\n");
    printf("   isEmpty()? %s\n\n", isEmpty() ? "TRUE" : "FALSE (Nao vazia)");

    printf("4. Realizando pop:\n");
    pop();
    pop();

    return 0;
}
