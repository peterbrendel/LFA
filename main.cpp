#include <bits/stdc++.h>
#include "afd.hpp"

using namespace std;

int main(int argc, const char* argv[]){
	
	AFD * afd;

	if(argc == 1){
		char escolha;
		cout << "Deseja entrar os dados manualmente? (S/N): ";
		cin >> escolha;
		Utils::UP(&escolha);

		switch(escolha){
			case 'S':
			cout << "Uso: ./automato -n" << endl;
			break;

			case 'N':
			cout << "Uso: ./automato -i arquivo_entrada.afd" << endl;
			break;

			default:
			cerr << "Flag nao encontrada" << endl;
			Utils::printFlags();
			break;
		}
		return 0;
	}else{

		for(int i=1; i <= argc; i++){

			string op = argv[i];

			if(op[0] == '-'){

				switch(op[1]){
					case 'n':
					cout << "Criando novo automato..." << endl;
					afd = new AFD();

					case 'i':
					if(argc > 1+i){
						cout << "Criando novo automato baseado no arquivo " << argv[1+i] << endl;
						afd = new AFD(argv[1+i]); // Passa como parametro o arquivo .afd
					}else{
						cerr << "Arquivo nao encontrado" << endl;
						Utils::printFlags();
						return 0;
					}

					case 'o':
					if(argc > 1+i){
						cout << "Criando novo automato baseado no arquivo " << argv[1+i] << endl;
						afd = new AFD(argv[1+i]); // Passa como parametro o arquivo .afd
					}else{
						cerr << "Arquivo nao encontrado" << endl;
						Utils::printFlags();
						return 0;
					}
					break;

					default:
					cerr << "Flag nao encontrada" << endl;
					Utils::printFlags();
					break;

				}

			}

		}

	}

}