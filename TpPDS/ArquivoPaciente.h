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
	//Construtores
	ArquivoPaciente(string stNomeArquivo);
	~ArquivoPaciente();
	//Métodos getters e setters
	string GetNome();
	int GetIdade();
	char GetSexo();
	void SetNome(string Nome);
	void SetIdade(int Idade);
	void SetSexo(char Sexo);
	//Funções sobrescritas
	void Excluir() override;
	void Editar() override;
	void Pesquisar() override;
	void MontarLinha() override;	
	void ListarTodos() override;
	//Função auxiliar
	void PreencherVectorPacientes(vector<strPacientes>& vcPcnt);
};

