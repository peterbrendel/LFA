#ifndef AFD_HPP
#define AFD_HPP

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

void game_loop();

class AFD {

private:
	
	bool minimizado;
	string inicial;
	string alfabeto;
	vector<string> finais;
	vector<string> estados; 
	map<pair<string,char>,string> conexoes;
	map<string,int> alcancaveis;

public:

	AFD(int x);
	AFD();
	AFD(const char *);
	AFD 	Minimizar();
	bool 	isFinal(string estado);
	bool 	isInicial(string estado);
	bool 	isInutil(string estado);
	bool	isMinimizado();
	// bool 	ReadEntry(string daVez, string::iterator entry);
	int 	lerArquivoAFD(string diretorio);
	int 	FuncTot();
	string 	get_inicial();
	void 	set_inicial(string inicial);
	void 	conectar_estados(pair<string,char> from, string to);
	void 	AddFinais(string state);
	void 	AddEstados(string state);
	void 	monta_fecho(string daVez);
	// void 	NewAlphabet(string alpha);
	void 	RemoverEstado(string estado);
	void 	RemoverEstadosInalcancaveis();
	void 	setEstadoInicial(string state);
	void 	saveToFile(string file);
	void	saveToFile();

};

#endif
