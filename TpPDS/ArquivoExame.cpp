#pragma warning(disable : 4996)
#include "ArquivoExame.h"
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
const int itPNomePaciente = 30;
const int itPTipoExame = 30;
const int itPLaudo = 50;
const int itPApresentaRiscoIminente = 4;

const string stNomeArquivoAux = "ArquivoExames.txt";
using namespace std;

ArquivoExame::ArquivoExame(string stNomeArquivo = stNomeArquivoAux) : Arquivo(stNomeArquivo = stNomeArquivoAux) {

}

ArquivoExame::~ArquivoExame() {
	fclose(Arq);
}

string ArquivoExame::GetData() {
	return this->stData;
}

string ArquivoExame::GetNomePaciente() {
	return this->stNomePaciente;
}

string ArquivoExame::GetTipoExame() {
	return this->stTipoExame;
}

string ArquivoExame::GetLaudo() {
	return this->stLaudo;
}

string ArquivoExame::GetApresentaRiscoIminente() {
	return this->stApresentaRiscoIminente;
}

void ArquivoExame::SetData(string _Data) {
	this->stData = _Data;
}

void ArquivoExame::SetNomePaciente(string _NomePaciente) {
	this->stNomePaciente = _NomePaciente;
}

void ArquivoExame::SetTipoExame(string _TipoExame) {
	this->stTipoExame = _TipoExame;
}

void ArquivoExame::SetLaudo(string _Laudo) {
	this->stLaudo = _Laudo;
}

void ArquivoExame::SetApresentaRiscoIminente(string _ApresentaRiscoIminente) {
	this->stApresentaRiscoIminente = _ApresentaRiscoIminente;
}


void ArquivoExame::MontarLinha() {
	//Aqui se monta a linha de acordo com a estrutura esperada no arquivo
	//stData;stNomePaciente;stTipoExame;stLaudo;stApresentaRiscoIminente;
	string stLinhaAux = this->GetData() + ";" + this->GetNomePaciente() + ";" +
		this->GetTipoExame() + ";" + this->GetLaudo() + ";" + this->GetApresentaRiscoIminente() + ";" + '\n';
	this->SetLinha(stLinhaAux);
}

void ArquivoExame::PreencherVectorExames(vector<strExame>& vcPcnt, bool blSpace) {
	strExame pc1;
	char chLinhaAux[500];
	string stCampo;
	this->CarregarArquivo(stNomeArquivoAux, "");
	
	while (fgets(chLinhaAux, 500, this->Arq) != NULL) {
		//stData;stNomePaciente;stTipoExame;stLaudo;stApresentaRiscoIminente;
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
			stCampo.resize(itPTipoExame, ' ');
		pc1.stTipoExame = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPLaudo, ' ');
		pc1.stLaudo = stCampo;

		stLinha = stLinha.substr(stLinha.find(';') + 1, stLinha.size());
		stCampo = stLinha.substr(0, stLinha.find(';'));
		if (blSpace)
			stCampo.resize(itPApresentaRiscoIminente, ' ');
		pc1.stApresentaRiscoIminente = stCampo;

		vcPcnt.push_back(pc1);
	}
	fclose(this->Arq);
}

void ArquivoExame::Excluir() throw (Ex_LinhaNaoEncontrada) {
	vector<strExame> vcPcnt;
	this->PreencherVectorExames(vcPcnt, false);
	int j = 0;
	bool blEncontrou = false;
	for (strExame i : vcPcnt) {
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
		for (strExame i : vcPcnt) {
			//stData;stNomePaciente;stTipoExame;stLaudo;stApresentaRiscoIminente;
			string stLinha = i.stData + ";" + i.stNomePaciente + ";" + i.stTipoExame + ";" +
				i.stLaudo + ";" + i.stApresentaRiscoIminente + '\n';
			fprintf_s(arqNovo, stLinha.c_str());
		}
		_fclose_nolock(this->Arq);
		fclose(arqNovo);

		remove(stNomeArquivoAux.c_str());
		rename("excluir.txt", stNomeArquivoAux.c_str());
	}
}

