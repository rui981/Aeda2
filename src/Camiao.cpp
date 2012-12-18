/*
 * Camiao.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Camiao.h"

Camiao::Camiao()
{}

Camiao::Camiao(string mc, string mdl, string mt, string cat):Veiculo(mc,mdl,mt)
{
  categoria = cat;
}

Camiao::~Camiao()
{}

string Camiao::getCategoria() const
{
  return categoria;
}

void Camiao::setCategoria(string cat)
{
  categoria = cat;
}

ostream & operator<<(ostream & o, const Camiao & cm){
      o << "Marca: " << cm.getMarca() << endl;
      o << "Modelo: " << cm.getModelo() << endl;
      o << "Matricula: " << cm.getMatricula() << endl;
      o << "Categoria: " << cm.getCategoria() << endl;

      return o;
}
