#pragma warning(disable : 4996)
#include "ArquivoPaciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include "Execoes.h"
const int itPNome = 31;
const int itPIdade = 6;
const int itPSexo = 5;
const string stNomeArquivoAux = "ArquivoPacientes.txt";
using namespace std;

ArquivoPaciente::~ArquivoPaciente() {
	fclose(Arq);
}

ArquivoPaciente::ArquivoPaciente(string stNomeArquivo = stNomeArquivoAux) : Arquivo(stNomeArquivo = stNomeArquivoAux) {

}


string ArquivoPaciente::GetNome() {
	return this->stNome;
}

int ArquivoPaciente::GetIdade() {
	return this->itIdade;
}

char ArquivoPaciente::GetSexo() {
	return this->chSexo;
}

void ArquivoPaciente::SetNome(string Nome) {
	this->stNome = Nome;
}

void ArquivoPaciente::SetIdade(int Idade) {
	this->itIdade = Idade;
}

void ArquivoPaciente::SetSexo(char Sexo) {
	this->chSexo = Sexo;
}

void ArquivoPaciente::MontarLinha() {
	//Aqui se monta a linha de acordo com a estrutura esperada no arquivo
	string aux(1, this->GetSexo());
	//Nome;Idade;Sexo;
	string stLinhaAux = this->GetNome() + ";" + to_string(this->GetIdade()) + ";" + aux + ";"+'\n';
	this->SetLinha(stLinhaAux);
}

void ArquivoPaciente::PreencherVectorPacientes(vector<strPacientes>& vcPcnt, bool blSpace) {
	strPacientes pc1;
	char chLinhaAux[300];
	string stCampo;
	this->CarregarArquivo(stNomeArquivoAux, "");

	while (fgets(chLinhaAux, 300, this->Arq) != NULL) {
		string stLinha(chLinhaAux);
		//cout << stLinha;
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPNome, ' ');
		pc1.stNome = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPIdade, ' ');
		pc1.itIdade = stoi(stCampo);

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPSexo, ' ');
		pc1.stSexo = stCampo;

		vcPcnt.push_back(pc1);
	}
	fclose(this->Arq);
}

void ArquivoPaciente::Excluir() throw (Ex_LinhaNaoEncontrada) {
	vector<strPacientes> vcPcnt;
	this->PreencherVectorPacientes(vcPcnt, false);
	int j = 0;
	bool blEncontrou = false;
	for (strPacientes i : vcPcnt) {
		if (i.stNome == this->GetNome()) {
			vcPcnt.erase(vcPcnt.begin() + j);
			blEncontrou = true;
		}
		j++;
	}

	if (!blEncontrou) {
		throw Ex_LinhaNaoEncontrada();
	}
	else {
		FILE* arqNovo = fopen("excluir.txt", "w");
		for (strPacientes i : vcPcnt) {
			string stLinha = i.stNome + ";" + to_string(i.itIdade) + ";" + i.stSexo + ";" + '\n';
			fprintf_s(arqNovo, stLinha.c_str());
		}
		_fclose_nolock(this->Arq);
		fclose(arqNovo);

		remove(stNomeArquivoAux.c_str());
		rename("excluir.txt", stNomeArquivoAux.c_str());
	}
}

void ArquivoPaciente::Editar() throw (Ex_LinhaNaoEncontrada) {
	vector<strPacientes> vcPcnt;
	this->PreencherVectorPacientes(vcPcnt, false);
	int j = 0;
	bool blEncontrou = false;
	for (strPacientes i : vcPcnt) {
		if (i.stNome == this->GetNome()) {
			vcPcnt.erase(vcPcnt.begin() + j);
			i.stNome = this->GetNome();
			i.itIdade = this->GetIdade();
			i.stSexo = this->GetSexo();
			vcPcnt.insert(vcPcnt.begin() + j, i);
			blEncontrou = true;
		}
		j++;
	}

	if (!blEncontrou) {
		throw Ex_LinhaNaoEncontrada();
	}
	else {
		FILE* arqNovo = fopen("editar.txt", "w");
		for (strPacientes i : vcPcnt) {
			string stLinha = i.stNome + ";" + to_string(i.itIdade) + ";" + i.stSexo + ";" + '\n';
			fprintf_s(arqNovo, stLinha.c_str());
		}
		_fclose_nolock(this->Arq);
		fclose(arqNovo);

		remove(stNomeArquivoAux.c_str());
		rename("editar.txt", stNomeArquivoAux.c_str());
	}
}

int ArquivoPaciente::Pesquisar() {
	//Realiza a busca por nome
	int result = 0;
	vector<strPacientes> vcPcnt;
	this->PreencherVectorPacientes(vcPcnt, false);

	for (strPacientes i : vcPcnt) {
		if (i.stNome == this->GetNome()) {
			string stLinhaAux = i.stNome + ";" + to_string(i.itIdade) + ";" + i.stSexo + ";";
			cout << stLinhaAux << endl;
			result = 1;
		}
	}
	return result;
}

void ArquivoPaciente::ListarTodos(){
	vector<strPacientes> vctListar;
	this->PreencherVectorPacientes(vctListar, true);
	string stCbNome = "Nome";
	stCbNome.resize(itPNome, ' ');
	string stCbIdade = "Idade";
	stCbIdade.resize(itPIdade, ' ');
	string stCbSexo = "Sexo";
	stCbSexo.resize(itPSexo, ' ');
	cout << stCbNome << stCbIdade << stCbSexo << endl;

	for (strPacientes p : vctListar) {
		p.stNome.resize(itPNome, ' ');
		string stIdade = to_string(p.itIdade);
		stIdade.resize(itPIdade, ' ');
		p.stSexo.resize(itPSexo, ' ');
		cout << p.stNome << stIdade << p.stSexo << endl;
	}
}