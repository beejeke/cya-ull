//========================================================================================
// Practica 8 Computabilidad y Algoritmia
// Autor: Omar Mendo Mesa
// Declaracion de la clase TuringMachine
//========================================================================================

#pragma once
#include "Tuple.hpp"
#include "Tape.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//!  Clase TuringMachine.
/*!
  Una clase destinada a la declaración de atributos y metodos de la clase TuringMachine
*/
class TuringMachine{

//! Atributos privados de la clase TuringMachine
/*! En este apartado declaran las variables solo accecibles por metodos del objeto TuringMachine */

private:

	//! number_of_states_.
	/*!Variable tipo int que almacena el numero de estados que tiene la maquina de turing*/
	int number_of_states_;

	//! start_state_.
	/*!Variable tipo int que almacena el estado de arranque o inicial de la maquina de turing*/
	int start_state_;

	//! number_of_tuples_.
	/*!Variable tipo int que almacena el numero de tuplas de la maquina de turing*/
	int number_of_tuples_;

	//! acepted_states_.
	/*!Variable tipo vector de ints que almacena los estadosde aceptacion de la maquina de turing*/
	vector<int> acepted_states_;

	//! tuples_vector_.
	/*!Variable tipo vector de objetos Tuple(tuplas) que almacenan las tuplas de la maquina de turing*/
	vector<Tuple> tuples_vector_;

	//! tape_.
	/*!Variable tipo Tape que contiene la cinta o tape de la maquina de turing*/
	Tape tape_;


//! Atributos publicos de la clase TuringMachine
/*! En este apartado declaran los metodos del objeto TuringMachine */
public:

	/**
	* @brief Metodo constructor por defecto de la clase TuringMachine.
	*/
	TuringMachine(void);

	/**
	* @brief Metodo constructor destructor por defecto de la clase TuringMachine.
	*/
	~TuringMachine(void);

	/**
	* @brief Metodo para imprimir la maquina de turing por pantalla.
	* @param void
	* @return void
	*/
	void print_TM(void);

	/**
	* @brief Metodo para comprobar o revisar la cinta.
	* @param void
	* @return void
	*/
	void TM_check_tape(void);

	/**
	* @brief Metodo para leer la maquina de turing determinada.
	* @param void
	* @return void
	*/
	void read_TM(void);

};
