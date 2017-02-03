
#pragma once
#include <set>
#include <iterator>
#include "transition.hpp"

class state_t
{
  private:
    set <transition_state_t> transiciones_;
    bool aceptacion_;
    int ID_;
  public:
    state_t(void);
    state_t(const state_t &);

    state_t(set<transition_state_t> transiciones, bool aceptacion, int id);

    ~state_t(void);
    bool reconocido(char x);
    bool reconocido(char x) const;

    void mostrar(void);
    void mostrar(void) const;

    int operator==(const int x) const;

    set<int> get_conjunto_transiciones(char x);
    set<int> get_conjunto_transiciones(char x) const;
    set<int> get_epsilon_clausura(void);
    set<int> get_epsilon_clausura(void) const;

    set <transition_state_t> get_transiciones(void) const;

    state_t& operator=(const state_t &x);
    int operator<(const state_t &x) const;

    bool aceptacion(void);
    bool aceptacion(void) const;

    bool estado_muerte(void);
    bool estado_muerte(void) const;

    int get_id(void);
    int get_id(void) const;

  private:
    friend ostream &operator<<(ostream &, const state_t &);
};
