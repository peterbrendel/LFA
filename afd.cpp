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
	while(qtd_estados--){
		string aux;
		cin >> aux;
		this->estados.push_back(aux);
	}

	cout << "Quantos estados finais? ";
	cin >> qtd_estados;
	cout << "Quais os estados finais? " << endl;
	while(qtd_estados--){
		string aux;
		cin >> aux;
		this->finais.push_back(aux);
	}

	cout << "Quantas letras no alfabeto? ";
	cin >> qtd_estados;
	cout << "Quais as letras do alfabeto? " << endl;
	while(qtd_estados--){
		char aux;
		cin >> aux;
		this->alfabeto+=aux;
	}

	cout << "Quantas transicoes? ";
	cin >> qtd_estados;
	cout << "Quais as transicoes? " << endl;
	cout << "Exemplo de transicao: q0 a q1" << endl;
	while(qtd_estados--){
		string qOrigem, qDestino;
		char alfabeto;
		cin >> qOrigem >> alfabeto >> qDestino;
		this->conectar_estados(make_pair(qOrigem, alfabeto), qDestino);
	}

}

AFD::AFD(const char * s){

	this->minimizado = false;

	int qtd_estados;
	ifstream file;
	try{
		file.open(s, ifstream::in);
	}catch(ifstream::failure e){
		cerr << "Arquivo nao pode ser aberto, digitou o nome correto?" << endl;
		exit(1);
	}


	if(!file.is_open()){
		cerr << "Arquivo nao pode ser aberto, digitou o nome correto?" << endl;
		exit(1);
	}
	
	file >> this->inicial;
	file >> qtd_estados;

	while(qtd_estados--){
		string aux;
		file >> aux;
		this->estados.push_back(aux);
	}
	
	file >> qtd_estados;
	while(qtd_estados--){
		string aux;
		file >> aux;
		this->finais.push_back(aux);
	}

	file >> qtd_estados;
	while(qtd_estados--){
		char aux;
		file >> aux;
		this->alfabeto+=aux;
	}


	file >> qtd_estados;
	while(qtd_estados--){
		string qOrigem, qDestino;
		char alfabeto;
		file >> qOrigem >> alfabeto >> qDestino;
		this->conectar_estados(make_pair(qOrigem, alfabeto), qDestino);
	}

	file.close();
	cout << "Criado com sucesso" << endl;
}

void AFD::conectar_estados(pair<string, char> from, string to){

	this->conexoes[from] = to;

}

void AFD::saveToFile(string file){

}

void AFD::saveToFile(){

	system(clear);
	system(clear);

	cout << "Este automato " << (this->minimizado ? "foi":"nao foi") << " minimizado pelo programa" << endl << endl;

	cout << "Estado inicial: " << this->inicial << endl << endl;

	cout << "Estados:";
	for(int i=0, size = this->estados.size(); i < size; i++){
		cout << " " << this->estados[i];	
	}
	cout << endl << endl;

	cout << "Estados finais:";
	for(int i=0, size = this->finais.size(); i < size; i++){
		cout << " " << this->finais[i];
	}
	cout << endl << endl;

	cout << "Alfabeto:";
	for(int i=0, size = this->alfabeto.size(); i < size; i++){
		cout << " " << this->alfabeto[i];
	}
	cout << endl << endl;
	
	cout << "Conexoes" << endl;;
	for(auto iterator = this->conexoes.begin(); iterator != this->conexoes.end(); iterator++){
		cout << iterator->first.first << " " << iterator->first.second << " -> " << iterator->second << endl; 
	}

	cout << endl << endl;
	cout << "Presione ENTER para voltar ao menu";
	getchar();

}