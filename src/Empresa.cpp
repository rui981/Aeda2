#include "Empresa.h"
#include "Exception.h"
#include <fstream>
#include <stdlib.h>

#define SIZETEXTO 20


Empresa::Empresa() {
	empresas_aluguer = list<EmpresaAluguer *>();

	try{
		leClientes();
	}
	catch (FailLerClientes) {
		cout << "Leitura de clientes falhou" << endl; 
	}
	catch (FicheiroVazio){
		cout << "Nada para ler no ficheiro " << endl;
	}

	leFuncionarios();

	leStandards();

	leBuses();
	leCamioes();
	leCarros();

	distribuiPessoas();
	distribuiVeiculos();

}

void Empresa::insereInativos(Cliente cl){
	inativos.insert(cl);
}

void Empresa::apagaInativos(Cliente cl){
	tr1::unordered_set<Cliente, hash,eq>::iterator it;

	it= inativos.find(cl);
	if(it!= inativos.end()){
		inativos.erase(it);
	}

}

Empresa::~Empresa() {

}

///////////////////////Funcoes usadas em todos os menus ////////////////////
void Empresa::clear() {
	for (unsigned int i = 0; i < 40; i++) {
		cout << endl;
	}
}

void Empresa::pause() {
	cout << "Prima enter para continuar" << endl;
	cin.get();
}

////////////////////////////////////////////////////////////////////////

/////////////////////Acrescenta e remove objectos aos vectores respectivos ///////////////////

void Empresa::novoCliente(Cliente * c) {
	clientes.push_back(c);
}

void Empresa::novoFuncionario(Funcionario * f) {
	funcionarios.push_back(f);
}

void Empresa::removeFuncionario(int i) {
	funcionarios.erase(funcionarios.begin() + i);
}

void Empresa::removeCliente(int indice) {
	clientes.erase(clientes.begin() + indice);
}

void Empresa::novoCarro(Carro *c) {
	carros.push_back(c);
}

void Empresa::novoCamiao(Camiao *c) {
	camioes.push_back(c);
}

void Empresa::novoBus(Bus *b) {
	buses.push_back(b);
}

void Empresa::removeCarro(int indice) {
	carros.erase(carros.begin() + indice);
}

void Empresa::removeCamiao(int indice) {
	camioes.erase(camioes.begin() + indice);
}

void Empresa::removeBus(int indice) {
	buses.erase(buses.begin() + indice);
}

void Empresa::novoStandard(Standard *s) {
	standards.push_back(s);
}

void Empresa::removeStandard(int indice) {
	standards.erase(standards.begin() + indice);
}

//////////////////////////////////////////////////////////////////

////////////////////////////////// Passa os vectores filho para o vector pai respectivo

void Empresa::distribuiPessoas() {
	for (unsigned int i = 0; i < clientes.size(); i++) {
		pessoas.push_back(clientes[i]);
	}
	for (unsigned int i = 0; i < funcionarios.size(); i++) {
		pessoas.push_back(funcionarios[i]);
	}
}

void Empresa::distribuiVeiculos() {
	for (unsigned int i = 0; i < carros.size(); i++) {
		veiculos.push_back(carros[i]);
	}

	for (unsigned int i = 0; i < camioes.size(); i++) {
		veiculos.push_back(camioes[i]);
	}

	for (unsigned int i = 0; i < buses.size(); i++) {
		veiculos.push_back(buses[i]);
	}
}

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////Escreve nos ficheiros respectivos////////

