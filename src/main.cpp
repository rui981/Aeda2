/*
 * main.cpp
 *
 *  Created on: Oct 28, 2012
 *      Author: ster
 */


#include "Veiculo.h"
#include "Carro.h"
#include "Camiao.h"
#include "Bus.h"
#include <algorithm>

#include "Funcionario.h"
#include "Cliente.h"
#include "Pessoa.h"

#include "Empresa.h"

using namespace std;

int main(){
	Empresa *emp = new Empresa();

	//emp->menu();

	EmpresaAluguer * a1 = new EmpresaAluguer("Emp1",0,5);
	EmpresaAluguer * a2 = new EmpresaAluguer("Emp2",0,20);
	EmpresaAluguer * a3 = new EmpresaAluguer("Emp3",0,3);
	EmpresaAluguer * a4 = new EmpresaAluguer("Emp4",0,10);

	emp->addEmpresaAluguer(a1);
	emp->addEmpresaAluguer(a2);
	emp->addEmpresaAluguer(a3);
	emp->addEmpresaAluguer(a4);


	//Testar esta merda
	list<EmpresaAluguer *>::const_iterator it;
	cout << endl;
	for(it = emp->getEmpresasAluguer().begin(); it!= emp->getEmpresasAluguer().end(); it++) {
		cout << "Nome: " << (*it)->getNome() << endl;
	}

	cout << "Testado :)" << endl;

}
