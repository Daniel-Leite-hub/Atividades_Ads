/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 14
 * ============================================================================
 * 
 * ENUNCIADO:
 * 14. Implementação Pilha usando uma classe Nó:
 *     Completar os métodos da classe Pilha:
 *     - Pilha(): construtor que inicializa topo como NULL
 *     - push(char n): empilha o caractere no topo
 *     - pop(): desempilha e retorna o caractere do topo
 *     - isEmpty(): verifica se o topo é NULL
 *     - main(): desempilhar e mostrar os itens desempilhados
 * ============================================================================
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// usando uma classe No
class No {
public:
    char nome;
    No *prox;

    No(char n) {
        nome = n;
        prox = NULL;
    }
};

class Pilha {
public:
    No *topo;

    Pilha() {
        topo = NULL;
    }

    void push(char n) {
        No *novo = new No(n);
        novo->prox = topo; // O novo nó aponta para o antigo topo
        topo = novo;       // O topo passa a ser o novo nó
        cout << "[PUSH] Elemento '" << n << "' inserido no topo." << endl;
    }

    char pop() {
        if (isEmpty()) {
            cout << "[ERRO] Pilha vazia!" << endl;
            return '\0';
        }
        No *temp = topo;
        char n = temp->nome;
        topo = topo->prox; // Atualiza o topo para o próximo nó
        delete temp;       // Libera o nó desempilhado
        return n;
    }

    int isEmpty() {
        return (topo == NULL);
    }

    ~Pilha() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    printf("============================================================\n");
    printf("QUESTAO 14 - PILHA DINAMICA COM CLASSE NO EM C++\n");
    printf("============================================================\n\n");

    Pilha *p = new Pilha();

    cout << "1. Empilhando itens: 'A', 'B', 'C'" << endl;
    p->push('A');
    p->push('B');
    p->push('C');

    cout << "\n2. Desempilhando e mostrando os itens (Ordem LIFO: C, B, A):" << endl;
    while (!p->isEmpty()) {
        char item = p->pop();
        cout << "Item desempilhado: " << item << endl;
    }

    delete p;
    return 0;
}
