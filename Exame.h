#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED
#include "atendimento.h"
#include "Paciente.h"
#include<iostream>
#include<locale.h>
using namespace std;
class Exame: public Atendimento{
public:
    Exame();
    ~Exame();
    char tipo_sanguineo;
    void Cadastrar();
    void Excluir();
    void Pesquisar();
    void Laudo();
private:

};
Exame::Exame(){

}
Exame::~Exame(){

}
void Exame::Laudo(){
    /* Se sim para 3 ou mais perguntas e coleterol total maior que 170 alto risco de doença cardiovascular
    se sim para 3 ou mais perguntas e coleterol total dentro da faixa esperada risco de doença cardiovascular medio
    se sim para  menos q 3 perguntas e colestetol total alto o risco é baixo para doença cardiovascular mas necessario acompanhamento medico
    se sim para menos q 3 perguntas e colesterol total normal risco baxio
*/
    setlocale(LC_ALL,"");
    char resp;
    int cont=0,c;
    cout<<"Digite os resultados dos seus exames"<<endl;
    cout<<"Colesterol Total: "<<endl;//
    cin>>c;
    cout<<"Digite 'S' para sim e 'N' para nao para responder as perguntas a seguir:"<<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
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
    cout<<"Tem ou possui histórico de hipertensão na familia?"<<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    cout<<"E fumante? Seja ativo ou passivo?" <<endl;
    cin>>resp;
    if(resp=='S')
        ++cont;
    system("cls");
    cout<<"Resultado:"<<endl;
    if(c>170 && cont>=3)
        cout<<"Risco de doênça cardiovascular."<<endl;
    else if(c<=170 && cont>=3)
        cout<<"Risco de doença cardiovascular médio."<<endl;
    else if(c>=170 && cont<3)
        cout<<"Risco baixo para doença cardiovascular,mas necessário acompanhamento medico devido ao colesterol mais alto que o usual."<<endl;
    else
        cout<<"Risco baixo de doença cardiovascular e colesterol mais baixo que o usual"<<endl;
}
void Exame::Cadastrar(){

}
void Exame::Excluir(){

}
void Exame::Pesquisar(){

}
#endif // EXAME_H_INCLUDED
