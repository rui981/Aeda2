#ifndef PECA_H
#define PECA_H


/** @defgroup Peca Peca
 * @{
 *
 * Criacao de classe para objecto peca e respectivas funcoes
 *
 */

#include <iostream>
using namespace std;


/**@{
 *
 * Classe para criacao de objecto Peca
 */
class Peca{

	int codigo;
	string designacao;
	int stock;
	string loja;
	static int ultimoCod;

public:

	/**@brief Overload de operador ostream
		 *
		 *@param out Endereco de ostream
		 *@param p1 Endereco de Peca
		 *
		 */
	friend ostream& operator<< (ostream &out,const Peca &p1);

	/**
	 * @brief Obter o codigo
	 *
	 * Permite aceder ao atributo privado "codigo" da classe "Peca"
	 *
	 * @return Int com o valor do atributo privado "codigo".
	 */
	int getCodigo() const;

	/**
		 * @brief Alterar o codigo
		 *
		 * Permite alterar o atributo privado "codigo" da classe "Peca"
		 *
		 * @param codigo Inteiro com o novo valor de codigo para alterar .
		 */
	void setCodigo(int codigo);

	/**
		 * @brief Obter a designacao
		 *
		 * Permite aceder ao atributo privado "designacao" da classe "Peca"
		 *
		 * @return String com o valor do atributo privado "string".
		 */
	string getDesignacao() const;

	/**
			 * @brief Alterar a designacao
			 *
			 * Permite alterar o atributo privado "designacao" da classe "Peca"
			 *
			 * @param designacao String com o novo valor de designacao para alterar .
			 */
	void setDesignacao(string designacao);

	/**
		 * @brief Obter o stock
		 *
		 * Permite aceder ao atributo privado "stock" da classe "Peca"
		 *
		 * @return Int com o valor do atributo privado "stock".
		 */
	int getStock() const;

	/**
			 * @brief Alterar o stock
			 *
			 * Permite alterar o atributo privado "stock" da classe "Peca"
			 *
			 * @param stock Inteiro com o novo valor de stock para alterar .
			 */
	void setStock(int stock);

	/**
		 * @brief Obter a loja
		 *
		 * Permite aceder ao atributo privado "loja" da classe "Peca"
		 *
		 * @return String com o valor do atributo privado "loja".
		 */
	string getLoja() const;

	/**
			 * @brief Alterar a loja
			 *
			 * Permite alterar o atributo privado "loja" da classe "Peca"
			 *
			 * @param loja String com o novo valor de loja para alterar .
			 */
	void setLoja(string loja);


	/**
	 * @brief Construtor de Peca
	 *
	 * Cria um objecto peca, com um conjunto de atributos (designacao, stock, loja). O atributo codigo e alterado atraves de um static.
	 *
	 * @param designacao Designacao da peca
	 * @param stock Stock existente da peca
	 * @param loja Loja de origem da peca
	 */
	Peca(string designacao, int stock, string loja);

	/**
	 * @brief Overload do construtor de Peca (a atribuir um codigo)
	 *
	 * Cria um objecto peca, com um conjunto de atributos (designacao, stock, loja e codigo).
	 * Neste caso o codigo e passado como argumento, sendo assim possivel, ao modificar atributos de uma peca, atribuir o codigo da peca original.
	 * @param designacao Designacao da peca
	 * @param stock Stock existente da peca
	 * @param loja Loja de origem da peca
	 * @param codigo Codigo da peca
	 */
	Peca(int codigo, string designacao, int stock, string loja);

	/**
	 * @brief Construtor por omissao de Peca
	 *
	 * Cria um objecto Peca, em que todos os atributos sao nulos ou vazios.
	 *
	 */
	Peca();

	/**@brief Operador <
	 *
	 * Booleano para comparar dois objectos Peca, atraves do parametro designacao de cada um deles.
	 *
	 * @param p Peca a ser comparada
	 *
	 * @return Retorna true se a peca for menor, false se a peca for maior ou igual.
	 */
	bool operator < (const Peca & p) const {
		return designacao < p.designacao; }


	/**@brief Operador ==
	 *
	 * Booleano para verificar se dois objectos Peca sao o mesmo atraves do parametro designacao, tendo este de ser igual e ambos os casos.
	 * @param p Peca a ser comparada
	 * @return Retorna true se o parametro designacao for igual, false se for diferente.
	 */
	bool operator == (const Peca & p) const {
		return designacao == p.designacao; }


};








#endif
