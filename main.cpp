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
#include "afd.hpp"

using namespace std;

AFD * afd;
const char * clear;
string saida;
int main(int argc, const char* argv[]){
	
	if(!OS){
		clear = "clear";
	}else{
		clear = "cls";
	}
	
	

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

		for(int i=1; i < argc; i++){

			string op = argv[i];

			if(op[0] == '-'){

				switch(op[1]){
					case 'n':
					cout << "Criando novo automato..." << endl;
					afd = new AFD(1);
					break;

					case 'i':
					if(argc > 1+i){
						cout << "Criando novo automato baseado no arquivo " << argv[1+i] << endl;
						if(afd != nullptr){
							cout << "Automato ja criado. abortando criacao por arquivo" << endl << endl;
							cout << "Pressione ENTER para abrir o menu";
							getchar();
							getchar();
							break;
						}
						afd = new AFD(argv[1+i]); // Passa como parametro o arquivo .afd
					}else{
						cerr << "Arquivo nao encontrado" << endl;
						Utils::printFlags();
						return 0;
					}
					break;
					
					case 'o':
					if(argc > 1+i){
						cout << "Enviando saida para o arquivo " << argv[1+i] << endl;
						saida = argv[i+1];
					}else{
						cerr << "Nome do arquivo de saida nao definido" << endl;
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
	
	game_loop();
	return 0;

}

void game_loop(){

	while(1){
		system(clear);
		system(clear);
		Utils::menu();
		char c;
		c = getchar();
		system(clear);

		switch(c){

			case '1':
			getchar();
			afd->saveToFile();
			break;

			case '2':
			if(!saida.empty()){
				afd->saveToFile(saida);
			}
			else{
				cout << "Digite o nome do arquivo de saida: ";
				cin >> saida;
				afd->saveToFile(saida);
			}
			break;

			case '3':
			if(!afd->isMinimizado()){
				cout << "Minimizando automato...";
				cout << endl;
				*afd = afd->Minimizar();
				saida = "";
			}else{
				cout << "Este automato ja foi minimizado!" << endl;
			}
			cout << endl << endl << "Pressione ENTER para voltar ao menu";
			getchar();
			getchar();
			break;

			case 'Q':
			case 'q':
			return;
			break;

		}

	}

}
