#pragma once
#include <stdio.h>
#include <iostream>
#include "ArquivoPaciente.h"

class Pacientes
{
public:
	void CadastraPacientes();
	void EditarPacientes();
	void ExcluirPacientes();
	void PesquisarPacientes();
	void ChamaOpcaoSelecionadaPacientes(int itOp);
	void ImprimeOpcoesPacientes();
};

