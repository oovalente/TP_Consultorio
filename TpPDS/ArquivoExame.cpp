#include "ArquivoExame.h"


#pragma warning(disable : 4996)
#include "ArquivoConsulta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include "Execoes.h"

const int itPData = 11;
const int itPNomePaciente = 40;
const int itPModalidade = 20;
const int itPDescricao = 150;
const int itPExameMarcado = 4;

const string stNomeArquivoAux = "ArquivoConsultas.txt";
using namespace std;

ArquivoConsulta::~ArquivoConsulta() {
	fclose(Arq);
}

ArquivoConsulta::ArquivoConsulta(string stNomeArquivo = stNomeArquivoAux) : Arquivo(stNomeArquivo = stNomeArquivoAux) {

}

string ArquivoConsulta::GetData() {
	return this->stData;
}

string ArquivoConsulta::GetNomePaciente() {
	return this->stNomePaciente;
}

string ArquivoConsulta::GetModalidade() {
	return this->stModalidade;
}

string ArquivoConsulta::GetDescricao() {
	return this->stDescricao;
}

string ArquivoConsulta::GetExameMarcado() {
	return this->stExameMarcado;
}

void ArquivoConsulta::SetData(string _Data) {
	this->stData = _Data;
}

void ArquivoConsulta::SetNomePaciente(string _NomePaciente) {
	this->stNomePaciente = _NomePaciente;
}

void ArquivoConsulta::SetModalidade(string _Modalidade) {
	this->stModalidade = _Modalidade;
}

void ArquivoConsulta::SetDescricao(string _Descricao) {
	this->stDescricao = _Descricao;
}

void ArquivoConsulta::SetExameMarcado(string _ExameMarcado) {
	this->stExameMarcado = _ExameMarcado;
}


void ArquivoConsulta::MontarLinha() {
	//Aqui se monta a linha de acordo com a estrutura esperada no arquivo
	//Data;NomePaciente;Modalidade;Descricao;ExameMarcado;
	string stLinhaAux = this->GetData() + ";" + this->GetNomePaciente() + ";" + this->GetModalidade() + ";" +
		this->GetDescricao() + ";" + this->GetExameMarcado() + '\n';
	this->SetLinha(stLinhaAux);
}

void ArquivoConsulta::PreencherVectorConsultas(vector<strConsulta>& vcPcnt, bool blSpace) {
	strConsulta pc1;
	char chLinhaAux[500];
	string stCampo;
	this->CarregarArquivo(stNomeArquivoAux, "");

	while (fgets(chLinhaAux, 500, this->Arq) != NULL) {
		string stData;
		string stNomePaciente;
		string stModalidade;
		string stDescricao;
		string stExameMarcado;

		//Data;NomePaciente;Modalidade;Descricao;ExameMarcado;
		string stLinha(chLinhaAux);
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPData, ' ');
		pc1.stData = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPNomePaciente, ' ');
		pc1.stNomePaciente = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPModalidade, ' ');
		pc1.stModalidade = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace) {
			pc1.stDescricao = stCampo + ' ';
		}
		else {
			pc1.stDescricao = stCampo;
		}

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPExameMarcado, ' ');
		pc1.stExameMarcado = stCampo;

		vcPcnt.push_back(pc1);
	}
	fclose(this->Arq);
}

void ArquivoConsulta::Excluir() throw (Ex_LinhaNaoEncontrada) {
	vector<strConsulta> vcPcnt;
	this->PreencherVectorConsultas(vcPcnt, false);
	int j = 0;
	bool blEncontrou = false;
	for (strConsulta i : vcPcnt) {
		if ((i.stNomePaciente == this->GetNomePaciente()) && (i.stData == this->GetData())) {
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
		for (strConsulta i : vcPcnt) {
			string stLinha = this->GetData() + ";" + this->GetNomePaciente() + ";" + this->GetModalidade() + ";" +
				this->GetDescricao() + ";" + this->GetExameMarcado() + '\n';
			fprintf_s(arqNovo, stLinha.c_str());
		}
		_fclose_nolock(this->Arq);
		fclose(arqNovo);

		remove(stNomeArquivoAux.c_str());
		rename("excluir.txt", stNomeArquivoAux.c_str());
	}
}

void ArquivoConsulta::Editar() throw (Ex_LinhaNaoEncontrada) {
	vector<strConsulta> vcPcnt;
	this->PreencherVectorConsultas(vcPcnt, false);
	int j = 0;
	bool blEncontrou = false;
	for (strConsulta i : vcPcnt) {
		if ((i.stNomePaciente == this->GetNomePaciente()) && (i.stData == this->GetData())) {
			vcPcnt.erase(vcPcnt.begin() + j);
			i.stData = this->GetData();
			i.stNomePaciente = this->GetNomePaciente();
			i.stModalidade = this->GetModalidade();
			i.stDescricao = this->GetDescricao();
			i.stExameMarcado = this->GetExameMarcado();
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
		for (strConsulta i : vcPcnt) {
			string stLinha = this->GetData() + ";" + this->GetNomePaciente() + ";" + this->GetModalidade() + ";" +
				this->GetDescricao() + ";" + this->GetExameMarcado() + '\n';
			fprintf_s(arqNovo, stLinha.c_str());
		}
		_fclose_nolock(this->Arq);
		fclose(arqNovo);

		remove(stNomeArquivoAux.c_str());
		rename("editar.txt", stNomeArquivoAux.c_str());
	}
}

int ArquivoConsulta::Pesquisar() {
	//Realiza a busca por nome
	int result = 0;
	vector<strConsulta> vcPcnt;
	this->PreencherVectorConsultas(vcPcnt, false);

	for (strConsulta i : vcPcnt) {
		if ((i.stNomePaciente == this->GetNomePaciente()) && (i.stData == this->GetData())) {
			string stLinhaAux = i.stData + ";" + i.stNomePaciente + ";" + i.stModalidade + ";" +
				i.stDescricao + ";" + i.stExameMarcado + ";";
			cout << stLinhaAux << endl;
			result = 1;
		}
	}
	return result;
}

void ArquivoConsulta::ListarTodos() {
	vector<strConsulta> vctListar;

	const int itPData = 11;
	const int itPNomePaciente = 40;
	const int itPModalidade = 20;
	const int itPDescricao = 150;
	const int itPExameMarcado = 4;

	this->PreencherVectorConsultas(vctListar, true);
	//Data;NomePaciente;Modalidade;Descricao;ExameMarcado;
	string stData = "Data";
	string stNomePaciente = "Nome Paciente";
	string stModalidade = "Modalidade";
	string stDescricao = "Descrição";
	string stExameMarcado = "Exame";

	stData.resize(itPData, ' ');
	stNomePaciente.resize(itPNomePaciente, ' ');
	stModalidade.resize(itPModalidade, ' ');
	stDescricao = stDescricao + ' ';
	stExameMarcado.resize(itPExameMarcado, ' ');

	cout << stData << stNomePaciente << stModalidade << stDescricao << stExameMarcado << endl;

	for (strConsulta p : vctListar) {
		stData = p.stData;
		stNomePaciente = p.stNomePaciente;
		stModalidade = p.stModalidade;
		stDescricao = p.stDescricao;
		stExameMarcado = p.stExameMarcado;
		cout << stData << stNomePaciente << stModalidade << stDescricao << stExameMarcado << endl;
	}
}