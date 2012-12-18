#ifndef STANDART_H
#define STANDART_H

/** @defgroup Standart Standart
 * @{
 *
 * Criacao de classe para objecto Standard e respectivas funcoes
 *
 */

#include "Servico.h"
#include <iostream>

/**@{
 *
 * Classe para criacao de objecto Standard
 */
class Standard: public Servico {
private:
	string nome;
	string descricao;
	double preco;
	double duracao;

public:

	/**
	 * @brief Construtor de Standard
	 *
	 * Cria um objecto Standard com um conjunto de atributos (nome, descricao, preco, duracao, dataInicio,dataFim).
	 * Invoca tambem o construtor da classe Servico(classe pai).
	 *
	 * @param nome Nome do Standard a ser criado
	 * @param descricao Descricao do Standard a ser criado
	 * @param preco Preco do Standard a ser criado
	 * @param duracao Duracao do Standard a ser criado
	 * @param dataInicio Data inicial (em que o servico vai comecar a ser efectuado) do Standard a ser criado
	 * @param dataFim Data final(em que o servico ira terminar) do Standard a ser criado
	 *
	 */
	Standard(string nome, string descricao, double preco, double duracao,
			string dataInicio, string dataFim);

	/**
		 * @brief Obter o nome de Standard
		 *
		 * Permite aceder ao atributo privado "nome" da classe "Standard" (nome identificativo de um servico standard)
		 *
		 * @return String com o mesmo valor do atributo privado "nome".
		 */
	string getNome() const;

	/**
		 * @brief Alterar o nome de Standard
		 *
		 * Permite alterar o atributo privado "nome" da classe "Standard" (nome identificativo de um servico standard)
		 *
		 * @param nome String com o novo valor de nome para alterar .
		 */
	void setNome(string nome);

	/**
			 * @brief Obter a descricao de Standard
			 *
			 * Permite aceder ao atributo privado "descricao" da classe "Standard" (descricao de um servico standard)
			 *
			 * @return String com o mesmo valor do atributo privado "nome".
			 */
	string getDescricao() const;

	/**
			 * @brief Alterar a descricao de Standard
			 *
			 * Permite alterar o atributo privado "descricao" da classe "Standard" (descricao de um servico standard)
			 *
			 * @param descricao String com o novo valor de descricao para alterar .
			 */
	void setDescricao(string descricao);

	/**
			 * @brief Obter o preco de Standard
			 *
			 * Permite aceder ao atributo privado "preco" da classe "Standard" (preco de um servico standard)
			 *
			 * @return String com o mesmo valor do atributo privado "preco".
			 */
	double getPreco() const;

	/**
				 * @brief Alterar o preco de Standard
				 *
				 * Permite alterar o atributo privado "preco" da classe "Standard" (preco de um servico standard)
				 *
				 * @param preco String com o novo valor de descricao para alterar .
				 */
	void setPreco(double preco);

	/**
			 * @brief Obter a duracao de Standard
			 *
			 * Permite aceder ao atributo privado "duracao" da classe "Standard" (duracao de um servico standard)
			 *
			 * @return Double com o mesmo valor do atributo privado "duracao".
			 */
	double getDuracao() const;

	/**
				 * @brief Alterar a duracao de Standard
				 *
				 * Permite alterar o atributo privado "duracao" da classe "Standard" (duracao de um servico standard)
				 *
				 * @param duracao String com o novo valor de duracao para alterar .
				 */
	void setDuracao(double duracao);

	/**@brief Overload de operador ostream
	 *
	 *@param out Endereco de ostream
	 *@param s Endereco de Standard
	 */
	friend ostream & operator<<(ostream & o, const Standard & s);

};

#endif
