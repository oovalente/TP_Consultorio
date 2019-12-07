#pragma once
#include<iostream>
#include<locale.h>
#include<string>
#include<fstream>
#include<time.h>

using namespace std;

class ExameColesterol
{
public:
	ExameColesterol();
	~ExameColesterol();
	void Laudo();
	string getResultado();
	void setResultado(string exame);
	void Dicas();
	void GerarColesterol();
private:
	string resultado;

};
