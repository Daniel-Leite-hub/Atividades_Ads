/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 1 (PARTE 1: LISTA ESTÁTICA SEQUENCIAL)
 * ============================================================================
 * 
 * ENUNCIADO:
 * 1. Para os dois códigos sobre lista estática e lista dinâmica enviados (completar).
 *    Obs: os integrantes do grupo devem se dividir para explicar partes do código.
 * 
 * ESTRUTURA DO ARQUIVO ORIGINAL (ListaVs1_arrayIncompleto.cpp):
 * O código gerencia uma lista linear estática de Alunos com capacidade para 30 elementos:
 * - incluirDesordenado(Aluno e): insere um novo aluno no final da lista.
 * - procura(int mat): busca sequencialmente pela matrícula e retorna o índice ou -1.
 * - mostrar(int pos): exibe os dados do aluno na posição informada.
 * - mostra(): exibe todos os alunos cadastrados.
 * - remover00(): Estratégia 1 -> substitui o elemento removido pelo último da lista O(1).
 * - remover01(): Estratégia 2 -> desloca todos os elementos posteriores uma posição à esquerda O(n).
 * 
 * DIVISÃO SUGERIDA PARA APRESENTAÇÃO EM GRUPO:
 * - Membro 1: Declaração da struct, vetor estático, controle de quantidade e busca (procura).
 * - Membro 2: Inserção desordenada e funções de exibição (mostrar e mostra).
 * - Membro 3: Estratégias de remoção (remover00 vs remover01) comparando complexidade e ordenação.
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CAPACIDADE 30
#define TAM_NOME 100

typedef struct aluno {
    int mat;
    char nome[TAM_NOME];
} Aluno;

/* Variáveis globais de controle da lista estática */
Aluno lista[CAPACIDADE];
int quantidade = 0; // Quantidade de elementos atualmente ocupados (0 a 29)

/* Protótipos das funções */
int procura(int mat);
void mostrar(int pos);
void mostra(void);
bool incluirDesordenado(Aluno e);
bool remover00(int mat);
bool remover01(int mat);

/**
 * [MEMBRO 1] PROCURA:
 * Busca linear pela matrícula no vetor lista.
 * Retorna o índice (0 a quantidade-1) se encontrado, ou -1 se não existir.
 * Complexidade: O(n).
 */
int procura(int mat) {
    for (int i = 0; i < quantidade; i++) {
        if (lista[i].mat == mat) {
            return i; // Encontrado no índice i
        }
    }
    return -1; // Não encontrado
}

/**
 * [MEMBRO 2] MOSTRAR:
 * Recebe uma posição e imprime os dados do aluno na tela se o índice for válido.
 */
void mostrar(int pos) {
    if (pos < 0 || pos >= quantidade) {
        printf("[AVISO] Posicao %d invalida ou inexistente.\n", pos);
        return;
    }
    printf("  -> Posicao [%02d] | Matricula: %4d | Nome: %s\n", pos, lista[pos].mat, lista[pos].nome);
}

/**
 * [MEMBRO 2] MOSTRA:
 * Percorre e exibe todos os elementos cadastrados na lista.
 */
void mostra(void) {
    printf("\n--- RELATORIO DA LISTA (%d/%d alunos cadastrados) ---\n", quantidade, CAPACIDADE);
    if (quantidade == 0) {
        printf("  [Lista vazia]\n");
        printf("---------------------------------------------------\n");
        return;
    }
    for (int i = 0; i < quantidade; i++) {
        mostrar(i);
    }
    printf("---------------------------------------------------\n");
}

/**
 * [MEMBRO 2] INCLUIR DESORDENADO:
 * Insere um novo aluno na primeira posição livre (lista[quantidade]).
 * Valida se a lista já atingiu a capacidade máxima e se a matrícula já existe.
 * Retorna true em caso de sucesso, false caso contrário.
 * Complexidade: O(1) se não verificar duplicidade, ou O(n) com procura.
 */
