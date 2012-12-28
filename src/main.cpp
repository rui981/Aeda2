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

	emp->menu();

	/*EmpresaAluguer * a1 = new EmpresaAluguer("Emp1",0);
	EmpresaAluguer * a2 = new EmpresaAluguer("Emp2",0);
	EmpresaAluguer * a3 = new EmpresaAluguer("Emp3",0);
	EmpresaAluguer * a4 = new EmpresaAluguer("Emp5",0,20);
	EmpresaAluguer * a5 = new EmpresaAluguer("Emp6",0,25);
	EmpresaAluguer * a6 = new EmpresaAluguer("Emp7",0,30);
	EmpresaAluguer * a7 = new EmpresaAluguer("Emp8",0,35);
	EmpresaAluguer * a8 = new EmpresaAluguer("Emp9",0,40);
	EmpresaAluguer * a9 = new EmpresaAluguer("Emp10",0,45);
	EmpresaAluguer * a10 = new EmpresaAluguer("Emp11",0,50);
	EmpresaAluguer * a11 = new EmpresaAluguer("Emp12",0,55);
	EmpresaAluguer * a12 = new EmpresaAluguer("Emp13",0,60);



	a2->removeVeiculo(0);
	a2->removeVeiculo(1);

	cout << "Veiculos em a1:  " << a1->getNumVeiculosDisp() << endl;
	cout << "Veiculos em a2:  " << a2->getNumVeiculosDisp() << endl;
	cout << "Veiculos em a3:  " << a3->getNumVeiculosDisp() << endl;

	//Faliram os bots
	emp->removerEmpresaAluguer("Emp3");
	emp->addEmpresaAluguer(a3);
	emp->addEmpresaAluguer(a4);
	emp->addEmpresaAluguer(a5);
	emp->addEmpresaAluguer(a6);
	emp->addEmpresaAluguer(a7);
	emp->addEmpresaAluguer(a8);
	emp->addEmpresaAluguer(a9);
	emp->addEmpresaAluguer(a10);
	emp->addEmpresaAluguer(a11);
	emp->addEmpresaAluguer(a12);


	//Testar esta merda
	list<EmpresaAluguer *>::const_iterator it;
	cout << endl;
	for(it = emp->getEmpresasAluguer().begin(); it!= emp->getEmpresasAluguer().end(); it++) {
		cout << "Nome: " << (*it)->getNome() << endl;
	}

	cout << "Testado :)" << endl;

	//A wild Client appears!!!
	Cliente * cl1 = new Cliente("Labrego","1234","Canelas");
	Cliente * cl2 = new Cliente("Zezinho","1234","Porto");
	emp->clienteRequisitaViatura(cl1);
	emp->clienteRequisitaViatura(cl2);
	emp->printClienteViaturaAlugada();
	//Verificar se removeu o veiculo da frota da empresa depois deste ter sido alugado
	//cout << "Veiculos em a2:  " << a2->getNumVeiculosDisp() << endl;

	//Testar esta merda 2
	list<EmpresaAluguer *>::const_iterator it1;
	cout << endl;
	for(it1 = emp->getEmpresasAluguer().begin(); it1!= emp->getEmpresasAluguer().end(); it1++) {
		cout << "Nome: " << (*it1)->getNome() << endl;
	}

	cout << "Testado 2 :D" << endl;*/


}
