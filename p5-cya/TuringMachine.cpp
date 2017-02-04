//========================================================================================
// Practica 8 Computabilidad y Algoritmia
// Autor: Omar Mendo Mesa
// Implementacion de la clase TuringMachine
//========================================================================================

#include "TuringMachine.hpp"

TuringMachine::TuringMachine()
{
	read_TM();
	tape_=Tape();
	tape_.read_tape_file();
}

TuringMachine::~TuringMachine()
{}

void TuringMachine::read_TM(void)
{
	cout << "Introduce el nombre del fichero que contiene la máquina de turing" << endl;
	char file_name[20];
	cin >> file_name;
	fstream file;
	file.open(file_name);

	if(file.is_open()){

		string line_of_acepted_states;

		file >> number_of_states_;
		file >> start_state_;
		file.seekp(4, ios::beg);
		getline(file, line_of_acepted_states);

		int i=0;
		int contador=0;

		do{
			if(line_of_acepted_states[i]==' ')
				contador++;
			i++;
		}while(line_of_acepted_states[i] != '\0');

		contador++;

		file.seekp(4, ios::beg);

		int acepted_state;

		for(int i=0; i<contador; i++){
			file >> acepted_state;
			acepted_states_.push_back(acepted_state);
		}

		file >> number_of_tuples_;

		//Lets start creating the t-uplas
		int state;
		char read_symbol;
		char write_symbol;
		char move;
		int next_state;

		do{

			file >> state;
			file >> read_symbol;
			file >> write_symbol;
			file >> move;
			file >> next_state;

			Tuple new_tuple = Tuple(state, read_symbol, write_symbol, move, next_state);
			tuples_vector_.push_back(new_tuple);

		}while(!file.eof());
	}
	else
		cout << "Error al abrir el fichero" << endl;
}

void TuringMachine::print_TM(void)
{
	cout << "Maquina de Turing: " << endl << endl;
	cout << number_of_states_ << endl;
	cout << start_state_ << endl;

	for(int i=0; i<acepted_states_.size(); i++)
		cout << acepted_states_[i] << " ";
	cout << endl;
	cout << number_of_tuples_ << endl;

	for(int i=0; i<number_of_tuples_; i++){
		cout << tuples_vector_[i].get_state() << " ";
		cout << tuples_vector_[i].get_read_symbol() << " ";
		cout << tuples_vector_[i].get_write_symbol() << " ";
		cout << tuples_vector_[i].get_move() << " ";
		cout << tuples_vector_[i].get_next_state() << endl;
	}
	cout << "Cinta: " << endl;
	tape_.print_tape();

}

void TuringMachine::TM_check_tape(void)
{
	int current_pos=0;
	bool stop=false;
	int current_state=start_state_;
	Tuple current_tuple;
	bool state_found=false;
	bool acepted=false;

	do{

		for(int j=0; j<tuples_vector_.size(); j++){
			if((tuples_vector_[j].get_read_symbol()==tape_.get_char()) && (tuples_vector_[j].get_state()==current_state)){
				current_tuple=tuples_vector_[j];
				j=tuples_vector_.size();
				state_found=true;
			}
			else
				state_found=false;
		}
		if(state_found==true){
			tape_.set_char(current_tuple.get_write_symbol());
			tape_.move_tape(current_tuple.get_move());
			current_state=current_tuple.get_next_state();
		}
		else
			stop=true;

	cout << endl;
	if(!stop)
	tape_.print_tape();


}while(!stop);

for(int i=0; i <acepted_states_.size(); i++)
	if(current_state==acepted_states_[i]){
		cout << "Cadena aceptada" << endl;
		acepted=true;
	}

	if(acepted==false)
		cout << "Cadena no aceptada" << endl;
}
