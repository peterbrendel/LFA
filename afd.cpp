#include "afd.hpp"

using namespace std;

AFD::AFD(){

	int qtd_estados;
	cout << "Qual o estado inicial?" << endl;
	cout << "Estado inicial: ";
	cin >> this->inicial;

	cout << "Quantos estados? ";
	cin >> qtd_estados;
	cout << "Quais os estados? " << endl;
	while(--qtd_estados){
		string aux;
		cin >> aux;
		this->estados.push_back(aux);
	}

	cout << "Quantos estados finais? ";
	cin >> qtd_estados;
	cout << "Quais os estados finais? " << endl;
	while(--qtd_estados){
		string aux;
		cin >> aux;
		this->finais.push_back(aux);
	}

	cout << "Quantas letras no alfabeto? ";
	cin >> qtd_estados;
	cout << "Quais as letras do alfabeto? " << endl;
	while(--qtd_estados){
		char aux;
		cin >> aux;
		this->alfabeto+=aux;
	}

	cout << "Quantas transicoes? ";
	cin >> qtd_estados;
	cout << "Quais as transicoes? " << endl;
	cout << "Exemplo de transicao: q0 a q1" << endl;
	while(--qtd_estados){
		string qOrigem, qDestino;
		char alfabeto;
		cin >> qOrigem >> alfabeto >> qDestino;
		this->conectar_estados(make_pair(qOrigem, alfabeto), qDestino);
	}

}

AFD::AFD(const char * s){

	

}

void AFD::conectar_estados(pair<string, char> from, string to){

	this->conexoes[from] = to;

}