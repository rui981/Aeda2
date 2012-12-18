#ifndef CARRO_H_
#define CARRO_H_


/** @defgroup Camiao Camiao
 * @{
 *	Criacao de classe para objecto Camiao e respectivas funcoes
 */

#include "Veiculo.h"

using namespace std;


/**@{
 *
 * Classe para criacao de objecto Carro
 */
class Carro: public Veiculo
{

private:
  string tipo;

public:

  /**
  	 * @brief Construtor por omissao de Carro
  	 *
  	 * Cria um objecto Carro, com um conjunto de atributos (marca, modelo, matricula, tipo).
  	 * Invoca o construtor da classe Veiculo (classe pai).
  	 */
  Carro();

  /**
  	  	 * @brief Construtor de Carro
  	  	 *
  	  	 * Cria um objecto Carro com um conjunto de atributos (marca, modelo, matricula, tipo).
  	  	 * Invoca tambem o construtor da classe Veiculo(classe pai).
  	  	 *
  	  	 * @param mc Marca do Carro a ser criado
  	  	 * @param mdl Modelo do Carro a ser criado
  	  	 * @param mt Matricula do Carro a ser criado
  	  	 * @param tp Tipo do Carro a ser criado
  	  	 */
  Carro(string mc, string mdl, string mt, string tp);


	/**
	 * @brief Destrutor de Carro
	 */
  virtual ~Carro();

  /**
  		 * @brief Obter o tipo de Carro
  		 *
  		 * Permite aceder ao atributo privado "tipo" da classe "Carro"
  		 *
  		 * @return String com o mesmo valor do atributo privado "tipo".
  		 */
  string getTipo() const;

  /**
  		 * @brief Alterar o tipo de Carro
  		 *
  		 * Permite alterar o atributo privado "tipo" da classe "Carro"
  		 *
  		 * @param cat String com o novo valor de tipo para alterar .
  		 */
  void setTipo(string tp);

  /**@brief Overload de operador ostream
  	     	 *
  	     	 *@param out Endereco de ostream
  	     	 *@param c Endereco de Carro
  	     	 */
  friend ostream & operator<<(ostream & o, const Carro & c);

};

#endif /* CARRO_H_ */
