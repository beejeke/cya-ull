
#include "status.hpp"

using namespace std;



status_t::status_t(void):
status_id_(0),
num_trans_(0),
num_acept_(false),  //
symbol_(NULL),
destin_(NULL)
{}

status_t::status_t(int status_id,bool num_acept,int num_trans,char* symbol,int* destin):
status_id_(status_id),
num_trans_(num_trans),
num_acept_(num_acept),
symbol_(NULL),
destin_(NULL)
{
	symbol_ =new char[num_trans_];
	destin_= new int[num_trans_];

	for(int i=0;i<num_trans_;i++){
		symbol_[i]=symbol[i];
		destin_[i]=destin[i];
	}

	if((symbol_==NULL) || (destin_==NULL)) {
		cout<<"Error."<<endl;
	}

}

status_t::status_t(const status_t &cop) {

	status_id_=cop.status_id_;
	num_trans_=cop.num_trans_;
	num_acept_=cop.num_acept_;
	symbol_=cop.symbol_;
	destin_=cop.destin_;

}

//Metodo destructor de la clase estado

status_t::~status_t(){}


int status_t::operator<(const status_t &rhs) const {
	if(this->status_id_< rhs.status_id_)
		return 1;
	return 0;

}

int status_t::operator==(const status_t &rhs) const {

	if(this->status_id_!=rhs.status_id_)
		return 0;
	if(this->num_acept_!=rhs.num_acept_)
		return 0;
	if(this->num_trans_!=rhs.num_trans_)
		return 0;

	for(int i=0;i<num_trans_;i++) {
		if(symbol_[i]!=rhs.symbol_[i])
			return 0;
		if(destin_[i]!=rhs.destin_[i])
			return 0;
	}

 return 1;
}

status_t& status_t::operator=(const status_t &rhs) {

	this->status_id_=rhs.status_id_;
	this->num_acept_=rhs.num_acept_;
	this->num_trans_=rhs.num_trans_;

	symbol_ = new char[num_trans_];
	destin_ = new int[num_trans_];

	for(int i=0;i<num_trans_;i++) {
		symbol_[i]=rhs.symbol_[i];
		destin_[i]=rhs.destin_[i];
	}

return *this;

}

std::ostream &operator<<(std::ostream &output,const status_t &bbb) {

	output<<bbb.status_id_<<" "<<bbb.num_acept_<< " "<<bbb.num_trans_<< " ";
	for(int i=0;i<bbb.num_trans_;i++) {
		output<<bbb.symbol_[i]<<" "<<bbb.destin_[i]<<" ";
	}
	cout<<endl;

return output;
}
