/*
 * Veiculo.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#include "Veiculo.h"

int Veiculo::ultimoID = 0;

Veiculo::Veiculo(string mc, string mdl, string mt, int id) {

	this->id = id;
	marca = mc;
	modelo = mdl;
	matricula = mt;

	if(id > ultimoID) {
		ultimoID = id;
	}

}

Veiculo::Veiculo(string mc, string mdl, string mt) {

	ultimoID++;
	id = ultimoID;
	marca = mc;
	modelo = mdl;
	matricula = mt;

}

//Operador cout de veiculo
ostream & operator<<(ostream & o, const Veiculo & v) {
	o << "ID: " << v.getID() << endl;
	o << "Marca: " << v.getMarca() << endl;
	o << "Modelo: " << v.getModelo() << endl;
	o << "Matricula: " << v.getMatricula() << endl;
	return o;
}

//Veiculo class methods implementation

int Veiculo::getID() const {
	return id;
}

string Veiculo::getMarca() const {
	return marca;
}

string Veiculo::getModelo() const {
	return modelo;
}

string Veiculo::getMatricula() const {
	return matricula;
}


void Veiculo::setMarca(string mc) {
	marca = mc;
}

void Veiculo::setModelo(string md) {
	modelo = md;
}

void Veiculo::setMatricula(string mt) {
	matricula = mt;
}

Veiculo::~Veiculo() {
}



void Veiculo::novoStandard(Standard * s){
		standards.push_back(s);
}

void Veiculo::removeStandard(int indice){
	standards.erase(standards.begin()+indice);
}

vector<Standard *> Veiculo::getStandards(){
	return standards;
}

void Veiculo::setStandards(vector<Standard*> standards){
	this->standards=standards;
}
