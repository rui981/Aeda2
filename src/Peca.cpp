#include "Peca.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int Peca::ultimoCod=1;


	int Peca::getCodigo() const{
		return codigo;
	}

	void Peca::setCodigo(int codigo){
		this->codigo=codigo;
	}

	string Peca::getDesignacao() const{
		return designacao;
	}

	void Peca::setDesignacao(string designacao){
		this->designacao=designacao;
	}

	int Peca::getStock() const{
		return stock;
	}
	void Peca::setStock(int stock){
		this->stock=stock;
	}

	string Peca::getLoja() const{
		return loja;
	}


	void Peca::setLoja(string loja){
		this->loja=loja;
	}


	Peca::Peca(string designacao, int stock, string loja){
		codigo=ultimoCod;
		this->designacao=designacao;
		this->stock=stock;
		this->loja=loja;
		ultimoCod++;
	}


	Peca::Peca(int codigo,string designacao, int stock, string loja){
			this->codigo=codigo;
			this->designacao=designacao;
			this->stock=stock;
			this->loja=loja;
			ultimoCod=codigo;
	}


	Peca::Peca(){
		codigo=ultimoCod;
		designacao="";
		stock=0;
		loja="";
	}





	ostream& operator<< (ostream &out,const Peca &p1){
		out << "Codigo: " << p1.getCodigo() << endl;
		out << "Designacao: " << p1.getDesignacao() << endl;
		out << "Loja: " << p1.getLoja() << endl;
		out << "Stock: " << p1.getStock() << endl;

	return out;
	}