void ArquivoExame::Editar() throw (Ex_LinhaNaoEncontrada) {
	vector<strExame> vcPcnt;
	this->PreencherVectorExames(vcPcnt, false);
	int j = 0;
	bool blEncontrou = false;
	for (strExame i : vcPcnt) {
		if ((i.stNomePaciente == this->GetNomePaciente()) && (i.stData == this->GetData())) {
			vcPcnt.erase(vcPcnt.begin() + j);
			//stData;stNomePaciente;stTipoExame;stLaudo;stApresentaRiscoIminente;
			i.stData = this->GetData();
			i.stNomePaciente = this->GetNomePaciente();
			i.stTipoExame = this->GetTipoExame();
			i.stLaudo = this->GetLaudo();
			i.stApresentaRiscoIminente = this->GetApresentaRiscoIminente();
			vcPcnt.insert(vcPcnt.begin() + j, i);
			blEncontrou = true;
		}
		j++;
	}

	if (!blEncontrou) {
		throw Ex_LinhaNaoEncontrada();
	}
	else {
		FILE* arqNovo = fopen("excluir.txt", "w");
		for (strExame i : vcPcnt) {
			//stData;stNomePaciente;stTipoExame;stLaudo;stApresentaRiscoIminente;
			string stLinha = i.stData + ";" + i.stNomePaciente + ";" + i.stTipoExame + ";" +
				i.stLaudo + ";" + i.stApresentaRiscoIminente + '\n';
			fprintf_s(arqNovo, stLinha.c_str());
		}
		_fclose_nolock(this->Arq);
		fclose(arqNovo);

		remove(stNomeArquivoAux.c_str());
		rename("excluir.txt", stNomeArquivoAux.c_str());
	}
}

int ArquivoExame::Pesquisar() {
	//Realiza a busca por nome
	int result = 0;
	vector<strExame> vcPcnt;
	this->PreencherVectorExames(vcPcnt, false);

	for (strExame i : vcPcnt) {
		if ((i.stNomePaciente == this->GetNomePaciente()) && (i.stData == this->GetData())) {
			string stLinhaAux = i.stData + ";" + i.stNomePaciente + ";" + i.stModalidade + ";" +
				i.stDescricao + ";" + i.stExameMarcado + ";";
			cout << stLinhaAux << endl;
			result = 1;
		}
	}
	return result;
}

void ArquivoExame::ListarTodos() {
	vector<strExame> vctListar;

	this->PreencherVectorExames(vctListar, true);
	//stData;stNomePaciente;stTipoExame;stLaudo;stApresentaRiscoIminente;
	string stData = "Data";
	string stNomePaciente = "Nome Paciente";
	string stTipoExame = "Tipo do Exame";
	string stLaudo = "Laudo";
	string stApresentaRiscoIminente = "Risco Iminente";

	stData.resize(itPData, ' ');
	stNomePaciente.resize(itPNomePaciente, ' ');
	stTipoExame.resize(itPTipoExame, ' ');
	stLaudo.resize(itPLaudo, ' ');
	stApresentaRiscoIminente.resize(itPApresentaRiscoIminente, ' ');

	cout << stData << stNomePaciente << stTipoExame << stLaudo << stApresentaRiscoIminente << endl;

	for (strExame p : vctListar) {
		stData = p.stData;
		stNomePaciente = p.stNomePaciente;
	    stTipoExame = p.stTipoExame;
		stLaudo = p.stLaudo;
		stApresentaRiscoIminente = p.stApresentaRiscoIminente;
		
		stData.resize(itPData, ' ');
		stNomePaciente.resize(itPNomePaciente, ' ');
		stTipoExame.resize(itPTipoExame, ' ');
		stLaudo.resize(itPLaudo, ' ');
		stApresentaRiscoIminente.resize(itPApresentaRiscoIminente, ' ');

		cout << stData << stNomePaciente << stTipoExame << stLaudo << stApresentaRiscoIminente << endl;
	}
}