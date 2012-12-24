#include "EmpresaAluguer.h"


EmpresaAluguer::EmpresaAluguer(string nome, int dist, int numVeic) {
	this->nome = nome;
	this->distancia = dist;
	this->veiculos = vector<Veiculo *>();
	this->veiculos_disp = numVeic;
}

EmpresaAluguer::EmpresaAluguer(string nome, int dist) {
	this->nome = nome;
	this->distancia = dist;
	this->veiculos = vector<Veiculo *>();
	veiculos_disp = 0;
}


void EmpresaAluguer::adicionaVeiculo(Veiculo * v){
	veiculos.push_back(v);
	veiculos_disp = veiculos.size();
}

void EmpresaAluguer::removeVeiculo(int indice) {
	veiculos.erase(veiculos.begin() + indice);
	veiculos_disp = veiculos.size();
}

int EmpresaAluguer::getNumVeiculosDisp() const{
	return veiculos_disp;
}

string EmpresaAluguer::getNome() const{
	return nome;
}

int EmpresaAluguer::getDistancia() const{
	return distancia;
}

vector<Veiculo *> EmpresaAluguer::getVeiculos() {
	return veiculos;
}

bool compare(EmpresaAluguer *e1, EmpresaAluguer *e2) {
	if(e1->getNumVeiculosDisp() > e2->getNumVeiculosDisp()) {
		return true;
	}
	else {
		return false;
	}
}






