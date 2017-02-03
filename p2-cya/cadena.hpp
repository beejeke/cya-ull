#include <iostream>
#include <fstream>
#include <string>
#pragma once
using namespace std;

class cadena{

	private:
		string palabra;
		int sz_;
	public:
		cadena();
		cadena(string nueva);

		void set(string nueva);

		int get_sz();
		string get_string();

		int concatenar();
		int* pintar();
		string concatenar(string add);
		bool igual( string same);
		string inversa();
		cadena& operator=(const cadena &rhs);
		int operator==(const cadena &rhs) const;
		int operator<(const cadena &rhs) const;
		friend ostream &operator<<(ostream &, const cadena &);
};

cadena::cadena(){}

cadena::cadena(string nueva)
{
	set(nueva);
}

void cadena::set(string nueva)
{
	palabra = nueva;
	sz_ = nueva.size();
}

int cadena::get_sz()
{
	return sz_;
}

string cadena::get_string()
{
	return palabra;
}

string cadena::concatenar(string add)
{
	string aux;
	aux = palabra;
	if (add != "&")
	{
		for (int i = 0; i <add.size(); i++)
		{
			aux.push_back(add[i]);

		}
	}
	return aux;
}

bool cadena::igual(string same)
{
	if( palabra.size()!= same.size() ) return false;
	for(int i=0; i< palabra.size(); i++)
	{
		if(palabra[i] != same[i]) return false;
	} 
	return true;
}

string cadena::inversa()
{
	string aux;
	for (int i = 0; i < palabra.size(); i++)
	{
		aux.push_back(palabra[sz_ - 1 - i]);
	}
	return aux;	
}

cadena& cadena::operator=(const cadena &rhs)
{
   this->palabra = rhs.palabra;
   this->sz_ = rhs.sz_;
   return *this;
}

int cadena::operator==(const cadena &rhs) const
{
   if( this->palabra != rhs.palabra) return 0;
   if( this->sz_ != rhs.sz_) return 0;
   return 1;
}


int cadena::operator<(const cadena &rhs) const
{
   if(this->sz_ < rhs.sz_) return 1;
   if( this->palabra < rhs.palabra ) return 1;
   return 0;
}

ostream &operator<<(ostream &output, const cadena &bbb)
{
   output << " Cadena:" << bbb.palabra << endl;
   return output;
}


