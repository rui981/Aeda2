#include "Cliente.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;



Cliente::Cliente(string nome, string contacto, string morada):Pessoa(nome, contacto, morada){


}



Cliente::~Cliente(){

}

/*
vector<Veiculo*> Cliente::getVeiculos() const {
	return veiculos;
}

void Cliente::setVeiculos(vector <Veiculo*> veiculos){
	this->veiculos=veiculos;
}
*/



ostream& operator<< (ostream &out,const Cliente &clie){
	out << "Nome: " << clie.nome << endl;
	out << "Contacto: " << clie.contacto << endl;
	out << "Morada: " << clie.morada << endl;


return out;}
