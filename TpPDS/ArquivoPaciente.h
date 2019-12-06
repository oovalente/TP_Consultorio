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

class ArquivoPaciente : public Arquivo
{
private:
	//Atributos específicos da classe
	string stNome;
	int itIdade;
	char chSexo;
	//Strcut auxiliar na exclusão, edição e inserção
	struct strPacientes {
		string stNome;
		int itIdade;
		string stSexo;
	};
public:
	//Construtor
	ArquivoPaciente(string stNomeArquivo);
	//Destrutor
	~ArquivoPaciente();
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
	//Funções sobrescritas por que devem ser configuradas de forma específica para o tipo de arquivo
	void Excluir() throw (Ex_LinhaNaoEncontrada) override;
	void Editar() throw (Ex_LinhaNaoEncontrada)override;
	int Pesquisar() override;
	void MontarLinha() override;	
	void ListarTodos() override;
	//Método que preenche um vetor com os dados dos pacientes 
	void PreencherVectorPacientes(vector<strPacientes>& vcPcnt, bool blSpace);
};

