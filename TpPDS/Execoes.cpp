#include "Execoes.h"
#include <stdio.h>
#include <string>
using namespace std;

const char* Ex_LinhaVazia::what() const noexcept {
	return "Não é possível inserir uma linha vazia.";
}

const char* Ex_LinhaNaoEncontrada::what() const noexcept {
	return "Não foi encontrado a linha com os parâmetros descritos.";
}