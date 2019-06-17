#include "percursos.h"

percursos::percursos()
{

}

void percursos::ordenar_por_nome()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_nome);
}

void percursos::ordenar_por_idade()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_idade);
}

void percursos::ordenar_por_peso()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_peso);
}

void percursos::ordenar_por_tempo()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_tempo);
}

void percursos::ordenar_por_distancia()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_distancia);
}

void percursos::ordenar_por_velocidade()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_velocidade);
}

void percursos::ordenar_por_gasto_energetico()
{
    std::sort(pelotao.begin(),pelotao.end(),comparar_Por_gasto_energetico);
}

double percursos::calcular_desvioP_tempo()
{
    double soma_quadrada=0.0;
    double media=calcular_media_tempo();
    int i;
    for (i=0;i<pelotao.size();i++) {
        soma_quadrada+=qPow((pelotao[i].getTempo()-media),2.0);
    }
    return qSqrt(soma_quadrada/i);
}

double percursos::calcular_desvioP_velocidade()
{
    double soma_quadrada=0.0;
    double media=calcular_media_velocidade();
    int i;
    for (i=0;i<pelotao.size();i++) {
        soma_quadrada+=qPow(((pelotao[i].getDistancia()/pelotao[i].getTempo())-media),2.0);
    }
    return qSqrt(soma_quadrada/i);
}

double percursos::calcular_desvioP_distancia()
{
    double soma_quadrada=0.0;
    double media=calcular_media_distancia();
    int i;
    for (i=0;i<pelotao.size();i++) {
        soma_quadrada+=qPow((pelotao[i].getDistancia()-media),2.0);
    }
    return qSqrt(soma_quadrada/i);
}

double percursos::calcular_media_velocidade()
{
    double soma_velocidade=0.0;
    int i;
    for(i=0;i<pelotao.size();i++){
        soma_velocidade+=pelotao[i].getDistancia()/pelotao[i].getTempo();
    }
    return soma_velocidade/i;
}

double percursos::calcular_media_tempo()
{
    double soma_tempo=0.0;
    int i;
    for(i=0;i<pelotao.size();i++){
        soma_tempo+=pelotao[i].getTempo();
    }
    return soma_tempo/i;
}

double percursos::calcular_media_distancia()
{
    double soma_distancia=0.0;
    int i;
    for(i=0;i<pelotao.size();i++){
        soma_distancia+=pelotao[i].getDistancia();
    }
    return soma_distancia/i;
}

QString percursos::quem_maior_distancia()
{
    double maior=1.000000;
    QString nome_maior;
    for (int i=0;i<pelotao.size();i++) {
        if(pelotao[i].getDistancia()>maior){
            maior=pelotao[i].getDistancia();
            nome_maior=pelotao[i].getNome();
         }
     }
    return nome_maior;
}

QString percursos::quem_menor_tempo()
{
    double menor=100000000.000000;
    QString nome_menor;
    for (int i=0;i<pelotao.size();i++) {
        if(pelotao[i].getTempo()<menor){
            menor=pelotao[i].getTempo();
            nome_menor=pelotao[i].getNome();
         }
     }
    return nome_menor;
}

QString percursos::quem_maior_velocidade()
{
    QString veloz;
    ordenar_por_velocidade();
    return pelotao[0].getNome();
}

void percursos::cadastrar_no_pelotao(ciclista y)
{
    pelotao.append(y);
}

int percursos::size()
{
    return pelotao.size();
}

ciclista percursos::operator[](int j)
{
    return pelotao[j];
}

bool percursos::salvarPelotao(QString archive)
    {
        QFile file(archive);
        QString linha;
        if(!file.open(QIODevice::WriteOnly))
            return false;
        QTextStream out(&file);
        for(ciclista a:pelotao){
            out<<a.getNome()<<","<<a.getIdade()<<","<<a.getPeso()<<","
              <<a.getDistancia()<<","<<a.getTempo()<<","<<a.getVelocidade_media()<<","
             <<a.getGasto_energetico()<<endl;
        }
}

bool percursos::carregarPelotao(QString archive)
{
        QFile file(archive);
            if(!file.open(QIODevice::ReadOnly))
                return false;

            QString linha;
            ciclista objeto;
            while(!file.atEnd()){
                linha = file.readLine();
                QStringList lido = linha.split(",");
                objeto.setNome(lido[0]);
                objeto.setIdade(lido[1].toInt());
                objeto.setPeso(lido[2].toDouble());
                objeto.setDistancia(lido[3].toDouble());
                objeto.setTempo(lido[4].toDouble());
                objeto.setVelocidade_media(lido[5].toDouble());
                objeto.setGasto_energetico(lido[6].toDouble());
                cadastrar_no_pelotao(objeto);
                objeto.clear();
            }
}

void percursos::erase(ciclista a)
{
    int i=0;
    QVector<ciclista>::iterator it;
    for(it=pelotao.begin();it!=pelotao.end();it++,i++){
        if(a.getNome()==pelotao[i].getNome()){
            *it=pelotao[i];
            pelotao.erase(it);
    }
}
}

void percursos::removeLast()
{
    pelotao.removeLast();
}

void percursos::clearPelotao()
{
    pelotao.clear();
}

bool comparar_Por_nome(ciclista u, ciclista v)
{
    QString a,b;
    a=u.getNome().toLower();
    b=v.getNome().toLower();
    return a<b;
}
bool comparar_Por_idade(ciclista w, ciclista x)
{
    return w.getIdade()<x.getIdade();
}
bool comparar_Por_peso(ciclista y, ciclista z)
{
    return y.getPeso()>z.getPeso();
}
bool comparar_Por_tempo(ciclista a, ciclista b)
{
    return a.getTempo()<b.getTempo();
}
bool comparar_Por_distancia(ciclista p, ciclista q)
{
    return p.getDistancia()>q.getDistancia();
}
bool comparar_Por_velocidade(ciclista g, ciclista h)
{
    return g.getDistancia()/g.getTempo() > h.getDistancia()/h.getTempo();
}
bool comparar_Por_gasto_energetico(ciclista x, ciclista y)
{
    return x.getTempo()*0.133*x.getPeso() > y.getTempo()*0.133*y.getPeso();
}

