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


#include "Funcionario.h"
#include "Cliente.h"
#include "Pessoa.h"

#include "Empresa.h"

using namespace std;

int main(){
	Empresa *emp = new Empresa();

	emp->menu();

}
