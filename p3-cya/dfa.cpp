#include "dfa.hpp"
#include <cstring>

using namespace std;



DFA_t::DFA_t(void){}

void DFA_t::create_DFA(char nombrefichero[]) {  //Método de carga del DFA

	ifstream file;
    int id_,trans_;
    bool acept_;
    int *destino;
    char *simbolo;

	file.open(nombrefichero);

	if(file.is_open()==1) {

        while(!file.eof()) {


            file >> num_total_stat_;
            file >> stat_ini_;

            for(int i=0;i<num_total_stat_;i++) {

                file>>id_>>acept_>>trans_;
                simbolo = new char[trans_];
                destino = new int[trans_];

                for(int j=0;j<trans_;j++){
                    file >> simbolo[j] >> destino[j];
                }
            status_t aux(id_,acept_,trans_,simbolo,destino);
            stat_.insert(aux);

            }

        if(stat_.size()==num_total_stat_) {

            cout<<"Automata cargado correctamente"<<endl;
        }

     file.close();
	}

   }

	else {
    cout << "El fichero no existe" << endl;
    }



}

DFA_t::~DFA_t(){}


void DFA_t::show_DFA() {			//Método que muestra el DFA

     cout<<endl<<endl;
     cout<<"-----------------------------------"<<endl;
     cout<<"El DFA actual es : "<<endl;
     cout<<num_total_stat_<<endl;
     cout<<stat_ini_<<endl;

     for(set<status_t>::iterator i=stat_.begin();i!=stat_.end();i++) {

        cout<<(*i);
     }

     cout<<endl;
     cout<<"-----------------------------------"<<endl;

}


void DFA_t::ident_deathstat() {			//Método que identifica los estados de muerte del DFA

    bool existe=false;

    for(set<status_t>::iterator i=stat_.begin();i!=stat_.end();i++) {
        int cont=0;
        status_t aux;
        aux=(*i);
        for(int j=0;j<aux.num_trans_;j++) {
            if(aux.destin_[j]==aux.status_id_) {
                cont++;
            }
        }
      if(cont==aux.num_trans_) {
        cout<<"El estado "<<aux.status_id_<<"  es de muerte"<<endl;
        existe=true;
      }
    }

    if(existe==false) {
        cout<<"No existen estados de muerte en este DFA"<<endl;
    }
}


void DFA_t::check_string() {		//Método que comprueba si una cadena esta aceptada o no en el DFA

    char cadena[85];
    cout<<"Introduzca la cadena de caracteres a comprobar: "<<endl;
    cin>>cadena;
    cin.ignore();

    int actual_state=stat_ini_;
    int next_stat= stat_ini_;
    bool acept_;

    cout<<endl;
    cout<<"-----------------------------------"<<endl;

    cout<<"ESTADO ACTUAL   ENTRADA   SIGUIENTE ESTADO"<<endl;

    for(int j=0;j<strlen(cadena);j++){
        actual_state=next_stat;

        for(set<status_t>::iterator i=stat_.begin();i!= stat_.end();i++){
            status_t aux;
            aux=(*i);

            if(aux.status_id_==actual_state) {
                for(int k=0;k<aux.num_trans_;k++) {
                    if(cadena[j]==aux.symbol_[k]){
                        next_stat=aux.destin_[k];
                    }
                }
            }
        }

    cout<< actual_state<<"    "<<cadena[j]<<"     "<<next_stat<<endl;
    }

   for(set<status_t>::iterator i=stat_.begin();i!= stat_.end();i++) {
       status_t aux;
       aux=(*i);

       if(aux.status_id_==next_stat) {
        acept_=aux.num_acept_;
       }
   }

   if(acept_==true) {
    cout<<"Cadena aceptada"<<endl;
   }
   else {
    cout<<"Cadena no aceptada"<<endl;
   }


}

void DFA_t::start(void){		//Método para introducir en archivo DFA

    char file_name[50];
    menu(1);
    int option;
    cin >> option;

    if(option == 1){
        cout << endl;
        cout << "Introduzca el nombre del fichero del DFA: ";
        cin >> file_name;

        create_DFA(file_name);

        cin.ignore();

        while(option!=5){
            menu(2);
            cin >> option;
            switch(option){

                case 1:
                    start();
                    break;

                case 2:
                    show_DFA();
                    break;

                case 3:
                   ident_deathstat();
                    break;

                case 4:
                    check_string();
                    break;

                case 5:
                exit(0);
                    break;

                default:
                    cout << "Opcion incorrecta" << endl;
                    break;
            }
        }

    }
}

void DFA_t::menu(int n){					//Menú del programa DFA

    if(n==1){

		cout <<"----------------------------------------------"<< endl;
        cout << "1 - Cargar dfa" << endl;
        cout << "5 - Salir" << endl;
        cout <<"----------------------------------------------"<< endl;
        cout << "Introduzca una opcion :  ";

    }else if(n==2){

        cout << endl;

		cout <<"----------------------------------------------"<< endl;
        cout << "1 => Leer DFA desde fichero" << endl;
        cout << "2 => Mostrar DFA" << endl;
        cout << "3 => Identificar estados de muerte del DFA" << endl;
        cout << "4 => Analizar cadena" << endl;
        cout << "5 => Salir" << endl;
        cout <<"----------------------------------------------"<< endl;
        cout << "Introduzca una opcion :  ";
    }
}
