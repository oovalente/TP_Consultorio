#include<iostream>
#include "paciente.h"
#include "atendimento.h"
#include<locale.h>
#include "Exame.h"
using namespace std;
int main(){
    setlocale(LC_ALL,"");
<<<<<<< HEAD
    Paciente *p1= new Paciente();
    p1->Cadastro();
    p1->Imp_Ficha();
=======
    Atendimento *p1=new Atendimento();
    p1->Cadastrar();
>>>>>>> daa3351686f276eb7c76aa95895fc2cd37b93e71
    return 0;
}
