#ifndef CLIENTE_H
#define CLIENTE_H

/** @defgroup Cliente Cliente
 * @{
 *
 *	Criacao de classe para objecto Cliente e respectivas funcoes
 *
 */

#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Veiculo.h"

using namespace std;



class Cliente : public Pessoa {

	private:

	vector <Veiculo*> veiculos;

	public:
	/**
		 * @brief Construtor de Cliente
		 *
		 * Cria um objecto Cliente com um conjunto de atributos (nome, contacto, morada).
		 * Invoca tambem o construtor da classe Pessoa(classe pai).
		 *
		 * @param nome Nome da pessoa a ser criada
		 * @param contacto Contacto da pessoa a ser criada
		 * @param morada Morada da pessoa a ser criada
		 *
		 */
	Cliente(string nome, string contacto, string morada);
	Cliente(string nome, string contacto, string morada, int id);
	bool clienteInativo;
	int getId() const;


	/**
		 * @brief Destrutor de Cliente
		 */
	~Cliente();


	/**
		 * @brief Identificador de Cliente
		 *
		 * Quando criado um Cliente, este booleano identifica-o perante a classe Pessoa
		 *
		 * @return True
		 */
	bool sabe(){
		return true;
	}

	/* TODO VER SE ISTO E PRA MANTER
	vector<Veiculo*> getVeiculos() const;
	void setVeiculos (vector <Veiculo*> Veiculos);*/

	/**@brief Overload de operador ostream
		 *
		 *@param out Endereco de ostream
		 *@param clie Endereco de Cliente
		 *
		 */
	friend ostream& operator<< (ostream &out,const Cliente &clie);

	/**
			 * @brief Imprimir Cliente
			 *
			 * Imprime no ecra todas as informacoes de um Cliente
			 *
			 * @return String com todas as informacoes
			 */
	string imprime();

};



#endif
