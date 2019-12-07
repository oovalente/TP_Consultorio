#include "Exames.h"
#include "ExameColesterol.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void Exames::CadastraExames() {
	ArquivoExame* arq = new ArquivoExame("");

	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);

	cout << "Digite o nome do paciente: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);

	cout << "Digite o tipo do exame: " << endl;
	string stTipoExame;
	cin >> stTipoExame;
	arq->SetTipoExame(stTipoExame);

	cout << "Digite o laudo do exame: " << endl;
	string stLaudo;
	cin >> stData;
	arq->SetLaudo(stLaudo);

	cout << "Digite se o paciente possui risco iminente (S - Sim, N - Não): " << endl;
	string stApresentaRiscoIminente;
	cin >> stApresentaRiscoIminente;
	arq->SetApresentaRiscoIminente(stApresentaRiscoIminente);

	arq->Cadastrar();
	cout << "Exame cadastrado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesExames();
}

void Exames::EditarExames() {
	ArquivoExame* arq = new ArquivoExame("");

	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);

	cout << "Digite o nome do paciente: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);

	cout << "Digite o tipo do exame: " << endl;
	string stTipoExame;
	cin >> stTipoExame;
	arq->SetTipoExame(stTipoExame);

	cout << "Digite o laudo do exame: " << endl;
	string stLaudo;
	cin >> stData;
	arq->SetLaudo(stLaudo);

	cout << "Digite se o paciente possui risco iminente (S - Sim, N - Não): " << endl;
	string stApresentaRiscoIminente;
	cin >> stApresentaRiscoIminente;
	arq->SetApresentaRiscoIminente(stApresentaRiscoIminente);

	arq->Editar();
	cout << "Exame alterado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesExames();
}

void Exames::ExcluirExames() {
	ArquivoExame* arq = new ArquivoExame("");

	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);

	cout << "Digite o nome do paciente: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);

	arq->Excluir();
	cout << "Exame deletado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesExames();
}

void Exames::PesquisarExames() {
	ArquivoExame* arq = new ArquivoExame("");

	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);

	cout << "Digite o nome do paciente: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);

	arq->Pesquisar();
	delete arq;
	this->ImprimeOpcoesExames();
}

void Exames::ExecExameColesterol() {
	ExameColesterol *ex = new ExameColesterol();
	ex->GerarColesterol();
	delete ex;
}

void Exames::ChamaOpcaoSelecionadaExames(int itOp) {
	cout << "--------------------------------------------------------------" << endl;
	switch (itOp)
	{
	case 1:
		CadastraExames();
	case 2:
		EditarExames();
	case 3:
		ExcluirExames();
	case 4:
		PesquisarExames();
	case 5:
		ExecExameColesterol();
	default:
		return;
	}
}

void Exames::ImprimeOpcoesExames() {
	cout << "Digite o número para as seguintes opções: " << endl;
	cout << "1 - Cadastrar novo exame " << endl;
	cout << "2 - Editar exame " << endl;
	cout << "3 - Excluir exame " << endl;
	cout << "4 - Pesquisar exame " << endl;
	cout << "5 - Exame de colesterol " << endl;
	cout << "6 - Sair " << endl;
	int itOp = -1;
	cin >> itOp;
	ChamaOpcaoSelecionadaExames(itOp);
}

