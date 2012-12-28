#ifndef BUS_H_
#define BUS_H_

/** @defgroup Bus Bus
 * @{
 *	Criacao de classe para objecto Bus e respectivas funcoes
 */

#include "Veiculo.h"

using namespace std;



/**@{
 *
 * Classe para criacao de objecto Bus
 */
class Bus: public Veiculo
{
public:


  /**
  	 * @brief Construtor de Bus
  	 *
  	 * Cria um objecto Bus com um conjunto de atributos (marca, modelo, matricula).
  	 * Invoca tambem o construtor da classe Veiculo(classe pai).
  	 *
  	 * @param mc Marca do Bus a ser criado
  	 * @param mdl Modelo do Bus a ser criado
  	 * @param mt Matricula do Bus a ser criado
  	 */
  Bus(string mc, string mdl, string mt);
  Bus(string mc, string mdl, string mt, int id);

	/**
	 * @brief Destrutor de Bus
	 */
  virtual ~Bus();

  /**@brief Overload de operador ostream
     	 *
     	 *@param out Endereco de ostream
     	 *@param b Endereco de Bus
     	 */
  friend ostream & operator<<(ostream & o, const Bus & b);

};

#endif /* BUS_H_ */


