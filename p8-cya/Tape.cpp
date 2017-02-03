//========================================================================================
// Practica 8 Computabilidad y Algoritmia
// Autor: Omar Mendo Mesa
// Implementacion de la clase Tape
//========================================================================================

#include "Tape.hpp"

Tape::Tape(void):
tape_position_(0)
{}

Tape::~Tape(void)
{}

void Tape::read_tape_file(void)
{
	cout << "Introduce la cinta de la TM " << endl;
	char file_name[20];
	cin >> file_name;

	fstream file;
	file.open(file_name);

	if(file.is_open()){
		char symbol;
		file >> symbol;
		do{
			tape_vector.push_back(symbol);
			file >> symbol;
		}while(!file.eof());
	}
	else
		cout << "Error al intentar abrir el fichero con la definición de la cinta " << endl;
}

void Tape::print_tape(void)
{
	for(int i=0; i<tape_vector.size(); i++)
		cout << tape_vector[i];
	cout << endl;
}

char Tape::get_char(void)
{
	return tape_vector[tape_position_];
}

void Tape::set_char(char symbol)
{
	tape_vector[tape_position_]=symbol;
}

void Tape::add_white_symbol_L(void)
{
	vector<char>::iterator it=tape_vector.begin();
	tape_vector.insert(it,'$');
}

void Tape::add_white_symbol_R(void)
{
	tape_vector.push_back('$');
}

void Tape::move_tape(char move)
{
	if(move == 'L'){
		if(tape_position_==0){
			add_white_symbol_L();
		}
		else
		tape_position_--;
	}
	else if(move == 'R'){
		tape_position_++;
		if(tape_position_==tape_vector.size())
			add_white_symbol_R();
	 }
}
