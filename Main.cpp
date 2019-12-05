#include<iostream>
#include "Paciente.h"
#include "atendimento.h"
#include<locale.h>
#include "Exame.h"
using namespace std;
int main(){
    setlocale(LC_ALL,"");
<<<<<<< HEAD:C_paciente.cpp
<<<<<<< HEAD
    Paciente *p1= new Paciente();
    p1->Cadastro();
    p1->Imp_Ficha();
=======
    Atendimento *p1=new Atendimento();
    p1->Cadastrar();
>>>>>>> daa3351686f276eb7c76aa95895fc2cd37b93e71
=======
    Exame *p1=new Exame();
    p1->Laudo();
    cout<<"Resultado:"<<endl<<p1->getResultado()<<endl;
>>>>>>> 9a4a4fdb9f722fa92f9aa7fcd0c53cf318919d2d:Main.cpp
    return 0;
}
