/**
 * ============================================================================
 * INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO PIAUÍ - IFPI
 * DISCIPLINA: Estrutura de Dados | PROFESSORA: Elanne
 * LISTA PARA APRESENTAÇÃO - QUESTÃO 16
 * ============================================================================
 * 
 * ENUNCIADO:
 * 16. Realize uma pesquisa sobre as estruturas de dados fila (std::queue) e pilha 
 *     (std::stack) disponíveis na biblioteca padrão do C++ (STL – Standard Template Library). 
 *     Em sua resposta, explique:
 *     a. As principais características e finalidades de cada estrutura.
 *     b. As funções básicas utilizadas para manipular uma fila e uma pilha (como push, 
 *        pop, front, top, empty, entre outras).
 *     c. Apresente exemplos de código demonstrando as operações fundamentais:
 *        - Inserção de elementos
 *        - Remoção de elementos
 *        - Acesso ao elemento do topo (no caso da pilha)
 *        - Acesso ao primeiro elemento (no caso da fila)
 *        - Verificação de vazio
 * 
 * ============================================================================
 * RESPOSTAS TEÓRICAS:
 * ============================================================================
 * 
 * PARTE A: CARACTERÍSTICAS E FINALIDADES
 * ----------------------------------------------------------------------------
 * Na STL do C++, tanto std::queue quanto std::stack NÃO são contêineres puros, 
 * mas sim ADAPTADORES DE CONTÊINER (container adapters).
 * Eles encapsulam uma estrutura subjacente (por padrão, std::deque) e restringem 
 * intencionalmente sua interface para forçar a disciplina de acesso desejada:
 * 
 * 1. FILA (std::queue - cabeçalho <queue>):
 *    - Disciplina: FIFO (First-In, First-Out).
 *    - Finalidade: Gerenciar fluxos em ordem de chegada, como filas de impressão, 
 *      escalonamento de tarefas em sistemas operacionais, buffers de rede e 
 *      algoritmos de busca em largura (BFS - Breadth-First Search).
 * 
 * 2. PILHA (std::stack - cabeçalho <stack>):
 *    - Disciplina: LIFO (Last-In, First-Out).
 *    - Finalidade: Gerenciar contextos onde a ação mais recente deve ser processada 
 *      primeiro, como mecanismos de desfazer/refazer (Undo/Redo), chamadas de função 
 *      (Call Stack), avaliação/conversão de expressões matemáticas (notação pós-fixa) 
 *      e algoritmos de busca em profundidade (DFS - Depth-First Search).
 * 
 * PARTE B: FUNÇÕES BÁSICAS COMPARADAS
 * ----------------------------------------------------------------------------
 * | Operação                | std::queue (Fila)  | std::stack (Pilha) | Complexidade |
 * |-------------------------|--------------------|--------------------|--------------|
 * | Inserir elemento        | push(x) (no fim)   | push(x) (no topo)  | O(1)         |
 * | Remover elemento        | pop() (da frente)  | pop() (do topo)    | O(1)         |
 * | Consultar frente/topo   | front()            | top()              | O(1)         |
 * | Consultar último        | back()             | N/A                | O(1)         |
 * | Verificar se está vazia | empty()            | empty()            | O(1)         |
 * | Quantidade de elementos | size()             | size()             | O(1)         |
 * | Construção direta       | emplace(...)       | emplace(...)       | O(1)         |
 * | Troca de conteúdo       | swap(...)          | swap(...)          | O(1)         |
 * 
 * NOTA CRÍTICA SOBRE O POP():
 * Na STL do C++, o método pop() é void (não retorna o valor removido). Para capturar 
 * o elemento antes de removê-lo, deve-se sempre consultar front() ou top() antes de chamar pop().
 * ============================================================================
 */

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void demonstrarFilaSTL() {
    cout << "============================================================" << endl;
    cout << "DEMONSTRACAO 1: FILA (std::queue - FIFO)" << endl;
    cout << "============================================================" << endl;

    queue<string> filaAtendimento;

    // 1. Verificacao de vazio inicial
    cout << "A fila esta vazia inicialmente? " << (filaAtendimento.empty() ? "SIM" : "NAO") << endl;

    // 2. Insercao de elementos (push)
    cout << "\nInserindo clientes na fila:" << endl;
    filaAtendimento.push("Ana");
    cout << " -> Inserido: Ana" << endl;
    filaAtendimento.push("Bruno");
    cout << " -> Inserido: Bruno" << endl;
    filaAtendimento.push("Carlos");
    cout << " -> Inserido: Carlos" << endl;

    cout << "Tamanho atual da fila: " << filaAtendimento.size() << endl;

    // 3. Acesso ao primeiro elemento (front) e ultimo (back)
    cout << "\nPrimeiro da fila (front()): " << filaAtendimento.front() << endl;
    cout << "Ultimo da fila (back()):     " << filaAtendimento.back() << endl;

    // 4. Remocao de elementos (pop)
    cout << "\nAtendendo e removendo da fila (ordem FIFO):" << endl;
    while (!filaAtendimento.empty()) {
        cout << " -> Atendendo: " << filaAtendimento.front() << endl;
        filaAtendimento.pop(); // Remove o primeiro
    }

    // 5. Verificacao de vazio final
    cout << "A fila esta vazia agora? " << (filaAtendimento.empty() ? "SIM" : "NAO") << endl << endl;
}

void demonstrarPilhaSTL() {
    cout << "============================================================" << endl;
    cout << "DEMONSTRACAO 2: PILHA (std::stack - LIFO)" << endl;
    cout << "============================================================" << endl;

    stack<int> pilhaHistorico;

    // 1. Verificacao de vazio inicial
    cout << "A pilha esta vazia inicialmente? " << (pilhaHistorico.empty() ? "SIM" : "NAO") << endl;

    // 2. Insercao de elementos (push)
    cout << "\nEmpilhando acoes (identificadores 10, 20, 30):" << endl;
    pilhaHistorico.push(10);
    cout << " -> Empilhado: 10" << endl;
    pilhaHistorico.push(20);
    cout << " -> Empilhado: 20" << endl;
    pilhaHistorico.push(30);
    cout << " -> Empilhado: 30" << endl;

    cout << "Tamanho atual da pilha: " << pilhaHistorico.size() << endl;

    // 3. Acesso ao elemento do topo (top)
    cout << "\nElemento no topo (top()): " << pilhaHistorico.top() << endl;

    // 4. Remocao de elementos (pop)
    cout << "\nDesfazendo acoes e desempilhando (ordem LIFO):" << endl;
    while (!pilhaHistorico.empty()) {
        cout << " -> Desfazendo acao do topo: " << pilhaHistorico.top() << endl;
        pilhaHistorico.pop(); // Remove o topo
    }

    // 5. Verificacao de vazio final
    cout << "A pilha esta vazia agora? " << (pilhaHistorico.empty() ? "SIM" : "NAO") << endl;
}

int main() {
    printf("============================================================\n");
    printf("QUESTAO 16 - PESQUISA E DEMONSTRACAO: std::queue e std::stack\n");
    printf("============================================================\n\n");

    demonstrarFilaSTL();
    demonstrarPilhaSTL();

    return 0;
}
