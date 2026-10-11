// Questao 16 - Estruturas de dados: fila e pilha na biblioteca padrao do C++.
// Este arquivo e C++ (.cpp), pois std::queue e std::stack nao existem em C.
// Os comentarios e a saida usam caracteres ASCII para facilitar o terminal.

#include <iostream>  // Disponibiliza std::cout para escrever na tela.
#include <queue>     // Disponibiliza o adaptador de fila std::queue.
#include <stack>     // Disponibiliza o adaptador de pilha std::stack.

int main() {  // Ponto de entrada: a execucao do programa comeca aqui.
    // Faz os valores booleanos aparecerem como true/false, em vez de 1/0.
    std::cout << std::boolalpha;

    // ===================== PARTE 1: FILA (FIFO) =====================
    // std:: indica o namespace da biblioteca padrao; <int> indica o tipo.
    // A declaracao cria uma fila inicialmente vazia de numeros inteiros.
    std::queue<int> fila;
    std::cout << "=== FILA (FIFO) ===\n";

    // empty() apenas consulta: true significa que nao ha elementos.
    std::cout << "Vazia inicialmente? " << fila.empty() << '\n';

    // push() insere no FINAL. A ordem de chegada sera preservada na saida.
    fila.push(10);  // Primeiro: [10].
    fila.push(20);  // Depois: [10, 20].
    fila.push(30);  // Depois: [10, 20, 30]; a frente e 10 e o final e 30.
    std::cout << "Inseridos: 10, 20, 30\n";
    std::cout << "Quantidade: " << fila.size() << '\n';  // Agora sao 3.
    std::cout << "Vazia apos inserir? " << fila.empty() << '\n';

    // ! nega o resultado: !empty() significa que EXISTE algum elemento.
    // front(), back() e pop() precisam de uma fila nao vazia.
    if (!fila.empty()) {
        // Consultar nao remove: os tres numeros continuam na fila.
        std::cout << "Primeiro (front): " << fila.front() << '\n';
        std::cout << "Ultimo (back): " << fila.back() << '\n';

        // pop() nao retorna o numero removido. Copiamos front() ANTES.
        const int removido = fila.front();  // Guarda 10 em outra variavel.
        fila.pop();  // Remove o PRIMEIRO: a fila passa a ser [20, 30].
        std::cout << "Removido por pop: " << removido << '\n';
    }

    // Consultamos novamente com protecao, mesmo sabendo que sobraram dois.
    if (!fila.empty()) {
        std::cout << "Novo primeiro: " << fila.front() << '\n';  // 20.
    }
    std::cout << "Quantidade apos pop: " << fila.size() << '\n';  // 2.

    // O while repete ENQUANTO houver elementos e para quando a fila esvazia.
    // Como 10 ja saiu, esta etapa mostra somente os restantes: 20 e 30.
    std::cout << "Removendo restantes:";
    while (!fila.empty()) {
        std::cout << ' ' << fila.front();  // Le o proximo: 20, depois 30.
        fila.pop();  // Remove o numero que acabou de ser mostrado.
    }
    std::cout << '\n';  // Finaliza a linha da ordem de remocao.
    std::cout << "Vazia ao final? " << fila.empty() << '\n';  // true.
    std::cout << "Quantidade final: " << fila.size() << "\n\n";  // 0.

    // ===================== PARTE 2: PILHA (LIFO) =====================
    // Cria uma pilha vazia; <int> tambem indica elementos inteiros.
    std::stack<int> pilha;
    std::cout << "=== PILHA (LIFO) ===\n";
    std::cout << "Vazia inicialmente? " << pilha.empty() << '\n';

    // Na pilha, insercao e remocao acontecem na mesma extremidade: o TOPO.
    pilha.push(10);  // Base e topo: 10.
    pilha.push(20);  // Base -> topo: [10, 20].
    pilha.push(30);  // Base -> topo: [10, 20, 30]; agora o topo e 30.
    std::cout << "Inseridos: 10, 20, 30\n";
    std::cout << "Quantidade: " << pilha.size() << '\n';
    std::cout << "Vazia apos inserir? " << pilha.empty() << '\n';

    // top() e pop() tambem precisam de uma pilha nao vazia.
    if (!pilha.empty()) {
        // top() consulta o ultimo inserido e NAO o remove.
        std::cout << "Topo (top): " << pilha.top() << '\n';  // 30.
        const int removido = pilha.top();  // Copia 30 antes da remocao.
        pilha.pop();  // Remove o TOPO: agora restam 10 e 20, com 20 no topo.
        std::cout << "Removido por pop: " << removido << '\n';
    }

    if (!pilha.empty()) {
        std::cout << "Novo topo: " << pilha.top() << '\n';  // 20.
    }
    std::cout << "Quantidade apos pop: " << pilha.size() << '\n';

    // Como 30 ja saiu, os restantes saem na ordem 20, 10.
    std::cout << "Removendo restantes:";
    while (!pilha.empty()) {
        std::cout << ' ' << pilha.top();  // Le 20, depois 10.
        pilha.pop();  // Retira o topo atual, permitindo acessar o seguinte.
    }
    std::cout << '\n';
    std::cout << "Vazia ao final? " << pilha.empty() << '\n';  // true.
    std::cout << "Quantidade final: " << pilha.size() << '\n';  // 0.

    // Retornar zero indica que o programa terminou com sucesso.
    return 0;
}
