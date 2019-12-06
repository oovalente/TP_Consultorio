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

class ArquivoConsulta : public Arquivo
{
private:
	//Atributos espec�ficos da classe
	string stData;
	string stNomePaciente;
	string stModalidade;
	string stDescricao;
	string stExameMarcado;

	//Strcut auxiliar na exclus�o, edi��o e inser��o
	struct strConsulta {
		string stData;
		string stNomePaciente;
		string stModalidade;
		string stDescricao;
		string stExameMarcado;
	};
public:
	//Construtor
	ArquivoConsulta(string stNomeArquivo);
	//Destrutor
	~ArquivoConsulta();
	string GetData();
	string GetNomePaciente();
	string GetModalidade();
	string GetDescricao();
	string GetExameMarcado();
	void SetData(string _Data);
	void SetNomePaciente(string _NomePaciente);
	void SetModalidade(string _Modalidade);
	void SetDescricao(string _Descricao);
	void SetExameMarcado(string _ExameMarcado);

	//Fun��es sobrescritas por que devem ser configuradas de forma espec�fica para o tipo de arquivo
	void Excluir() throw (Ex_LinhaNaoEncontrada)override;
	void Editar() throw (Ex_LinhaNaoEncontrada)override;
	int Pesquisar() override;
	void MontarLinha() override;
	void ListarTodos() override;
	//M�todo que preenche um vetor com os dados dos pacientes 
	void PreencherVectorConsultas(vector<strConsulta>& vcPcnt, bool blSpace);
};

