
#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
#include "state.hpp"
class NFA_t
{
  private:
    set <state_t> estados_;
    state_t estado_inicial_;
    set<char> alfabeto_;
  public:

 /**
 * @name    NFA_t
 * @brief   Constructor por defecto
 */
    NFA_t(void);
 /**
 * @name    ~NFA_t
 * @brief   Destructor
 */
    ~NFA_t(void);

 /**
 * @name    analizar_cadena_recursivo
 * @brief   Analiza la cadena para ver si está aceptada por el lenguaje que reconoce un NFA
 */
    void analizar_cadena_recursivo(int &n, char cadena [], int i, const stringbuf &buffer, const ostream &os, state_t estado, bool &baux);

  /**
  * @name    get_n_estados
  * @brief   Devuelve el número de estados
  */

    int get_n_estados(void);

    /**
  * @name    get_n_estados
  * @brief   Devuelve el número de estados
  */

    int get_n_estados(void) const;

     /**
    * @name    get_inicial
    * @brief   Devuelve el estado inicial
    */

    state_t get_inicial(void);

    /**
    * @name    get_inicial
    * @brief   Devuelve el estado inicial

    */
    state_t get_inicial(void) const;

     /**
    * @name    get_estados
    * @brief   Devuelve el número de estados
    */
    set<state_t> get_estados(void) const;

   /**
 * @name    Comprobar
 * @brief   Comprueba si es un DFA no un NFA lo que se ha cargado en el programa
 */
    bool comprobar(void);

     /**
 * @name    mostrar_estados_muerte
 * @brief   Muestra los estados de muerte
 */
    void mostrar_estados_muerte(void);

    /**
  * @name    leer_fichero
  * @brief   Lee el fichero y devuelve true si se ha leído bien
  */
    bool leer_fichero(void);

    /**
  * @name    mostrar
  * @brief   Muestra el contenido del fichero
  */

    void mostrar(void);

  /**
  * @name    analizar_cadena
  * @brief   analiza la cadena para ver si se acepta
  */

    void analizar_cadena(void);

    /**
  * @name    get_state
  * @brief   Devuelve el estado dependiendo del id que se le pasa
  */

    state_t get_state(const int x);


  private:

  /**
  * @name    operator<<
  * @brief   Sobrecarga del operador salida
  */
    friend ostream &operator<<(ostream &, const NFA_t &);
};
