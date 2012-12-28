#include "Standart.h"



Standard::Standard(string nome, string descricao, double preco, double duracao, string data_inicio, string data_fim):Servico(data_inicio, data_fim){

	this->nome=nome;
	this->preco=preco;
	this->duracao=duracao;
	this->descricao=descricao;

}

string Standard::getNome() const{
	return nome;
}


void Standard::setNome(string nome){
	this->nome=nome;
}

string Standard::getDescricao() const{
	return descricao;
}


void Standard::setDescricao(string descricao){
	this->descricao=descricao;
}


double Standard::getPreco() const{
	return preco;
}


void Standard::setPreco(double preco){
	this->preco=preco;
}


double Standard::getDuracao() const{
	return preco;
}


void Standard::setDuracao(double duracao){
	this->duracao=duracao;
}


ostream & operator<<(ostream & o, const Standard & v){
	o << "Nome: " << v.getNome()<< endl;
	o << "Descricao: " <<v.getDescricao() << endl;
	o << "Preco: " << v.getDuracao() << endl;
	o << "Duracao: " << v.getDuracao() << endl;
	o << "Data de inicio: " << v.getDataInicio() << endl;
	o << "Data de fim: " << v.getDataFim() << endl;
	return o;
}
