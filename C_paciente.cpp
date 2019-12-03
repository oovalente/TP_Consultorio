#include<iostream>
#include "paciente.h"
#include "atendimento.h"
#include<locale.h>
using namespace std;
int main(){
    setlocale(LC_ALL,"");
    Paciente *p1= new Paciente();
    p1->Cadastro();
    p1->Imp_Ficha();
    p1->Consulta();
    p1->getConsulta();
    return 0;
}
