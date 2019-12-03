#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include<iostream>
#include<string>
#include<locale.h>
#include "atendimento.h"
using namespace std;
class Paciente:public Atendimento{
private:
    int idade;
    char sexo;
    int horas;
    int minutos;
    int dia;
    int mes;
    int ano;
public:
    Paciente();
    ~Paciente();
    string nome;
    string getNome();
    int getIdade();
    char getSexo();
    void setNome(string nome);
    void setSexo(char sexo);
    void setIdade(int idade);
    void Imp_Ficha();
    void Cadastro();
    void Excluir();
    void Consulta();
    void get_Consulta();
    void Pesquisar();
};
Paciente::Paciente(){

}
Paciente::~Paciente(){

}
void Paciente::Pesquisar(){
    //Ver como se faz a classe pesquisa
}
void Paciente::get_Consulta(){
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"Consulta do paciente "<<getNome()<<endl;
    cout<<"Data: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
    cout<<"Horário: "<<horas<<":"<<minutos<<endl;
}
void Paciente::Consulta(){
    if(nome=="NULL"){
        cout<<"Paciente não cadastrado!!"<<endl;
    }
    else{
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"Digite o dia do mês que você deseja fazer a consulta:"<<endl;
            cin>>dia;
        cout<<"Digite o respectivo número do mês para o cadastro:"<<endl;
            cin>>mes;
        cout<<"Digite o ano da consulta:"<<endl;
            cin>>ano;
        cout<<"Digite o as hora da consulta e em seguida os minutos:"<<endl;
        cin>>horas;
        cin>>minutos;
        //if(horas==disponível && minutos==disponível && dia==disponível)
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"Consulta marcada com sucesso!!"<<endl;
            cout<<"Data: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
            cout<<"Horário: "<<horas<<":"<<minutos<<endl;
        //else
            //cout<<"Consulta não marcada! Horário indisponível!"<<endl;
    }
}
void Paciente::Excluir( ){
    setNome("NULL");
    setIdade(0);
    setSexo('n');
}
void Paciente::Cadastro(){
    string n;
    int ida;
    char sex;
    cout<<"Digite o nome completo do paciente:"<<endl;
    cin>>n;
    setNome(n);
    cout<<"Digite a idade do paciente"<<endl;
    cin>>ida;
    setIdade(ida);
    cout<<"Digite M para o sexo masculino e F para o sexo feminino"<<endl;
    cin>>sex;
    setSexo(sex);
}
void Paciente::Imp_Ficha(){
    cout<<endl;
    if(getNome()!="Null")
    cout<<"             Ficha do Paciente "<<getNome()<<endl;
    cout<<"     Nome: "<<getNome()<<endl;
    cout<<"     Idade: "<<getIdade()<<endl;
    cout<<"     Sexo: ";
    if(getSexo()=='M' or getSexo()=='m')
        cout<<"Masculino"<<endl;
    else if(getSexo()=='F'or getSexo()=='f')
        cout<<"Feminino"<<endl;
    else
        cout<<"NULL"<<endl;
}
string Paciente::getNome(){
    return nome;
}
int Paciente::getIdade(){
    return idade;
}
char Paciente::getSexo(){
    return sexo;
}
void Paciente::setNome(string nome){
    this->nome=nome;
}
void Paciente::setSexo(char sexo){
    this->sexo=sexo;
}
void Paciente::setIdade(int idade){
    this->idade=idade;
}

#endif
