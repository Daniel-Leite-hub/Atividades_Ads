/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 1
 * ============================================================================
 * 
 * ENUNCIADO:
 * Preencha de acordo com a correspondência:
 * ( 1 ) lista circular
 * ( 2 ) pilha
 * ( 3 ) fila
 * ( 4 ) lista duplamente encadeada
 * ( 5 ) lista simplesmente encadeada
 * 
 * a. ( ) Para remover o último elemento de uma _______________________, apesar
 *        de já sabermos quem é este elemento, é necessário percorrer os n 
 *        elementos da lista e parar a frente do último elemento para só então 
 *        poder removê-lo, pois não existe acesso imediato aos seus predecessores. 
 *        Portanto, o algoritmo para remover o último nó da lista realiza n comparações.
 *        -> RESPOSTA: ( 5 ) Lista simplesmente encadeada.
 *           JUSTIFICATIVA: Como o encadeamento é unidirecional (apenas ponteiro prox),
 *           para remover o último nó precisamos atualizar o ponteiro 'prox' do
 *           penúltimo nó para NULL. Sem ponteiro para o nó anterior, é mandatório
 *           percorrer a lista desde o início até o penúltimo elemento, realizando O(n) passos.
 * 
 * b. ( ) Em uma _____________________________, sabendo-se que a acessibilidade 
 *        do último nó é imediata, o algoritmo para remover o último nó da lista 
 *        é executado apenas com um acesso a lista (em tempo constante).
 *        -> RESPOSTA: ( 4 ) Lista duplamente encadeada.
 *           JUSTIFICATIVA: Com ponteiro direto para o fim ('fim' ou 'tail') e 
 *           ponteiros bidirecionais ('ant' / 'prev'), podemos acessar o nó anterior 
 *           imediatamente via fim->ant em tempo O(1) (constante), sem percorrer a lista.
 * 
 * c. ( ) Um exemplo de sua aplicação é quando diversos processos estão usando 
 *        os mesmos recursos ao mesmo tempo e temos de assegurar que nenhum 
 *        processo acesse o recurso antes de todos os outros processos. Os 
 *        processos são colocados em uma ____________________________, acessíveis 
 *        através do ponteiro "corrente". Depois que um nó da lista é acessado e o 
 *        número do processo é recuperado do nó para ativar esse processo, o 
 *        ponteiro "corrente" se move para o próximo nó de modo que o próximo 
 *        processo possa ser ativado a seguir.
 *        -> RESPOSTA: ( 1 ) Lista circular.
 *           JUSTIFICATIVA: Descreve o clássico escalonamento Round-Robin de 
 *           sistemas operacionais, onde o último nó aponta de volta para o primeiro, 
 *           formando um ciclo contínuo percorrido pelo ponteiro corrente.
 * 
 * d. ( ) Uma ____________ é uma estrutura linear de dados que pode ser acessada 
 *        somente por uma de suas extremidades para armazenar e recuperar dados.
 *        -> RESPOSTA: ( 2 ) Pilha.
 *           JUSTIFICATIVA: Segue o princípio LIFO (Last-In, First-Out). Todas as 
 *           inserções (push) e remoções (pop) ocorrem em uma única extremidade: o topo.
 * 
 * e. ( ) Uma ____________ é uma linha de espera que cresce somando elementos ao 
 *        seu final e que diminui tomando elementos de sua frente, desta forma, 
 *        ambas as extremidades são utilizadas.
 *        -> RESPOSTA: ( 3 ) Fila.
 *           JUSTIFICATIVA: Segue a política FIFO (First-In, First-Out). A inserção 
 *           (enqueue) ocorre no final/cauda e a remoção (dequeue) na frente/cabeça.
 * 
 * ============================================================================
 * CORRESPONDÊNCIA FINAL:
 * a -> 5
 * b -> 4
 * c -> 1
 * d -> 2
 * e -> 3
 * 
 * ALTERNATIVA CORRETA: B (A-5 B-4 C-1 D-2 E-3)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Demonstração didática das estruturas citadas */

/* 1. Nó para Lista Simplesmente Encadeada */
typedef struct NoSimples {
    int dado;
    struct NoSimples *prox;
} NoSimples;

/* 2. Nó para Lista Duplamente Encadeada */
typedef struct NoDuplo {
    int dado;
    struct NoDuplo *ant;
    struct NoDuplo *prox;
} NoDuplo;

/* Demonstração da remoção em Lista Simples (necessita percorrer até o penúltimo) */
void demonstrarRemocaoSimples() {
    printf("--- [Item a] Lista Simplesmente Encadeada ---\n");
    printf("Para remover o ultimo elemento de uma lista simplesmente encadeada,\n");
    printf("precisamos caminhar com um ponteiro 'atual' ate o penultimo no,\n");
    printf("pois nao ha ponteiro de volta ('ant'). Complexidade: O(n).\n\n");
}

/* Demonstração da remoção em Lista Dupla (tempo constante O(1)) */
void demonstrarRemocaoDupla() {
    printf("--- [Item b] Lista Duplamente Encadeada ---\n");
    printf("Tendo o ponteiro 'fim', o penultimo no eh acessado imediatamente via fim->ant.\n");
    printf("Portanto, a remocao do ultimo no eh realizada em tempo constante O(1).\n\n");
}

/* Demonstração da Lista Circular */
void demonstrarListaCircular() {
    printf("--- [Item c] Lista Circular ---\n");
    printf("Ideal para escalonamento Round-Robin de processos:\n");
    printf("P1 -> P2 -> P3 -> volta para P1... ponteiro corrente gira ciclicamente.\n\n");
}

/* Demonstração da Pilha e Fila */
void demonstrarPilhaEFila() {
    printf("--- [Item d] Pilha (LIFO) ---\n");
    printf("Acesso restrito a uma unica extremidade: o TOPO (push e pop).\n\n");

    printf("--- [Item e] Fila (FIFO) ---\n");
    printf("Utiliza ambas as extremidades: insercao no FIM e remocao na FRENTE.\n\n");
}

int main() {
    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 1:\n");
    printf("GABARITO: ALTERNATIVA B (A-5 B-4 C-1 D-2 E-3)\n");
    printf("============================================================\n\n");

    demonstrarRemocaoSimples();
    demonstrarRemocaoDupla();
    demonstrarListaCircular();
    demonstrarPilhaEFila();

    return 0;
}
