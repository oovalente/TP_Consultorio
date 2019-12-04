#include<iostream>
#include "Paciente.h"
#include "atendimento.h"
#include<locale.h>
#include "Exame.h"
using namespace std;
int main(){
    setlocale(LC_ALL,"");
    Atendimento *p1=new Atendimento();
    p1->Cadastrar();
    return 0;
}
