#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Execoes.h"
using namespace std;

class Arquivo
{
	public:
		//Construtores e destrutores
		Arquivo(string stNomeArquivo);
		~Arquivo();
		//Monta o formato de uma linha do arquivo
		virtual void MontarLinha();
		//Deleta linha no arquivo
		virtual void Excluir() throw (Ex_LinhaNaoEncontrada);
		//Edita linha no arquivo
		virtual void Editar() throw (Ex_LinhaNaoEncontrada);
		//Pesquisa uma linha no arquivo
		virtual int Pesquisar();
		//Lista todas as linhas do arquivo
		virtual void ListarTodos();
		//Insere uma nova linha no arquivo
		void Cadastrar() throw (Ex_LinhaVazia);
		//Retorna o nome do arquivo txt a ser utilizado
		virtual string GetNomeArquivo();
		//Insere o nome do arquivo txt a ser utilizado
		virtual void SetNomeArquivo(string stNome);
		//Retorna a linha que será inserida/alterada
		string GetLinha();
		//Seta a linha que será inserida/alterada
		void SetLinha(string stLinha);
	private:
		//Nome do arquivo
		string stNomeArquivo;
		//Linha do arquivo
		string stLinha;		
	protected:
		//Arquvio que armazena os dados
		FILE *Arq;
		//Carrega o arquivo txt
		void CarregarArquivo(string _Nome, string _Tipo);
};

