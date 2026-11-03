/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 13
 * ============================================================================
 * 
 * ENUNCIADO:
 * 13. Considerando uma lista duplamente encadeada, IMPLEMENTE AS FUNÇÕES 
 *     QUE ESTÃO INCOMPLETAS NO CÓDIGO:
 *     - inserirNoInicio(struct No** cabeca, int dado)
 *     - exibirLista(struct No* no)
 *     - exibirLista_inv(struct No* no)
 * 
 * FUNDAMENTAÇÃO TEÓRICA:
 * - Em uma lista duplamente encadeada, cada nó possui dois ponteiros:
 *   * 'prox': aponta para o próximo nó da sequência (ou NULL se for o último).
 *   * 'prev': aponta para o nó anterior (ou NULL se for o primeiro).
 * - Ao inserir no início:
 *   * novo->prox aponta para a cabeça atual.
 *   * Se a lista não estava vazia, (*cabeca)->prev aponta para o novo nó.
 *   * A cabeça (*cabeca) é atualizada para o novo nó.
 * - Ao exibir invertida:
 *   * Caminha-se até o último nó da lista via ponteiro 'prox'.
 *   * A partir dele, volta-se até a cabeça navegando pelo ponteiro 'prev'.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Define a estrutura do nó
struct No {
    int dado;
    struct No* prox;
    struct No* prev;
};

// Função para criar um novo nó
struct No* novoNo(int dado) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    if (no == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    no->dado = dado;
    no->prox = NULL;
    no->prev = NULL;
    return no;
}

// Complete a Função para inserir um nó no início da lista
void inserirNoInicio(struct No** cabeca, int dado) {
    struct No* no = novoNo(dado);

    // Se a lista já possuía elementos, o antigo primeiro aponta 'prev' para o novo nó
    if (*cabeca != NULL) {
        (*cabeca)->prev = no;
        no->prox = *cabeca;
    }

    // A cabeça da lista passa a ser o novo nó
    *cabeca = no;
}

// Complete a Função para exibir a lista do inicio até o final
void exibirLista(struct No* no) {
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->prox;
    }
    printf("\n");
}

// Complete a Função para exibir a lista invertida (final até o inicio)
void exibirLista_inv(struct No* no) {
    if (no == NULL) {
        printf("[Lista vazia]\n");
        return;
    }

    // 1. Percorre até o último nó da lista
    while (no->prox != NULL) {
        no = no->prox;
    }

    printf("Exibicao reversa (final ate o inicio): ");
    // 2. Volta do final até o início usando os ponteiros 'prev'
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->prev;
    }
    printf("\n");
}

// Função principal
int main() {
    printf("============================================================\n");
    printf("QUESTAO 13 - LISTA DUPLAMENTE ENCADEADA COMPLETA\n");
    printf("============================================================\n\n");

    struct No* cabeca = NULL;

    inserirNoInicio(&cabeca, 10);
    inserirNoInicio(&cabeca, 20);
    inserirNoInicio(&cabeca, 30);

    printf("Conteúdo da lista duplamente encadeada: ");
    exibirLista(cabeca);

    exibirLista_inv(cabeca);

    /* Liberação da memória */
    struct No* atual = cabeca;
    while (atual != NULL) {
        struct No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
