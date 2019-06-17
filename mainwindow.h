#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QInputDialog>
#include "ciclista.h"
#include "percursos.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inserir_Ciclista_tabela(int linha, ciclista x);
    void atualizarTabela();
    void printar_labels();
    void set_label_default();
private slots:
    void on_botao_adicionar_clicked();

    void on_botao_ordenar_nome_clicked();

    void on_botao_ordenar_idade_clicked();

    void on_botao_ordenar_peso_clicked();

    void on_botao_ordenar_distancia_clicked();

    void on_botao_ordenar_tempo_clicked();

    void on_botao_ordenar_velocidade_clicked();

    void on_botao_ordenar_calorias_clicked();

    void on_Carregar_triggered();

    void on_Salvar_triggered();

    void on_tabela_cellDoubleClicked(int row, int column);

    void on_botao_limpar_tabela_clicked();

private:
    Ui::MainWindow *ui;
    ciclista atleta;
    percursos meu_pelotao;
};
#endif // MAINWINDOW_H
