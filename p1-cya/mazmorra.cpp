
#include <fstream>
#include <iostream>
#include <conio.h>
#include "clase_mazmorra.hpp"
#include "clase_protagonista.cpp"
#include "monstruo.cpp"

using namespace std;


masmorra::masmorra():
n_(0),m_(0),x_(NULL),ale_(false)
{}

masmorra::masmorra(unsigned n,unsigned m, bool ale):
n_(n),m_(m),ale_(ale)
{
  x_=new char*[n_];
    for(int i=0;i < n_;i++){
        x_[i]=new char[m_];
    }
}
void masmorra::pintar_masmorra(const char* a){

            if (ale_){     // pinta la masmorra de forma aleatoria
                pintar_aleatorio();
            }
            else{         // pinta la masmorra desde la apertura de un fichero
                pintar_fichero(a);
            }
}

void masmorra::pintar_fichero(const char* a){		//Recorre el fichero y lo muestra
       
        int mostros_=0;
        fstream file;					//Apertura del fichero
        file.open(a,fstream::in);		
    
            if(file.is_open()){		//Si el archivo esta abierto, lee n_ y m_
                file >> n_;
                file >> m_;
                x_=new char*[n_];

                for(int i=0;i<n_;i++){
                    x_[i]=new char[m_];				//Da memoria a m_
                }

                    for (unsigned i=0;i<n_;i++){
                        for(unsigned j=0;j<m_;j++){
                            file >> x_[i][j];
                             cout << x_[i][j];
                             if (x_[i][j]=='@'){
                                Hero_=new Hero(i,j,5); //Pasa los parámetros de mov y salud
                             }
                             else if (x_[i][j]=='O'){
                                 mostros_++;
                               
                             }
                             else if(x_[i][j]=='-'){
                             }
                          } 					// Llave  del segundo
                            cout << endl;
                        } 						// Llave del primer for
                } 							// Llave del is_open
               
           
} 											// Llave de la funcion



char** masmorra::get_mapa(){
        return x_;
}
bool masmorra::iteracion_juego(){
        if (kbhit()){
            
            for (int i=0;i<n_;i++){
                for(int j=0;j<m_;j++){
                    cout << x_[i][j];
                        Hero_->move_character(x_);

                }
                cout << endl;
            }

        }
        return true;
}

void masmorra::pintar_aleatorio(){

 //NO IMPLEMENTADO
}

void clear() {
    
    std::cout << "\x1B[2J\x1B[H";
}
