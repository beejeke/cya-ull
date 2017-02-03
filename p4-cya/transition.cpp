#include "transition.hpp"


transition_state_t::transition_state_t(void):
  caracter_(0),
  next_state_(-1)
  {}


transition_state_t::transition_state_t(char caracter, int next_state):
  caracter_(caracter),
  next_state_(next_state)
  {}


transition_state_t::transition_state_t(const transition_state_t &cp)
{
  this->caracter_=cp.get_char();
  this->next_state_=cp.get_next_state();
}


char transition_state_t::get_char(void) const
{
  return(caracter_);
}


transition_state_t::~transition_state_t(void)
{}


bool transition_state_t::reconocido(char x)
{
  return(caracter_==x);
}


bool transition_state_t::reconocido(char x) const
{
  return(caracter_==x);
}


int transition_state_t::get_next_state(void)
{
  return(next_state_);
}


int transition_state_t::get_next_state(void) const
{
  return(next_state_);
}


void transition_state_t::mostrar(void)
{
  cout<<" "<<caracter_<<" "<<next_state_;
}


void transition_state_t::mostrar(void) const
{
  cout<<" "<<caracter_<<" "<<next_state_;
}


char transition_state_t::get_char(void)
{
  return(caracter_);
}


transition_state_t& transition_state_t::operator=(const transition_state_t &x)
{
  this->caracter_= x.get_char();
  this->next_state_=x.get_next_state();
  return(*this);
}


ostream &operator<<(ostream &output, const transition_state_t &x)
{
  output<<" "<<x.get_char()<<" "<<x.get_next_state();
  return(output);
}


int transition_state_t::operator<(const transition_state_t &x) const
{
  if(this->get_char()==x.get_char()&&this->get_next_state()<x.get_next_state())
    return(1);
  if(this->get_char()<x.get_char())
    return(1);
  return 0;
}
