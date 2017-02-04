#include <iostream>
#include "mazmorra.cpp"
#include "clase_protagonista.hpp"
#include "clase_monstruo.hpp"


int main(void){

	
int opcion;

cout << endl;
cout << "********************** -ROGUELIKE- *********************" << endl;
cout << "*												*" << endl;
cout << "*												*" << endl;
cout << "*				Seleccione opcion:				*" << endl;
cout << "*												*" << endl;
cout << "*				1.Crear la mazmorra				*" << endl;
cout << "*				2.Leer mazmorra (fichero)			*" << endl;
cout << "*				3.Salir							*" << endl;
cout << "*												*" << endl;
cout << "********************************************************" << endl;
cin >> opcion;

	while(opcion!=3){
	

	switch(opcion){
	
		case 2:
			bool gameover_=true;
			string z="dungeon_lvl1.txt";  //Lee el fichero en cuenstión
			const char* nivel_=z.c_str();  //Se almacenan los símbolos en el char

                    masmorra M;
                   M.pintar_masmorra(nivel_);  //Al leer el fichero, muestra por pantalla 
				   
                    while(gameover_){
                        gameover_=M.iteracion_juego();
                   }
              }				//Añadir un SCRATCH para el refresco del juego al mover
		break;
		
		//std::cout << "\x1B[2J\x1B[H";   scracth para no actualizar el tablero->PREGUNTAR
	}
	return 0;
}
