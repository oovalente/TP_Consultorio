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

	//Strcut auxiliar na exclus�o, edi��o e inser��o
	struct strConsulta {
		string stNome;
		int itIdade;
		string stSexo;
	};
public:
	//Construtor
	ArquivoConsulta(string stNomeArquivo);
	//Destrutor
	~ArquivoConsulta();
	//Retorna o nome do paciente
	string GetNome();
	//Retorna a idade do paciente
	int GetIdade();
	//Retorna o sexo do paciente
	char GetSexo();
	//Informa o nome do paciente
	void SetNome(string Nome);
	//Informa a idade do paciente
	void SetIdade(int Idade);
	//Informa o sexo do paciente
	void SetSexo(char Sexo);
	//Fun��es sobrescritas por que devem ser configuradas de forma espec�fica para o tipo de arquivo
	void Excluir() throw (Ex_LinhaNaoEncontrada)override;
	void Editar() throw (Ex_LinhaNaoEncontrada)override;
	int Pesquisar() override;
	void MontarLinha() override;
	void ListarTodos() override;
	//M�todo que preenche um vetor com os dados dos pacientes 
	void PreencherVectorPacientes(vector<strPacientes>& vcPcnt, bool blSpace);
};

