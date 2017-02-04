#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include "clase_moneda.hpp"

using namespace std;

//g++ -std=c++11

int main(void) // FUNCION PRINCIPAL
{

    float valor;
    int num;
    bool existe=true;

    const vector<int> dinerito = {50000,20000,10000,5000,1000,500,200,100,50,20,10,5,2,1};

    Dinero M(dinerito);

    cout << endl;

    cout << "----------------------------------------------------------------------------" << endl;
    cout << "-                                                                          -" << endl;
    cout << "-   [Aplicación de algoritmo devolución de cambio con billetes mejorada]   -" << endl;
    cout << "-                                                                          -" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Introduzca la cantidad 'n' para obtener la devolución mínima: ";
    cout << endl;
    cin >> valor;
    cout << "--------------------------------------------------------------------" << endl;

    //devuelve el argumento redondeado hacia arriba y lo multiplica por 100
    num = (int)ceil(valor * 100);

    vector<int> solucion = M.devolver_cambio(num,dinerito,existe);

    if(existe == true){

        cout << " Cambio = {";
        M.imprimir_solucion(solucion,dinerito);
        cout << "}" << endl;

    }


}
