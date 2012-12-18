#ifndef SERVICO_H
#define SERVICO_H


/** @defgroup Servico Servico
 * @{
 *
 * Criacao de classe para objecto servico e respectivas funcoes
 *
 */

#include <string>
#include <vector>
using namespace std;


/**@{
 *
 * Classe para criacao de objecto Servico
 */
class Servico{
private:
	string dataInicio;
	string dataFim;

public:

	/**
		 * @brief Construtor de Servico
		 *
		 * Cria um objecto Servico, com um conjunto de atributos (dataInicio, dataFim)
		 *
		 * @param dataInicio Data em que o Servico se iniciou
		 * @param dataFim Data em que o Servico ira terminar
		 */
	Servico(string dataInicio, string dataFim);

	/**
		 * @brief Destrutor de Servico
		 */
	virtual ~Servico();

	/**
		 * @brief Obter a Data de Inicio
		 *
		 * Permite aceder ao atributo privado "dataInicio" da classe "Servico"
		 *
		 * @return String com o mesmo valor do atributo privado "dataInicio".
		 */
	string getDataInicio() const;

	/**
	 * @brief Alterar a data de Inicio
	 *
	 * Permite alterar o atributo privado "dataInicio" da classe "Servico"
	 *
	 * @param data String com o novo valor de data para alterar em dataInicio.
	 */
	void setDataInicio(string data);

	/**
			 * @brief Obter a Data de Fim
			 *
			 * Permite aceder ao atributo privado "dataFim" da classe "Servico"
			 *
			 * @return String com o mesmo valor do atributo privado "dataFim".
			 */
	string getDataFim() const;

	/**
		 * @brief Alterar a data de Fim
		 *
		 * Permite alterar o atributo privado "dataFim" da classe "Servico"
		 *
		 * @param data String com o novo valor de data para alterar em dataFim.
		 */
	void setDataFim(string data);
	//virtual void imprime();

};



#endif
