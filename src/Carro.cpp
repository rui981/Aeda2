/*
 * Carro.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Carro.h"

Carro::Carro()
{}

Carro::Carro(string mc, string mdl, string mt, string tp):Veiculo(mc,mdl,mt)
{
  tipo = tp;
}

Carro::~Carro()
{}

string Carro::getTipo() const
{
  return tipo;
}

void Carro::setTipo(string tp)
{
  tipo = tp;
}

ostream & operator<<(ostream & o, const Carro & c){
      o << "Marca: " << c.getMarca() << endl;
      o << "Modelo: " << c.getModelo() << endl;
      o << "Matricula: " << c.getMatricula() << endl;
      o << "Tipo: " << c.getTipo() << endl;

      return o;
}

