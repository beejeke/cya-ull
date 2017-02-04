#pragma once
#include <stdio.h>
#include <conio.h> //ncurses.h para Linux
#include <stdlib.h>
#include <string>
#include "clase_protagonista.hpp"
#include "clase_monstruo.hpp"


using namespace std;

#define ARRIBA 72			//Se lee el número de tecla de desplazamiento
#define IZQUIERDA 75		//Se lee el número de tecla de desplazamiento
#define DERECHA 77		//Se lee el número de tecla de desplazamiento
#define ABAJO 80			//Se lee el número d tecla de desplazamiento

class masmorra {

private:
    unsigned n_;
    unsigned m_;
    unsigned s_;
    char** x_;			//Almacena el símbolo @
    bool ale_;			//Aleatoriedad de objetos -> No imple.
    bool amuleto;			//Almacena el amuleto del mapa

   Hero *Hero_;			//Puntero al protagonista
   Monster *Monster_;		//Puntero a los monstruos
   
    public:
        masmorra();
        masmorra(unsigned n,unsigned m, bool ale);
        void pintar_masmorra(const char* a);
        void pintar_aleatorio();
        void pintar_fichero(const char* a);
        char** get_mapa();

        bool objetivo();
        bool iteracion_juego();
        void clear();
        
};
