#pragma once
#include "Arquivo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class ArquivoPaciente : public Arquivo
{
private:
	//Atributos espec�ficos da classe
	string stNome;
	int itIdade;
	char chSexo;
	//Strcut auxiliar na exclus�o, edi��o e inser��o
	struct strPacientes {
		string stNome;
		int itIdade;
		string stSexo;
	};
public:
	//Construtores
	ArquivoPaciente(string stNomeArquivo);
	~ArquivoPaciente();
	//M�todos getters e setters
	string GetNome();
	int GetIdade();
	char GetSexo();
	void SetNome(string Nome);
	void SetIdade(int Idade);
	void SetSexo(char Sexo);
	//Fun��es sobrescritas
	void Excluir() override;
	void Editar() override;
	void Pesquisar() override;
	void MontarLinha() override;	
	void ListarTodos() override;
	//Fun��o auxiliar
	void PreencherVectorPacientes(vector<strPacientes>& vcPcnt);
};

