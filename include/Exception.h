#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Excepções Ficheiros
class FailLerClientes {};
class FailEscreverClientes {};
class FicheiroVazio {};
class FileClose {};
//Excepções menu Funcionario
class FuncionarioOFB {};
class fNomeOFB: public FuncionarioOFB{};
class fContactoOFB: public FuncionarioOFB{};
class fMoradaOFB: public FuncionarioOFB{};
class fTipoOFB: public FuncionarioOFB{};
class fSalarioOFB: public FuncionarioOFB{};
class fSalarioSize: public FuncionarioOFB{};
class FuncionarioInvalido: public FuncionarioOFB{};
class fHorasExtraOFB: public FuncionarioOFB{};
class fHorasExtraSize: public FuncionarioOFB{};
class fEspecOFB: public FuncionarioOFB{};
//Excepções menu Cliente
class ClienteOFB {};
class cNomeOFB: public ClienteOFB {};
class cMoradaOFB: public ClienteOFB {};
class cContactoOFB: public ClienteOFB {};
class ClienteInvalido: public ClienteOFB {};
//Excepções menu Serviços
class ServicosExc{};
class DataIniExc: public ServicosExc {};
class DataFimExc: public ServicosExc {};
class NomServExc: public ServicosExc {};
class DescServExc: public ServicosExc {};
class PrecoServExc: public ServicosExc {};
class DuracaoServExc: public ServicosExc {};
class ServInvalido: public ServicosExc {};
//Excepções Opcões
class OpcoesExc {};
class OFBOpcoes: public OpcoesExc {}; //Opcao out of bounds
//Excepções Veiculos
class VeicExc {};
class VeicInvalido: public VeicExc {};
//Carros
class CarMarcaExc: public VeicExc {};
class CarModeloExc: public VeicExc {};
class CarMatrExc: public VeicExc {};
class CarCategoriaExc: public VeicExc {};
class CarInvalido: public VeicExc {};
//Camiões
class CamiaoMarcaExc: public VeicExc {};
class CamiaoModeloExc: public VeicExc {};
class CamiaoMatrExc: public VeicExc {};
class CamiaoCategoriaExc: public VeicExc {};
class CamiaoInvalido: public VeicExc {};
//Bus
class BusMarcaExc: public VeicExc {};
class BusModeloExc: public VeicExc {};
class BusMatrExc: public VeicExc {};
class BusInvalido: public VeicExc {};

#endif /* EXCEPTION_H_ */
