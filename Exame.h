#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED
#include "atendimento.h"
#include "Paciente.h"
#include<iostream>
#include<locale.h>
#include<string>
using namespace std;
class Exame{
public:
    string resultado;
    Exame();
    ~Exame();
    char tipo_sanguineo;
    void Cadastrar();
    void Excluir();
    void Pesquisar();
    void Laudo();
    string getResultado();
    void setResultado(string exame);
private:

};
Exame::Exame(){

}
Exame::~Exame(){

}
void Exame::Laudo(){
    /* Se sim para 3 ou mais perguntas e coleterol total maior que 170 alto risco de doen�a cardiovascular
    se sim para 3 ou mais perguntas e coleterol total dentro da faixa esperada risco de doen�a cardiovascular medio
    se sim para  menos q 3 perguntas e colestetol total alto o risco � baixo para doen�a cardiovascular mas necessario acompanhamento medico
    se sim para menos q 3 perguntas e colesterol total normal risco baxio
*/
    setlocale(LC_ALL,"");
    char resp;
    int cont=0,c;
    cout<<"Digite os resultados dos seus exames"<<endl;
    cout<<"Colesterol Total: "<<endl;//
    cin>>c;
    cout<<"Digite 'S' para sim e 'N' para nao para responder as perguntas a seguir:"<<endl;
    cout<<"Possuiu algum tipo de diabetes Mellitus?"<<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    cout<<"E sedentario?"<<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    cout<<"Possui obesidade?"<<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    cout<<"Tem ou possui hist�rico de hipertens�o na familia?"<<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    cout<<"E fumante? Seja ativo ou passivo?" <<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    system("cls");
    if(c>170 && cont>=3)
        setResultado("Risco de do�n�a cardiovascular.");
    else if(c<=170 && cont>=3)
        setResultado("Risco de doen�a cardiovascular m�dio.");
    else if(c>=170 && cont<3)
        setResultado("Risco baixo para doen�a cardiovascular,mas necess�rio acompanhamento medico devido ao colesterol mais alto que o usual.");
    else
        setResultado("Risco baixo de doen�a cardiovascular e colesterol mais baixo que o usual");
}
void Exame::Cadastrar(){

}
void Exame::Excluir(){

}
void Exame::Pesquisar(){

}
string Exame::getResultado(){
    return resultado;
}
void Exame::setResultado(string exame){
    this->resultado=exame;
}
#endif // EXAME_H_INCLUDED
