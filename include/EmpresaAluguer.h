#ifndef EMPRESAALUGUER_H_
#define EMPRESAALUGUER_H_

#include "Veiculo.h"

/** @defgroup EmpresaAluguer EmpresaAluguer
 * @{
 *
 * Criacao de classe para objecto EmpresaAluguer e respectivas funcoes
 *
 */
using namespace std;


/**@{
 *
 * Classe EmpresaAluguer
 */
class EmpresaAluguer {
private:
	vector<Veiculo *> veiculos;
	string nome;
	int distancia;
	int veiculos_disp;
public:


	EmpresaAluguer(string nome, int dist, int numVeic);

	/**
			 * @brief Construtor de EmpresaAluguer
			 *
			 * Cria um objecto EmpresaAluguer, com um conjunto de atributos (marca, dist)
			 *
			 * @param nome Nome da EmpresaAlguer
			 * @param dist Distancia do cliente à empresa de Aluguer
			 */
	EmpresaAluguer(string nome, int dist);

	/**@brief Adiciona Veiculo a EmpresaAluguer
		 *
		 * Permite adicionar um Veiculo a frota de veiculos de uma EmpresaAluguer
		 *
		 * @param v Apontador para Veiculo
		 */
	void adicionaVeiculo(Veiculo * v);

	/**@brief Remove Veiculo a EmpresaAluguer
			 *
			 * Permite remover um Veiculo a frota de veiculos de uma EmpresaAluguer
			 *
			 * @param indice Indice do vector correspondente ao veiculo a ser removido
			 */
	void removeVeiculo(int indice);

	/**@brief Tamanho Frota
			 *
			 * Retorna o numero de veiculos disponiveis para aluguer
			 *
			 * @return Inteiro com o tamanho do vector de veiculos disponiveis
			 */
	int getNumVeiculosDisp() const;

	/**
		 * @brief Obter o nome
		 *
		 * Permite aceder ao atributo privado "nome" da classe "EmpresaAluguer"
		 *
		 * @return String com o mesmo valor do atributo privado "nome".
		 */
	string getNome() const;

	/**
		 * @brief Obter a distancia
		 *
		 * Permite aceder ao atributo privado "distancia" da classe "EmpresaAluguer"
		 *
		 * @return String com o mesmo valor do atributo privado "distancia".
		 */
	int getDistancia() const;

	/**
		 * @brief Obter os veiculos
		 *
		 * Retorna um vector de apontadores de Veiculo (por referência)
		 *
		 * @return Vector de apontador de veiculo com o mesmo valor que o atributo privado "veiculos"
		 */
	vector<Veiculo *> & getVeiculos();
};

/**@brief Funcao de comparacao de dois veiculos
 *
 *
 * @param e1 Primeira EmpresaAluguer a ser comparada
 * @param e2 Segunda EmpresaAluguer a ser comparada
 * @return True se o numero de veiculos disponiveis de e1 for maior do que e2; false nos restantes casos.
 */
bool compare(EmpresaAluguer * e1, EmpresaAluguer * e2);

#endif /* EMPRESAALUGUER_H_ */
