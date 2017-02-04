#pragma once
#include <stdio.h>
#include <conio.h>		//ncurses.h para Linux
#include <stdlib.h>
#include <string>

using namespace std;

#define ARRIBA 72					//Se lee el número de tecla de desplazamiento
#define IZQUIERDA 75				//Se lee el número de tecla de desplazamiento
#define DERECHA 77				//Se lee el número de tecla de desplazamiento
#define ABAJO 80					//Se lee el número de tecla de desplazamiento

class Hero {						//Clase del personaje

        int vida_;				//Se declara la vida del personaje
        unsigned x_;				//Mov de coordenadas x del personaje
        unsigned y_;				//Mov de coordenadas y del personaje
        bool amuleto_;				//Amuleto, se trabaja como un booleano

    public:
        Hero(unsigned x, unsigned y,int vida);		//Pasa los parámetros del personaje
        void move_character(char** mapa);			//Doble puntero al mapa
        void salud();								//Salud-> te deuelve la vida
        unsigned get_vida();						
        bool amuleto();
};
