#include "ciclista.h"

int ciclista::getIdade() const
{
    return idade;
}

void ciclista::setIdade(int value)
{
    if(value>0){
     if(No_alpha(QString::number(value)))
        idade = value;
    }
}

QString ciclista::getNome() const
{
    return nome;
}

void ciclista::setNome(const QString &value)
{
    if(value.size()>3){
    if(No_number(value))
        nome = value;
    }
}
double ciclista::getPeso() const
{
    return peso;
}

void ciclista::setPeso(double value)
{
    if(No_alpha(QString::number(value))){
    if(value>0.0)
        peso = value;
        }
}

double ciclista::getDistancia() const
{
    return distancia;
}

void ciclista::setDistancia(double value)
{
    if(No_alpha(QString::number(value))){
    if(value>0.0)
        distancia = value;
        }
}

double ciclista::getTempo() const
{
    return tempo;
}

void ciclista::setTempo(double value)
{
    if(No_alpha(QString::number(value))){
        if(value>0.0) tempo = value;
    }
}
double ciclista::getVelocidade_media() const
{
    return velocidade_media;
}

void ciclista::setVelocidade_media(double value)
{
    velocidade_media = value;
}

double ciclista::getGasto_energetico() const
{
    return gasto_energetico;
}

void ciclista::setGasto_energetico(double value)
{
    gasto_energetico = value;
}

void ciclista::clear(){
    nome="";
    peso=0.0;
    idade=0;
    tempo=0.0;
    distancia=0.0;
    velocidade_media=0.0;
    gasto_energetico=0.0;
}

ciclista::ciclista()
{

}

bool No_number(QString str){
int i=0,flag=0;
for(i=0;i<str.size();i++){
    if(str[i].isDigit()) flag++;
}
return !(flag>0);
}

bool No_alpha(QString str){
int j=0,flag=0;
for(;j<str.size();j++){
    if(str[j].isLetter()) flag++;
}
return !(flag>0);
}

