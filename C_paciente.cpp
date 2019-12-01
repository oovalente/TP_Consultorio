#include<iostream>
#include "paciente.h"
#include<locale.h>
using namespace std;
int main(){
    setlocale(LC_ALL,"");
    Paciente *p1= new Paciente();
    p1->setNome("Felipe Augusto Cruz Sousa");
    p1->setIdade(19);
    p1->setSexo('M');
    cout<<"Ficha do Paciente "<<p1->getNome()<<":"<<endl;
    cout<<"Nome: "<<p1->getNome()<<endl;
    cout<<"Idade: "<<p1->getIdade()<<endl;
    cout<<"Sexo: ";
    if(p1->getSexo()=='M')
        cout<<"Masculino"<<endl;
    else
        cout<<"Feminino"<<endl;
    return 0;
}
