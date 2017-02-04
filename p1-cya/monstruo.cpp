#include <iostream>
#include "clase_monstruo.hpp"

using namespace std;


Monster::Monster(unsigned x, unsigned y):
x_(x),y_(y)
{}

void Monster::move_character(char** mapa){
            unsigned int random_;
           int seed=0;
            const char a='O';
            if (kbhit()){// kbhit funcion de conio.h para detectar si se presiona una tecla
                 char tecla =getch();
                 srand(seed++);
                 random_=rand()%4;
                  
                  
                       if ((random_==0 )&&( mapa[x_+1][y_]!='*') && (mapa[x_+1][y_]!=' ')&& (mapa[x_+1][y_]!='+') ){
                            x_++;
                            mapa[x_][y_]=a;
                       } // si presiinamos j se mueve hacia la izquierda
                       if ((random_==1)&& (mapa[x_-1][y_]!='*') && (mapa[x_-1][y_]!=' ')&& (mapa[x_-1][y_]!='+') ){
                            x_--;
                            mapa[x_][y_]=a;
                       } // si presionamos l se mueve hacia la derecha
                       if ((random_==2) && (mapa[x_][y_+1]!='*') && (mapa[x_][y_+1]!=' ')&& (mapa[x_][y_+1]!='+') ){
                            y_++;
                            mapa[x_][y_]=a;
                       } // si presionamos i se mueve hacia arriba
                       if ((random_==3) &&  (mapa[x_][y_-1]!='*') && (mapa[x_][y_-1]!=' ') && (mapa[x_][y_-1]!='+') ){
                            y_--;
                            mapa[x_][y_]=a;
                       }
                  }
            }
                  


