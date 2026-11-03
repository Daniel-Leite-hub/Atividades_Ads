/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 1 (PARTE 2: LISTA DINÂMICA ENCADEADA)
 * ============================================================================
 * 
 * ENUNCIADO:
 * 1. Para os dois códigos sobre lista estática e lista dinâmica enviados (completar).
 *    Obs: os integrantes do grupo devem se dividir para explicar partes do código.
 * 
 * ESTRUTURA DO CÓDIGO DA LISTA DINÂMICA:
 * Implementa uma lista simplesmente encadeada com alocação dinâmica de nós (struct No):
 * - no(int x, Lista p): aloca memória dinamicamente via malloc e conecta o nó.
 * - inserirNoInicio(Lista *L, int x): insere na cabeça da lista em O(1).
 * - inserirNoFim(Lista *L, int x): percorre até o último nó e conecta em O(n).
 * - buscar(Lista L, int x): busca linear de um elemento.
 * - remover(Lista *L, int x): desvincula o nó e libera memória com free().
 * - exibe(Lista L): percurso iterativo exibindo os nós.
 * - libera_lista(Lista *L): desaloca todos os nós da memória evitando memory leaks.
 * 
 * DIVISÃO SUGERIDA PARA APRESENTAÇÃO EM GRUPO:
 * - Membro 1: Alocação dinâmica de memória, struct No e função construtora 'no()'.
 * - Membro 2: Inserção no início vs inserção no fim e função de exibição/percurso.
 * - Membro 3: Remoção de nós específicos, religamento de ponteiros e liberação geral (free).
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int item;
    struct No *prox;
} No;

typedef No* Lista;

/**
 * [MEMBRO 1] CRIAÇÃO DE NÓ:
 * Aloca memória para um novo nó dinamicamente.
 */
Lista no(int x, Lista p) {
    Lista novo = (Lista)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "[ERRO FATAL] Falha de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    novo->item = x;
    novo->prox = p;
    return novo;
}

/**
 * [MEMBRO 2] INSERÇÃO NO INÍCIO:
 * Cria um nó apontando para o antigo primeiro e atualiza a cabeça.
 * Complexidade: O(1).
 */
void inserirNoInicio(Lista *L, int x) {
    *L = no(x, *L);
    printf("[INSERIR INICIO] Elemento %d inserido na cabeca da lista.\n", x);
}

/**
 * [MEMBRO 2] INSERÇÃO NO FIM:
 * Percorre até o último nó existente e anexa o novo nó.
 * Complexidade: O(n).
 */
void inserirNoFim(Lista *L, int x) {
    Lista novo = no(x, NULL);
    if (*L == NULL) {
        *L = novo;
    } else {
        Lista atual = *L;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    printf("[INSERIR FIM] Elemento %d inserido no final da lista.\n", x);
}

/**
 * [MEMBRO 2] EXIBIÇÃO:
 * Percorre a lista sequencialmente do início ao fim exibindo os elementos.
 */
void exibe(Lista L) {
    printf("Lista: ");
    Lista p = L;
    while (p != NULL) {
        printf("[%d] -> ", p->item);
        p = p->prox;
    }
    printf("NULL\n");
}

/**
 * [MEMBRO 3] BUSCA:
 * Procura um valor na lista dinâmica.
 */
bool buscar(Lista L, int x) {
    for (Lista p = L; p != NULL; p = p->prox) {
        if (p->item == x) return true;
    }
    return false;
}

/**
 * [MEMBRO 3] REMOÇÃO DE VALOR ESPECÍFICO:
 * Localiza o nó, religa o ponteiro anterior ao sucessor e libera a memória com free().
 */
bool remover(Lista *L, int x) {
    if (*L == NULL) return false;

    Lista atual = *L;
    Lista anterior = NULL;

    while (atual != NULL && atual->item != x) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("[AVISO] Elemento %d nao encontrado na lista para remocao.\n", x);
        return false;
    }

    if (anterior == NULL) {
        // Remoção do primeiro nó
        *L = atual->prox;
    } else {
        // Pula o nó atual
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("[REMOVIDO] Elemento %d desalocado da memoria com sucesso.\n", x);
    return true;
}

/**
 * [MEMBRO 3] LIBERAÇÃO COMPLETA:
 * Desaloca recursiva/iterativamente todos os nós alocados para evitar memory leak.
 */
void libera_lista(Lista *L) {
    Lista atual = *L;
    while (atual != NULL) {
        Lista proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *L = NULL;
}

int main(void) {
    printf("============================================================\n");
    printf("QUESTAO 1 - PARTE 2: LISTA DINAMICA SIMPLESMENTE ENCADEADA\n");
    printf("============================================================\n\n");

    Lista minhaLista = NULL;

    printf("1. Inserindo elementos no inicio:\n");
    inserirNoInicio(&minhaLista, 30);
    inserirNoInicio(&minhaLista, 20);
    inserirNoInicio(&minhaLista, 10);
    exibe(minhaLista);

    printf("\n2. Inserindo elementos no fim:\n");
    inserirNoFim(&minhaLista, 40);
    inserirNoFim(&minhaLista, 50);
    exibe(minhaLista);

    printf("\n3. Buscando elementos:\n");
    printf("Buscar 30: %s\n", buscar(minhaLista, 30) ? "ENCONTRADO" : "NAO ENCONTRADO");
    printf("Buscar 99: %s\n", buscar(minhaLista, 99) ? "ENCONTRADO" : "NAO ENCONTRADO");

    printf("\n4. Removendo elementos (inicio, meio e fim):\n");
    remover(&minhaLista, 10); // Remove inicio
    exibe(minhaLista);

    remover(&minhaLista, 30); // Remove meio
    exibe(minhaLista);

    remover(&minhaLista, 50); // Remove fim
    exibe(minhaLista);

    printf("\n5. Liberando toda a lista da memoria:\n");
    libera_lista(&minhaLista);
    exibe(minhaLista);

    return 0;
}
