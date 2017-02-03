#include <iostream>
#include <string>
#include "cadena.hpp"
#include "lenguaje.hpp"
using namespace std;

int main()
{
	string aux;
	int c = 100;
	lenguaje mio;
	lenguaje tuyo;
	cout << "Como Desea introducir sus lenguajes"<< endl;
	cout << "1. Por palabras "<< endl;
	cout << "2. Mediante expresion"<< endl;
	cin >> c;
	if(c == 1){
		cout << endl << "Introduzca el numero de cadenas para su lenguaje A: ";
		cin >> c;
		lenguaje mi(c);

		cout << endl << "Introduzca el numero de cadenas para su lenguaje B: ";
		cin >> c;
		lenguaje tu(c);
		mio = mi;
		tuyo = tu;
	}
	else
	{
		if (c == 2)
		{
			cout << endl << "Introduzca su expresion numero 1 ";
			cin >> aux;
			lenguaje mi(aux);

			cout << endl << "Introduzca su expresion numero 2 ";
			cin >> aux;
			lenguaje tu(aux);
			mio = mi;
			tuyo = tu;
		}

	}


	c = 100;
	while(c != 0)
	{
	cout << endl << "---------------MENU---------------";
	cout << endl << "1. Inversa ()";
	cout << endl << "2. Concatenacion(.)";
	cout << endl << "3.Union( | )";
	cout << endl << "4. Interseccion";
	cout << endl << "5. Diferencia";
	cout << endl << "6. Sublenguajes";
	cout << endl << "7. Igualdad de lenguajes";
	cout << endl << "8. Potencia";
	cout << endl << "9. Cierre de Kleene( * )";
	cout << endl << "0. Cerrar";
	cout << endl << "-----------------------------------";
	cout << endl << "Seleccion:  ";
	cin >> c;
		switch(c)
		{

			case 1:
				mio.inversa().pintar();
				break;

			case 2:
				mio.concatenar(tuyo.get_lengua()).pintar();
				break;

			case 3:
				mio.uni(tuyo.get_lengua()).pintar();
				break;

			case 4:
				mio.interseccion(tuyo.get_lengua()).pintar();
				break;

			case 5:
				mio.diferencia(tuyo.get_lengua()).pintar();
				break;

			case 6:
				mio.sublenguajes(tuyo.get_lengua());
				break;

			case 7:
				mio.igual(tuyo.get_lengua());
				break;

			case 8:
				cout <<endl << "Escriba la potencia"<< endl;
				cin >> c;
				mio.potencia(c).pintar();
				c = 100;
				break;

			case 9:
				cout <<endl << "Seleccione el numero de iteraciones deseadas"<< endl;
				cin >> c;
				mio.cierre(c).pintar();
				break;

		}
	}
}
