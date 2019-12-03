#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Arquivo
{
	public:
		//Construtores e destrutores
		Arquivo(string stNomeArquivo);
		~Arquivo();
		//Métodos implementados na herança
		virtual void MontarLinha();
		virtual void Excluir();
		virtual void Editar();
		virtual void Pesquisar();
		virtual void ListarTodos();
		//Métodos constantes para as outras classes
		void Cadastrar();
		//Atributos da classe
		virtual string GetNomeArquivo();
		virtual void SetNomeArquivo(string stNome);
		string GetLinha();
		void SetLinha(string stLinha);
	private:
		//Nome do arquivo
		string stNomeArquivo;
		//Linha do arquivo
		string stLinha;
	protected:
		//Arquvio que armazena os dados
		FILE *Arq;
};