bool incluirDesordenado(Aluno e) {
    if (quantidade >= CAPACIDADE) {
        printf("[ERRO] Lista cheia! Nao eh possivel incluir o aluno %s.\n", e.nome);
        return false;
    }
    if (procura(e.mat) != -1) {
        printf("[ERRO] Matricula %d ja cadastrada! Aluno %s recusado.\n", e.mat, e.nome);
        return false;
    }
    lista[quantidade] = e;
    quantidade++;
    printf("[SUCESSO] Aluno %s (Mat: %d) incluido na posicao [%d].\n", e.nome, e.mat, quantidade - 1);
    return true;
}

/**
 * [MEMBRO 3] ESTRATÉGIA DE REMOÇÃO 1 (remover00):
 * Coloca o ÚLTIMO elemento da lista na posição do elemento removido.
 * VANTAGEM: Executa em tempo constante O(1), sem necessidade de deslocar outros elementos.
 * DESVANTAGEM: Não preserva a ordem relativa original dos dados.
 */
bool remover00(int mat) {
    int pos = procura(mat);
    if (pos == -1) {
        printf("[ERRO] Matricula %d nao encontrada para remocao (Estrategia 00).\n", mat);
        return false;
    }
    printf("[REMOVER-00] Removendo %s (Mat: %d) da posicao [%d].\n", lista[pos].nome, mat, pos);
    // Substitui o removido pelo último elemento cadastrado
    lista[pos] = lista[quantidade - 1];
    quantidade--; // Decrementa a quantidade
    return true;
}

/**
 * [MEMBRO 3] ESTRATÉGIA DE REMOÇÃO 2 (remover01):
 * Move TODOS os elementos que estão APÓS o elemento removido UMA POSIÇÃO À FRENTE (esquerda).
 * VANTAGEM: Preserva estritamente a ordem cronológica/relativa dos elementos na lista.
 * DESVANTAGEM: Executa em tempo linear O(n) no pior caso devido aos múltiplos deslocamentos.
 */
bool remover01(int mat) {
    int pos = procura(mat);
    if (pos == -1) {
        printf("[ERRO] Matricula %d nao encontrada para remocao (Estrategia 01).\n", mat);
        return false;
    }
    printf("[REMOVER-01] Removendo %s (Mat: %d) da posicao [%d] com deslocamento.\n", lista[pos].nome, mat, pos);
    for (int i = pos; i < quantidade - 1; i++) {
        lista[i] = lista[i + 1];
    }
    quantidade--;
    return true;
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 1 - PARTE 1: LISTA ESTATICA SEQUENCIAL (ARRAY)\n");
    printf("============================================================\n\n");

    /* Cadastro inicial de alunos */
    Aluno a1 = {101, "Ana Silva"};
    Aluno a2 = {202, "Bruno Costa"};
    Aluno a3 = {303, "Carla Souza"};
    Aluno a4 = {404, "Diego Lima"};
    Aluno a5 = {505, "Eduardo Santos"};

    incluirDesordenado(a1);
    incluirDesordenado(a2);
    incluirDesordenado(a3);
    incluirDesordenado(a4);
    incluirDesordenado(a5);

    mostra();

    /* Teste de busca */
    printf("\nTestando busca por matricula 303:\n");
    int pos = procura(303);
    mostrar(pos);

    /* Demonstração da Estratégia 1: remover00 (troca com o último) */
    printf("\n--- Teste da Estrategia 1 (remover00) ---\n");
    printf("Removendo Bruno Costa (Mat: 202). O ultimo aluno (Eduardo) ocupara seu lugar:\n");
    remover00(202);
    mostra();

    /* Demonstração da Estratégia 2: remover01 (deslocamento para manter ordem) */
    printf("\n--- Teste da Estrategia 2 (remover01) ---\n");
    printf("Removendo Carla Souza (Mat: 303). Todos os posteriores serao deslocados a esquerda:\n");
    remover01(303);
    mostra();

    return 0;
}
