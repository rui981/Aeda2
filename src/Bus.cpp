/*
 * Bus.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Bus.h"

Bus::Bus()
{}

Bus::Bus(string mc, string mdl, string mt):Veiculo(mc,mdl,mt)
{}

Bus::~Bus()
{}

ostream & operator<<(ostream & o, const Bus & b){
	o << "ID: " << b.getID() << endl;
	o << "Marca: " << b.getMarca() << endl;
	o << "Modelo: " << b.getModelo() << endl;
	o << "Matricula: " << b.getMatricula() << endl;

	return o;
}
