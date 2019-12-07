#pragma once
#include "ArquivoConsulta.h"
#include <stdio.h>
#include <iostream>


class Consultas
{
public:
	void CadastraConsulta();
	void EditarConsulta();
	void ExcluirConsulta();
	void PesquisarConsulta();
	void ChamaOpcaoSelecionadaConsulta(int itOp);
	void ImprimeOpcoesConsultas();
};

