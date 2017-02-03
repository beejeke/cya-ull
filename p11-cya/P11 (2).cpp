

//Autor: Omar Mendo Mesa


#include <iostream>
#include <cstdlib>

int cont_der = 0;
int cont_izq = 0;

void mostrar_vector(int* A, int begin, int size) { //Función que muestra el vector randomizado

  if(size-begin < 1)
    return;
  
    std::cout<<"[ ";
	 for(int i=begin; i<size; ++i)
            	std::cout<<A[i]<<" ";
			std::cout<<" ] ";
}



void fusion( int* A, int* B, int izq, int centro, int der){

            //Procedimiento de fusión del vector randomizado de tamaño "n"

    int final_izq, nroelem, tmp;
        final_izq = centro - 1;
            tmp = izq;
            nroelem=der-izq+1;
            while ((izq <= final_izq) && (centro <= der)){
                if (A[izq] < A[centro]){
                    B[tmp]=A[izq];
                        izq++;
                        }
                 else {
                    B[tmp]=A[centro];
                        centro++;
                    }
                        tmp++;
            }

            while (izq <= final_izq){

                B[tmp]=A[izq];
                    tmp++;
                        izq++;
                         }

               while (centro <= der){
                    B[tmp]=A[centro];
                        tmp++;
                            centro++;
                          }

        for(int i=0;i<nroelem;i++){
            A[der]=B[der];
                der--;
                }

        if (A[izq] < A[centro]){
            cont_izq++;

        }

        if (B[tmp]==A[centro]){
            cont_der++;
        }
}

void sort_fusion(int* A, int* B, int izq, int der, int& nivel){

            //Ordenación por fusión del vector randomizado de tamaño "n"
  
    std::cout<<"\n\t\tNIVEL DE RECURSION:"<<nivel<<std::endl;
	nivel++;

  bool verbose = true;  
        //Valor booleano que si es "true" muestra los extremos del subvector que se ordena en cada etapa
    int centro;
        if (izq < der) {
	  
	  std::cout<<"\n\tDividiendo[...]"<<std::endl;
            centro=(izq+der)/2;
	    mostrar_vector(A, izq, der);
	    std::cout<<std::endl;
	    
            sort_fusion(A,B,izq,centro, nivel);
		mostrar_vector(A, izq, centro);
		std::cout<<std::endl;
		
                sort_fusion(A,B,centro+1,der, nivel);
		mostrar_vector(A, centro+1, der);
		std::cout<<"\tFusionando[...]"<<std::endl;
		
                fusion(A,B,izq,centro+1,der);
                }
}


int main (void){


        std::cout<<std::endl;
        std::cout<<"*******PROGRAMA DE ORDENACIÓN POR FUSIÓN DE VECTORES*******"<<std::endl;
        std::cout<<std::endl;

    int size_array;
        std::cout<<"Introduzca el tamaño del vector que desee: ";
            std::cin>>size_array;

	int vector_A[size_array], vector_B[size_array]; //Array de datos y Array auxiliar

    for(int i=0; i<size_array; ++i) //Rellenamos el vector_A con numeros aleatorios entre 0-100
        vector_A[i] = rand() % 100 + 1;

    std::cout<<"Este es su -vector A- desordenado ->[ ";
          for(const int& i: vector_A)
            	std::cout<<i<<" ";
			std::cout<<" ]"<<std::endl;

    int nivel_rec=0;
        sort_fusion(vector_A, vector_B, 0, size_array-1,nivel_rec); //Invocamos a la ordenacion_por_fusion
        std::cout<<"\nEl resultado de la ordenación por fusión es: "<<std::endl;
	  
	 std::cout<<"Este es su -vector A- ordenado -> [ ";
	    for(const int& i: vector_A)
            	std::cout<<i<<" ";
			std::cout<<" ]"<<std::endl;
            std::cout<<std::endl;


            std::cout << "El índice de iteraciones por la izquierda son: "<< std::endl;
            std::cout << cont_izq << std::endl;
            std::cout << "El índice de iteraciones por la derecha son: "<< std::endl;
            std::cout << cont_der << std::endl;
            std::cout << std::endl;
        
        return 0;
}

//MODIFICACIÓN: Atributo contador de izq y der. Sumar ambos y dividir entre pasos
