/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 15
 * ============================================================================
 * 
 * ENUNCIADO:
 * 15. Implementação Fila usando uma classe Nó:
 *     Completar os métodos da classe Fila:
 *     - Fila(): inicializa inicio e fim como NULL
 *     - inserir(char n): enfileira no fim da fila
 *     - apagar(): desenfileira do início da fila
 *     - isEmpty(): verifica se inicio é NULL
 *     - apagaTodos(): esvazia toda a fila
 *     - main(): desenfileirar e mostrar os itens desenfileirados
 * ============================================================================
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

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

class Fila {
public:
    No *inicio;
    No *fim;

    Fila() {
        inicio = NULL;
        fim = NULL;
    }

    void inserir(char n) {
        No *novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        cout << "[INSERIR] Elemento '" << n << "' enfileirado no fim." << endl;
    }

    char apagar() {
        if (isEmpty()) {
            cout << "[ERRO] Fila vazia!" << endl;
            return '\0';
        }
        No *temp = inicio;
        char nome = temp->nome;
        inicio = inicio->prox;
        if (inicio == NULL) {
            fim = NULL;
        }
        delete temp;
        return nome;
    }

    bool isEmpty() {
        return (inicio == NULL);
    }

    void apagaTodos() {
        while (!isEmpty()) {
            apagar();
        }
        cout << "[INFO] Todos os elementos da fila foram removidos." << endl;
    }

    ~Fila() {
        apagaTodos();
    }
};

int main() {
    printf("============================================================\n");
    printf("QUESTAO 15 - FILA DINAMICA COM CLASSE NO EM C++\n");
    printf("============================================================\n\n");

    Fila *f1 = new Fila();
    Fila *f2 = new Fila();

    cout << "1. Enfileirando itens em f1: 'A', 'B', 'C'" << endl;
    f1->inserir('A');
    f1->inserir('B');
    f1->inserir('C');

    cout << "\n2. Desenfileirando e mostrando os itens (Ordem FIFO: A, B, C):" << endl;
    while (!f1->isEmpty()) {
        char item = f1->apagar();
        cout << "Item desenfileirado: " << item << endl;
    }

    cout << "\n3. Testando metodo apagaTodos() em f2:" << endl;
    f2->inserir('X');
    f2->inserir('Y');
    f2->inserir('Z');
    f2->apagaTodos();
    cout << "f2 esta vazia? " << (f2->isEmpty() ? "SIM" : "NAO") << endl;

    delete f1;
    delete f2;
    return 0;
}
