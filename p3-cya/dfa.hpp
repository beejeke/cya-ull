
#pragma once

#include "status.hpp"
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;


class DFA_t{

private:

     int num_total_stat_;    //Numero total de estados del DFA
     int stat_ini_;          //Numero del estado inicial o de partida
     set<status_t> stat_;    //Variable tipo estado que almacena un vector de posibles estados


public:

	DFA_t();								//Metodo contructor del DFA(leer el DFA)
	~DFA_t();							//Metodo destructor del DFA
	void create_DFA(char nombrefichero[]);
	void start();
	void show_DFA();						//Metodo que muestre el DFA(mostrar el DFA)
	void ident_deathstat();				//Metodo que identifique los estados de muerte
	void check_string();					//Metodo que analice cadenas de caracteres y diga si la cadena es aceptada o no es aceptada
	void menu(int n);

};
