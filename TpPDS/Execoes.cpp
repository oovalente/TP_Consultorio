#include "Execoes.h"
#include <stdio.h>
#include <string>
using namespace std;

const char* Ex_ErroInserir::what() const noexcept {
	return "Erro inesperado impossibilitou a inser��o do arquivo.";
}

const char* Ex_LinhaNaoEncontrada::what() const noexcept {
	return "N�o foi encontrado a linha com os par�metros descritos.";
}