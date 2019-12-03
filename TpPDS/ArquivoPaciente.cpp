#include "ArquivoPaciente.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

ArquivoPaciente::~ArquivoPaciente() {
	fclose(Arq);
}

ArquivoPaciente::ArquivoPaciente(string stNomeArquivo = "ArquivoPacientes.txt") : Arquivo(stNomeArquivo = "ArquivoPacientes.txt") {

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
	string stLinhaAux = this->GetNome() + ";" + to_string(this->GetIdade()) + ";" + aux + ";";
	this->SetLinha(stLinhaAux);
}

void ArquivoPaciente::PreencherVectorPacientes(vector<strPacientes>& vcPcnt) {
	strPacientes pc1;
	string stLinha;
	string stCampo;
	while (!Arq.eof()) {
		fscanf(this->Arq,"%s",stLinha);
		stCampo = stLinha.substr(0, stLinha.find(';'));
		pc1.stNome = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		pc1.itIdade = stoi(stCampo);

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		pc1.stSexo = stCampo;
		vcPcnt.push_back(pc1);
	}
}

void ArquivoPaciente::Excluir() {
	vector<strPacientes> vcPcnt;
	PreencherVectorPacientes(vcPcnt);
	for (strPacientes i : vcPcnt) {
		cout << i.stNome + '\n';
	}
	int j = 0;
	for (strPacientes i : vcPcnt) {
		if (i.stNome == this->GetNome()) {
			vcPcnt.erase(vcPcnt.begin() + j);
		}
		j++;
	}
	string stAux = this->GetNomeArquivo();
	remove(stAux.c_str());
	for (strPacientes i : vcPcnt) {
		this->Arq << i.stNome << ";" << to_string(i.itIdade) << ";" << i.stSexo << ";" << '\n';
		cout << i.stNome + '\n';
	}
	fclose(this->Arq);
	Arq = fopen(this->GetNomeArquivo.c_str(), "wt");
}

void ArquivoPaciente::Editar() {

}

void ArquivoPaciente::Pesquisar() {

}

void ArquivoPaciente::ListarTodos(){
	string stLinha;
	string stCampo;
	while (!Arq.eof()) {
		getline(Arq, stLinha);

		stCampo = stLinha.substr(0, stLinha.find(';'));
		stCampo.resize(30, ' ');
		cout << stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		stCampo.resize(4, ' ');
		cout << stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		stCampo.resize(2, ' ');
		cout << stCampo + '\n';
	}
}