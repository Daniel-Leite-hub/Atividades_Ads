# Questão 16: fila e pilha na biblioteca padrão do C++

Atividade da disciplina **Estrutura de Dados em C**. O enunciado solicita uma pesquisa sobre `std::queue` e `std::stack`, com características, funções básicas e exemplos de inserção, remoção, acesso e verificação de vazio.

## Linguagem utilizada

O programa usa **C++17**, pois `std::queue` e `std::stack` pertencem à biblioteca padrão de C++. O arquivo tem extensão `.cpp` e requer um compilador C++. Esses conceitos também podem ser implementados em C, mas a biblioteca padrão de C não fornece essas classes.

## a. Características e finalidades

- **Fila (`std::queue`)**: segue FIFO, primeiro a entrar, primeiro a sair. Insere no final e remove pela frente. Serve para tarefas e atendimentos por ordem de chegada.
- **Pilha (`std::stack`)**: segue LIFO, último a entrar, primeiro a sair. Insere e remove no topo. Serve, por exemplo, para guardar ações recentes em um mecanismo de desfazer.

São adaptadores de contêiner. Por padrão usam `std::deque` internamente e oferecem uma interface restrita, sem acesso por índice.

## b. Funções básicas

| Função | Fila | Pilha |
| --- | --- | --- |
| `push(valor)` | Insere no final | Insere no topo |
| `pop()` | Remove o primeiro | Remove o topo |
| `front()` | Acessa o primeiro | Não disponível |
| `back()` | Acessa o último | Não disponível |
| `top()` | Não disponível | Acessa o topo |
| `empty()` | Verifica se está vazia | Verifica se está vazia |
| `size()` | Retorna a quantidade | Retorna a quantidade |

`pop()` não retorna o valor retirado. O código copia `front()` ou `top()` antes de remover. As consultas não removem elementos. Antes de acessar ou remover, o programa verifica `!empty()`.

Outras funções incluem `emplace`, para construir o elemento na posição de inserção, e `swap`, para trocar conteúdos entre estruturas compatíveis. O exemplo demonstra as funções da tabela.

## c. Demonstração passo a passo

O [código comentado](src/fila_pilha.cpp) executa a sequência abaixo para cada estrutura:

1. Cria a estrutura vazia e consulta `empty()`.
2. Insere 10, 20 e 30 com `push()`.
3. Mostra a quantidade com `size()`.
4. Consulta `front()` e `back()` na fila, ou `top()` na pilha.
5. Copia o valor acessível e faz a primeira remoção com `pop()`.
6. Mostra o novo primeiro ou topo e a nova quantidade.
7. Remove os elementos restantes com `while (!estrutura.empty())`.
8. Confirma que `empty()` vale `true` e `size()` vale zero.

| Resultado | Fila | Pilha |
| --- | --- | --- |
| Primeiro valor retirado | 10 | 30 |
| Restantes retirados no laço | 20, 30 | 20, 10 |
| Ordem completa de remoção | 10, 20, 30 | 30, 20, 10 |
| Estado final | Vazia | Vazia |

## Organização

```text
github-questao16/
  README.md
  .gitignore
  src/
    fila_pilha.cpp
```

## Compilar e executar

Abra o terminal na pasta deste README. O programa não solicita entrada de teclado.

### GCC / MinGW no Windows (PowerShell)

```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/fila_pilha.cpp -o build/fila_pilha.exe
.\build\fila_pilha.exe
```

### Microsoft Visual C++

No Developer PowerShell do Visual Studio:

```powershell
New-Item -ItemType Directory -Force build
cl /nologo /std:c++17 /EHsc /W4 /WX /utf-8 src/fila_pilha.cpp /Fe:build/fila_pilha.exe /Fo:build/fila_pilha.obj
.\build\fila_pilha.exe
```

### Linux ou macOS com GCC

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/fila_pilha.cpp -o build/fila_pilha
./build/fila_pilha
```

## Publicação no GitHub

Crie um repositório e envie o conteúdo desta pasta, mantendo `README.md` na raiz e o código em `src`. Inclua `.gitignore`, que exclui os arquivos de compilação. O pacote não contém executáveis.

## Referências

- Microsoft Learn: [queue](https://learn.microsoft.com/en-us/cpp/standard-library/queue-class?view=msvc-170) e [stack](https://learn.microsoft.com/en-us/cpp/standard-library/stack-class?view=msvc-170).
- Rascunho público do padrão C++: [queue](https://eel.is/c++draft/queue) e [stack](https://eel.is/c++draft/stack).

Os exemplos usam operações disponíveis em C++17. A documentação do rascunho também inclui recursos de versões posteriores.
