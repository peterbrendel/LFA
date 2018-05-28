#include "afd.hpp"

using namespace std;

AFD::AFD(){
	this->minimizado = false;
}

AFD::AFD(){
	
	this->minimizado = false;
	
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

bool AFD::isFinal(string estado){

	return (find(this->finais.begin(), this->finais.end(), estado) != this->finais.end()); 
	// Retorna true se encontrou algum pois o iterator nao sera o fim do map
}

bool AFD::isInicial(string estado){

	return estado == this->inicial;
}

bool AFD::isInutil(string estado){

	if (isFinal(estado))
		return false;
	this->alcancaveis.clear();
	bool inutil;
	monta_fecho(estado);
	inutil = true;
	for (int i = 0; i < (int) this->finais.size(); i++){
		if (alcancaveis[finais[i]])
			inutil = false;
	}

return inutil;
}

bool AFD::isMinimizado(){
	return this->minimizado;
}

void AFD::setEstadoInicial(string estado){
	this->inicial = estado;
}

void AFD::AddFinais(string estado){
	this->finais.push_back(estado);
}

void AFD::conectar_estados(pair<string, char> from, string to){

	this->conexoes[from] = to;
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

void AFD::saveToFile(string arquivo){
	
	ofstream saida;
	string nome = arquivo+".afd";
	saida.open(npath);

	saida << "Estado Inicial: " << this->inicial << endl;
	
	saida << "Todos os Estados:\nQuantidade: " << this->estados.size() << endl;
	for (int i = 0; i << this->estados.size(); i++)
		saida << " " << this->estados[i];
	
	saida << endl;
	saida << "Estados Finais:" << this->EstadoFinalNovo.size();
	for (int i = 0; i << this->EstadoFinalNovo.size(); i++)////////
		saida << " " << this->EstadoFinalNovo[i];///////

	saida << endl;
	saida << "Alfabeto:" << this->alfabeto.size();
	for (int i = 0; i < this->alfabeto.size(); i++)
		saida << " " << alfabeto[i];

	saida << endl;
	saida << "Quantidade de conexoes: " << this->conexoes.size() << endl;
	map<pair<string, char>, string >::iterator it;
	for (it = this->conexoes.begin(); it != this->conexoes.end(); it++)
		saida << it->first.first << " " << it->first.second << " " << it->second << endl;

	saida.close();
}

int AFD::FuncTot(){
	int novoEstado = false;
	int tam_estados = this->estados.size();
	int tam_alfabeto = this->alfabeto.size();
	for (int i = 0; i < tam_estados; i++){
		for (int j = 0; j < tam_alfabeto; j++){
			if (!this->conexoes.count({estados[i], alfabeto[j]})){
				if (!novoEstado){
					novoEstado = true;
					this->AddEstados("Estadovazio");
				}
				this->conectar_estados(make_pair(estados[i],alfabeto[j]), "Estadovazio");
			}
		}
	}

	if (novoEstado){
		cout << " - Ocorreu o adicionamento do estado: chamado de Estadovazio\n";
		cout << "Para que a funcao seja total" << endl;
		for (int i = 0; i < tam_alfabeto; i++){
			this->conectar_estados(make_pair("Estadovazio", alfabeto[i]), "Estadovazio");
		}
	}

	return novoEstado;
}

void AFD::AddEstados(string estado){
	this->estados.push_back(estado);
}

void AFD::RemoverEstado(string estado){
	
	for (auto it = this->conexoes.begin(); it != this->conexoes.end();){
		if (it -> first.first == estado || it -> second == estado){
			it = this->conexoes.erase(it);
		}else{
			it++;
		}
	}

	vector<string>::iterator sit = find(this->estados.begin(), this->estados.end(), estado);
	this->estados.erase(sit);
	cout << " e foi removido." << endl;
}

void AFD::RemoverEstadosInalcancaveis(){

	monta_fecho(this->inicial);
	for (int i = estados.size() - 1; i >= 0; i--){
		if (!alcancaveis.count(estados[i])){

			

			for(auto itFuncProg = this->conexoes.begin(); itFuncProg != this->conexoes.end(); itFuncProg++){
				if(itFuncProg ->first.first == estados[i] or itFuncProg->second == estados[i]){
					this->conexoes.erase(itFuncProg);
					itFuncProg--;
				}
			}


			vector<string>::iterator itEstFinais = finais.begin();
			for (; itEstFinais != finais.end(); itEstFinais++){
				if (estados[i].compare(*itEstFinais) == 0){
					finais.erase(itEstFinais);
					itEstFinais--;
				}
			}
			estados.erase(estados.begin() + i);
		}
	}
}

void AFD::monta_fecho(string daVez){

	if (daVez == "")
		return;
	alcancaveis[daVez] = true;
	int als = this->alfabeto.size();
	string next;
	for (int i = 0; i < als; i++)
	{
		next = (this->conexoes.count({daVez, alfabeto[i]}) > 0) ?
			this->conexoes[{daVez, alfabeto[i]}] : "";
		if (!alcancaveis[next])
			monta_fecho(next);
	}

}

AFD AFD::Minimizar(){

	AFD novoAutomato; 
	novoAutomato.alfabeto = this->alfabeto;
	map<pair<string, string>, bool> equivalentes;

	int x = 0, y = 0;

	// Passo 1: Criação da tabela de estados equivalentes (completa, não triangular)
	// Passo 2: Marcação dos estados trivialmente não-equivalentes

	for (int i=0; i < (int)estados.size(); i++){

		for (int j=0; j < (int)estados.size(); j++){

			equivalentes[{estados[i], estados[j]}] = true;

			if ((find(finais.begin(), finais.end(), estados[i]) != finais.end()) != (find(finais.begin(), finais.end(), estados[j]) != finais.end())){
				equivalentes[{estados[i], estados[j]}] = false;
				x++;
			}
		}
	}

	bool areEqual;
	string r1, r2;
	y = x;

	// Passo 3: Marcação dos estados não equivalentes
	// feito até não marcar mais ninguém -> y == x

	do{

		x = y;

		for (int i=0; i < (int)estados.size(); i++){

			for (int j=0; j < (int)estados.size(); j++){

				areEqual = equivalentes[{estados[i], estados[j]}];

				for (int k=0; k < (int)alfabeto.size() and areEqual; k++){
					r1 = conexoes[{estados[i], alfabeto[k]}];
					r2 = conexoes[{estados[j], alfabeto[k]}];

					if (!equivalentes[{r1, r2}]){
						areEqual = false;
						equivalentes[{estados[i], estados[j]}] = false;
						y++;
					}
				}
			}
		}
	} while (y != x);

	cout << "Tabela de Equivalências:" << endl << endl;

	for (int i=0; i <= (int)estados.size()+1; i++){
		
		for (int j=0; j <= (int)estados.size()+1; j++){
			
			if(i==0 || i==(int)estados.size()+1) cout << "# ";
			else if(j==0 || j==(int)estados.size()+1) cout << "# ";
			else cout << (equivalentes[{estados[i-1], estados[j-1]}] ? "-" : "X") << " ";
		}
		cout << endl;
	}
	cout << endl;

	// Passo 4: Unificar estados equivalentes

	vector<string> sequenciaDeEstados;
	sequenciaDeEstados.push_back(this -> inicial);

	map<string, string> novosNomesDosEstados;

	map<string, vector<string> > estadosOriginaisDoNovoEstado;

	vector<string> novosEstados;
	novosEstados.push_back(this -> inicial);

	vector<string> novosEstadosFinais;

	queue<string> filaDeEstados;

	map<string, bool> novoEstadoJaVisitado;

	for(int i=0; i < (int)estados.size(); i++) {
		sequenciaDeEstados.clear();
		string estadoDaVez = estados[i];

		// pular checagem de estado já agrupado, marcar estado como visitado
		if(novoEstadoJaVisitado[estadoDaVez]) continue;
		novoEstadoJaVisitado[estadoDaVez] = true;
		sequenciaDeEstados.push_back(estadoDaVez);

		// começar a escrever o novo nome do grupo de estados
		string newName = estadoDaVez;

		// Encontrar estados equivalentes e adicioná-los ao estado atual e à lista de 'Vistos'
		for(int i=0; i < (int)this->estados.size(); i++){

			if(estadoDaVez != estados[i] && equivalentes[{estadoDaVez, estados[i]}]){

				if(sequenciaDeEstados.size() == 1)
					newName.insert(0, "{");

				newName += ",";
				newName += estados[i];
				sequenciaDeEstados.push_back(estados[i]);
				novoEstadoJaVisitado[estados[i]] = true;
			}
		}

		if(sequenciaDeEstados.size() > 1){
			
			newName += "}";
		}

		for(int i=0; i < (int)sequenciaDeEstados.size(); i++){
		
			novosNomesDosEstados[sequenciaDeEstados[i]] = newName;
		}

		estadosOriginaisDoNovoEstado[newName] = sequenciaDeEstados;
		
		// Verificar se é estado inicial, se sim, configurar conjunto inteiro como inicial.
		if (isInicial(estadoDaVez)){
			novoAutomato.setEstadoInicial(newName);

		}
		// Verificar se é estado final, se sim, configurar conjunto inteiro como final.
		if (isFinal(estadoDaVez)){
			novoAutomato.AddFinais(newName);

		}

		novoAutomato.AddEstados(newName);
	}

	for(int i=0; i < (int)novoAutomato.estados.size(); i++){
		string estadoDaVez = novoAutomato.estados[i];
		for (int j=0; j < (int)this->alfabeto.size(); j++){
			string estadoTeste = estadosOriginaisDoNovoEstado[estadoDaVez][0];
			char l = alfabeto[j];
			
			// Aqui faz-se a busca do grupo de destino nas transições com o primeiro componente do grupo atual.
			// Como todos os integrantes do grupo são equivalentes, qualquer um deles levará a estados equivalentes também.
			novoAutomato.conectar_estados(make_pair(novoAutomato.estados[i], alfabeto[j]),
													novosNomesDosEstados[this->conexoes[{estadoTeste, l}]]); // Bagunçado, mas funciona.
		}
	}
	// Passo 5: remover estados que não alcançam estados finais
	for (int i=(int)novoAutomato.estados.size()-1; i >= 0 ; i--){

		if (novoAutomato.isInutil(novoAutomato.estados[i])){
			
			novoAutomato.RemoverEstado(novoAutomato.estados[i]);
		}
	}

	// (*returner) = novoAutomato;
	novoAutomato.minimizado = true;
	return novoAutomato;
}
