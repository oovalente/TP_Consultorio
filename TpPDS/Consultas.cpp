#include "Consultas.h"

using namespace std;

void Consultas::CadastraConsulta() {
	ArquivoConsulta* arq = new ArquivoConsulta("");
	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);
	cout << "Digite o nome: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);
	cout << "Digite a modalidade: " << endl;
	string stModalidade;
	cin >> stModalidade;
	arq->SetModalidade(stModalidade);
	cout << "Digite a descricao: " << endl;
	string stDescricao;
	cin >> stDescricao;
	arq->SetDescricao(stDescricao);
	cout << "Digite se o exame já está marcado: " << endl;
	string stExameMarcado;
	cin >> stExameMarcado;
	arq->SetExameMarcado(stExameMarcado);
	arq->Cadastrar();
	cout << "Consulta cadastrado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesConsultas();
}

void Consultas::EditarConsulta() {
	ArquivoConsulta* arq = new ArquivoConsulta("");
	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);
	cout << "Digite o nome: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);
	cout << "Digite a modalidade: " << endl;
	string stModalidade;
	cin >> stModalidade;
	arq->SetModalidade(stModalidade);
	cout << "Digite a descricao: " << endl;
	string stDescricao;
	cin >> stDescricao;
	arq->SetDescricao(stDescricao);
	cout << "Digite se o exame já está marcado: " << endl;
	string stExameMarcado;
	cin >> stExameMarcado;
	arq->SetExameMarcado(stExameMarcado);
	arq->Editar();
	cout << "Consulta alterada com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesConsultas();
}

void Consultas::ExcluirConsulta() {
	ArquivoConsulta* arq = new ArquivoConsulta("");
	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);
	cout << "Digite o nome: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);
	arq->Excluir();
	cout << "Consulta alterado com sucesso " << endl;
	delete arq;
	this->ImprimeOpcoesConsultas();
}

void Consultas::PesquisarConsulta() {
	ArquivoConsulta* arq = new ArquivoConsulta("");
	cout << "Digite a data: " << endl;
	string stData;
	cin >> stData;
	arq->SetData(stData);
	cout << "Digite o nome: " << endl;
	string stNomePaciente;
	cin >> stNomePaciente;
	arq->SetNomePaciente(stNomePaciente);
	arq->Pesquisar();
	delete arq;
	this->ImprimeOpcoesConsultas();
}

void Consultas::ChamaOpcaoSelecionadaConsulta(int itOp) {
	cout << "--------------------------------------------------------------" << endl;
	switch (itOp)
	{
	case 1:
		CadastraConsulta();
	case 2:
		EditarConsulta();
	case 3:
		ExcluirConsulta();
	case 4:
		PesquisarConsulta();
	}
}


void Consultas::ImprimeOpcoesConsultas() {
	cout << "Digite o número para as seguintes opções: " << endl;
	cout << "1 - Cadastrar nova consulta " << endl;
	cout << "2 - Editar consulta " << endl;
	cout << "3 - Excluir consulta " << endl;
	cout << "4 - Pesquisar consulta " << endl;
	cout << "5 - Sair " << endl;
	int itOp = 0;
	cin >> itOp;
	ChamaOpcaoSelecionadaConsulta(itOp);
}