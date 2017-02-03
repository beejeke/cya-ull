#pragma once

#include <iostream>
#include <cstdio>


using namespace std;


class status_t
{
    friend std::ostream &operator<<(std::ostream &,const status_t &);  //metodo privado

//Atributos de la clase DFA:
public:

	int status_id_;  //Numero identificador de estado
	int num_trans_;  //Numero de transciciones que tiene el estado
	bool num_acept_;  //Numero que determina el valor es de aceptacion o no
    char *symbol_;    //Simbolo de entrada
    int *destin_;     //Estado destino de llegada



    status_t(void);                               //Constructor por defecto de la clase estado
    status_t(int,bool,int,char*,int*);
    status_t(const status_t &);
    ~status_t();

            //Sobrecarga de operadores

    status_t &operator=(const status_t &rhs);
    int operator==(const status_t &rhs) const;
    int operator<(const status_t &rhs) const;



};
