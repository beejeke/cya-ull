#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Dinero{

  private:
    const vector<int> moneda;

  public:
    Dinero(const vector<int> moneda_);
    ~Dinero();

    vector<int> devolver_cambio(int n,vector<int> monedero,bool &existe);
    int mayor(int suma, int n,int v,vector<int> monedero);
    void imprimir_solucion(vector<int> solucion,vector<int> monedero);  
};
