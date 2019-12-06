#include <stdio.h>
#include <iostream>
#include "Arquivo.h"
#include "ArquivoPaciente.h"

int main() {
	ArquivoPaciente* arq = new ArquivoPaciente("");
	arq->SetNome("Maradona");
	arq->SetIdade(15);
	arq->SetSexo('M');
	arq->Cadastrar();
	arq->ListarTodos();
	delete arq;
	return 0;
}