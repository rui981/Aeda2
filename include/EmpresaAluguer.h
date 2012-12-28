#ifndef EMPRESAALUGUER_H_
#define EMPRESAALUGUER_H_

#include "Veiculo.h"

using namespace std;

class EmpresaAluguer {
private:
	vector<Veiculo *> veiculos;
	string nome;
	int distancia;
	int veiculos_disp;
public:
	EmpresaAluguer(string nome, int dist, int numVeic);
	EmpresaAluguer(string nome, int dist);
	void adicionaVeiculo(Veiculo * v);
	void removeVeiculo(int indice);
	int getNumVeiculosDisp() const;
	string getNome() const;
	int getDistancia() const;
	vector<Veiculo *> & getVeiculos();
};

bool compare(EmpresaAluguer * e1, EmpresaAluguer * e2);

#endif /* EMPRESAALUGUER_H_ */
