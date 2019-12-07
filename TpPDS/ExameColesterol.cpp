#pragma warning(disable : 4996)
#include "ExameColesterol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdio>

ExameColesterol::ExameColesterol() {

}
ExameColesterol::~ExameColesterol() {

}

void ExameColesterol::GerarColesterol() {
	setlocale(LC_ALL, "");
	ExameColesterol* p1 = new ExameColesterol();
	p1->Laudo();
	cout << "Resultado:" << endl << p1->getResultado() << endl;
}

void ExameColesterol::Dicas() {
	setlocale(LC_ALL, "");
	system("cls");
	char chLinhaAux[500];
	FILE* Arq = fopen("Dica_texto.txt", "w");

	while (fgets(chLinhaAux, 500, Arq) != NULL) {
		cout << chLinhaAux;
	}
	fclose(Arq);
}
void ExameColesterol::Laudo() {
	/* Se sim para 3 ou mais perguntas e coleterol total maior que 170 alto risco de doença cardiovascular
	se sim para 3 ou mais perguntas e coleterol total dentro da faixa esperada risco de doença cardiovascular medio
	se sim para  menos q 3 perguntas e colestetol total alto o risco é baixo para doença cardiovascular mas necessario acompanhamento medico
	se sim para menos q 3 perguntas e colesterol total normal risco baxio
*/
	setlocale(LC_ALL, "");
	int tempo = clock();
	char resp_dica;
	char resp;
	int cont = 0, c;
	cout << "Digite os resultados dos seus exames" << endl;
	cout << "Colesterol Total: " << endl;//
	cin >> c;
	cout << "Digite 'S' para sim e 'N' para nao para responder as perguntas a seguir:" << endl;
	cout << "Possuiu algum tipo de diabetes Mellitus?" << endl;
	cin >> resp;
	if (resp == 'S')
		++cont;
	cout << "E sedentario?" << endl;
	cin >> resp;
	if (resp == 'S')
		++cont;
	cout << "Possui obesidade?" << endl;
	cin >> resp;
	if (resp == 'S')
		++cont;
	cout << "Tem ou possui histórico de hipertensão na familia?" << endl;
	cin >> resp;
	if (resp == 'S')
		++cont;
	cout << "E fumante? Seja ativo ou passivo?" << endl;
	cin >> resp;
	if (resp == 'S')
		++cont;
	system("cls");
	if (c > 170 && cont >= 3)
		setResultado("Risco de doênça cardiovascular.");
	else if (c <= 170 && cont >= 3)
		setResultado("Risco de doença cardiovascular médio.");
	else if (c >= 170 && cont < 3)
		setResultado("Risco baixo para doença cardiovascular,mas necessário acompanhamento medico devido ao colesterol mais alto que o usual.");
	else
		setResultado("Risco baixo de doença cardiovascular e colesterol mais baixo que o usual");
	cout << "Resultado:" << endl << endl << getResultado() << endl << endl;
	system("pause");
	system("cls");
	cout << "Deseja receber dicas de como melhorar sua saúde e melhorar sua reeducão alimentar:" << endl;
	cin >> resp_dica;
	if (resp_dica == 'S')
		Dicas();
	else {
		cout << "                 Obrigado por usar nosso Sistema!" << endl;
		system("cls");
	}
}

string ExameColesterol::getResultado() {
	return resultado;
}

void ExameColesterol::setResultado(string exame) {
	this->resultado = exame;
}
