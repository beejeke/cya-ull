//========================================================================================
// Practica 8 Computabilidad y Algoritmia
// Autor: Omar Mendo Mesa
// Implementacion de la clase Tuple
//========================================================================================

#include "Tuple.hpp"


Tuple::Tuple(int state, char read_symbol, char write_symbol, char move, int next_state):
state_(state),
read_symbol_(read_symbol),
write_symbol_(write_symbol),
move_(move),
next_state_(next_state)
{}

Tuple::Tuple(void)
{}

Tuple::~Tuple(void)
{
	state_=0;
	read_symbol_=0;
	write_symbol_=0;
	move_=0;
	next_state_=0;
}

int Tuple::get_state()
{
	return state_;
}

char Tuple::get_read_symbol()
{
	return read_symbol_;
}

char Tuple::get_write_symbol()
{
	return write_symbol_;
}

char Tuple::get_move()
{
	return move_;
}

int Tuple::get_next_state()
{
	return next_state_;
}
