#include "Arquivo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Execoes.h"

using namespace std;

Arquivo::Arquivo(string stNomeArquivo)
{
	this->SetNomeArquivo(stNomeArquivo);
	string aux = this->GetNomeArquivo();
	Arq = fopen(aux.c_str(), "rt");
	if (Arq == NULL) {
		Arq = fopen(aux.c_str(), "wt");
		if (Arq == NULL) {
			cout << "Erro ao abrir o arquivo.";
			exit(0);
		}
	}
}

Arquivo::~Arquivo()
{
	fclose(Arq);
}

void Arquivo::Cadastrar() throw (Ex_ErroInserir){
	this->MontarLinha();
	string stAux;
	//Arq << this->GetLinha() << '\n';
	fprintf(this->Arq,this->GetLinha().c_str());
}

void Arquivo::ListarTodos() {
	
}

void Arquivo::Excluir() throw (Ex_LinhaNaoEncontrada) {

}

void Arquivo::Editar() throw (Ex_LinhaNaoEncontrada) {

}

void Arquivo::Pesquisar() throw (Ex_LinhaNaoEncontrada) {

}

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