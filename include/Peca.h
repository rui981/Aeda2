#ifndef PECA_H
#define PECA_H

#include <iostream>
using namespace std;


class Peca{
	//código, designação, stock e loja

	int codigo;
	string designacao;
	int stock;
	string loja;
	static int ultimoCod;

public:

	friend ostream& operator<< (ostream &out,const Peca &p1);


	int getCodigo() const;
	void setCodigo(int codigo);

	string getDesignacao() const;
	void setDesignacao(string designacao);

	int getStock() const;
	void setStock(int stock);

	string getLoja() const;
	void setLoja(string loja);


	Peca(string designacao, int stock, string loja);
	Peca(int codigo, string designacao, int stock, string loja);
	Peca();

	bool operator < (const Peca & p) const {
		return designacao < p.designacao; }


	bool operator == (const Peca & p) const {
		return designacao == p.designacao; }


};








#endif
