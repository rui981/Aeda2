#ifndef PESSOA_H
#define PESSOA_H

/** @defgroup Pessoa Pessoa
 * @{
 *
 * Criacao de classe para objecto pessoa e respectivas funcoes
 *
 */

#include <iostream>
#include "Veiculo.h"

using namespace std;

/**@{
 *
 * Classe para criacao de objecto Pessoa
 */
class Pessoa {
protected:
	string nome;
	string contacto;
	string morada;

public:
	static int ultimoId;
	int id;



	Pessoa(string nome, string contacto,string morada, int id);





	/**
	 * @brief Construtor de Pessoa
	 *
	 * Cria um objecto pessoa, com um conjunto de atributos (nome, contacto, morada)
	 *
	 * @param nome Nome da pessoa a ser criada
	 * @param contacto Contacto da pessoa a ser criada
	 */
	Pessoa(string nome, string contacto, string morada);

	/**
	 * @brief Destrutor de Pessoa
	 */
	virtual ~Pessoa();

	/**
	 * @brief Saber se Pessoa e Cliente ou Funcionario
	 *
	 * Funcao virtual (tambem implementada nas classes filhas) para verificacao se e Cliente ou Funcionario.
	 *
	 * @return Falso por predefinicao, mas sera alterado sempre pelas classes filhas.
	 */
	virtual bool sabe() {
		return false;
	}

	/**
	 * @brief Obter o nome
	 *
	 * Permite aceder ao atributo privado "nome" da classe "Pessoa"
	 *
	 * @return String com o mesmo valor do atributo privado "nome".
	 */
	string getNome() const;

	/**
	 * @brief Alterar o nome
	 *
	 * Permite alterar o atributo privado "nome" da classe "Pessoa"
	 *
	 * @param nome String com o novo valor de nome para alterar .
	 */
	void setNome(string nome);

	/**
	 * @brief Obter o contacto
	 *
	 * Permite aceder ao atributo privado "contacto" da classe "Pessoa"
	 *
	 * @return String com o mesmo valor do atributo privado "contacto".
	 */
	string getContacto() const;

	/**
	 * @brief Alterar o contacto
	 *
	 * Permite alterar o atributo privado "contacto" da classe "Pessoa"
	 *
	 * @param contacto String com o novo valor de contacto para alterar .
	 */
	void setContacto(string contacto);

	/**
	 * @brief Obter a morada
	 *
	 * Permite aceder ao atributo privado "morada" da classe "Pessoa"
	 *
	 * @return String com o mesmo valor do atributo privado "morada".
	 */
	string getMorada() const;

	/**
	 * @brief Alterar a morada
	 *
	 * Permite alterar o atributo privado "morada" da classe "Pessoa"
	 *
	 * @param morada String com o novo valor de morada para alterar .
	 */
	void setMorada(string morada);




};

#endif
