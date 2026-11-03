/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 5
 * ============================================================================
 * 
 * ENUNCIADO:
 * O código define a classe 'No' e a classe 'X', onde:
 * - insereX(n) insere no fim da estrutura (comportamento de FILA).
 * - retiraX() retira do início da estrutura (comportamento de FILA).
 * 
 * Na função main(), são instanciadas duas filas: l1 e l2.
 * A lógica de inserção quando l1 já possui elementos é:
 * 1. Despejar todos os elementos de l1 para l2:
 *       while (l1->vaziaX() != 1) l2->insereX(l1->retiraX());
 * 2. Inserir a nova letra em l1 (ficando ela sozinha no início):
 *       l1->insereX(letra);
 * 3. Devolver todos os elementos de l2 para l1 (ficando atrás da nova letra):
 *       while (l2->vaziaX() != 1) l1->insereX(l2->retiraX());
 * 
 * Este algoritmo é a implementação clássica de uma PILHA (LIFO) usando DUAS FILAS (FIFO)!
 * O elemento mais recentemente inserido fica sempre na cabeça/início de l1.
 * 
 * RASTREAMENTO PASSO A PASSO COM A ENTRADA FORNECIDA:
 * ----------------------------------------------------------------------------
 * Entrada: 'A', depois 'B', depois 'C', depois 'D'.
 * 
 * Passo 1 (Letra 'A'):
 * - l1 estava vazia -> insere 'A'.
 * - Estado de l1: [A]
 * 
 * Passo 2 (Letra 'B'):
 * - Move 'A' de l1 para l2 -> l2: [A], l1: []
 * - Insere 'B' em l1       -> l1: [B]
 * - Devolve 'A' de l2 p/ l1-> l1: [B, A]
 * 
 * Passo 3 (Letra 'C'):
 * - Move 'B', 'A' p/ l2    -> l2: [B, A], l1: []
 * - Insere 'C' em l1       -> l1: [C]
 * - Devolve 'B', 'A' p/ l1 -> l1: [C, B, A]
 * 
 * Passo 4 (Letra 'D'):
 * - Move 'C', 'B', 'A' p/ l2 -> l2: [C, B, A], l1: []
 * - Insere 'D' em l1         -> l1: [D]
 * - Devolve 'C','B','A' p/ l1-> l1: [D, C, B, A]
 * 
 * Saída produzida por l1->mostra():
 * Nome D
 * Nome C
 * Nome B
 * Nome A
 * 
 * ============================================================================
 * ALTERNATIVA CORRETA: C
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No {
public:
    char nome;
    No *prox;
    No(char n) {
        nome = n;
        prox = NULL;
    }
};

class X {
public:
    No *inicio;
    No *fim;

    X() {
        inicio = NULL;
        fim = NULL;
    }

    /* Insere no fim (comportamento de Fila) */
    void insereX(char n) {
        No *novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    /* Retira do inicio (comportamento de Fila) */
    char retiraX() {
        No *el;
        char nome = '\0';
        if (inicio != NULL) {
            el = inicio;
            nome = el->nome;
            inicio = inicio->prox;
            delete el; // no código original usa free(el); delete é o par de new
        }
        return nome;
    }

    int vaziaX() {
        return (inicio == NULL);
    }

    void mostra() {
        No *temp;
        cout << "\n-------- Mostra ---------------\n";
        while (inicio != NULL) {
            temp = inicio;
            printf("Nome %c\n", inicio->nome);
            inicio = inicio->prox;
            delete temp;
        }
    }
};

/* Função simulando exatamente o comportamento da questão com a entrada A, B, C, D */
void simularExecucaoAutomatica() {
    X *l1 = new X();
    X *l2 = new X();

    char entradas[] = {'A', 'B', 'C', 'D'};
    int total = 4;

    for (int i = 0; i < total; i++) {
        char letra = entradas[i];
        if (l1->vaziaX() == 1) {
            l1->insereX(letra);
        } else {
            while (l1->vaziaX() != 1) {
                l2->insereX(l1->retiraX());
            }
            l1->insereX(letra);
            while (l2->vaziaX() != 1) {
                l1->insereX(l2->retiraX());
            }
        }
    }

    /* Exibe o resultado que comprova a Alternativa C */
    l1->mostra();

    delete l1;
    delete l2;
}

int main() {
    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 5:\n");
    printf("GABARITO: ALTERNATIVA C (Nome D, Nome C, Nome B, Nome A)\n");
    printf("============================================================\n");

    printf("\nExecutando simulacao com as entradas A, B, C, D:\n");
    simularExecucaoAutomatica();

    return 0;
}
