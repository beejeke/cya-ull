//========================================================================================
// Practica 8 Computabilidad y Algoritmia
// Autor: Omar Mendo Mesa
// Declaracion de la clase Tuple
//========================================================================================

#pragma once
#include <iostream>

using namespace std;
//!  Tuple class.
/*!
	Esta clase esta destinada a la declaracion de atributos y metodos de la Tuple
*/
class Tuple
{
	//! Atributos privados de la clase Tuple.
	/*! En este apartado declaran las variables solo accecibles por metodos del objeto Tuple. */

	//! state_.
	/*!Variable tipo int que almacena el identificador del estado*/
	int state_;

	//! read_symbol_.
	/*!Variable tipo char que almacena el caracter a leer o leido en la cinta */
	char read_symbol_;

	//! write_symbol_.
	/*! Variable tipo char que almacena el caracter que hay que escribir en la cinta. */
	char write_symbol_;

	//! move_.
	/*! Variable tipo char que almacena el movimiento del cabezal de la maquina de Turing */
	char move_;

	//! next_state_.
	/*! Variable tipo int que almacena el identificador del siguiente estado a visitar */
	int next_state_;

public:

	//! Metodos publicos de la clase Tuple.
	/*! En este apartado declaran los metodos publicos del objeto Tuple. */

	/**
	* @brief Metodo constructor que crea la clase Tupla mediante el paso de parametros.
	* @param state(int)
	* @param read_symbol(char)
	* @param write_symbol(char)
	* @param move(char)
	* @param next_state(int)
	*/
	Tuple(int state, char read_symbol, char write_symbol, char move, int next_state);

	/**
	* @brief Metodo constructor por defecto de la clase Tuple.
	*/
	Tuple();

	/**
	* @brief Metodo destructor de la clase Tuple.
	* @param void
	*/
	~Tuple(void);

	/**
	* @brief Metodo que obtiene el estado del objeto Tuple.
	* @param void
	* @return int
	*/
	int get_state(void);

	/**
	* @brief Metodo que obtiene el valor del atributo 'read_symbol' del objeto Tuple.
	* @param void
	* @return char
	*/
	char get_read_symbol(void);

	/**
	* @brief Metodo que obtiene el valor del atributo 'write_symbol' del objeto Tuple.
	* @param void
	* @return char
	*/
	char get_write_symbol(void);

	/**
	* @brief Metodo que obtiene el valor del atributo 'move' del objeto Tuple.
	* @param void
	* @return char
	*/
	char get_move(void);

	/**
	* @brief Metodo que obtiene el valor del atributo 'next_state' del objeto Tuple.
	* @param void
	* @return int
	*/
	int get_next_state(void);

};
