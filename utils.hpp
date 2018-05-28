#include <bits/stdc++.h>

using namespace std;

class Utils{

public:

	void UP(string& s);
	void UP(char& s);

	void printFlags(){
		cout << "FLAGS FOR AUTOMATA" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "-n Novo automato, inserindo os dados manualmente" << endl;
		cout << "-o Novo automato, dados vindo de um arquivo *.afd" << endl;
		cout << "--------------------------------------------------" << endl;
	}

}