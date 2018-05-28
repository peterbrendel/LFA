#include <bits/stdc++.h>
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