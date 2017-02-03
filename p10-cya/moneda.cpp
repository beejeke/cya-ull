#include "clase_moneda.hpp"


Dinero::Dinero(const vector<int> moneda_):
moneda(moneda_)
{}

Dinero::~Dinero()
{}


int Dinero::mayor(int suma,int n,int pos,vector<int> monedero){

    int resul = -1;
    for(int i=pos; i < monedero.size(); i++){

        if( (suma + monedero[i]) <= n){
            resul = i;
            break;
        }
    }
    return resul;
}

vector<int> Dinero::devolver_cambio(int n,vector<int> monedero,bool &existe)
{
    vector<int> solucion(monedero.size()); // conjunto de la solucion
    int suma=0; // suma de los elementos de Solucion
    int pos=0;

    while(suma != n){ // suma != n

        pos = mayor(suma,n,pos,monedero); // elige el mayor elemento --> pos

        if(pos == -1){ //no existe v entonces

            cout << "NO EXISTE SOLUCION" << endl;
            existe = false;
            break;

        }else{

            solucion[pos]++; //guarda los elementos de la solucion

        }
        suma = suma + monedero[pos];

    }

    return solucion;
}


void Dinero::imprimir_solucion(vector<int> solucion,vector<int> monedero)
{
    int aux=0;

    for(int i=0; i < solucion.size(); i++){

        if(solucion[i] > 0 )
        aux = i;
    }
   // cout << "VALOR DE AUX --> " << aux << endl;
    for(int i = 0 ; i < solucion.size() ; i++){

        if(solucion[i] > 0 ){
            int pos = solucion[i];

            if(pos == 1){ // una sola unidad
                if(monedero[i] <= 50){
                    cout << monedero[i] << "¢";
                }else{
                    cout << monedero[i] / 100 <<"€";
                }

            }else{ // mas de un billete o moneda

                if(monedero[i] <= 50){
                    cout << solucion[i] << "x"<< monedero[i] << "¢";
                }else{
                    cout << solucion[i] << "x" << monedero[i] / 100 <<"€";
                }
              }

              if(i !=  aux)
                cout << ",";
        }
    }
}
