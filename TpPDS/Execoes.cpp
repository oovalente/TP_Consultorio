#include "Execoes.h"
#include <stdio.h>
#include <string>
using namespace std;

const char* Ex_LinhaVazia::what() const noexcept {
	return "N�o � poss�vel inserir uma linha vazia.";
}

const char* Ex_LinhaNaoEncontrada::what() const noexcept {
	return "N�o foi encontrado a linha com os par�metros descritos.";
}