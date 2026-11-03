/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 4
 * ============================================================================
 * 
 * ENUNCIADO:
 * Considerando a estrutura abaixo, qual comando insere um novo nó no início 
 * da lista encadeada?
 * 
 * typedef struct Node {
 *     int data;
 *     struct Node *next;
 * } Node;
 * Node *head = NULL;
 * main() {
 *     Node *newNode = (Node*)malloc(sizeof(Node));
 *     newNode->data = 10;
 * }
 * 
 * ANÁLISE DAS ALTERNATIVAS:
 * 
 * a.( x ) newNode->next = head;
 *         head = newNode;
 *         -> CORRETO! 
 *            Passo 1: Faz o novo nó apontar para quem 'head' apontava (o antigo primeiro elemento).
 *            Passo 2: Atualiza a cabeça da lista 'head' para apontar para o novo nó.
 *            Dessa forma, nenhum nó anterior é perdido e a inserção é feita no início em O(1).
 * 
 * b.( ) head->next = newNode;
 *       newNode = head;
 *       -> INCORRETO: Se head for NULL (lista vazia), 'head->next' causará falha de segmentação 
 *          (Segmentation Fault / NullPointerException). Além disso, não insere no início.
 * 
 * c.( ) newNode = head;
 *       head->next = newNode;
 *       -> INCORRETO: Sobrescreve o ponteiro 'newNode' com 'head', perdendo a referência 
 *          ao nó recém-alocado na memória (gerando vazamento de memória / memory leak).
 * 
 * d.( ) head = newNode;
 *       newNode->next = NULL;
 *       -> INCORRETO: Ao fazer 'head = newNode' primeiro, perde-se o endereço de todos os nós 
 *          que já existiam na lista, e ao forçar 'newNode->next = NULL', a lista conteria 
 *          apenas este nó, desconectando qualquer elemento pré-existente.
 * 
 * ============================================================================
 * ALTERNATIVA CORRETA: A
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Ponteiro para o início da lista */
Node *head = NULL;

/* Função de inserção no início conforme a Alternativa A */
void inserirNoInicio(int valor) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = valor;

    /* OS DOIS COMANDOS DA ALTERNATIVA A: */
    newNode->next = head; // 1. O novo nó aponta para o atual início
    head = newNode;       // 2. A cabeça passa a ser o novo nó
}

/* Função para imprimir a lista encadeada */
void imprimirLista() {
    Node *atual = head;
    printf("Lista atual: ");
    while (atual != NULL) {
        printf("[%d] -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL\n");
}

int main() {
    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 4:\n");
    printf("GABARITO: ALTERNATIVA A\n");
    printf("============================================================\n\n");

    printf("Inserindo elementos sucessivamente no inicio:\n");

    /* Simulação: inserindo 30, depois 20, depois 10 */
    inserirNoInicio(30);
    imprimirLista();

    inserirNoInicio(20);
    imprimirLista();

    inserirNoInicio(10);
    imprimirLista();

    printf("\nObserve que cada novo no inserido passa a ser o primeiro elemento (head).\n");

    /* Liberação da memória */
    Node *atual = head;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
