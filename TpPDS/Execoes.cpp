#include "Execoes.h"
#include <stdio.h>
#include <string>
using namespace std;

const char* Ex_ErroInserir::what() const noexcept {
	return "Erro inesperado impossibilitou a inserção do arquivo.";
}

const char* Ex_LinhaNaoEncontrada::what() const noexcept {
	return "Não foi encontrado a linha com os parâmetros descritos.";
}