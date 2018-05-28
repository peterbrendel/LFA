#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int transforma(string aux);
int transforma_char(char atual);

void clear_screen(){
	system("clear");
}

int main(void){
	
	string string_einicial;
	int estado_inicial;
	vector<string> estados;
	vector<string> estados_finais;
	int qtd_finais;

	cout << "Estado inicial: ";
  	cin >> string_einicial;
  	estado_inicial = transforma(string_einicial);
  	clear_screen();
    int num_estados;
   	cout << "Quantidade de estados: ";
    cin >> num_estados;
    clear_screen();
    cout << "Entre com o nome dos estados ";
    for(int i=0; i<num_estados;i++){
    	cout << " : ";
    	string aux; cin >> aux;
    	estados.push_back(aux);
  	}
  	clear_screen();
  	cout << "Quantos estados sao finais? ";
  	cin >> qtd_finais;
  	clear_screen();
  	cout << "Entre com os estados finais ";
  	for(int i=0; i<qtd_finais; i++){
  		string aux; cin >> aux;
  		estados_finais.push_back(aux);
  	}
  	clear_screen();

  	map<char, int> grafo[num_estados];
  	int transicoes;
  	cout << "quantas transicoes: "; cin >> transicoes;
  	clear_screen();
  	string est_1, est_2;
    char leitura;

    cout << "Ex de transicao: q0 a q1\nResulta em: q0--a-->q1" << endl;
    cout << "Insira as transicoes: " << endl;

  	for(int i=0; i<transicoes; i++){
  		// if(est_1 == est_2 && est_1 == "0") break;
  		cin >> est_1 >> leitura >> est_2;
    	int transf_1 = transforma(est_1);
    	int transf_2 = transforma(est_2);
    	grafo[transf_1].insert(make_pair(leitura, transf_2));
    }
    clear_screen();
    // getchar();
    cout << "Entre com uma palavra do alfabeto: ";
    string resultado; cin >> resultado;
    clear_screen();
    int estado_atual = estado_inicial;
    for(char c : resultado){
    	if(grafo[estado_atual].find(c) == grafo[estado_atual].end()){
    		cout << "Palavra nao aceita!!! " << endl;
    		cout << "q"+to_string(estado_atual) << " nao tem transicoes com " << c << endl;
    		return 1;
    	}
    	cout << "Indo para: " << grafo[estado_atual].find(c)->second << endl;
    	estado_atual = grafo[estado_atual].find(c)->second;
    }
    // clear_screen();
    string estado_final = "q"+to_string(estado_atual);
    cout << "Estado final: " << estado_final << endl;

  	
}

int transforma(string aux){

  	int tam = aux.size();
  	int suporte = 0;
  	int conta = 1;

  	if(aux.size() == 2){
  		// cout << "Transformado: " << aux[1]-48 << endl;
  		return aux[1]-48;
  	}
	
	for(int i=tam-1; i>0; i++){
    	suporte += ((transforma_char(aux[i]) + conta));
     	conta *= 10;
    }
    return suporte;
 }

int transforma_char(char atual){
  return atual-48;
}



//                                                    Daqui pra baixo falta implementar                                        //

             
                  
/*
o que temos:

//q0 b q2
q0 a q1
q1 b q2
q1 a q0
q2 b q1


q0,b = map::end -> pointer

q0,b = map::end
q1,b = q2

if(q1[b] == map::end && q0[b] == map::end)
if(q1[b] == q0[b] && q1[b] != map::end)

(x,y,z) 
x == y == z == 0

ker t = 0;
x = y;
dim ker t != 0




grafo[map::end][map::end] == x
q1,q0 = x;

map::end,q2 = 

q0 (a,1)
q1 (b,2) (a,0)
q2 (b,1)
q2 (a,) 

q1 -> estado inicial

   
q2  x i
q3  x f  
q4    f  f  
d     r. f. f
  q1 q2 q3 q4


alfa = {a, b, c}

q0 a q1 
q0 b q2 
q1 abc q3 
q2 abc q3

<q1,q2>


q0 c d
q3 abc d
d abc d

q1 e q2 existam
q1 ou q2
ou ainda q1Uq2


monto uma nova matriz: estados x estados+estado adicional(complementar)

1) verificar quais estados sao finais e nao finais;
for(int i=0; i<num_estados; i++){
    for(int j=0; j<num_finais; j++){
    if(j<=i)
        if(estados[i] != estados_finais[j])
            faz uma marcacao(*)
    }
}


2) pegar todo o grafo e verificar onde nao possui marcacao e fazer a operacao de leitura;
for(int i=0; i<num_estados; i++){
    for(int j=0; j<num_estados+1; j++){
        if(grafo_novo[i][j] (nao tiver marcacao)){
            for(int k=0; k<tam_alfabeto; k++){
                string estado_1 = grafo_antigo[i][k], estados_2 = grafo_antigo[j][k];(char)
                if(grafo_novo[estado_1][estado_2] esta marcado?){
                    marca(*)
                    break;
                }
                else{
                    marca o estado que parou
                    grafo_novo[i][j] = estado_1+estado_2;
                    cont++;???
                }
                
            }
            
            
        }
    }
}
3) ira sobrar no grafo algum elemento dentro dele que estara estados e nao marcacao(*);
com eles, se montará um novo estado(montando mais uma matriz nova) e colocara as leituras que elas faziam;
for(int i=0; i<cont; i++){
    for(int j=0; j<tam_alfabeto; j++){
        ultimo_grafo[i][j] = para qual estado ele vai...
    }
}

http://wiki.icmc.usp.br/images/d/df/MinimizacaoAFD.pdf
*/