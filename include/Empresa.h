#ifndef EMPRESA_H
#define EMPRESA_H

#include <tr1/unordered_set>
#include <list>
#include <algorithm>
#include <map>
#include "EmpresaAluguer.h"


#include "Pessoa.h"
#include "Cliente.h"
#include "Funcionario.h"

#include "Veiculo.h"
#include "Carro.h"
#include "Camiao.h"
#include "Bus.h"

#include "Servico.h"
#include "Standart.h"

#include <iostream>
#include <vector>
using namespace std;


struct eq {
	bool operator() (const Cliente & cl1, const Cliente &cl2) const{
		if(cl1.getId() == cl2.getId()){
			return true;
		}
		else{
			return false;
		}
	}
};


struct hash {
	int operator() (const Cliente & cli1) const{
		string nome= cli1.getNome();
		int acc=0;
		for(unsigned int i =0;i< nome.size();i++){
			acc += 7*i+nome[i];
		}
		return acc;
	}
};

class Empresa {
private:

//hashtable
	tr1::unordered_set<Cliente,hash, eq> inativos;
//fila de prioridade
	//priority_queue<EmpresaAluguer> * aluguer;
	list<EmpresaAluguer *> empresas_aluguer;
	map<Cliente*,Veiculo*> alugueres;

	vector<Pessoa*> pessoas;
	vector<Cliente*> clientes;
	vector<Funcionario*> funcionarios;

	vector<Veiculo *> veiculos;
	vector<Carro *> carros;
	vector<Bus *> buses;
	vector<Camiao *> camioes;

	vector<Standard *> standards;
	vector<Servico *> servicos;
public:
	void insereInativos(Cliente cl);
	void apagaInativos(Cliente cl);






	/**
	 * @brief Construtor de Empresa
	 *
	 * O construtor da classe empresa tem como objectivo principal retirar toda a informacao que esta nos ficheiros .txt e passa-la para os sitios respectivos, nomeadamente vectores.
	 * Depois de efectuar esse processo para todos os ficheiros, adiciona as informacoes que foram passadas aos vectores das classes derivadas para o vector da sua classe base.
	 *
	 */
	Empresa();
	/** @brief Destrutor de Empresa
	 *
	 *
	 */
	~Empresa();

	/**@brief Menu principal
	 *
	 * Contem a interface grafica do programa e suas funcionalidades.
	 * Em alguns casos as funcoes estao realizadas fora de escopo desta funcao e sao apenas chamadas quando necessario.)
	 * Todos os casos que achamos convenientes dentro desta funcao e das que sao chamadas dentro da propria tem implementadas e
	 *
	 */
	void menu();

	/**@brief Menu Veiculos
	 *
	 * Funcao que contem a totalidade da interface respeitante a Veiculos e suas funcionalidades.
	 * E chamada na funcao menu()
	 *
	 */
	void menuVeiculos();

	/**@brief Clear do ecra
	 *
	 * Introduz diversas linhas em branco de forma a limpar o ecra do utilizador quando conveniente.
	 *
	 */
	void clear();

	/**@brief Pause do programa
	 *
	 * Permite que quando necessario o programa espere pelo input do utilizador para continuar o programa (atraves da insercao de um enter).
	 *
	 */
	void pause();

	/**@brief Novo Funcionario
	 *
	 * Acrescenta o funcionario passado como argumento ao vector funcionarios
	 *
	 * @param func Apontador para Funcionario
	 */
	void novoFuncionario(Funcionario* func);

	/**@brief Novo Cliente
	 *
	 * Acrescenta o cliente passado como argumento ao vector clientes
	 *
	 * @param func Apontador para Cliente
	 */
	void novoCliente(Cliente* c);

	/**@brief Novo Carro
	 *
	 * Acrescenta o carro passado como argumento ao vector carros
	 *
	 * @param func Apontador para Carro
	 */
	void novoCarro(Carro *c);

	/**@brief Novo Camiao
	 *
	 * Acrescenta o camiao passado como argumento ao vector camioes
	 *
	 * @param func Apontador para Camiao
	 */
	void novoCamiao(Camiao *c);

	/**@brief Novo Bus
	 *
	 * Acrescenta o bus passado como argumento ao vector buses
	 *
	 * @param func Apontador para Bus
	 */
	void novoBus(Bus *b);

	/**@brief Novo Standard
	 *
	 * Acrescenta o standard passado como argumento ao vector standards
	 *
	 * @param func Apontador para Standard
	 */
	void novoStandard(Standard *s);

	/**@brief Modifica Funcionario
	 *
	 * Lista os Funcionarios já existentes no sistema e da a opcao ao utilizador de modificar o campo que quiser.
	 *
	 */
	void modificaFunc();

	/**@brief Modifica Cliente
	 *
	 * Lista os Clientes já existentes no sistema e da a opcao ao utilizador de modificar o campo que quiser.
	 *
	 */
	void modificaCli();

	/**@brief Modifica Veiculo
	 *
	 * Lista os Veiculos já existentes no sistema e da a opcao ao utilizador de modificar o campo que quiser.
	 *
	 */
	void modificaVeic();

	/**@brief Modifica Servico
	 *
	 * Lista os Servicos já existentes no sistema e da a opcao ao utilizador de modificar o campo que quiser.
	 *
	 */
	void modificaServ();

	/**@brief Remove Carro
	 * Elimina o Carro correspondente ao indice passado como argumento do vector carros
	 * @param indice Indica a posicao do Carro que se deseja remover no vector carros
	 */
	void removeCarro(int indice);

