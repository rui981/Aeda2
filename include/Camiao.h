#ifndef CAMIAO_H_
#define CAMIAO_H_

/** @defgroup Camiao Camiao
 * @{
 *	Criacao de classe para objecto Camiao e respectivas funcoes
 */

#include "Veiculo.h"

using namespace std;



/**@{
 *
 * Classe para criacao de objecto Camiao
 */
class Camiao: public Veiculo {
private:
	string categoria;
public:

	/**
	 * @brief Construtor por omissao de Camiao
	 *
	 * Cria um objecto Bus, com um conjunto de atributos (marca, modelo, matricula, categoria).
	 * Invoca o construtor da classe Veiculo (classe pai).
	 */
	Camiao();

	/**
	  	 * @brief Construtor de Camiao
	  	 *
	  	 * Cria um objecto Camiao com um conjunto de atributos (marca, modelo, matricula, categoria).
	  	 * Invoca tambem o construtor da classe Veiculo(classe pai).
	  	 *
	  	 * @param mc Marca do Camiao a ser criado
	  	 * @param mdl Modelo do Camiao a ser criado
	  	 * @param mt Matricula do Camiao a ser criado
	  	 * @param cat Categoria do Camiao a ser criado
	  	 */
	Camiao(string mc, string mdl, string mt, string cat);


	/**
	 * @brief Destrutor de Camiao
	 */
	virtual ~Camiao();

	/**
		 * @brief Obter a categoria de Camiao
		 *
		 * Permite aceder ao atributo privado "categoria" da classe "Camiao"
		 *
		 * @return String com o mesmo valor do atributo privado "categoria".
		 */
	string getCategoria() const;

	/**
		 * @brief Alterar a categoria de Camiao
		 *
		 * Permite alterar o atributo privado "categoria" da classe "Camiao"
		 *
		 * @param cat String com o novo valor de categoria para alterar .
		 */
	void setCategoria(string cat);

	/**@brief Overload de operador ostream
	     	 *
	     	 *@param out Endereco de ostream
	     	 *@param cm Endereco de Camiao
	     	 */
	friend ostream & operator<<(ostream & o, const Camiao & cm);

};

#endif /* CAMIAO_H_ */
