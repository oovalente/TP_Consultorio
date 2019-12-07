#include <stdio.h>
#include <iostream>
#include "Consultas.h"
#include "Exames.h"
#include "Pacientes.h"

using namespace std;

void ChamaConsulta() {
	Consultas* c = new Consultas();
	c->ImprimeOpcoesConsultas();
	delete c;
}

void ChamaPaciente() {
	Pacientes* p = new Pacientes();
	p->ImprimeOpcoesPacientes();
	delete p;
}

void ChamaExame() {
	Exames* ex = new Exames();
	ex->ImprimeOpcoesExames();
	delete ex;
}

void ChamaOpcaoSelecionada(int itOp) {
	cout << "--------------------------------------------------------------" << endl;
	if (itOp == 1)
		ChamaConsulta();
	if (itOp == 2)
		ChamaPaciente();
	if (itOp == 3)
		ChamaExame();
}

void ImprimirOpcoesGerais() {
	cout << "Digite o número para as seguintes opções: " << endl;
	cout << "1 - Consultas " << endl;
	cout << "2 - Pacientes " << endl;
	cout << "3 - Exames " << endl;
	cout << "4 - Sair " << endl;
	int itOp = -1;
	cin >> itOp;
	ChamaOpcaoSelecionada(itOp);
}


int main() {
	bool blSair = true;
	while (blSair) {
		ImprimirOpcoesGerais();
		char chSair = 'N';
		cout << "Deseja realizar nova operação?" << endl;
		cin >> chSair;
		if (chSair != 'S')
			blSair = false;
	}

	return 0;
}