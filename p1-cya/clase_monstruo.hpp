#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Monster{
     unsigned x_;			//Mov eje x de los monstruos
     unsigned y_;			//Mov ehe y de los monstruos
    public:
        Monster(unsigned x, unsigned y);			//Almacena coordenadas de monstruos
        void move_character(char** mapa);		//Mov caracter de monstruos 'O'
       
};
