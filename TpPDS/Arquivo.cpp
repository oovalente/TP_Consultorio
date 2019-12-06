#include "Arquivo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Execoes.h"

using namespace std;
//Carrega o arquivo texto
void Arquivo::CarregarArquivo(string _Nome, string _Tipo) {
	this->SetNomeArquivo(stNomeArquivo);
	_Tipo = "r";
	fopen_s(&this->Arq, this->GetNomeArquivo().c_str(), _Tipo.c_str());
	if (this->Arq == NULL) {
		_Tipo = "w";
		fopen_s(&this->Arq, this->GetNomeArquivo().c_str(), _Tipo.c_str());
		if (this->Arq == NULL) {
			cout << "Erro ao abrir o arquivo.";
			exit(0);
		}
	}
}
//Construtor
Arquivo::Arquivo(string stNomeArquivo)
{
	this->SetNomeArquivo(stNomeArquivo);
}
//Destrutor
Arquivo::~Arquivo()
{
	if (this->Arq != NULL) {
		fclose(this->Arq);
	}	
}
//Método que insere uma linha
void Arquivo::Cadastrar() throw (Ex_LinhaVazia){
	this->MontarLinha();
	if (this->GetLinha() == "") {
		throw Ex_LinhaVazia();
	}
	this->CarregarArquivo(this->GetNomeArquivo().c_str(), "");
	fprintf_s(this->Arq, this->GetLinha().c_str());
	fclose(this->Arq);
}
//Método que lista todas as linhas do arquivo
void Arquivo::ListarTodos() {
	
}
//Método que exclui uma linha
void Arquivo::Excluir() throw (Ex_LinhaNaoEncontrada) {

}
//Método que edita uma linha
void Arquivo::Editar() throw (Ex_LinhaNaoEncontrada) {

}
//Método que retorna uma linha a partir de um atributo setado
int Arquivo::Pesquisar() {
	return -1;
}
//Método que monta a estrutura de gravação no arquivo
void Arquivo::MontarLinha() {
	
}


void Arquivo::SetNomeArquivo(string stNome) {
	this->stNomeArquivo = stNome;
}

string Arquivo::GetNomeArquivo() {
	return this->stNomeArquivo;
}

void Arquivo::SetLinha(string stLinha) {
	this->stLinha = stLinha;
}

string Arquivo::GetLinha() {
	return this->stLinha;
}