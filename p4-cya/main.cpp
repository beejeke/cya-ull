#include "NFA.hpp"

int main (void)
{
  NFA_t NFA;
  while(!NFA.leer_fichero());
  
  int opcion;
  do
  {
    cout<<"MENU:"<<endl;
    cout<<"1->Mostrar NFA."<<endl;
    cout<<"2->Mostrar estados de muerte."<<endl;
    cout<<"3->Analizar cadena."<<endl;
    cout<<"4->Leer fichero."<<endl;
    cout<<"5->Salir."<<endl;
    cout<<"Introduzca una opción: ";
    cin>>opcion;

    switch(opcion)
    {
      case 1:
        NFA.mostrar();
        break;
      case 2:
        NFA.mostrar_estados_muerte();
        break;
      case 3:
        NFA.analizar_cadena();
        break;
      case 4:
        NFA.leer_fichero();
        break;
      case 5:
        break;
      default:
        cout<<"Opción no encontrada."<<endl;
        break;
    }
  }while(opcion!=5);
}