	/**@brief Remove Camiao
	 * Elimina o Camiao correspondente ao indice passado como argumento do vector camioes
	 * @param indice Indica a posicao do Camiao que se deseja remover no vector camioes
	 */
	void removeCamiao(int indice);

	/**@brief Remove Bus
	 * Elimina o Bus correspondente ao indice passado como argumento do vector buses
	 * @param indice Indica a posicao do Bus que se deseja remover no vector buses
	 */
	void removeBus(int indice);

	/**@brief Remove Funcionario
	 * Elimina o Funcionario correspondente ao indice passado como argumento do vector funcionarios
	 * @param i Indica a posicao do Funcionario que se deseja remover no vector funcionarios
	 */
	void removeFuncionario(int i);

	/**@brief Remove Cliente
	 * Elimina o Cliente correspondente ao indice passado como argumento do vector clientes
	 * @param indice Indica a posicao do Clientes que se deseja remover no vector clientes
	 */
	void removeCliente(int indice);

	/**@brief Remove Standard
	 * Elimina o Standard correspondente ao indice passado como argumento do vector standards
	 * @param indice Indica a posicao do standard que se deseja remover no vector standards
	 */
	void removeStandard(int indice);

	/**@brief Escreve Clientes
	 *
	 * Abre o ficheiro clientes.txt e, percorrendo o vector clientes, escreve os clientes do vector e seus atributos no txt.
	 *
	 */

	void escreveClientes();

	/**@brief Escreve Funcionarios
	 *
	 * Abre o ficheiro funcionarios.txt e, percorrendo o vector funcionarios, escreve os funcionarios do vector e seus atributos no txt.
	 *
	 */
	void escreveFuncionarios();

	/**@brief Escreve Carros
	 *
	 * Abre o ficheiro carros.txt e, percorrendo o vector carros, escreve os carros do vector e seus atributos no txt.
	 *
	 */
	void escreveCarros();

	/**@brief Escreve Buses
	 *
	 * Abre o ficheiro buses.txt e, percorrendo o vector buses, escreve os buses do vector e seus atributos no txt.
	 *
	 */
	void escreveBuses();

	/**@brief Escreve Camioes
	 *
	 * Abre o ficheiro camioes.txt e, percorrendo o vector camioes, escreve os camioes do vector e seus atributos no txt.
	 *
	 */
	void escreveCamioes();

	/**@brief Escreve Standards
	 *
	 * Abre o ficheiro standards.txt e, percorrendo o vector standards, escreve os standards do vector e seus atributos no txt.
	 *
	 */
	void escreveStandards();

	/**@brief Le clientes
	 *
	 * Abre o ficheiro clientes.txt e percorre-o ate ao fim adicionando as informacoes do txt como novos objectos ao vector clientes.
	 *
	 */
	void leClientes();

	/**@brief Le Funcionarios
	 *
	 * Abre o ficheiro funcionarios.txt e percorre-o ate ao fim adicionando as informacoes do txt como novos objectos ao vector funcionarios.
	 *
	 */
	void leFuncionarios();

	/**@brief Le Carros
	 *
	 * Abre o ficheiro carros.txt e percorre-o ate ao fim adicionando as informacoes do txt como novos objectos ao vector carros.
	 *
	 */
	void leCarros();

	/**@brief Le Buses
	 *
	 * Abre o ficheiro buses.txt e percorre-o ate ao fim adicionando as informacoes do txt como novos objectos ao vector buses.
	 *
	 */
	void leBuses();

	/**@brief Le Camioes
	 *
	 * Abre o ficheiro camioes.txt e percorre-o ate ao fim adicionando as informacoes do txt como novos objectos ao vector camioes.
	 *
	 */
	void leCamioes();

	/**@brief Le Standards
	 *
	 * Abre o ficheiro standards.txt e percorre-o ate ao fim adicionando as informacoes do txt como novos objectos ao vector standards.
	 *
	 */
	void leStandards();

	/**@brief Distribui Pessoas
	 *
	 *Coloca todos os objectos dos vectores clientes e funcionarios no vector pessoas
	 */
	void distribuiPessoas();

	/**@brief Distribui Veiculos
		 *
		 *Coloca todos os objectos dos vectores carros, camioes e bus no vector veiculos
		 */
	void distribuiVeiculos();

/**@brief Adiciona Veiculo a um Funcionario
 *
 *Opcao do menu para atribuir um Veiculo a um Funcionario que o utilizador quiser.
 */
	void adicionaVeiculoFuncionario();

	/**@brief Remove Veiculo a um Funcionario
	 *
	 *Opcao do menu para remover um Veiculo de um Funcionario que o utilizador quiser.
	 */
	void removeVeiculoFuncionario();

	/**@brief Remove Servico a um Veiculo
	 *
	 *Opcao do menu para remover um Servico de um Veiculo que o utilizador quiser.
	 */
	void removeServicoVeiculo();

	/**@brief Lista Servico de Veiculo
	 *
	 *Opcao do menu para listar os Servicos que um Veiculo tem.
	 */
	void listaVeiculosServicos(Veiculo *v);

	void addEmpresaAluguer(EmpresaAluguer * emp);
	list<EmpresaAluguer *> & getEmpresasAluguer();
	list<EmpresaAluguer *> & removerEmpresaAluguer(string nome);
	void clienteRequisitaViatura(Cliente * c);
	void printClienteViaturaAlugada();
	void listarEmpresasAluguer();
	void EmpresasAluguerbegin();
	//priority_queue<EmpresaAluguer> * getQueue() const;
	//void setQueue(priority_queue<EmpresaAluguer> * pq);

};
#endif
