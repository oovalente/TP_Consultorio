#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include<string>
using namespace std;

class Paciente{
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
};
Paciente::Paciente(){

}
Paciente::~Paciente(){

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
