#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>
#include "Utils.hpp"

using namespace std;

void Utils::UP(string& s){
	for(auto c = s.begin(); c != s.end(); c++){
		if(*c >= 'a' && *c <= 'z'){
			*c -= 32;
		}
	}
}

void Utils::UP(char * c){
	if((*c) >= 'a' && (*c) <= 'z'){
			(*c) -= 32;
		}
}

void Utils::printFlags(){
	cout << "FLAGS FOR AUTOMATA" << endl;
	cout << endl << "--------------------------------------------------" << endl;
	cout << "-n | Novo automato, inserindo os dados manualmente" << endl;
	cout << "-i *.afd | Novo automato, dados vindo de um arquivo *.afd" << endl;
	cout << "-o * | Envia a saida para o arquivo *" << endl;
	cout << endl << "--------------------------------------------------" << endl;
}

void Utils::menu(){

	cout << "|--------------------------------------------------|" << endl;
	cout << "|                       MENU                       |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "| 1   Visualizar automato                          |" << endl;
	cout << "| 2   Salvar automato                              |" << endl;
	cout << "| 3   Minimizar automato                           |" << endl;
	cout << "| 4   Criar novo automato                          |" << endl;
	cout << "| Q   Sair                                         |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                       MENU                       |" << endl;
	cout << "|--------------------------------------------------|" << endl;

}
