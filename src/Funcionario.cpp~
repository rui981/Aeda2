#include "Funcionario.h"
#include <sstream>

using namespace std;

Funcionario::Funcionario(string nome, string contacto, string morada, string tipo, double salario, int horasExtra):
	Pessoa( nome, contacto, morada){
		this->tipo=tipo;
		this->salario=salario;
		this->horasExtra=horasExtra;

}

Funcionario::Funcionario(string nome, string contacto, string morada, string tipo, double salario, int horasExtra, int id):
	Pessoa( nome, contacto, morada,  id){
		this->tipo=tipo;
		this->salario=salario;
		this->horasExtra=horasExtra;

}



int Funcionario::getId(){
return id;

}

Funcionario::~Funcionario(){

}

string Funcionario::getTipo() const{
	return tipo;
}

void Funcionario::setTipo(string tipo){
	this->tipo=tipo;
}

double Funcionario::getSalario() const{
	return salario;
}


void Funcionario::setSalario(double salario){
	this->salario=salario;
}

int Funcionario::getHorasExtra() const{
	return horasExtra;
}


void Funcionario::setHorasExtra(int horasExtra){
	this->horasExtra=horasExtra;
}

vector <Veiculo*> Funcionario::getVeiculos() const{
	return veiculos;
}

void Funcionario::setVeiculos(vector <Veiculo*> veiculos){
	this->veiculos=veiculos;
}



string Funcionario::imprime(){
	stringstream ss;
	string retorno;

	ss << nome<< endl;
	ss << contacto << endl;
	ss << morada <<endl;

	ss << tipo << endl;
	ss << salario << endl;
	ss << horasExtra << endl;

	for(unsigned int i=0; i<veiculos.size(); i++){
			ss <<i << ": " << veiculos[i] << endl;
		}

retorno = ss.str();
return retorno;
}

void Funcionario::adicionaVeiculo(Veiculo * v){
	veiculos.push_back(v);
}


void Funcionario::removeVeiculo(int indice){
	veiculos.erase(veiculos.begin()+indice);
}



ostream& operator<< (ostream &out, const Funcionario &func){
	out << "Id: " << func.id << endl;
	out << "Nome: " << func.nome << endl;
	out << "Contacto: " << func.contacto << endl;
	out << "Morada: " << func.morada << endl;

	out << "Tipo: " << func.getTipo() << endl;
	out << "Salario: " << func.getSalario() << endl;
	out << "Numero horas extra: " << func.getHorasExtra() << endl;
	out << "Veiculos: " << endl;
	for(unsigned int i =0; i<func.getVeiculos().size(); i++){
		out << func.getVeiculos()[i]->getMarca() << endl;
	}


	return out;}


