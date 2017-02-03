#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "cadena.hpp"

using namespace std;
class lenguaje
{
	private:
		set<cadena> lengua;
		int sz_;
		bool infinito = false;

	public:
		lenguaje();
		lenguaje(int n);
		lenguaje(string n);
		~lenguaje();

		void add(string nuevo);
		set<cadena> get_lengua();
		void pintar();
		int get_sz();
		string polaco(string exp);
		lenguaje calcular(string intro);
		void destruir();

		lenguaje inversa();
		lenguaje concatenar(set<cadena> otro);
		lenguaje uni(set<cadena> otro);
		lenguaje interseccion(set<cadena> otro);
		lenguaje diferencia(set<cadena> otro);


		void sublenguajes(set<cadena> otro);
		void igual(set<cadena> otro);

		lenguaje potencia(int pot);
		lenguaje cierre(int n);




};


lenguaje::lenguaje()
{
sz_ = 0;
}

lenguaje::lenguaje(int n)
{
	sz_ = 0;
	for(int i = 0; i < n; i++)
	{
		string aux;
		cout << endl << "Introduzca la cadena numero "<< i +1<< " de su lenguaje"<< endl;
		cin >> aux;
		add(aux);
	}
}

lenguaje::lenguaje(string n)
{
	sz_ = 0;
	if (n[0] == '{')
	{
		if(n.size() > 2)
		{
			int i = 0;
			string aux;
			while(n[i] != '}')
			{
				i++;
				if(n[i] != ',' && n[i] != '}')
				{

					aux.push_back(n[i]);
				}
				else
				{
					add(aux);
					aux.clear();
				}
			}
		}
	}
	else	lengua = calcular(polaco(n)).get_lengua();

}
lenguaje::~lenguaje()
{
	destruir();
}

void lenguaje::destruir()
{
	lengua.clear();
}
string lenguaje::polaco(string exp )
{
	vector<char> simbolos;
	vector<char> operadores;
	for(int i = 0; i< exp.size(); i++)
	{
		char c = exp[i];
		if(c == '*' || c == '.' || c == '|' || c == '(' || c == ')')
		{

			switch(c)
			{
				case '|':
					if(operadores.empty()) operadores.push_back(c);
					else
					{
						while(!operadores.empty() && operadores.back() != '(' && operadores.back() != '|')
						{
							simbolos.push_back(operadores.back());
							operadores.pop_back();
						}
						operadores.push_back(c);
					}
					break;

				case '.':
					if(operadores.empty() || operadores.back() == '|' || operadores.back() == '.') operadores.push_back(c);
					else
					{
						while(!operadores.empty() && operadores.back() != '('  && operadores.back() != '|' && operadores.back() != '.')
						{
							simbolos.push_back(operadores.back());
							operadores.pop_back();
						}
						operadores.push_back(c);
					}
					break;

				case '*':
					if(operadores.empty() || operadores.back() == '|'|| operadores.back() == '.' || operadores.back() == '*') operadores.push_back(c);
					else
					{
						while(!operadores.empty() && operadores.back() != '('  && operadores.back() != '|' && operadores.back() != '.' || operadores.back() != '*')
						{
							simbolos.push_back(operadores.back());
							operadores.pop_back();
						}
						operadores.push_back(c);
					}
					break;

				case '(':
					operadores.push_back(c);
					break;

				case ')':
					while(operadores.back() != '(' && !operadores.empty())
					{
						simbolos.push_back(operadores.back());
						operadores.pop_back();
					}
					operadores.pop_back();
					break;
			}
		}
		else simbolos.push_back(c);
	}

	while(!operadores.empty())
	{
		simbolos.push_back(operadores.back());
		operadores.pop_back();
	}
	cout << endl;
	string end;
	for (int i = 0; i< simbolos.size(); i++)
	{

		end.push_back(simbolos[i]);
		cout << simbolos[i];
	}
	return end;
}

lenguaje lenguaje::calcular(string intro)
{

	vector<lenguaje> aux;

	for(int i = 0; i< intro.size(); i++)
	{
		char c = intro[i];
		if(c == '*' || c == '.' || c == '|' )
		{
			lenguaje xua;
			lenguaje uax;
			switch(c)
			{
				case '|':

					xua = aux.back();
					aux.pop_back();
					uax = aux.back();
					aux.pop_back();
					uax= uax.uni(xua.get_lengua());
					aux.push_back(uax);
					break;

				case '.':
					xua  = aux.back();
					aux.pop_back();
					uax = aux.back();
					aux.pop_back();
					uax= uax.concatenar(xua.get_lengua());
					aux.push_back(uax);
					break;

				case '*':
					xua  = aux.back();
					aux.pop_back();
					xua = xua.cierre(3);
					aux.push_back(xua);
					infinito = true;
					break;
			}
		}
		else
		{
			lenguaje xua;
			string x;
			x.push_back(c);
			xua.add(x);
			aux.push_back(xua);
			sz_ ++;
		}
	}
	lenguaje xua = aux.back();
	return xua;
}

void lenguaje::add(string nuevo)
{
	cadena aux(nuevo);
	lengua.insert(aux);
	sz_++;
}

