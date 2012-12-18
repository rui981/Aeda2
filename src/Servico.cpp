#include "Servico.h"

Servico::Servico(string data_inicio, string data_fim) {
	this->dataInicio = dataInicio;
	this->dataFim = dataFim;
}

Servico::~Servico() {

}

string Servico::getDataInicio() const {
	return dataInicio;
}

string Servico::getDataFim() const {
	return dataFim;
}

void Servico::setDataInicio(string data) {
	dataInicio = data;
}

void Servico::setDataFim(string data) {
	dataFim = data;
}
