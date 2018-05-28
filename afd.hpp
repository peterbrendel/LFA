#ifndef AFD_HPP
#define AFD_HPP

#include <bits/stdc++.h>
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

	AFD();
	AFD(const char *);
	AFD 	Minimizar();
	bool 	isFinal(string estado);
	bool 	isInicial(string estado);
	bool 	isInutil(string estado);
	// bool 	ReadEntry(string daVez, string::iterator entry);
	int 	lerArquivoAFD(string diretorio);
	int 	FazerFuncTotal();
	string 	get_inicial();
	void 	set_inicial(string inicial);
	void 	conectar_estados(pair<string,char> from, string to);
	void 	AddFinalStates(string state);
	void 	AddStates(string state);
	void 	Fecho(string daVez);
	// void 	NewAlphabet(string alpha);
	void 	RemoverEstado(string estado);
	void 	RemoverEstadosInalcancaveis();
	void 	setEstadoInicial(string state);
	void 	saveToFile(string file);
	void	saveToFile();


};

#endif