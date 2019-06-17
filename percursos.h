#ifndef PERCURSOS_H
#define PERCURSOS_H
#include "ciclista.h"
#include <qmath.h>
#include <algorithm>
#include <QVector>
#include <QFile>
#include <QTextStream>

class percursos
{
private:
    QVector<ciclista> pelotao;
public:
    percursos();

    void ordenar_por_nome();
    void ordenar_por_idade();
    void ordenar_por_peso();
    void ordenar_por_tempo();
    void ordenar_por_distancia();
    void ordenar_por_velocidade();
    void ordenar_por_gasto_energetico();

    double calcular_desvioP_tempo();
    double calcular_desvioP_velocidade();
    double calcular_desvioP_distancia();
    double calcular_media_velocidade();
    double calcular_media_tempo();
    double calcular_media_distancia();

    QString quem_maior_distancia();
    QString quem_menor_tempo();
    QString quem_maior_velocidade();

    void cadastrar_no_pelotao(ciclista y);
    int size();
    ciclista operator[](int j);

    bool salvarPelotao(QString archive);
    bool carregarPelotao(QString archive);

    void erase(ciclista a);
    void removeLast();
    void clearPelotao();

};
bool comparar_Por_nome(ciclista u, ciclista v);
bool comparar_Por_idade(ciclista w, ciclista x);
bool comparar_Por_peso(ciclista y, ciclista z);
bool comparar_Por_tempo(ciclista a, ciclista b);
bool comparar_Por_distancia(ciclista p, ciclista q);
bool comparar_Por_velocidade(ciclista g, ciclista h);
bool comparar_Por_gasto_energetico(ciclista x, ciclista y);
#endif // PERCURSOS_H
