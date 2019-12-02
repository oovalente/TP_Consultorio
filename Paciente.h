#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;

class Paciente/*:public (Nome da classe do Gustavo)*/{
private:
    int idade;
    char sexo;
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
};
Paciente::Paciente(){

}
Paciente::~Paciente(){

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
    cout<<"             Ficha do Paciente "<<getNome()<<endl;
    cout<<"     Nome: "<<getNome()<<endl;
    cout<<"     Idade: ";if(getIdade()==0) cout<<"NULL"<<endl;
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
