//========================================================================================
// Practica 8 Computabilidad y Algoritmia
// Autor: Omar Mendo Mesa
// Declaracion de la clase Tape
//========================================================================================

#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//!  Clase Tape.
/*!
  Una clase destinada a la declaración de atributos y metodos de la clase Tape
*/
class Tape{

//! Atributos privados de la clase Tape
/*! En este apartado declaran las variables solo accecibles por metodos del objeto Tape */

private:

	//! tape_vector.
	/*!Variable tipo vector de char que almacena los caracteres de la cinta o Tape*/
	vector<char> tape_vector;

	//! tape_position_.
	/*!Variable tipo int que almacena la posicion en el vector de caracteres de la cinta o Tape*/
	int tape_position_;


//! Atributos publicos de la clase Tape
/*! En este apartado declaran los metodos del objeto Tape */
public:

	/**
	* @brief Metodo constructor por defecto de la clase Tape.
	*/
	Tape();

	/**
	* @brief Metodo destructor por defecto de la clase Tape.
	*/
	~Tape(void);

	/**
	* @brief Metodo para obtener el caracter de dentro del vector de caracteres de la cinta.
	* @param void
	* @return char
	*/
	char get_char(void);

	/**
	* @brief Metodo para cambiar el caracter de dentro del vector de caracteres de la cinta.
	* @param symbol(char)
	* @return void
	*/
	void set_char(char symbol);

	/**
	* @brief Metodo para leer el contenido de la cinta desde un fichero externo
	* @param void
	* @return void
	*/
	void read_tape_file(void);

	/**
	* @brief Metodo para imprimir el contenido del vector de caracteres de la cinta.
	* @param void
	* @return void
	*/
	void print_tape(void);

	/**
	* @brief Metodo para añadir un blanco por la izquierda de la cinta.
	* @param void
	* @return void
	*/
	void add_white_symbol_L(void);

	/**
	* @brief Metodo para añadir un blanco por la derecha de la cinta.
	* @param void
	* @return void
	*/
	void add_white_symbol_R(void);

	/**
	* @brief Metodo para mover el cabezal de la cinta o la posicion dependiendo del parametro que se le pase.
	* @param move(char)
	* @return void
	*/
	void move_tape(char move);
};
