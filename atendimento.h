#ifndef ATENDIMENTO_H_INCLUDED
#define ATENDIMENTO_H_INCLUDED
#include "Paciente.h"
#include "Exame.h"
class Atendimento{
private:
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
public:
    void Laudo();
    Atendimento();
    ~Atendimento();
    void Cadastrar();
    void Excluir();
    void Pesquisar();
};
Atendimento::Atendimento(){

}
Atendimento::~Atendimento(){

}
void Atendimento::Pesquisar(){

}
void Atendimento::Excluir(){

}
void Atendimento::Cadastrar(){

}
void Atendimento::Laudo(){

}

#endif // ATENDIMENTO_H_INCLUDED
