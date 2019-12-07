#include "Pacientes.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void Pacientes::CadastraPacientes() {
	ArquivoPaciente* arq = new ArquivoPaciente("");
	cout << "Digite o nome: " << endl;
	string stNome;
	cin >> stNome;
	arq->SetNome(stNome);
	cout << "Digite o idade: " << endl;
	int itIdade;
	cin >> itIdade;
	arq->SetIdade(itIdade);
	cout << "Digite a sexo (M - Masculino; F - Feminino; o - Outro): " << endl;
	char chSexo;
	cin >> chSexo;
	arq->SetSexo(chSexo);
	arq->Cadastrar();
	cout << "Paciente cadastrado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesPacientes();
}

void Pacientes::EditarPacientes() {
	ArquivoPaciente* arq = new ArquivoPaciente("");
	cout << "Digite o nome: " << endl;
	string stNome;
	cin >> stNome;
	arq->SetNome(stNome);
	cout << "Digite o idade: " << endl;
	int itIdade;
	cin >> itIdade;
	arq->SetIdade(itIdade);
	cout << "Digite a sexo (M - Masculino; F - Feminino; o - Outro): " << endl;
	char chSexo;
	cin >> chSexo;
	arq->SetSexo(chSexo);
	arq->Editar();
	cout << "Paciente alterado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesPacientes();
}

void Pacientes::ExcluirPacientes() {
	ArquivoPaciente* arq = new ArquivoPaciente("");
	cout << "Digite o nome: " << endl;
	string stNome;
	cin >> stNome;
	arq->SetNome(stNome);
	arq->Excluir();
	cout << "Paciente excluido com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesPacientes();
}

void Pacientes::PesquisarPacientes() {
	ArquivoPaciente* arq = new ArquivoPaciente("");
	cout << "Digite o nome: " << endl;
	string stNome;
	cin >> stNome;
	arq->SetNome(stNome);
	arq->Pesquisar();
	delete arq;
	this->ImprimeOpcoesPacientes();
}

void Pacientes::ChamaOpcaoSelecionadaPacientes(int itOp) {
	cout << "--------------------------------------------------------------" << endl;
	switch (itOp)
	{
	case 1:
		CadastraPacientes();
	case 2:
		EditarPacientes();
	case 3:
		ExcluirPacientes();
	case 4:
		PesquisarPacientes();
	default:
		return;
	}
}

void Pacientes::ImprimeOpcoesPacientes() {
	cout << "Digite o número para as seguintes opções: " << endl;
	cout << "1 - Cadastrar nova paciente " << endl;
	cout << "2 - Editar paciente " << endl;
	cout << "3 - Excluir paciente " << endl;
	cout << "4 - Pesquisar paciente " << endl;
	cout << "5 - Sair " << endl;
	int itOp = -1;
	cin >> itOp;
	ChamaOpcaoSelecionadaPacientes(itOp);
}