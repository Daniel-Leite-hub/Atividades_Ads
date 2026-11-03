/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * CURSO: Análise e Desenvolvimento de Sistemas (ADS)
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * PROVA 1 - QUESTÃO 6
 * ============================================================================
 * 
 * ENUNCIADO:
 * Verifique o código e escolha a alternativa verdadeira.
 * 
 * ANÁLISE DOS MÉTODOS:
 * - m1(novo): Insere mantendo a ordenação por código (desloca elementos maiores).
 * - m2(novo): Insere diretamente no FINAL do vetor na posição 'ultimo', SEM DESLOCAR 
 *             nenhum elemento existente (0 elementos têm sua posição modificada).
 * - m3(cod) : Busca linear de um livro pelo código.
 * - m4()    : Imprime todos os livros cadastrados de 0 até ultimo-1.
 * - m5(novo, posicao): Insere o livro na posição indicada ('posicao'), deslocando 
 *             para a direita todos os elementos do índice 'posicao' até 'ultimo-1'.
 * 
 * RASTREAMENTO DA FUNÇÃO MAIN():
 * 1. Inserção de (8, "Aprendendo a programar em C") via m2(novo):
 *    - Vetor no índice [0] = 8. 'ultimo' passa a 1.
 *    - Nenhum elemento foi deslocado.
 * 
 * 2. Inserção de (6, "Fundamentos em Estrutura de Dados") via m2(novo):
 *    - Vetor no índice [1] = 6. 'ultimo' passa a 2.
 *    - Nenhum elemento foi deslocado.
 * 
 * 3. Inserção de (10, "Aprendendo a Programar em Python") via m2(novo):
 *    - Vetor no índice [2] = 10. 'ultimo' passa a 3.
 *    - Nenhum elemento foi deslocado.
 * 
 * 4. m4() imprime os 3 livros presentes nos índices 0, 1 e 2.
 * 
 * 5. Chamada de m5(novo, 2) com novo = (4, "Aprendendo Estrutura de Dados II"):
 *    - Parâmetros recebidos: posicao = 2.
 *    - Variável global 'ultimo' = 3.
 *    - Laço de deslocamento:
 *      for (int i = ultimo; i > posicao; i--) => for (int i = 3; i > 2; i--)
 *      * Passo i = 3: (3 > 2 é VERDADEIRO):
 *        livros[3] = livros[2]; // O livro da posição 2 (cod 10) é movido para o índice 3.
 *      * Próximo passo i = 2: (2 > 2 é FALSO) => O LAÇO TERMINA!
 *    - livros[2] recebe o novo livro (cod 4).
 *    - 'ultimo' passa a 4.
 *    - CONCLUSÃO: EXATAMENTE UM elemento teve sua posição modificada (o elemento do índice 2).
 * 
 * ANÁLISE DAS ALTERNATIVAS:
 * a.( ) Incorreta: m2 insere no final, não modifica a posição de nenhum elemento existente.
 * b.( ) Incorreta: m5 deslocou apenas 1 elemento (o do índice 2), e não dois.
 * c.( ) Incorreta: m2 insere no final, não modifica a posição de todos os elementos.
 * d.( X ) Para posicionar o elemento novo (4,"Aprendendo Estrutura de Dados II") 
 *         na lista de livros o algoritmo m5 vai modificar a posição de somente um elemento.
 *         -> EXATAMENTE VERDADEIRO!
 * 
 * ============================================================================
 * ALTERNATIVA CORRETA: D
 * ============================================================================
 */

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct livro {
    int cod;
    string nome;
};

typedef struct livro Tlivro;

Tlivro livros[5];
int ultimo = 0;

/* m1: Inserção ordenada */
void m1(Tlivro novo) {
    if (ultimo < 5) {
        int p = -1;
        if (ultimo == 0) {
            livros[0] = novo;
            ultimo++;
        } else {
            for (int i = 0; i < ultimo; i++) {
                if (novo.cod < livros[i].cod) {
                    p = i;
                    break;
                }
            }
            if (p == -1) {
                livros[ultimo] = novo;
                ultimo++;
            } else {
                for (int i = ultimo; i > p; i--) {
                    livros[i] = livros[i - 1];
                }
                livros[p] = novo;
                ultimo++;
            }
        }
    } else {
        printf("\nBiblioteca lotada\n");
    }
}

/* m2: Inserção no final (append) - NÃO desloca nenhum elemento */
void m2(Tlivro novo) {
    if (ultimo < 5) {
        livros[ultimo].cod = novo.cod;
        livros[ultimo].nome = novo.nome;
        ultimo++;
    } else {
        printf("\nBiblioteca lotada!!!\n");
    }
}

/* m3: Busca sequencial por código */
int m3(int codigo) {
    int p = -1;
    for (int i = 0; i < ultimo; i++) {
        if (livros[i].cod == codigo) {
            p = i;
            break;
        }
    }
    return p;
}

/* m4: Exibição dos livros */
void m4() {
    printf("\n--- Relatorio de Livros Cadastrados ---");
    for (int i = 0; i < ultimo; i++) {
        printf("\nIndice [%d] -> Codigo: %d | Nome: %s", i, livros[i].cod, livros[i].nome.c_str());
    }
    printf("\n---------------------------------------\n");
}

/* m5: Inserção em posição específica com contagem explícita de deslocamentos */
int m5_com_contador(Tlivro novo, int posicao) {
    int elementos_modificados = 0;
    if (ultimo >= 5) {
        printf("Biblioteca lotada\n");
        return 0;
    } else {
        printf("\nExecutando m5(novo, posicao = %d) com ultimo = %d:\n", posicao, ultimo);
        for (int i = ultimo; i > posicao; i--) {
            printf(" -> Deslocando elemento do indice [%d] para [%d] (Cod: %d)\n", 
                   i - 1, i, livros[i - 1].cod);
            livros[i].cod = livros[i - 1].cod;
            livros[i].nome = livros[i - 1].nome;
            elementos_modificados++;
        }
        livros[posicao] = novo;
        ultimo++;
    }
    return elementos_modificados;
}

int main() {
    printf("============================================================\n");
    printf("RESPOSTA DA QUESTAO 6:\n");
    printf("GABARITO: ALTERNATIVA D\n");
    printf("============================================================\n");

    Tlivro novo;

    /* 1º Livro */
    novo.cod = 8;
    novo.nome = "Aprendendo a programar em C";
    m2(novo);

    /* 2º Livro */
    novo.cod = 6;
    novo.nome = "Fundamentos em Estrutura de Dados";
    m2(novo);

    /* 3º Livro */
    novo.cod = 10;
    novo.nome = "Aprendendo a Programar em Python";
    m2(novo);

    m4();

    /* 4º Livro: Inserção com m5 na posição 2 */
    novo.cod = 4;
    novo.nome = "Aprendendo Estrutura de Dados II";
    int deslocados = m5_com_contador(novo, 2);

    m4();

    printf("\nTotal de elementos que tiveram sua posicao modificada pelo algoritmo m5: %d\n", deslocados);
    printf("Portanto, comprova-se que a Alternativa D eh a unica VERDADEIRA.\n");

    return 0;
}
