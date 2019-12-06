#pragma once
#include "Arquivo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include "Execoes.h"
using namespace std;

class ArquivoExame : public Arquivo
{
private:
	//Atributos espec�ficos da classe
	string stData;
	string stNomePaciente;
	string stTipoExame;
	string stLaudo;
	string stApresentaRiscoIminente;

	//Strcut auxiliar na exclus�o, edi��o e inser��o
	struct strExame {
		string stData;
		string stNomePaciente;
		string stTipoExame;
		string stLaudo;
		string stApresentaRiscoIminente;
	};
public:
	//Construtor
	ArquivoExame(string stNomeArquivo);
	//Destrutor
	~ArquivoExame();

	string GetData();
	string GetNomePaciente();
	string GetTipoExame();
	string GetLaudo();
	string GetApresentaRiscoIminente();

	void SetData(string _Data);
	void SetNomePaciente(string _NomePaciente);
	void SetTipoExame(string _TipoExame);
	void SetLaudo(string _Laudo);
	void SetApresentaRiscoIminente(string _ApresentaRiscoIminente);

	//Fun��es sobrescritas por que devem ser configuradas de forma espec�fica para o tipo de arquivo
	void Excluir() throw (Ex_LinhaNaoEncontrada)override;
	void Editar() throw (Ex_LinhaNaoEncontrada)override;
	int Pesquisar() override;
	void MontarLinha() override;
	void ListarTodos() override;
	//M�todo que preenche um vetor com os dados dos pacientes 
	void PreencherVectorExames(vector<strExame>& vcPcnt, bool blSpace);
};