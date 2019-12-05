#include<iostream>
#include "Paciente.h"
#include "atendimento.h"
#include<locale.h>
#include "Exame.h"
using namespace std;
int main(){
    setlocale(LC_ALL,"");
    Exame *p1=new Exame();
    p1->Cadastrar();
    p1->Laudo();
    cout<<"Resultado:"<<endl<<p1->getResultado()<<endl;
    return 0;
}
