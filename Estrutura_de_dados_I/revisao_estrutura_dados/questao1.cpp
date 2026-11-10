#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Pilha{
	public:
		No *topo;

		Pilha(){
			topo = NULL;
		}

		void push(char n){
			No *novo = new No(n);
			if(topo == NULL){
				topo = novo;
			}else{
				novo->prox = topo;
				topo = novo;
			}
		}

		char nomeTopo(){
			return topo->nome;
		}

		char pop(){
			No *temp;
			char popped;
			if(topo != NULL){
				temp = topo;
				popped = temp->nome;
				topo = topo->prox;
				free(temp);
			}
			return popped;
		}

		int isEmpty(){
			return (topo == NULL); // retorna 1 se for verdadeiro
		}
};

void verify(string str){
	//Você pode declarar mais variáveis, se achar necessário
	int erro = 0; // 0 = sem erro, 1 = deu erro
	char par[3][3];
	strcpy(par[0], "()");
	strcpy(par[1], "[]");
	strcpy(par[2], "{}");

	Pilha *pilha = new Pilha();

	for(int i = 0; i < str.length(); i++){
		if(str[i] == par[0][0]){ //(
			// item A- complete o algoritmo
			pilha->push(str[i]); // empilha '('

		}else if(str[i] == par[1][0]){
			// item B- complete o algoritmo
			pilha->push(str[i]); // empilha '['

		}else if(str[i] == par[2][0]){
			// item C- complete o algoritmo
			pilha->push(str[i]); // empilha '{'

		}

		if(str[i] == par[0][1]){
			// item D- complete o algoritmo
			// se a pilha nao estiver vazia e o topo for '(', desempilha
			if(!pilha->isEmpty() && pilha->nomeTopo() == par[0][0]){
				pilha->pop();
			}else{
				erro = 1;
				break;
			}

		}else if(str[i] == par[1][1]){
			// item E- complete o algoritmo
			// se a pilha nao estiver vazia e o topo for '[', desempilha
			if(!pilha->isEmpty() && pilha->nomeTopo() == par[1][0]){
				pilha->pop();
			}else{
				erro = 1;
				break;
			}

		}else if(str[i] == par[2][1]){
			// item F- complete o algoritmo
			// se a pilha nao estiver vazia e o topo for '{', desempilha
			if(!pilha->isEmpty() && pilha->nomeTopo() == par[2][0]){
				pilha->pop();
			}else{
				erro = 1;
				break;
			}
		}
	}

	// item G- complete o algoritmo
	// no final, se nao deu erro e a pilha ficou vazia, esta tudo certo
	if(erro == 0 && pilha->isEmpty()){
		cout << "Expressao correta" << endl;
	}else{
		cout << "ERRO na expressao" << endl;
	}
}

int main(){
	string str("{a + [b + (2*c*d + 2)]");
	verify(str);
	string str2("a + b + (2*c*d + 2)]");
	verify(str2);
	string str3("a + b + 2*c*d + 2)]");
	verify(str3);
}
