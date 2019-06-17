#ifndef CICLISTA_H
#define CICLISTA_H
#include <QString>
#include <QDebug>
class ciclista
{
private:
   QString nome;
   double peso,distancia,tempo,velocidade_media,gasto_energetico;
   int idade;

public:
    ciclista();

    QString getNome() const;
    void setNome(const QString &value);

    int getIdade() const;
    void setIdade(int value);

    double getPeso() const;
    void setPeso(double value);

    double getDistancia() const;
    void setDistancia(double value);

    double getTempo() const;
    void setTempo(double value);

    double getVelocidade_media() const;
    void setVelocidade_media(double value);

    double getGasto_energetico() const;
    void setGasto_energetico(double value);

    void clear();
};
bool No_number(QString str);
bool No_alpha(QString str);

#endif // CICLISTA_H