void Empresa::escreveClientes() {
	fstream ficheiro;
	ficheiro.open("Clientes.txt", fstream::out);

	if (ficheiro.is_open()) {
		for (unsigned int i = 0; i < clientes.size(); i++) {
			ficheiro << clientes[i]->getId() << endl;
			ficheiro << clientes[i]->getNome() << endl;
			ficheiro << clientes[i]->getContacto() << endl;
			ficheiro << clientes[i]->getMorada();
			if (i != clientes.size() - 1) {
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}

void Empresa::escreveFuncionarios() {
	fstream ficheiro;
	ficheiro.open("Funcionarios.txt", fstream::out);

	if (ficheiro.is_open()) {
		for (unsigned int i = 0; i < funcionarios.size(); i++) {
			ficheiro << funcionarios[i]->getId()<< endl;
			ficheiro << funcionarios[i]->getNome() << endl;
			ficheiro << funcionarios[i]->getContacto() << endl;
			ficheiro << funcionarios[i]->getMorada() << endl;
			ficheiro << funcionarios[i]->getTipo() << endl;
			ficheiro << funcionarios[i]->getSalario() << endl;
			ficheiro << funcionarios[i]->getHorasExtra() << endl;
			ficheiro << funcionarios[i]->getVeiculos().size();
			for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size();
					j++) {
				ficheiro << endl;
				ficheiro << funcionarios[i]->getVeiculos()[j]->getMarca()
										<< endl;
				ficheiro << funcionarios[i]->getVeiculos()[j]->getMatricula()
										<< endl;
				ficheiro << funcionarios[i]->getVeiculos()[j]->getModelo();
				if (j != funcionarios[i]->getVeiculos().size() - 1) {
					ficheiro << endl;
				}
			}
			if (i != funcionarios.size() - 1) {
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}

void Empresa::escreveCarros() {
	fstream filestr;
	filestr.open("Carros.txt", fstream::out);

	if (filestr.is_open()) {
		for (unsigned int i = 0; i < carros.size(); i++) {
			filestr << carros[i]->getID() << endl;
			filestr << carros[i]->getMarca() << endl;
			filestr << carros[i]->getModelo() << endl;
			filestr << carros[i]->getMatricula() << endl;
			filestr << carros[i]->getTipo() << endl;
			filestr << carros[i]->getStandards().size();

			for (unsigned int j = 0; j < carros[i]->getStandards().size();
					j++) {
				if(j==0) filestr << endl;
				filestr << carros[i]->getStandards()[j]->getNome() << endl;
				filestr << carros[i]->getStandards()[j]->getDescricao() << endl;
				filestr << carros[i]->getStandards()[j]->getPreco() << endl;
				filestr << carros[i]->getStandards()[j]->getDuracao() << endl;
				filestr << carros[i]->getStandards()[j]->getDataInicio()
												<< endl;
				filestr << carros[i]->getStandards()[j]->getDataFim();
				if (j != carros[i]->getStandards().size() - 1) {
					filestr << endl;
				}
			}

			if (i != carros.size() - 1) {
				filestr << endl;
			}

		}

	}
	filestr.close();
}

void Empresa::escreveBuses() {
	fstream filestr;
	filestr.open("Buses.txt", fstream::out);

	if (filestr.is_open()) {
		for (unsigned int i = 0; i < buses.size(); i++) {
			filestr << buses[i]->getID() << endl;
			filestr << buses[i]->getMarca() << endl;
			filestr << buses[i]->getModelo() << endl;
			filestr << buses[i]->getMatricula()<< endl;
			filestr << buses[i]->getStandards().size();
			for (unsigned int j = 0; j < buses[i]->getStandards().size();
					j++) {
				if(j==0) filestr << endl;
				filestr << buses[i]->getStandards()[j]->getNome() << endl;
				filestr << buses[i]->getStandards()[j]->getDescricao()
													<< endl;
				filestr << buses[i]->getStandards()[j]->getPreco() << endl;
				filestr << buses[i]->getStandards()[j]->getDuracao()
													<< endl;
				filestr << buses[i]->getStandards()[j]->getDataInicio()
													<< endl;
				filestr << buses[i]->getStandards()[j]->getDataFim();

				if (j != buses[i]->getStandards().size() - 1) {
					filestr << endl;
				}

			}
			if (i != buses.size() - 1) {
				filestr << endl;
			}

		}

	}filestr.close();
}

void Empresa::escreveCamioes() {
	ofstream filestr;
	filestr.open("Camioes.txt");

	if (filestr.is_open()) {
		for (unsigned int i = 0; i < camioes.size(); i++) {
			filestr << camioes[i]->getID() << endl;
			filestr << camioes[i]->getMarca() << endl;
			filestr << camioes[i]->getModelo() << endl;
			filestr << camioes[i]->getMatricula() << endl;
			filestr << camioes[i]->getCategoria() << endl;
			filestr << camioes[i]->getStandards().size();
			for (unsigned int j = 0; j < camioes[i]->getStandards().size();
					j++) {
				if(j==0) filestr << endl;
				filestr << camioes[i]->getStandards()[j]->getNome() << endl;
				filestr << camioes[i]->getStandards()[j]->getDescricao()
													<< endl;
				filestr << camioes[i]->getStandards()[j]->getPreco()
													<< endl;
				filestr << camioes[i]->getStandards()[j]->getDuracao()
													<< endl;
				filestr << camioes[i]->getStandards()[j]->getDataInicio()
													<< endl;
				filestr << camioes[i]->getStandards()[j]->getDataFim();
				if (j != camioes[i]->getStandards().size() - 1) {
					filestr << endl;
				}

			}

			if (i != camioes.size() - 1) {
				filestr << endl;
			}

		}

	} filestr.close();
}

void Empresa::escreveStandards() {
	fstream ficheiro;
	ficheiro.open("Standards.txt", fstream::out);

	if (ficheiro.is_open()) {
		for (unsigned int i = 0; i < standards.size(); i++) {
			ficheiro << standards[i]->getNome() << endl;
			ficheiro << standards[i]->getDescricao() << endl;
			ficheiro << standards[i]->getDuracao() << endl;
			ficheiro << standards[i]->getPreco() << endl;
			ficheiro << standards[i]->getDataInicio() << endl;
			ficheiro << standards[i]->getDataFim();
			if (i != standards.size() - 1) {
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}

//////////////////////////////////////////////////////////////////////////

////////////////////////////////Le ficheiros respectivos//////////////////////

void Empresa::leClientes() {
	fstream ficheiro;

	string nome, morada, contactoe;
	string contacto, idS;
	int id;

	ficheiro.open("Clientes.txt", ios::in);

	if (ficheiro.is_open()) {
		while (!ficheiro.eof()) {
			getline(ficheiro, idS);
			getline(ficheiro, nome);
			if (nome == " ") {
				//Se o ficheiro estiver vazio lança excepção
				FicheiroVazio fv;
				throw fv;
			}
			getline(ficheiro, contacto);
			getline(ficheiro, morada);
			id= atoi(idS.c_str());
			Cliente * ce = new Cliente(nome, contacto, morada, id);
			clientes.push_back(ce);

		}
	}
	else {
		cout << "Ficheiro nao aberto, vou lancar excepcao\n";
		FailLerClientes fc;
		throw  fc;
	}
}

void Empresa::leFuncionarios() {
	vector<Veiculo*> vTemp;

	fstream ficheiro;
	int id, horasExtra, tmi;
	string nome, morada, contacto, tipo, salarioe, horasExtrae, temp, marca,
	modelo, matricula, idS;
	double salario;

	ficheiro.open("Funcionarios.txt", fstream::in);

	if (ficheiro.is_open()) {
		while (!ficheiro.eof()) {
			getline(ficheiro, idS);
			getline(ficheiro, nome);
			if (nome == " ")
				return;
			getline(ficheiro, contacto);
			getline(ficheiro, morada);
			getline(ficheiro, tipo);
			getline(ficheiro, salarioe);
			getline(ficheiro, horasExtrae);
			getline(ficheiro, temp);
			tmi = atoi(temp.c_str());
			for (unsigned int i = 0; i < tmi; i++) {
				getline(ficheiro, marca);
				getline(ficheiro, modelo);
				getline(ficheiro, matricula);
				Veiculo *vec = new Veiculo(marca, modelo, matricula);
				vTemp.push_back(vec);
			}

			salario = atof(salarioe.c_str());
			horasExtra = atoi(horasExtrae.c_str());
			id= atoi(idS.c_str());
			Funcionario * ce = new Funcionario(nome, contacto, morada, tipo,
					salario, horasExtra, id);
			ce->setVeiculos(vTemp);
			funcionarios.push_back(ce);

		}
	}

}

void Empresa::leCarros() {
	fstream file;
	string id, brand, model, lp, tip, nre, nome, descricao, precoe, duracaoe, datai,
	dataf;
	int nr,id1;
	vector<Standard*> stand;

	double preco, duracao;
	file.open("Carros.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, id);
			getline(file, brand);
			getline(file, model);
			getline(file, lp);
			getline(file, tip);
			getline(file, nre);
			nr = atoi(nre.c_str());
			id1 = atoi(id.c_str());
			for (unsigned int i = 0; i < nr; i++) {
				getline(file, nome);
				getline(file, descricao);
				getline(file, precoe);
				getline(file, duracaoe);
				getline(file, datai);
				getline(file, dataf);
				preco = atof(precoe.c_str());
				duracao = atof(duracaoe.c_str());
				Standard *s = new Standard(nome, descricao, preco, duracao,
						datai, dataf);
				stand.push_back(s);

			}

			if(brand.size() > 0) {
				cout << "matricula" << lp << endl;
				Carro * v = new Carro(brand, model, lp, tip, id1);
				v->setStandards(stand);
				novoCarro(v);
			}

		}
	}

}

void Empresa::leBuses() {
	fstream file;
	string id, brand, model, lp, nre, nome, descricao, precoe, duracaoe, datai,
	dataf;
	double preco, duracao;
	int nr,id1;
	vector<Standard*> stand;

	file.open("Buses.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, id);
			getline(file, brand);
			getline(file, model);
			getline(file, lp);

			getline(file, nre);
			nr = atoi(nre.c_str());
			id1 = atoi(id.c_str());
			for (unsigned int i = 0; i < nr; i++) {
				getline(file, nome);
				getline(file, descricao);
				getline(file, precoe);
				getline(file, duracaoe);
				getline(file, datai);
				getline(file, dataf);
				preco = atof(precoe.c_str());
				duracao = atof(duracaoe.c_str());
				Standard *s = new Standard(nome, descricao, preco, duracao,
						datai, dataf);
				stand.push_back(s);

			}

			if(brand.size() > 0) {
				Bus * v = new Bus(brand, model, lp, id1);
				v->setStandards(stand);
				novoBus(v);
			}

		}
	}

}

void Empresa::leCamioes() {
	fstream file;
	string id, brand, model, lp, cat, nre, nome, descricao, precoe, duracaoe, datai,
	dataf;
	int nr,id1;
	double preco, duracao;
	vector<Standard *> stand;
	int control = 0;

	file.open("Camioes.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, id);
			getline(file, brand);
			getline(file, model);
			getline(file, lp);
			getline(file, cat);

			getline(file, nre);
			nr = atoi(nre.c_str());
			id1 = atoi(id.c_str());
			for (unsigned int i = 0; i < nr; i++) {
				getline(file, nome);
				getline(file, descricao);
				getline(file, precoe);
				getline(file, duracaoe);
				getline(file, datai);
				getline(file, dataf);
				preco = atof(precoe.c_str());
				duracao = atof(duracaoe.c_str());
				Standard *s = new Standard(nome, descricao, preco, duracao,
						datai, dataf);
				stand.push_back(s);

			}

			if(brand.size() > 0) {
				Camiao * v = new Camiao(brand, model, lp, cat, id1);
				v->setStandards(stand);
				novoCamiao(v);
			}
		}
	}
}

void Empresa::leStandards() {

	fstream file;
	string nome, descricao, duracaoe, precoe, dataI, dataF;
	double duracao, preco;
	file.open("Standards.txt");
	if (file.is_open()) {
		while (!file.eof()) {

			getline(file, nome);
			getline(file, descricao);
			getline(file, duracaoe);
			getline(file, precoe);
			getline(file, dataI);
			getline(file, dataF);

			duracao = atof(duracaoe.c_str());
			preco = atof(precoe.c_str());

			Standard * s = new Standard(nome, descricao, duracao, preco, dataI,
					dataF);
			novoStandard(s);
		}
	}

}

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////MENU geral////////////////////////////////////

void Empresa::menu() {
	int op;
	int opF, opC;
	string nomeCliente, moradaCliente, contactoCliente,ope;

	do {
		clear();
		cout << "Bemvindo a empresa Jopati" << endl << endl;
		cout << "Menu Funcionarios-------------1" << endl;
		cout << "Menu Cliente------------------2" << endl;
		cout << "Menu Veiculos-----------------3" << endl;
		cout << "Servicos----------------------4" << endl;
		cout << "Sair--------------------------0" << endl;
		cout << "Escolha a sua opcao" << endl;
		cout << "Opcao : ";


		try {		

			getline(cin, ope);
			op=atoi(ope.c_str());


			if(op < 0 || op > 4) {
				OFBOpcoes o;
				throw o;
			}			
		}

		catch (OpcoesExc){
			cout << "Opção Invalida" << endl;
			pause();
			clear();
		}


		switch (op) {
		case 1: {
			string opfe;
			clear();
			cout << "**************Menu Funcionarios***********************"
					<< endl << endl;
			cout << "Adicionar Funcionario----------------1" << endl;
			cout << "Remover Funcionario------------------2" << endl;
			cout << "Modificar Funcionario----------------3" << endl;
			cout << "Listar Funcionarios------------------4" << endl;
			cout << "Adicionar Veiculo a Funcionario------5" << endl;
			cout << "Remover Veiculo a Funcionario--------6" << endl;
			cout << "Sair---------------------------------0" << endl;
			try{	
				getline(cin, opfe);
				opF=atoi(opfe.c_str());

				if(opF < 0 || opF > 6) {
					OFBOpcoes ofb;
					throw ofb;
				}
			}

			catch (OpcoesExc) {
				cout << "Opçao invalida" << endl;
				pause();
				clear();
				break;

			} 


			string nome, contacto, morada, tipo, salarioe;
			double salario;
			int horasExtra = 0;

			switch (opF) {
			case 1: {
				int confirmacao;
				do {
					clear();
					try {
						cout << "Insira nome de Funcionario" << endl;
						getline(cin, nome);
						if(nome.size() > SIZETEXTO){
							fNomeOFB nb;
							throw nb;
						}

						cout << "Insira contacto de Funcionario" << endl;
						getline(cin, contacto);
						if(contacto.size() > SIZETEXTO){
							fContactoOFB cb;
							throw cb;
						}

						cout << "Insira morada de Funcionario" << endl;
						getline(cin, morada);
						if(morada.size() > SIZETEXTO){
							fMoradaOFB mb;
							throw mb;
						}
						cout << "Insira tipo de Funcionario" << endl;
						getline(cin, tipo);
						if(tipo.size() > SIZETEXTO){
							fTipoOFB tb;
							throw tb;
						}
						cout << "Insira salario de Funcionario" << endl;
						getline(cin, salarioe);

						if(salarioe.size() > SIZETEXTO){
							fSalarioOFB sb;
							throw sb;
						}
					}
					catch (FuncionarioOFB) {
						cout << "String Overflow.... A relançar menu" << endl;
						pause();
						clear();
						break;

					}

					try{
						salario = atof(salarioe.c_str());
						if(salario <= 0) {
							fSalarioOFB fs;
							throw fs;
						}
					}
					catch(FuncionarioOFB){
						cout << "Salario Invalido" << endl;
						pause();
						clear();
						break;
						menu();
					}
					string confirmacaoe;

					Funcionario * funcTemp = new Funcionario(nome, contacto,
							morada, tipo, salario, horasExtra);
					clear();
					funcTemp->imprime();

					cout << "Confirma os dados?" << endl;
					cout << "Sim----------------------1" << endl;
					cout << "Nao----------------------2" << endl;
					try {
						getline(cin, confirmacaoe);
						confirmacao = atoi(confirmacaoe.c_str());

						if(confirmacao < 1 || confirmacao > 2) {
							OFBOpcoes of;
							throw of;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção Invalida" << endl;
						pause();
						clear();
						break;
						menu();
					}

					if (confirmacao == 1) {
						novoFuncionario(funcTemp);
						cout << "Funcionario adicionado com sucesso!" << endl;
						pause();
					} else {
						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;

						try {

							getline(cin, confirmacaoe);
							confirmacao = atoi(confirmacaoe.c_str());

							if(confirmacao < 1 || confirmacao > 2) {
								OFBOpcoes of;
								throw of;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							break;
						}	
					}

				} while (confirmacao != 1);

			}
			break;
			case 2: {
				clear();
				int numeracao, conf;
				string numeracaoe, confe;
				do {
					for (unsigned int i = 0; i < funcionarios.size(); i++) {
						cout << i + 1 << "   " << funcionarios[i]->getNome()
												<< endl;
					}
					cout << "Qual dos funcionarios deseja eliminar?" << endl;

					try {
						getline(cin, numeracaoe);
						numeracao = atoi(numeracaoe.c_str());

						if(numeracao < 1 || numeracao > funcionarios.size()) {
							FuncionarioInvalido iv;
							throw iv;
						}
					}
					catch (FuncionarioOFB){
						cout << "Funcionario que deseja remover não existe" << endl;
						pause();
						clear();
						break;
					}

					clear();
					cout << *(funcionarios[numeracao - 1]) << endl;
					cout << "Tem a certeza que quer apagar este Funcionario?"
							<< endl;
					cout << "Sim --------------------------------------1"
							<< endl;
					cout << "Nao --------------------------------------2"
							<< endl;
					try {
						getline(cin, confe);
						conf = atoi(confe.c_str());

						if(conf < 1 || conf > 2){
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc){
						cout << "Opcao Invalida" << endl;
						pause();
						clear();
						break;

					}

					if (conf == 1) {

						removeFuncionario(numeracao - 1);
						cout << "Funcionario apagado do sistema" << endl;
						pause();
					} else {

						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;

						try {
							getline(cin, confe);
							conf = atoi(confe.c_str());

							if(conf < 1 || conf > 2){
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc){
							cout << "Opcao Invalida" << endl;
							pause();
							clear();
							break;
						}

					}
				} while (conf != 1);
			}

			break;

			case 3: {
				modificaFunc();
			}
			break;

			case 4: {
				clear();
				string numeracaoe, confe;
				int numeracao, conf;
				for (unsigned int i = 0; i < funcionarios.size(); i++) {
					cout << i + 1 << "   " << funcionarios[i]->getNome()
											<< endl;
				}

				cout << "Qual dos funcionarios deseja examinar?" << endl;
				try {
					getline(cin, numeracaoe);
					numeracao = atoi(numeracaoe.c_str());

					if(numeracao < 1 || numeracao > funcionarios.size()) {
						FuncionarioInvalido iv;
						throw iv;
					}
				}
				catch (FuncionarioOFB) {
					cout << "Funcionario não existente" << endl;
					pause();
					clear();
					break;

				}

				cout << *(funcionarios[numeracao - 1]) << endl;
				pause();
			}
			break;
			case 5: { //adiciona veiculos a um funcionario
				clear();
				adicionaVeiculoFuncionario();

			}break;

			case 6: {
				clear();
				removeVeiculoFuncionario();
				pause();

			} break;


			case 0: {
				opF = 0;
			}
			break;
			}

		}
		break;
		case 2: {
			string opCe;
			clear();
			cout << "**************Menu Clientes***********************" << endl
					<< endl;
			cout << "Adicionar Cliente----------------1" << endl;
			cout << "Remover Cliente------------------2" << endl;
			cout << "Modificar Cliente----------------3" << endl;
			cout << "Listar Clientes------------------4" << endl;
			cout << "Sair---------------------------------0" << endl;

			try {
				getline(cin, opCe);
				opC = atoi(opCe.c_str());


				if(opC < 0 || opC > 4) {
					OFBOpcoes of;
					throw of;
				}
			}
			catch (OpcoesExc)  {
				cout << "Opção Invalida: " << endl;
				pause();
				clear();
				break;
			}

			switch (opC) {

			case 1: {
				int confirmacao;
				string confirmacaoe;
				do {
					try{
						clear();
						cout << "Insira nome do Cliente" << endl;
						getline(cin, nomeCliente);
						if(nomeCliente.size() > SIZETEXTO) {
							cNomeOFB of;
							throw of;
						}

						cout << "Insira morada do CLiente" << endl;
						getline(cin, moradaCliente);
						if(moradaCliente.size() > SIZETEXTO) {
							cMoradaOFB om;
							throw om;
						}

						cout << "Insira contacto cliente" << endl;
						getline(cin, contactoCliente);
						if(contactoCliente.size() > SIZETEXTO) {
							cContactoOFB oc;
							throw oc;
						}
					}
					catch (ClienteOFB) {
						cout << "String Overflow" << endl;
						pause();
						clear();
						break;
					}

					Cliente * cliTemp = new Cliente(nomeCliente,
							contactoCliente, moradaCliente);
					clear();
					cout << *cliTemp << endl << endl;

					cout << "Confirma os dados?" << endl;
					cout << "Sim-----------1" << endl;
					cout << "Nao-----------2" << endl;

					try {
						getline(cin, confirmacaoe);
						confirmacao = atoi(confirmacaoe.c_str());

						if(confirmacao < 1 || confirmacao > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch(OpcoesExc) {
						cout << "Opçao Invalida" << endl;
					}


					if (confirmacao == 1) {
						novoCliente(cliTemp);
						cout << "Cliente adicionado" << endl;
						pause();
					} else {
						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;

						try {
							getline(cin, confirmacaoe);
							confirmacao = atoi(confirmacaoe.c_str());

							if(confirmacao < 1 || confirmacao > 2) {
								OFBOpcoes o;
								throw o;
							}
						}
						catch(OpcoesExc) {
							cout << "Opçao Invalida" << endl;
							pause();
							clear();
							break;
						}

						pause();
					}
				} while (confirmacao != 1);

			}

			break;
			case 2: {

				clear();
				int numeracao, conf;
				string numeracaoe, confe;

				do {
					for (unsigned int i = 0; i < clientes.size(); i++) {
						cout << i + 1 << "   " << clientes[i]->getNome()
												<< endl;
					}

					cout << "Qual dos clientes deseja eliminar?" << endl;
					try {
						getline(cin, numeracaoe);
						numeracao = atoi(numeracaoe.c_str());

						if(numeracao < 1 || numeracao > clientes.size()) {
							ClienteInvalido iv;
							throw iv;
						}
					}
					catch (ClienteOFB) {
						cout << "Tentou remover cliente não existente" << endl;
						pause();
						clear();
						break;
					}


					clear();
					cout << *(clientes[numeracao - 1]) << endl;
					cout << "Tem a certeza que quer apagar este cliente?"
							<< endl;
					cout << "Sim --------------------------------------------1"
							<< endl;
					cout << "Nao --------------------------------------------2"
							<< endl;
					try {		
						getline(cin, confe);
						conf = atoi(confe.c_str());

						if(conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção Invalida" << endl;
						pause();
						clear();
						break;
					} 


					if (conf == 1) {
						removeCliente(numeracao - 1);
						cout << "Cliente apagado do sistema" << endl;
						pause();
					} else {
						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;

						try {		
							getline(cin, confe);
							conf = atoi(confe.c_str());

							if(conf < 1 || conf > 2) {
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							break;
						} 

						pause();
					}
				} while (conf != 1);
			}
			break;

			case 3: {
				modificaCli();
			}
			break;

			case 4: {
				clear();
				int opcao;
				string opcaoe;

				for (unsigned int i = 0; i < clientes.size(); i++) {
					cout << i + 1 << "  " << clientes[i]->getNome() << endl;
				}
				cout << "Qual o cliente que deseja analisar?" << endl;

				try {
					getline(cin, opcaoe);
					opcao = atoi(opcaoe.c_str());

					if(opcao < 1 || opcao > clientes.size()) {
						ClienteInvalido inv;
						throw inv;
					}
				}
				catch (ClienteOFB){
					cout << "Cliente Invalido" << endl;
					pause();
					clear();
					break;

				}

				cout << *(clientes[opcao - 1]) << endl;
				pause();
			}
			break;
			}
		}
		break;

		case 3: { //Menu Veiculos
			menuVeiculos();
		}
		break;
		case 4: {		//Menu Servicos
			clear();
			int opS;
			string opSe;
			string datai, dataf, nome, descricao, precoe, duracaoe;
			double preco, duracao;
			cout << "**************Menu Servicos***********************" << endl
					<< endl;
			cout << "Adicionar Servico Standard----------------1" << endl;
			cout << "Remover Servico Standard------------------2" << endl;
			cout << "Modificar Servico Standard----------------3" << endl;
			cout << "Listar Servicos Standard------------------4" << endl;
			cout << "Adicionar Servico a veiculo---------------5" << endl;
			cout << "Retirar Servico a veiculo-----------------6" << endl;
			cout << "Sair--------------------------------------0" << endl;

			try {
				getline(cin, opSe);
				opS = atoi(opSe.c_str());

				if(opS < 0 || opS > 6) {
					OFBOpcoes o;
					throw o;
				}
			}
			catch (OpcoesExc) {
				cout << "Opção invalida" << endl;
				pause();
				clear();
				break;
			}

			clear();

			switch (opS) {
			case 1: {		// Adicionar Servico Standard
				int conf;
				string confe;

				do {

					try {
						cout << "Insira data de inicio (XX-XX-XX)" << endl;
						getline(cin, datai);
						if(datai.size() > SIZETEXTO) {
							DataIniExc di;
							throw di;
						}

						cout << "Insira data de fim (XX-XX-XX)" << endl;
						getline(cin, dataf);
						if(dataf.size() > SIZETEXTO) {
							DataFimExc df;
							throw df;
						}

						cout << "Insira nome do servico" << endl;
						getline(cin, nome);
						if(nome.size() > SIZETEXTO) {
							NomServExc ns;
							throw ns;
						}

						cout << "Insira descricao do servico" << endl;
						getline(cin, descricao);
						if(descricao.size() > SIZETEXTO) {
							DescServExc dc;
							throw dc;
						}

						cout << "Insira preco por hora do servico" << endl;
						getline(cin, precoe);
						if(precoe.size() > SIZETEXTO) {
							PrecoServExc ps;
							throw ps;
						}

						cout << "Insira duracao do servico" << endl;
						getline(cin, duracaoe);
						if(duracaoe.size() > SIZETEXTO) {
							DuracaoServExc ds;
							throw ds;
						}
					}
					catch (ServicosExc) {
						cout << "String Overflow" << endl;
						pause();
						clear();
						break;
					}

					try {
						preco = atof(precoe.c_str());
						if (preco <= 0) {
							PrecoServExc ps;
							throw ps;
						}
					}
					catch(PrecoServExc) {
						cout << "Preço Invalido" <<endl;
						pause();
						clear();
						break;
					}

					try {
						duracao = atof(duracaoe.c_str());
						if(duracao <= 0) {
							DuracaoServExc ds;
							throw ds;
						}
					}
					catch(DuracaoServExc) {
						cout << "Duração Invalida" << endl;
						pause();
						clear();
						break;
					}

					Standard *s = new Standard(nome, descricao, preco, duracao,
							datai, dataf);

					cout << "Servico bem criado?" << endl;
					cout << "Sim----------------1" << endl;
					cout << "Nao----------------2" << endl;

					try {
						getline(cin, confe);
						conf = atoi(confe.c_str());

						if (conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção invalida" << endl;
						pause();
						clear();
						break;
					}

					if (conf == 1) {
						novoStandard(s);
					} else {
						cout << "Deseja repetir os dados?" << endl;
						cout << "Nao----------------1" << endl;
						cout << "Sim----------------2" << endl;

						try {
							getline(cin, confe);
							conf = atoi(confe.c_str());

							if (conf < 1 || conf > 2) {
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção invalida" << endl;
							pause();
							clear();
							break;
						}

					}
				} while (conf != 1);

			}
			break;
			case 2: { //Remover servicos standard
				int serv, conf;
				string serve, confe;

				do {
					for (unsigned int i = 0; i < standards.size(); i++) {
						cout << i + 1 << "  " << standards[i]->getNome()
												<< endl;
					}

					cout << "Qual o servico que deseja remover?" << endl;
					try {

						getline(cin, serve);
						serv = atoi(serve.c_str());

						if(serv < 1 || serv > standards.size()) {
							ServInvalido si;
							throw si;
						}
					}
					catch (ServicosExc) {
						cout << "Tentou remover serviço inexistente" << endl;
						pause();
						clear();
						break;
					}



					cout << "Tem a certeza que quer remover o Servico "
							<< standards[serv - 1]->getNome() << endl;
					cout << "Sim----------------1" << endl;
					cout << "Nao----------------2" << endl;

					try {

						getline(cin, confe);
						conf = atoi(confe.c_str());

						if(conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção Invalida" << endl;
						pause();
						clear();
						break;				

					}

					if (conf == 1) {
						removeStandard(serv - 1);
						cout << "Servico removido com sucesso" << endl;

					} else {
						cout << "Deseja eliminar outro servico?" << endl;
						cout << "Nao----------------1" << endl;
						cout << "Sim----------------2" << endl;

						try {
							getline(cin, confe);
							conf = atoi(confe.c_str());

							if(conf < 1 || conf > 2) {
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							break;				
						}
					}
				} while (conf != 1);
			}
			break;

			case 3: { //Modifica servico standard
				modificaServ();

			}
			break;

			case 4: { //Lista servicos

				clear();
				int opcao;
				string opcaoe;

				for (unsigned int i = 0; i < standards.size(); i++) {
					cout << i + 1 << "  " << standards[i]->getNome() << endl;
				}

				cout << "Qual o servico que deseja analisar?" << endl;

				try{

					getline(cin, opcaoe);
					opcao = atoi(opcaoe.c_str());

					if(opcao < 1 || opcao > standards.size()){
						ServInvalido si;
						throw si;
					}
				}
				catch (ServicosExc) {
					cout << "Serviço Inexistente" << endl;
					pause();
					clear();
					break;
				}


				cout << *(standards[opcao - 1]) << endl;
				pause();

			}
			break;

			case 5: { // adicionar servico ao veiculo
				clear();
				int opcao, opcao2, opcao3;
				string opcaoe, opcao2e, opcao3e;

				cout << "A que veiculo deseja adicionar o servico?" << endl;
				for (unsigned int i = 0; i < veiculos.size(); i++) {
					cout << i + 1 << "  " << veiculos[i]->getMarca() << endl;
				}

				try {
					getline(cin, opcaoe);
					opcao = atoi(opcaoe.c_str());

					if(opcao < 1 || opcao > veiculos.size()){
						VeicInvalido vi;
						throw vi;
					}
				}
				catch (VeicExc){
					cout << "Veiculo Invalido" << endl;
					pause();
					clear();
					break;
				}

				cout << "Deseja acrescentar um servico standart " << endl;
				cout << "Sim----------------1" << endl;
				cout << "Nao----------------2" << endl;

				try {
					getline(cin, opcao2e);
					opcao2 = atoi(opcao2e.c_str());

					if(opcao2 < 1 || opcao2 > 2) {
						OFBOpcoes o;
						throw o;
					}
				}
				catch (OpcoesExc) {
					cout << "Opcao Invalida" << endl;
					pause();
					clear();
					break;
				}


				if (opcao2 == 1) {
					cout << "Que servico deseja adicionar?" << endl;
					for (unsigned int i = 0; i < standards.size(); i++) {
						cout << i + 1 << "  " << standards[i]->getNome()
												<< endl;
					}

					try {
						getline(cin, opcao3e);
						opcao3 = atoi(opcao3e.c_str());

						if(opcao3 < 1 || opcao3 > standards.size()) {
							ServInvalido si;
							throw si;
						}
					}
					catch (ServicosExc){
						cout << "Servico Invalido" << endl;
						pause();
						clear();
						break;
					}


					veiculos[opcao - 1]->novoStandard(standards[opcao3 - 1]);
					cout << "Servico Standard adicionado a Veiculo com sucesso" << endl;

				} else if (opcao2 == 2) {
					int conf;
					do {
						try {
							cout << "Insira data de inicio (XX-XX-XX)" << endl;
							getline(cin, datai);
							if(datai.size() > 8){
								DataIniExc di;
								throw di;
							}

							cout << "Insira data de fim (XX-XX-XX)" << endl;
							getline(cin, dataf);
							if(dataf.size() > 8){
								DataFimExc df;
								throw df;
							}

							cout << "Insira nome do servico" << endl;
							getline(cin, nome);
							if(nome.size() > SIZETEXTO){
								NomServExc ns;
								throw ns;
							}

							cout << "Insira descricao do servico" << endl;
							getline(cin, descricao);
							if(descricao.size() > SIZETEXTO) {
								DescServExc ds;
								throw ds;
							}

							cout << "Insira preco por hora do servico" << endl;
							getline(cin, precoe);
							if(precoe.size()>SIZETEXTO) {
								PrecoServExc ps;
								throw ps;
							}

							cout << "Insira duracao do servico" << endl;
							getline(cin, duracaoe);
							if(duracaoe.size()>SIZETEXTO) {
								DuracaoServExc ds;
								throw ds;
							}
						}
						catch (ServicosExc){
							cout << "String overflow" << endl;
							pause();
							clear();
							break;
						}

						try {
							preco = atof(precoe.c_str());
							if(preco <= 0) {
								PrecoServExc ps;
								throw ps;
							}
						}
						catch(ServicosExc) {
							cout << "Preço Invalido" << endl;
							pause();
							clear();
							break;
						}

						try {
							duracao = atof(duracaoe.c_str());
							if(duracao < 0){
								DuracaoServExc ds;
								throw ds;
							}
						}
						catch (ServicosExc) {
							cout << "Duracao Invalida" << endl;
							pause();
							clear();
							break;
						}
						string confe;
						Standard *s = new Standard(nome, descricao, preco,
								duracao, datai, dataf);
						cout << "Servico bem criado?" << endl;
						cout << "Sim----------------1" << endl;
						cout << "Nao----------------2" << endl;

						try{
							getline(cin, confe);
							conf = atoi(confe.c_str());

							if(conf < 1 || conf > 2){
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc){
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							break;
						}

						if (conf == 1) {
							veiculos[opcao - 1]->novoStandard(s);

						} else {
							cout << "Deseja repetir os dados?" << endl;
							cout << "Nao----------------1" << endl;
							cout << "Sim----------------2" << endl;

							try{
								getline(cin, confe);
								conf = atoi(confe.c_str());

								if(conf < 1 || conf > 2){
									OFBOpcoes o;
									throw o;
								}
							}
							catch (OpcoesExc){
								cout << "Opção Invalida" << endl;
								pause();
								clear();
								break;
							}

						}
					} while (conf != 1);
				}
			}
			break;

			case 6: {//remove servico a veiculo
				clear();
				removeServicoVeiculo();
				pause();

			}break;

			}
		} //fim menu servicos
		break;

		case 0: {
			escreveStandards();
			escreveClientes();
			escreveFuncionarios();
			escreveBuses();
			escreveCamioes();
			escreveCarros();
			op = 0;
		}
		break;
		} //end 1st switch

	} while (op != 0);
}

void Empresa::modificaFunc() {
	int numeracao, conf;
	string numeracaoe, confe;

	for (unsigned int i = 0; i < funcionarios.size(); i++) {
		cout << i + 1 << "   " << funcionarios[i]->getNome() << endl;
	}

	cout << "Qual o funcionario que deseja modificar" << endl;

	try {
		getline(cin, numeracaoe);
		numeracao = atoi(numeracaoe.c_str());

		if(numeracao < 1 || numeracao > funcionarios.size()){
			FuncionarioInvalido fi;
			throw fi;
		}
	}
	catch (FuncionarioOFB) {
		cout << "Funcionario não existente" << endl;
		pause();
		clear();
	}


	clear();

	if(numeracao >=1 && numeracao <=funcionarios.size()){

		cout << *(funcionarios[numeracao - 1]) << endl;
		pause();
		cout << "o que deseja modificar ?" << endl;
		cout << "Nome---------------1" << endl;
		cout << "Contacto-----------2" << endl;
		cout << "Morada-------------3" << endl;
		cout << "Horas extra--------4" << endl;
		cout << "Salario------------5" << endl;
		cout << "Especializacao-----6" << endl;
		cout << "Alterar Veiculos---7" << endl;
		cout << "Sair---------------0" << endl;

		try {
			getline(cin, confe);
			conf = atoi(confe.c_str());

			if(conf < 0 || conf > 7){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc) {
			cout << "Opção Invalida" << endl;
			pause();
			clear();

		}


		switch (conf) {

		case 1: {
			try{
				clear();
				string nome;
				cout << "Qual o novo nome?" << endl;
				getline(cin, nome);
				if(nome.size() > SIZETEXTO) {
					fNomeOFB n;
					throw n;
				}

				funcionarios[numeracao - 1]->setNome(nome);
				cout << "Nome alterado com sucesso" << endl;
				pause();
			}
			catch (FuncionarioOFB){
				cout << "String overflow" << endl;
				pause();
				clear();
				break;

			}


		}
		break;

		case 2: {
			try {
				clear();
				string contacto;
				cout << "Qual o novo contacto?" << endl;
				getline(cin, contacto);
				if(contacto.size() > SIZETEXTO) {
					fContactoOFB c;
					throw c;
				}
				funcionarios[numeracao - 1]->setContacto(contacto);
				cout << "Contacto alterado com sucesso" << endl;
				pause();
			}
			catch (FuncionarioOFB){
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
			}


		}
		break;
		case 3: {
			try {
				clear();
				string morada;
				cout << "Qual a nova morada?" << endl;
				getline(cin, morada);
				if(morada.size() > SIZETEXTO) {
					fMoradaOFB m;
					throw m;
				}
				funcionarios[numeracao - 1]->setMorada(morada);
				cout << "Morada alterada com sucesso" << endl;
				pause();
			}
			catch (FuncionarioOFB){
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
			}

		}
		break;
		case 4: {

			clear();
			string temp;
			int horasEx;
			try {

				cout << "Qual o numero das horas extra?" << endl;
				getline(cin, temp);
				if(temp.size() > SIZETEXTO) {
					fHorasExtraSize fhs;
					throw fhs;
				}


				horasEx = atoi(temp.c_str());
				if(horasEx <= 0) {
					fHorasExtraOFB o;
					throw o;
				}
			}

			catch (fHorasExtraOFB){
				cout << "Horas extra invalidas" << endl;
				pause();
				menu();
				break;
			}

			catch (fHorasExtraSize){
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
			}

			funcionarios[numeracao - 1]->setHorasExtra(horasEx);
			cout << "Horas extra alteradas com sucesso" << endl;
			pause();

		}
		break;
		case 5: {
			try {
				clear();
				string temp;
				int salario;
				cout << "Qual o novo salario?" << endl;
				getline(cin, temp);

				if(temp.size() > SIZETEXTO){
					fSalarioSize fss;
					throw fss;
				}

				salario = atoi(temp.c_str());
				if(salario <= 0) {
					fSalarioOFB of;
					throw of;
				}

				funcionarios[numeracao - 1]->setSalario(salario);
				cout << "Salario alterado com sucesso" << endl;
				pause();
			}
			catch (fSalarioSize){
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
				clear();
			}
			catch (fSalarioOFB) {
				cout << "Salario Invalido" << endl;
				pause();
				menu();
				break;
				clear();
			}

		}
		break;
		case 6: {
			try {
				clear();
				string especializacao;
				cout << "Qual a nova especializacao?" << endl;
				getline(cin, especializacao);
				if(especializacao.size() > SIZETEXTO){
					fEspecOFB esp;
					throw esp;
				}
				funcionarios[numeracao - 1]->setTipo(especializacao);
				cout << "Especializacao alterada com sucesso" << endl;
				pause();
			}
			catch (FuncionarioOFB){
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
				clear();
			}
		}
		break;

		case 7: {
			clear();
			int opcao, nrvei;
			string opcaoe, nrveie;

			cout << "Adicionar veiculo--------1" << endl;
			cout << "Remover veiculo----------2" << endl;

			try {
				getline(cin, opcaoe);
				opcao = atoi(opcaoe.c_str());

				if (opcao < 1 || opcao > 2) {
					OFBOpcoes o;
					throw o;
				}
			}
			catch (OpcoesExc){
				cout << "Opção Invalida" << endl;
				pause();
				clear();
				break;
			}



			if (opcao == 1) {
				clear();
				cout << "Veiculos disponiveis para adicionar" << endl;
				for (unsigned int i = 0; i < veiculos.size(); i++) {
					cout << i + 1 << "   " << veiculos[i]->getMarca() << endl;
				}
				cout << "Selecione veiculo para adicionar" << endl;

				try {
					getline(cin, nrveie);
					nrvei = atoi(nrveie.c_str());

					if(nrvei < 1 || nrvei > veiculos.size()) {
						VeicInvalido vi;
						throw vi;
					}
				}
				catch (VeicExc){
					cout << "Veiculo Inexistente" << endl;
					pause();
					clear();
					break;
				}



				funcionarios[numeracao - 1]->adicionaVeiculo(veiculos[nrvei - 1]);
				cout << "Veiculo adicionado com sucesso" << endl;
				pause();

			} else {
				if (opcao == 2) {
					clear();
					cout << "Veiculos do funcionario para remover" << endl;
					for (unsigned int i = 0;
							i < funcionarios[numeracao - 1]->getVeiculos().size();
							i++) {
						cout << i + 1
								<< funcionarios[numeracao - 1]->getVeiculos()[i]->getMarca()
								<< endl;
					}
					cout << "Selecione veiculo para retirar" << endl;

					try {
						getline(cin, nrveie);
						nrvei = atoi(nrveie.c_str());

						if(nrvei < 1 || nrvei > veiculos.size()) {
							VeicInvalido vi;
							throw vi;
						}
					}
					catch (VeicExc){
						cout << "Veiculo Inexistente" << endl;
						pause();
						clear();
						break;
					}


					funcionarios[numeracao - 1]->removeVeiculo(nrvei - 1);
					cout << "Veiculo removido com sucesso" << endl;
					pause();

				}

			}
		}
		break;

		case 0: {

		}
		break;

		}
	}
}

void Empresa::modificaCli() {

	clear();
	int indice, temp;
	string indicee, tempe;

	for (unsigned int i = 0; i < clientes.size(); i++) {
		cout << i + 1 << "  " << clientes[i]->getNome() << endl;
	}
	cout << "Qual o cliente que deseja modificar?" << endl;
	try {
		getline(cin, indicee);
		indice = atoi(indicee.c_str());

		if(indice < 1 || indice > clientes.size()){
			ClienteInvalido ci;
			throw ci;
		}
	}
	catch (ClienteOFB){
		cout << "Cliente Inexistente" << endl;
		pause();
		clear();
	}

	if(indice >1 && indice <clientes.size()){
		clear();
		cout << *(clientes[indice - 1]) << endl;
		pause();

		cout << "O que deseja modificar?" << endl;
		cout << "Nome ----------------1" << endl;
		cout << "Contacto ------------2" << endl;
		cout << "Morada---------------3" << endl;
		cout << "Sair-----------------0" << endl;

		try {
			getline(cin, tempe);
			temp = atoi(tempe.c_str());

			if(temp < 0 || temp > 3) {
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc) {
			cout << "Opção invalida" << endl;
			pause();
			clear();

		}



		switch (temp) {
		case 1: {
			clear();
			string nome;
			cout << "Qual o novo nome?" << endl;
			getline(cin, nome);
			try {
				if(nome.size() > SIZETEXTO){
					cNomeOFB cn;
					throw cn;
				}
			}
			catch(ClienteOFB) {
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
				clear();
			}

			clientes[indice - 1]->setNome(nome);
			cout << "Nome alterado com sucesso" << endl;
			pause();
		}
		break;
		case 2: {
			clear();
			string contacto;
			cout << "Qual o novo contacto?" << endl;
			getline(cin, contacto);
			try {
				if(contacto.size() > SIZETEXTO){
					cContactoOFB ct;
					throw ct;
				}
			}
			catch(ClienteOFB) {
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
				clear();
			}


			clientes[indice - 1]->setContacto(contacto);
			cout << "Contacto alterado com sucesso" << endl;
			pause();
		}
		break;
		case 3: {
			clear();
			string morada;
			cout << "Qual a nova morada?" << endl;
			getline(cin, morada);
			try {
				if(morada.size() > SIZETEXTO){
					cMoradaOFB md;
					throw md;
				}
			}
			catch(ClienteOFB) {
				cout << "String overflow" << endl;
				pause();
				menu();
				break;
				clear();
			}

			clientes[indice - 1]->setMorada(morada);
			cout << "Morada alterada com sucesso" << endl;
			pause();
		}
		break;
		case 0: {

		}
		break;

		}
	}
}

void Empresa::menuVeiculos() {
	clear();
	int opcao;
	string opcaoe;
	cout << "Seleccione uma opcão:" << endl;
	cout << "Adicionar Veiculo----------1" << endl;
	cout << "Remover Veiculo------------2" << endl;
	cout << "Modificar Veiculo----------3" << endl;
	cout << "Listar Veiculos------------4" << endl;
	cout << "Sair ----------------------0" << endl;

	try {
		getline(cin, opcaoe);
		opcao = atoi(opcaoe.c_str());


		if(opcao < 0 || opcao > 4){
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção Invalida" << endl;
		pause();
	}


	switch (opcao) {

	case 1: {
		clear();

		int i;
		string ie;

		string marca, modelo, matricula, tipo;
		cout << "Tipo de veiculo " << endl;
		cout << "Carro---------------1" << endl;
		cout << "Camiao--------------2" << endl;
		cout << "Bus-----------------3" << endl;
		cout << "Sair----------------0" << endl;

		try {
			getline(cin, ie);
			i = atoi(ie.c_str());

			if(i < 0 || i > 3){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			break;

		}

		switch (i) {
		case 1: {  //Carro
			clear();
			cout << "Insira marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > SIZETEXTO) {
					CarMarcaExc cm;
					throw cm;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > SIZETEXTO) {
					CarModeloExc cmd;
					throw cmd;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira Matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 8) {
					CarMatrExc cmt;
					throw cmt;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}


			cout << "Insira categoria" << endl;
			getline(cin, tipo);
			try {
				if(tipo.size() > SIZETEXTO) {
					CarCategoriaExc cg;
					throw cg;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}


			Carro *c = new Carro(marca, modelo, matricula, tipo);
			veiculos.push_back(c);
			novoCarro(c);
			cout << "Carro adicionado com sucesso" << endl;
			pause();

		}
		break;
		case 2: { //Camiao
			clear();
			cout << "Insira marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > SIZETEXTO){
					CamiaoMarcaExc cm;
					throw cm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > SIZETEXTO){
					CamiaoModeloExc cmd;
					throw cmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira Matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 8){
					CamiaoMatrExc cmt;
					throw cmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira categoria" << endl;
			getline(cin, tipo);
			try {
				if(tipo.size() > SIZETEXTO){
					CamiaoCategoriaExc cg;
					throw cg;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			Camiao *c = new Camiao(marca, modelo, matricula, tipo);
			veiculos.push_back(c);
			novoCamiao(c);
			cout << "Camiao adicionado com sucesso" << endl;
			pause();

		}
		break;

		case 3: { //Bus

			clear();
			cout << "Insira marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > SIZETEXTO) {
					BusMarcaExc bm;
					throw bm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > SIZETEXTO) {
					BusModeloExc bmd;
					throw bmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << "Insira Matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 8) {
					BusMatrExc bmt;
					throw bmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			Bus *b = new Bus(marca, modelo, matricula);
			veiculos.push_back(b);
			novoBus(b);
			cout << "Bus adicionado com sucesso" << endl;
			pause();
		}
		break;

		}

	}
	break;

	case 2: {
		clear();
		int opcao, temp;
		string opcaoe, tempe;

		cout << "Insira tipo que deseja remover" << endl;
		cout << "Carro-------------------1" << endl;
		cout << "Camiao------------------2" << endl;
		cout << "Bus---------------------3" << endl;
		cout << "Sair--------------------0" << endl;

		try{
			getline(cin, opcaoe);
			opcao = atoi(opcaoe.c_str());

			if(opcao < 0 || opcao > 3){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc) {
			cout << "Opção Invalida" << endl;
			pause();
			menu();
			break;
			clear();
		}



		switch (opcao) {
		case 1: {
			clear();
			for (unsigned int i = 0; i < carros.size(); i++) {
				cout << i + 1 << "   " << carros[i]->getMarca() << endl;
			}
			cout << "Selecione o carro que deseja eliminar" << endl;
			try{

				getline(cin, tempe);
				temp = atoi(tempe.c_str());


				if(temp < 1 || temp > carros.size()){
					CarInvalido ci;
					throw ci;
				}
			}
			catch (VeicExc){
				cout << "Carro inexistente" << endl;
				pause();
				clear();
				break;
				menu();
			}

			removeCarro(temp - 1);
			cout << "Carro removido com sucesso" << endl;
			pause();
		}
		break;
		case 2: {
			clear();
			for (unsigned int i = 0; i < camioes.size(); i++) {
				cout << i + 1 << "   " << camioes[i]->getMarca() << endl;
			}
			cout << "Selecione o camiao que deseja eliminar" << endl;

			try{
				getline(cin, tempe);
				temp = atoi(tempe.c_str());

				if(temp < 1 || temp > camioes.size()){
					CamiaoInvalido ti;
					throw ti;
				}
			}
			catch (VeicExc){
				cout << "Camiao inexistente" << endl;
				pause();
				clear();
				break;
				menu();			
			}


			removeCamiao(temp - 1);
			cout << "Camiao removido com sucesso" << endl;
			pause();
		}
		break;

		case 3: {
			clear();
			for (unsigned int i = 0; i < buses.size(); i++) {
				cout << i + 1 << "   " << buses[i]->getMarca() << endl;
			}
			cout << "Selecione o bus que deseja eliminar" << endl;

			try{
				getline(cin, tempe);
				temp = atoi(tempe.c_str());

				if(temp < 1 || temp > buses.size()){
					BusInvalido bi;
					throw bi;
				}
			}
			catch (VeicExc){
				cout << "Bus inexistente" << endl;
				pause();
				clear();
				break;
				menu();			
			}


			removeBus(temp - 1);
			cout << "Bus removido com sucesso"<< endl;
			pause();
		}
		break;

		case 0: {

		}
		break;
		}
	}
	break;
	case 3: {
		modificaVeic();
	}
	break;
	case 4: { //listagem de veiculos
		clear();
		int op, car;
		string ope, care;

		cout << "O que deseja listar?" << endl;
		cout << "Carros----------------1" << endl;
		cout << "Camioes---------------2" << endl;
		cout << "Buses-----------------3" << endl;
		cout << "Todos-----------------4" << endl;
		cout << "Sair------------------0" << endl;

		try {
			getline(cin, ope);
			op = atoi(ope.c_str());

			if(op < 0 || op > 4){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção invalida" << endl;
			pause();
			clear();
			break;
			menu();
		}


		switch (op) {
		case 1: { // listar carros
			clear();
			for (unsigned int i = 0; i < carros.size(); i++) {
				cout << i + 1 << "  " << carros[i]->getMarca() << endl;
			}
			cout << "Que carro deseja analizar?" << endl;
			try {
				getline(cin, care);
				car = atoi(care.c_str());

				if(car < 1 || car > carros.size()) {
					CarInvalido ci;
					throw ci;
				}
			}
			catch (VeicExc){
				cout << "Carro inexistente" << endl;
				pause();
				clear();
				break;
				menu();
			}


			cout << *(carros[car - 1]) << endl;
			listaVeiculosServicos(carros[car - 1]);
			pause();

		}
		break;
		case 2: { //listar camioes
			clear();
			for (unsigned int i = 0; i < camioes.size(); i++) {
				cout << i + 1 << "  " << camioes[i]->getMarca() << endl;
			}
			cout << "Que camiao deseja analizar?" << endl;

			try {
				getline(cin, care);
				car = atoi(care.c_str());

				if(car < 1 || car > camioes.size()) {
					CamiaoInvalido ti;
					throw ti;
				}
			}
			catch (VeicExc){
				cout << "Camião inexistente" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << *(camioes[car - 1]) << endl;
			listaVeiculosServicos(camioes[car - 1]);
			pause();

		}
		break;
		case 3: { // listar buses

			clear();
			for (unsigned int i = 0; i < buses.size(); i++) {
				cout << i + 1 << "  " << buses[i]->getMarca() << endl;
			}
			cout << "Que bus deseja analizar?" << endl;

			try {
				getline(cin, care);
				car = atoi(care.c_str());

				if(car < 1 || car > buses.size()) {
					BusInvalido bi;
					throw bi;
				}
			}
			catch (VeicExc){
				cout << "Bus inexistente" << endl;
				pause();
				clear();
				break;
				menu();
			}

			cout << *(buses[car - 1]) << endl;
			listaVeiculosServicos(buses[car - 1]);
			pause();

		}
		break;

		case 4: { //listar todos
			clear();
			for (unsigned int i = 0; i < veiculos.size(); i++) {
				cout << i + 1 << "  " << veiculos[i]->getMarca() << endl;
			}
			cout << "Que veiculo deseja analizar?" << endl;

			try {
				getline(cin, care);
				car = atoi(care.c_str());

				if(car < 1 || car > veiculos.size()){
					VeicInvalido vi;
					throw vi;
				}
			}
			catch (VeicExc){
				cout << "Veiculo inexistente" << endl;
				pause();
				clear();
				break;
				menu();
			}


			cout << *(veiculos[car - 1]) << endl;
			pause();
		}
		break;
		case 0: {

		}
		break;

		}

	}
	break;

	}

}

//Case 3 do Menu Veiculos
void Empresa::modificaVeic() {
	clear();
	string marca, modelo, matricula, categoria;
	int indice;
	string indicee;
	cout << "Que tipo de veiculo deseja alterar?" << endl;
	cout << "Carro-----------------------------1" << endl;
	cout << "Camiao----------------------------2" << endl;
	cout << "Bus-------------------------------3" << endl;
	cout << "Sair------------------------------0" << endl;

	try {
		getline(cin, indicee);
		indice = atoi(indicee.c_str());

		if(indice < 0 || indice > 3){
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção invalida" << endl;
		pause();
		clear();
		menu();
	}



	switch (indice) {
	case 1: {
		clear();
		int op, nCarro;
		string ope, nCarroe;

		for (unsigned int i = 0; i < carros.size(); i++) {
			cout << i + 1 << "   " << carros[i]->getMarca() << endl;
		}
		cout << "Insira carro que deseja alterar" << endl;
		try {
			getline(cin, nCarroe);
			nCarro = atoi(nCarroe.c_str());

			if(nCarro < 1 || nCarro > carros.size()) {
				CarInvalido ci;
				throw ci;
			}
		}
		catch (VeicExc) {
			cout << "Carro inexistente" << endl;
			pause();
			clear();
			break;
		}


		cout << "Que atributo deseja alterar?" << endl;
		cout << "Marca------------------------1" << endl;
		cout << "Modelo-----------------------2" << endl;
		cout << "Matricula--------------------3" << endl;
		cout << "Categoria--------------------4" << endl;
		cout << "Sair-------------------------0" << endl;

		try {
			getline(cin, ope);
			op = atoi(ope.c_str());

			if(op < 0 || op > 4){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção invalida" << endl;
			pause();
			clear();
			break;
		}


		clear();

		switch (op) {
		case 1: {
			cout << "Insira nova marca" << endl;
			getline(cin, marca);
			try{
				if(marca.size() > SIZETEXTO) {
					CarMarcaExc cm;
					throw cm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
			}

			carros[nCarro - 1]->setMarca(marca);
			cout << "Marca de Carro alterada com sucesso" << endl;
		}
		break;
		case 2: {
			cout << "Insira novo modelo" << endl;
			getline(cin, modelo);
			try{
				if(modelo.size() > SIZETEXTO) {
					CarMarcaExc cmd;
					throw cmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			carros[nCarro - 1]->setMarca(modelo);
			cout << "Modelo de Carro alterado com sucesso" << endl;
		}
		break;
		case 3: {
			cout << "Insira nova matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try{
				if(matricula.size() > 8) {
					CarMatrExc cmt;
					throw cmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			carros[nCarro - 1]->setMatricula(matricula);
			cout << "Matricula de Carro alterada com sucesso" << endl;
		}
		break;
		case 4: {
			cout << "Insira novo tipo" << endl;
			string tipo;
			getline(cin, tipo);
			try{
				if(tipo.size() > SIZETEXTO) {
					CarCategoriaExc cg;
					throw cg;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			carros[nCarro - 1]->setTipo(tipo);
			cout << "Tipo de Carro alterado com sucesso" << endl;
		}
		break;
		case 0: {

		}
		break;
		}
		pause();
	}
	break;
	case 2: { /*modificar camioes*/

		int op, nCarro;
		string ope, nCarroe;

		for (unsigned int i = 0; i < camioes.size(); i++) {
			cout << i + 1 << "   " << camioes[i]->getMarca() << endl;
		}
		cout << "Insira camiao que deseja alterar" << endl;

		try {
			getline(cin, nCarroe);
			nCarro = atoi(nCarroe.c_str());

			if(nCarro < 1 || nCarro > camioes.size()) {
				CamiaoInvalido ti;
				throw ti;
			}
		}
		catch (VeicExc) {
			cout << "Camiao inexistente" << endl;
			pause();
			clear();
			break;
			menu();
		}


		cout << "Que atributo deseja alterar?" << endl;
		cout << "Marca------------------------1" << endl;
		cout << "Modelo-----------------------2" << endl;
		cout << "Matricula--------------------3" << endl;
		cout << "Categoria--------------------4" << endl;
		cout << "Sair-------------------------0" << endl;

		try {
			getline(cin, ope);
			op = atoi(ope.c_str());

			if(op < 0 || op > 4) {
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc) {
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			break;
			menu();
		}


		clear();
		switch (op) {
		case 1: {
			cout << "Insira nova marca" << endl;
			getline(cin, marca);
			try{
				if(marca.size() > SIZETEXTO){
					CamiaoMarcaExc cm;
					throw cm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			camioes[nCarro - 1]->setMarca(marca);
			cout << "Marca de Camiao alterada com sucesso" << endl;

		}
		break;
		case 2: {
			cout << "Insira novo modelo" << endl;
			getline(cin, modelo);
			try{
				if(modelo.size() > SIZETEXTO){
					CamiaoModeloExc cmd;
					throw cmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			camioes[nCarro - 1]->setMarca(modelo);
			cout << "Modelo de Camiao alterado com sucesso" << endl;
		}
		break;
		case 3: {
			cout << "Insira nova matricula(XX-XX-XX)" << endl;
			getline(cin, matricula);
			try{
				if(matricula.size() > 8){
					CamiaoMatrExc cmt;
					throw cmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			camioes[nCarro - 1]->setMatricula(matricula);
			cout << "Matricula de Camiao alterada com sucesso" << endl;
		}
		break;
		case 4: {
			cout << "Insira nova categoria" << endl;
			getline(cin, categoria);
			try{
				if(categoria.size() > SIZETEXTO){
					CamiaoCategoriaExc cg;
					throw cg;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			camioes[nCarro - 1]->setCategoria(categoria);
			cout << "Categoria de Camiao alterada com sucesso" << endl;
		}
		break;
		case 0: {

		}
		break;
		}
		pause();
	}
	break;

	case 3: { /*Modifica bus  */
		clear();
		int opcao, nBus;
		string opcaoe, nBuse;

		for (unsigned int i = 0; i < buses.size(); i++) {
			cout << i + 1 << "   " << buses[i]->getMarca() << endl;
		}
		cout << "Selecione qual o bus que deseja modificar" << endl;
		try {
			getline(cin, nBuse);
			nBus = atoi(nBuse.c_str());

			if(nBus < 1 || nBus > buses.size()) {
				BusInvalido bi;
				throw bi;
			}
		}
		catch (VeicExc) {
			cout << "Bus inexistente" << endl;
			pause();
			clear();
			break;
			menu();
		}


		clear();
		cout << "Que atributo deseja alterar?" << endl;
		cout << "Marca------------------------1" << endl;
		cout << "Modelo-----------------------2" << endl;
		cout << "Matricula--------------------3" << endl;
		cout << "Sair-------------------------0" << endl;

		try {
			getline(cin, opcaoe);
			opcao = atoi(opcaoe.c_str());

			if(opcao < 0 || opcao > 3){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			break;
			menu();
		}


		clear();

		switch (opcao) {
		case 1: {
			cout << "Insira nova marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > SIZETEXTO) {
					BusMarcaExc bm;
					throw bm;
				}
			}
			catch (VeicExc){
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			buses[nBus - 1]->setMarca(marca);
			cout << "Marca de Bus alterada com sucesso" << endl;
		}
		break;
		case 2: {
			cout << "Insira novo modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > SIZETEXTO) {
					BusModeloExc bmt;
					throw bmt;
				}
			}
			catch (VeicExc){
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			buses[nBus - 1]->setMarca(modelo);
			cout << "Modelo de Bus alterado com sucesso" << endl;
		}
		break;
		case 3: {
			cout << "Insira nova matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 8) {
					BusMatrExc bmp;
					throw bmp;
				}
			}
			catch (VeicExc){
				cout << "String overflow" << endl;
				pause();
				clear();
				break;
				menu();
			}

			buses[nBus - 1]->setMatricula(matricula);
			cout << "Matricula de Bus alterada com sucesso" << endl;
			pause();
		}
		break;
		case 0: {

		}
		break;

		}
		pause();
		break;

	}
	break;
	}
}

void Empresa::modificaServ() {
	clear();
	int escolha, opS;
	string escolhae, opSe;

	for (unsigned int i = 0; i < standards.size(); i++) {
		cout << i + 1 << "  " << standards[i]->getNome() << endl;
	}
	string nome, descricao, dataI, dataF, precoe, duracaoe;
	double preco, duracao;

	cout << "Qual dos servicos deseja alterar?" << endl;
	try {
		getline(cin, escolhae);
		escolha = atoi(escolhae.c_str());

		if(escolha < 1 || escolha > standards.size()) {
			ServInvalido si;
			throw si;
		}
	}
	catch (ServicosExc) {
		cout << "Servico Inixestente" << endl;
		pause();
		clear();
		//break;
		menu();
	}


	cout << "Que atributo deseja alterar?" << endl;
	cout << "Data de inicio---------------------1" << endl;
	cout << "Data de fim------------------------2" << endl;
	cout << "Nome-------------------------------3" << endl;
	cout << "Descricao--------------------------4" << endl;
	cout << "Preco por hora---------------------5" << endl;
	cout << "Duracao----------------------------6" << endl;
	cout << "Sair-------------------------------0" << endl;

	try {
		getline(cin, opSe);
		opS = atoi(opSe.c_str());

		if(opS < 0 || opS > 6) {
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção invalida" << endl;
		pause();
		clear();
		//break;
		menu();
	}


	clear();
	switch (opS) {

	case 1: {
		cout << "Insira nova Data de inicio " << endl;
		getline(cin, dataI);
		try {
			if(dataI.size() > SIZETEXTO) {
				DataIniExc di;
				throw di;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			break;
		}

		standards[escolha - 1]->setDataInicio(dataI);
		cout << "Servico alterado com sucesso " << endl;
	}
	break;

	case 2: {
		cout << "Insira nova Data de fim " << endl;
		getline(cin, dataF);
		try {
			if(dataF.size() > SIZETEXTO) {
				DataFimExc df;
				throw df;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			break;
			menu();
		}

		standards[escolha - 1]->setDataFim(dataF);
		cout << "Servico alterado com sucesso " << endl;

	}
	break;

	case 3: {
		cout << "Insira novo Nome " << endl;
		getline(cin, nome);
		try {
			if(nome.size() > SIZETEXTO) {
				NomServExc ns;
				throw ns;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			break;
			menu();
		}

		standards[escolha - 1]->setNome(nome);
		cout << "Servico alterado com sucesso " << endl;

	}
	break;

	case 4: {
		cout << "Insira nova Descricao " << endl;
		getline(cin, descricao);
		try {
			if(descricao.size() > SIZETEXTO) {
				DescServExc ds;
				throw ds;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			break;
			menu();
		}

		standards[escolha - 1]->setDescricao(descricao);
		cout << "Servico alterado com sucesso " << endl;

	}
	break;

	case SIZETEXTO: {
		cout << "Insira novo Preco " << endl;
		getline(cin, precoe);
		try {
			if(dataI.size() > SIZETEXTO) {
				PrecoServExc ps;
				throw ps;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			break;

		}


		try {
			preco = atof(precoe.c_str());
			if(preco <= 0) {
				PrecoServExc pc;
				throw pc;
			}
		}
		catch (PrecoServExc) {
			cout << "Preço Invalido" << endl;
			pause();
			clear();
			break;

		}

		standards[escolha - 1]->setPreco(preco);
		cout << "Servico alterado com sucesso " << endl;

	}
	break;

	case 6: {
		cout << "Insira nova Duracao (Em horas) " << endl;
		getline(cin, duracaoe);
		try {
			if(duracaoe.size() > SIZETEXTO) {
				DuracaoServExc dse;
				throw dse;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			break;

		}


		try {
			duracao = atof(duracaoe.c_str());
			if(duracao <= 0) {
				DuracaoServExc dr;
				throw dr;
			}
		}
		catch (ServicosExc) {
			cout << "Duração Invalida" << endl;
		}
		cout << "Servico alterado com sucesso " << endl;

		standards[escolha - 1]->setDuracao(duracao);
	}
	break;

	case 0: {

	}
	break;
	} //fecha primeiro switch

}

void Empresa::listaVeiculosServicos(Veiculo *v) {
	int opcao;
	string opcaoe;

	cout << "Deseja listar os servicos associados a este veiculo?" << endl;
	cout << "Sim-------------------1" << endl;
	cout << "Nao-------------------2" << endl;

	try {
		getline(cin, opcaoe);
		opcao = atoi(opcaoe.c_str());

		if(opcao < 1 || opcao > 2) {
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção Invalida" << endl;
		pause();
		clear();
		//	break;
		menu();
	}

	if (opcao == 1) {
		for (unsigned int i = 0; i < v->getStandards().size(); i++) {
			cout << *(v->getStandards()[i]) << endl;
		}

	}
}



void Empresa :: removeVeiculoFuncionario(){
	int opcao, opcao2;
	string opcaoe, opcao2e;

	cout << "Qual o Funcionario? " << endl;
	for(unsigned int i=0; i<funcionarios.size(); i++){
		cout << i+1 << "  " << funcionarios[i]->getNome() << endl;
	}

	try {
		getline(cin, opcaoe);
		opcao = atoi(opcaoe.c_str());

		if(opcao < 1 || opcao > funcionarios.size()){
			FuncionarioInvalido fi;
			throw fi;
		}
	}
	catch (FuncionarioOFB){
		cout << "Funcionario inexistente" << endl;
		pause();
		clear();
		menu();
	}


	cout << "Qual o veiculo que quer remover? " << endl;

	for (unsigned int i = 0; i < veiculos.size(); i++) {
		cout << i + 1 << "   " << veiculos[i]->getMarca() << endl;
	}

	try {
		getline(cin, opcao2e);
		opcao2 = atoi(opcao2e.c_str());

		if(opcao2 < 1 || opcao2 > veiculos.size()) {
			VeicInvalido vi;
			throw vi;
		}
	}
	catch (VeicExc) {
		cout << "Veiculo inexistente" << endl;
		pause();
		clear();
		menu();
	}

	if(opcao >=1 && opcao <=funcionarios.size()){
		if(opcao2>=1 && opcao2<=veiculos.size()){

			funcionarios[opcao-1]->removeVeiculo(opcao2-1);
			cout << "Veiculo removido com sucesso" << endl;
		}}

}





void Empresa::adicionaVeiculoFuncionario() {
	int opcao, opcao2;
	string opcaoe, opcao2e;

	cout << "Qual o Funcionario?" << endl;
	for (unsigned int i = 0; i < funcionarios.size(); i++) {
		cout << i + 1 << "   " << funcionarios[i]->getNome() << endl;
	}
	try {
		getline(cin, opcaoe);
		opcao = atoi(opcaoe.c_str());

		if(opcao < 1 || opcao > funcionarios.size()){
			FuncionarioInvalido fi;
			throw fi;
		}
	}
	catch (FuncionarioOFB){
		cout << "Funcionario inexistente" << endl;
		pause();
		clear();
		menu();
	}

	cout << "Qual o veiculo que quer adicionar? " << endl;
	for (unsigned int i = 0; i < veiculos.size(); i++) {
		cout << i + 1 << "   " << veiculos[i]->getMarca() << endl;
	}
	try {
		getline(cin, opcao2e);
		opcao2 = atoi(opcao2e.c_str());

		if(opcao2 < 1 || opcao2 > veiculos.size()) {
			VeicInvalido vi;
			throw vi;
		}
	}
	catch (VeicExc) {
		cout << "Veiculo inexistente" << endl;
		pause();
		clear();
		//	break;
		menu();
	}

	funcionarios[opcao - 1]->adicionaVeiculo(veiculos[opcao2 - 1]);
	cout << "Veiculo adicionado com sucesso" << endl;
	pause();
}


void Empresa::removeServicoVeiculo(){
	int opcao, opcao2;
	string opcaoe, opcao2e;

	cout << "Qual o Veiculo? " << endl;
	for(unsigned int i=0; i<veiculos.size(); i++){
		cout << i+1 << "  " << veiculos[i]->getMarca() << endl;
	}

	try {
		getline(cin, opcaoe);
		opcao = atoi(opcaoe.c_str());

		if(opcao < 1 || opcao > veiculos.size()){
			VeicInvalido fi;
			throw fi;
		}
	}
	catch (VeicExc){
		cout << "Veiculo inexistente" << endl;
		pause();
		clear();
		menu();
	}


	cout << "Qual o Servico que quer remover? " << endl;

	for (unsigned int i = 0; i < veiculos[opcao-1]->getStandards().size(); i++) {
		cout << i + 1 << "   " << veiculos[opcao-1]->getStandards()[i]->getNome()<< endl;
	}
	try {
		getline(cin, opcao2e);
		opcao2 = atoi(opcao2e.c_str());

		if(opcao2 < 1 || opcao2 > veiculos[opcao-1]->getStandards().size()) {
			ServInvalido vi;
			throw vi;
		}
	}
	catch (ServicosExc) {
		cout << "Servico inexistente" << endl;
		pause();
		clear();
		menu();
	}


	veiculos[opcao-1]->removeStandard(opcao2-1);
	cout << "Servico removido com sucesso" << endl;

}


void Empresa::addEmpresaAluguer(EmpresaAluguer * emp) {

	empresas_aluguer.push_front(emp);
	empresas_aluguer.sort(compare);
}

list<EmpresaAluguer *> & Empresa::getEmpresasAluguer() {
	return empresas_aluguer;
}

list<EmpresaAluguer *> & Empresa::removerEmpresaAluguer(string nome) {
	list<EmpresaAluguer *>::iterator it;

	for(it = empresas_aluguer.begin(); it != empresas_aluguer.end(); it++){
		if((*it)->getNome() == nome) {
			cout << "entrei" << endl;
			empresas_aluguer.erase(it);
			cout << "apaguei" << endl;
			break;
		}
	}

	empresas_aluguer.sort(compare);
	return empresas_aluguer;
}


void Empresa::clienteRequisitaViatura(Cliente * c) {
	pair<map<Cliente*,Veiculo*>::iterator,bool> it;

	//Obter primeiro veiculo da empresa com mais veiculos disponiveis
	Veiculo * v = empresas_aluguer.front()->getVeiculos()[0];

	//associar ao cliente
	it = alugueres.insert(pair<Cliente*,Veiculo*> (c,v));
	if(it.second == false) {
		cout << "Cliente: " << c->getNome() << " " << "ja requisitou um veiculo" << endl;
	}
	else {
		//Remover do vector veiculos da empresa de aluguer o primeiro veiculo
		empresas_aluguer.front()->removeVeiculo(0);
		empresas_aluguer.sort(compare);
	}

}

void Empresa::printClienteViaturaAlugada() {
	map<Cliente*,Veiculo*>::const_iterator it;

	for(it = alugueres.begin(); it != alugueres.end(); it++) {
		cout << "Nome do cliente: " << it->first->getNome() << endl;
		cout << "Veiculo alugado: " << it->second->getMarca() << endl << endl;
	}

}









