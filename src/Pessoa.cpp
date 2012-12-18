#include "Pessoa.h"


Pessoa::Pessoa (string nome, string contacto, string morada){
	this->nome=nome;
	this->contacto=contacto;
	this->morada=morada;

}



Pessoa::~Pessoa(){

}

string Pessoa::getNome() const {
	return nome;
}

void Pessoa::setNome(string nome){
	this->nome=nome;
}


string Pessoa::getContacto() const{
	return contacto;
}

void Pessoa::setContacto(string contacto){
	this->contacto=contacto;
}

string Pessoa::getMorada() const{
	return morada;
}

void Pessoa::setMorada(string morada){
	this->morada=morada;
}


/*
string Pessoa::imprime(const Pessoa & peeps){
	stringstream ss;
	ss << nome<< endl;
	ss << contacto << endl;
	ss << morada <<endl;
	return ss;
}*/



