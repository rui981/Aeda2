#ifndef Veiculo_H_
#define Veiculo_H_

/** @defgroup Veiculo Veiculo
 * @{
 *
 * Criacao de classe para objecto Veiculo e respectivas funcoes
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include <Standart.h>
using namespace std;


/**@{
 *
 * Classe para criacao de objecto Veiculo
 */
class Veiculo
{
private:
	static int ID;
	int id;
	string marca;
	string modelo;
	string matricula;
	vector<Standard *> standards;
public:

	/**
	 * @brief Construtor por omissao de Veiculo
	 *
	 * Cria um objecto Veiculo, com um conjunto de atributos (marca, modelo, matricula) inicializados em branco.
	 */
	Veiculo();

	/**
	 * @brief Construtor de Veiculo
	 *
	 * Cria um objecto Veiculo, com um conjunto de atributos (marca, modelo, matricula)
	 *
	 * @param marca Marca do veiculo a ser criado
	 * @param modelo Modelo do veiculo a ser criado
	 * @param matricula Matricula do veiculo a ser criado
	 */
	Veiculo(string mc, string mdl, string mt);

	/**@ brief Destrutor de Veiculo
	 *
	 */
	virtual ~Veiculo();

	/**
	 * @brief Obter a marca
	 *
	 * Permite aceder ao atributo privado "marca" da classe "Veiculo"
	 *
	 * @return String com o mesmo valor do atributo privado "marca".
	 */
	string getMarca() const;

	/**
	 * @brief Alterar a marca
	 *
	 * Permite alterar o atributo privado "marca" da classe "Veiculo"
	 *
	 * @param mc String com o novo valor de marca para alterar.
	 */
	void setMarca (string mc);

	/**
	 * @brief Obter o modelo
	 *
	 * Permite aceder ao atributo privado "modelo" da classe "Veiculo"
	 *
	 * @return String com o mesmo valor do atributo privado "modelo".
	 */
	string getModelo() const;

	/**
	 * @brief Alterar o modelo
	 *
	 * Permite alterar o atributo privado "modelo" da classe "Veiculo"
	 *
	 * @param mdl String com o novo valor de modelo para alterar .
	 */
	void setModelo (string mdl);

	/**
	 * @brief Obter a matricula
	 *
	 * Permite aceder ao atributo privado "matricula" da classe "Veiculo"
	 *
	 * @return String com o mesmo valor do atributo privado "matricula".
	 */
	string getMatricula() const;

	/**
	 * @brief Alterar a matricula
	 *
	 * Permite alterar o atributo privado "matricula" da classe "Veiculo"
	 *
	 * @param mt String com o novo valor de matricula para alterar .
	 */
	void setMatricula (string mt);

	/**@brief Obter Servicos de um Veiculo
	 *
	 * Permite aceder aos Servicos efectuados no Veiculo criado
	 *
	 * @return Vector de apontador de Standard(Servico), correspondente a todos os servicos do Veiculo em questão.
	 */
	vector<Standard *> getStandards();

	/**
	 * @brief Alterar os Servicos de Veiculo
	 *
	 * Permite alterar os servicos que estao a ser efectuados no Veiculo
	 *
	 * @param standards Vector de apontador de Standard, correspondente aos novos servicos do Veiculo em questao.
	 */
	void setStandards(vector<Standard*> standards);

	/**@brief Adiciona Servico a Funcionario
	 *
	 * Permite adicionar um Servico para ser efectuado num Veiculo
	 *
	 * @param s Apontador para Servico
	 */
	void novoStandard(Standard * s);


	/**@brief Remove Servico a Veiculo
	 *
	 * Permite remover um Servico
	 *
	 * @param indice Inteiro com a indicacao da posicao no vector do veiculo que desejamos remover
	 */
	void removeStandard(int indice);

	/**@brief Overload de operador ostream
	 *
	 *@param out Endereco de ostream
	 *@param v Endereco de Veiculo
	 */
	friend ostream & operator<<(ostream & o, const Veiculo & v);
	int getID() const;

};


#endif /* Veiculo_H_ */
