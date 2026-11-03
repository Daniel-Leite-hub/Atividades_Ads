/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 8
 * ============================================================================
 * 
 * ENUNCIADO:
 * Sobre o código da classe genérica 'Lista<T>', verifique se as afirmações 
 * são Verdadeiras ou Falsas e marque a alternativa correta:
 * 
 * ANÁLISE DOS MÉTODOS DA CLASSE:
 * - Lista(): Construtor inicializa 'inicio' e 'fim' como NULL.
 * - x(T *ele): Inserção no FINAL da lista:
 *              Se inicio == NULL: inicio = fim = ele;
 *              Senão: fim->prox = ele; fim = fim->prox;
 * - w(): Retorna se a lista está vazia (inicio == NULL).
 * - y(): Percorre a lista desalocando os nós com free(atual) (esvazia/destrói a lista).
 * 
 * ANÁLISE DAS AFIRMAÇÕES:
 * 
 * A. ( V ) O algoritmo implementa uma lista simplesmente encadeada.
 *          -> VERDADEIRA: A estrutura possui apenas encadeamento simples para frente 
 *             através do membro 'prox'. Não há ponteiros de retorno ('ant' / 'prev').
 * 
 * B. ( F ) O algoritmo implementa uma lista duplamente encadeada.
 *          -> FALSA: Uma lista duplamente encadeada requer dois ponteiros por nó 
 *             ('ant' e 'prox'), o que não existe aqui.
 * 
 * C. ( V ) O método "x" inclui um elemento novo do tipo genérico "T" ao final da lista.
 *          -> VERDADEIRA: O código 'fim->prox = ele; fim = fim->prox;' anexa o 
 *             novo elemento após o último nó atual e avança o ponteiro 'fim'.
 * 
 * D. ( F ) O método "x" inclui um elemento novo do tipo genérico "T" no início da lista.
 *          -> FALSA: A inserção no início alteraria o ponteiro 'inicio' (ex: ele->prox = inicio; inicio = ele), 
 *             o que não ocorre aqui (exceto no caso trivial de lista vazia).
 * 
 * E. ( V ) “T” é um valor genérico que, no momento da criação do objeto tipo Lista, 
 *          pode ser definido de qualquer tipo, como no exemplo: Lista<int> *l1=new Lista<int>();
 *          -> VERDADEIRA (no contexto teórico do enunciado sobre 'template<class T>'):
 *             Representa a sintaxe e o propósito conceitual dos Templates em C++, onde 
 *             o parâmetro T pode assumir qualquer tipo no momento da instanciação.
 *             [Nota prática: Em tempo de compilação, para que o código do template compile, 
 *              o tipo T deve conter o membro ponteiro 'prox', como uma struct/classe Node].
 * 
 * ============================================================================
 * CLASSIFICAÇÃO: A-V, B-F, C-V, D-F, E-V
 * ALTERNATIVA CORRETA: A (a. A-V B-F C-V D-F E-V)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* 
 * Estrutura representando um nó compatível com o template da questão,
 * contendo o atributo 'prox' e uma carga útil (dado).
 */
struct No {
    int valor;
    No *prox;
    No(int v) : valor(v), prox(NULL) {}
};

template<class T>
class Lista {
public:
    T *inicio;
    T *fim;

    Lista() {
        inicio = NULL;
        fim = NULL;
    }

    /* Método 'x': Inclusão ao FINAL da lista */
    void x(T *ele) {
        if (inicio == NULL) {
            inicio = ele;
            fim = ele;
        } else {
            fim->prox = ele;
            fim = fim->prox;
        }
    }

    /* Método 'w': Verifica se está vazia */
    int w() {
        return (inicio == NULL);
    }

    /* Método 'y': Libera todos os nós da lista */
    void y() {
        T *atual = inicio;
        T *proximo = NULL;
        while (atual != NULL) {
            proximo = atual->prox;
            delete atual; // no original usa free(atual)
            atual = proximo;
        }
        inicio = atual;
        fim = NULL;
    }

    /* Método auxiliar para imprimir a lista */
    void imprimir() {
        T *atual = inicio;
        cout << "Lista: ";
        while (atual != NULL) {
            cout << "[" << atual->valor << "] -> ";
            atual = atual->prox;
        }
        cout << "NULL\n";
    }
};

int main() {
    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 8:\n");
    printf("CLASSIFICACAO: A-V, B-F, C-V, D-F, E-V\n");
    printf("GABARITO: ALTERNATIVA A\n");
    printf("============================================================\n\n");

    Lista<No> *minhaLista = new Lista<No>();

    printf("1. Verificando se a lista esta vazia com w(): %s\n", minhaLista->w() ? "SIM" : "NAO");

    printf("\n2. Inserindo elementos no final com metodo x():\n");
    minhaLista->x(new No(100));
    minhaLista->imprimir();

    minhaLista->x(new No(200));
    minhaLista->imprimir();

    minhaLista->x(new No(300));
    minhaLista->imprimir();

    printf("\n3. Esvaziando a lista com o metodo y():\n");
    minhaLista->y();
    printf("Apos y(), a lista esta vazia? %s\n", minhaLista->w() ? "SIM" : "NAO");

    delete minhaLista;
    return 0;
}
