#include <stdio.h>
#include <iostream>
#include "Arquivo.h"
#include "ArquivoPaciente.h"

int main() {
	ArquivoPaciente* arq = new ArquivoPaciente("");
	//arq->ListarTodos();
	arq->SetNome("Otávio1");
	arq->SetIdade(15);
	arq->SetSexo('M');
	arq->Cadastrar();
	delete arq;
	return 0;
}