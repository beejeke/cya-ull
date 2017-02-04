#include <iostream>
#include "clase_protagonista.hpp"


using namespace std;


Hero::Hero(unsigned x, unsigned y,int vida):			//Pasa los parámetros del personaje
x_(x),y_(y),vida_(vida)							//Parámetros de coordenadas y vida
{
amuleto_=false;
}


void Hero::move_character(char** mapa){			//Movimiento del personaje
            char a='@';
                if (kbhit()){// kbhit funcion de conio.h para detectar si se presiona una tecla
                char tecla =getch(); //damos el valor de la tecla a una variable
                       if ((tecla==ARRIBA )&&( mapa[x_-1][y_]!='*') && (mapa[x_-1][y_]!='-')) {
                            mapa[x_][y_]='.';
                            x_--;
                            mapa[x_][y_]=a;
                       } // si presiinamos j se mueve hacia la izquierda
                       if ((tecla==ABAJO )&& (mapa[x_+1][y_]!='*') && (mapa[x_+1][y_]!='-')){
                            mapa[x_][y_]='.';
                            x_++;
                            mapa[x_][y_]=a;
                            } // si presionamos l se mueve hacia la derecha
                       if ((tecla==IZQUIERDA) && (mapa[x_][y_-1]!='*') && (mapa[x_][y_-1]!='-')){
                            mapa[x_][y_]='.';
                            y_--;
                            mapa[x_][y_]=a;
                       }// si presionamos i se mueve hacia arriba
                       if ((tecla==DERECHA) &&  (mapa[x_][y_+1]!='*') && (mapa[x_][y_+1]!='-')){
                            mapa[x_][y_]='.';
                            y_++;
                            mapa[x_][y_]=a;
                            }//si presionamos k se mueve hacia abajo
                       if (mapa[x_][y_]!='&'){
                            mapa[x_][y_]=a;
                            amuleto_=true;
                            }//si presionamos k se mueve hacia abajo
                }
}

void Hero::salud(){
        vida_--;				//Al chocar, te resta una vida
}

unsigned Hero::get_vida(){
        return vida_;
}

bool Hero::amuleto(){
    amuleto_=true;			//Al conseguirlo, te devuelve el amuleto
    return amuleto_;
}
