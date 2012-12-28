#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

/** @defgroup Funcionario Funcionario
 * @{
 *	Criacao de classe para objecto Funcionario e respectivas funcoes
 */

#include <iostream>
#include "Pessoa.h"
#include <vector>

using namespace std;

/**@{
 *
 * Classe para criacao de objecto Funcionario
 */
class Funcionario: public Pessoa {
private:

	string tipo;
	double salario;
	int horasExtra;
	vector<Veiculo*> veiculos;

public:

	Funcionario(string nome, string contacto, string morada, string tipo, double salario, int horasExtra, int id);

	int getId();





	/**
	 * @brief Construtor de Funcionario
	 *
	 * Cria um objecto Funcionario com um conjunto de atributos (nome, contacto, morada, tipo, salario, horas extra).
	 * Invoca tambem o construtor da classe Pessoa(classe pai).
	 *
	 * @param nome Nome da pessoa a ser criada
	 * @param contacto Contacto da pessoa a ser criada
	 * @param morada Morada da pessoa a ser criada
	 * @param tipo Tipo de Funcionario a ser criado
	 * @param salario Salario de Funcionario a ser criado
	 * @param horasExtra Horas Extra de Funcionario a ser criado
	 *
	 */
	Funcionario(string nome, string contacto, string morada, string tipo,
			double salario, int horasExtra);

	/**
	 * @brief Destrutor de Funcionario
	 */
	~Funcionario();

	/**
	 * @brief Identificador de Funcionario
	 *
	 * Quando criado um Funcionario, este booleano identifica-o perante a classe Pessoa
	 *
	 * @return False
	 */
	bool sabe() {
		return false;
	}

	/**
	 * @brief Obter o tipo de funcionario
	 *
	 * Permite aceder ao atributo privado "tipo" da classe "Funcionario"
	 *
	 * @return String com o mesmo valor do atributo privado "tipo".
	 */
	string getTipo() const;

	/**
	 * @brief Alterar o tipo de Funcionario
	 *
	 * Permite alterar o atributo privado "tipo" da classe "Funcionario"
	 *
	 * @param tipo String com o novo valor de nome para alterar .
	 */
	void setTipo(string tipo);

	/**
	 * @brief Obter o salario de funcionario
	 *
	 * Permite aceder ao atributo privado "salario" da classe "Funcionario"
	 *
	 * @return String com o mesmo valor do atributo privado "salario".
	 */
	double getSalario() const;

	/**
	 * @brief Alterar o salario de Funcionario
	 *
	 * Permite alterar o atributo privado "salario" da classe "Funcionario"
	 *
	 * @param salario String com o novo valor de salario para alterar .
	 */
	void setSalario(double salario);

	/**
	 * @brief Obter as horas extra de funcionario
	 *
	 * Permite aceder ao atributo privado "horasExtra" da classe "Funcionario"
	 *
	 * @return String com o mesmo valor do atributo privado "horasExtra".
	 */
	int getHorasExtra() const;

	/**
	 * @brief Alterar as horas extra de Funcionario
	 *
	 * Permite alterar o atributo privado "horasExtra" da classe "Funcionario"
	 *
	 * @param horasExtra String com o novo valor de horasExtra para alterar .
	 */
	void setHorasExtra(int horasExtra);

	/**@brief Obter veiculos de um Funcionario
	 *
	 * Permite aceder aos veiculos pelos quais um Funcionario este responsavel
	 *
	 * @return Vector de apontador de Veiculo, correspondente a todos os veiculos do Funcionario em questão.
	 */
	vector<Veiculo*> getVeiculos() const;

	/**
		 * @brief Alterar os veiculos de Funcionario
		 *
		 * Permite alterar os veiculos pelo qual um Funcionario e responsavel
		 *
		 * @param veiculos Vector de apontador de Veiculo, correspondente aos novos veiculos do Funcionario em questão.
		 */
	void setVeiculos(vector<Veiculo*> veiculos);


	/**@brief Overload de operador ostream
	 *
	 *@param out Endereco de ostream
	 *@param func Endereco de Funcionario
	 */
	friend ostream& operator<<(ostream &out, const Funcionario &func);


	/**
		 * @brief Imprimir Funcionario
		 *
		 * Imprime no ecra todas as informacoes de um funcionario
		 *
		 * @return String com todas as informacoes
		 */
	string imprime();

	/**@brief Adiciona Veiculo a Funcionario
		 *
		 * Permite adicionar um veiculo pelo qual o Funcionario vai ser responsavel
		 *
		 * @param v Apontador para Veiculo
		 */
	void adicionaVeiculo(Veiculo * v);


	/**@brief Remove Veiculo a Funcionario
		 *
		 * Permite remover um veiculo pelo qual o Funcionario e responsavel
		 *
		 * @param indice Inteiro com a indicacao da posicao no vector do veiculo que desejamos remover
		 */
	void removeVeiculo(int indice);

};

#endif