void lenguaje::pintar()
{

	cout << "{";
	for(set<cadena>::iterator j = lengua.begin(); j != lengua.end(); j++)
	{
			cadena aux = *j;
			cout << aux.get_string()<< " , ";
	}
	if (infinito == true){
		cout << ",...}";
	}
	else
	{
		cout << "}";
	}
	cout << endl;
}

lenguaje lenguaje::inversa()					//Inversa de los lenguajes
{
	lenguaje aux;
	cadena xua;
	for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		xua =*i;
		aux.add(xua.inversa());
	}
	cout << "}";
	return aux;
}

lenguaje lenguaje::concatenar(set<cadena> otro)			//Concatenacion de los lenguajes A y B
{
	lenguaje aux;
	if(!otro.empty()){
		for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			for(set<cadena>::iterator j = otro.begin(); j != otro.end(); j++)
			{
				cadena xua = *i;
				cadena uxa = *j;

					aux.add(xua.concatenar(uxa.get_string() ));

			}
		}
	}
	else
	{
		for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			cadena xua = *i;
			aux.add(xua.get_string());
		}

	}
	return aux;
}

set<cadena> lenguaje::get_lengua()
{
	return lengua;
}

lenguaje lenguaje::interseccion(set<cadena> otro)		//Interseccion de los dos lenguajes
{
	lenguaje aux;
	for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		for(set<cadena>::iterator j = otro.begin(); j != otro.end(); j++)
		{
			cadena xua = *i;
			cadena uxa = *j;
			if( xua == uxa)
			{
				aux.add(xua.get_string() );
			}
		}
	}
	return aux;
}

lenguaje lenguaje::uni(set<cadena> otro)			//Union de los dos lenguajes
{
	lenguaje aux;
	for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		cadena xua = *i;
		aux.add(xua.get_string());
	}
	for(set<cadena>::iterator j = otro.begin(); j != otro.end(); j++)
	{
		cadena xua = *j;
		aux.add(xua.get_string());
	}
	return aux;
}

lenguaje lenguaje::diferencia(set<cadena> otro)			//Diferencia de los dos lenguajes
{
	lenguaje aux;
	for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		bool a = false;
		cadena xua = *i;
		for(set<cadena>::iterator j = otro.begin(); j != otro.end(); j++)
		{

			cadena uxa = *j;
			if( xua == uxa)
			{
				a = true;
			}
		}
		if ( a == false) aux.add(xua.get_string() );
	}

	for(set<cadena>::iterator i = otro.begin(); i != otro.end(); i++)
	{
		bool a = false;
		cadena xua = *i;
		for(set<cadena>::iterator j = lengua.begin(); j != lengua.end(); j++)
		{

			cadena uxa = *j;
			if( xua == uxa)
			{
				a = true;
			}
		}
		if ( a == false) aux.add(xua.get_string() );
	}
	return aux;
}

void lenguaje::sublenguajes(set<cadena> otro)		//Comprueba si el lenguaje A es un sublenguaje de B
{
	bool a = false;
	if(sz_ <= otro.size() )
	{
		for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			bool b = false;
			for(set<cadena>::iterator j = otro.begin(); j != otro.end(); j++)
			{
				cadena xua = *i;
				cadena uxa = *j;
				if( xua == uxa)
				{
					b = true;
				}
			}
			if (b == false) a = true;
		}
		if(a == false) cout << endl << "La cadena A es subcadena de la cadena B"<< endl;
		else cout << endl << "La cadena A no es subcadena de la cadena B"<< endl;
	}
	else cout << endl << "La cadena A no es subcadena de la cadena B"<< endl;

}

void lenguaje::igual(set<cadena> otro)  //Comprueba si los dos lenguajes son iguales
{
	bool a = false;
	if(sz_ == otro.size() )
	{
		for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			bool b = false;
			for(set<cadena>::iterator j = otro.begin(); j != otro.end(); j++)
			{
				cadena xua = *i;
				cadena uxa = *j;
				if( xua == uxa)
				{
					b = true;
				}
			}
			if (b == false) a = true;
		}
		if(a == false) cout << endl << "La cadena A es igual a la cadena B"<< endl;
		else cout << endl << "La cadena A no es igual a la cadena B"<< endl;
	}
	else cout << endl << "La cadena A no es igual a la cadena B"<< endl;

}

lenguaje lenguaje::potencia(int pot)		//Realiza la potencia de un lenguaje
{
	int j = pot;

	lenguaje aux;
	lenguaje xua;
	if(j == 0)
	{
		aux.add("&");
		return aux;
	}
	for(set<cadena>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			cadena xua = *i;
			aux.add(xua.get_string());
		}
	if( j-1 > 0)
	{
		j--;
		xua = potencia(j);

	}

	return aux.concatenar(xua.get_lengua());

}

lenguaje lenguaje::cierre(int n)			//Realiza el cierre de Kleene de los lenguajes
{
	lenguaje aux;
	for (int i = 0; i< n; i++)
	{
		aux = aux.uni(potencia(i).get_lengua());
	}
	return aux;
}
