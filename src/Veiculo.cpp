/*
 * Veiculo.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#include "Veiculo.h"


Veiculo::Veiculo() {

	marca = "";
	modelo = "";
	matricula = "";

}

Veiculo::Veiculo(string mc, string mdl, string mt) {

	marca = mc;
	modelo = mdl;
	matricula = mt;

}

//Operador cout de veiculo
ostream & operator<<(ostream & o, const Veiculo & v) {
	o << "Marca: " << v.getMarca() << endl;
	o << "Modelo: " << v.getModelo() << endl;
	o << "Matricula: " << v.getMatricula() << endl;
	return o;
}

//Veiculo class methods implementation

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
