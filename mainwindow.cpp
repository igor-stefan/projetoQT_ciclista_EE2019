#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->Salvar, SIGNAL(triggered()), this, SLOT(Salvar()));
    connect (ui->Carregar, SIGNAL(triggered()), this, SLOT(Carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inserir_Ciclista_tabela(int linha, ciclista x)
{
    QString mystr;
    ui->tabela->insertRow(linha);
    ui->tabela->setItem(linha,0,new QTableWidgetItem(x.getNome()));
    ui->tabela->setItem(linha,1,new QTableWidgetItem(QString::number(x.getIdade())));
    mystr=QString::number(x.getPeso(),'f',2) + " Kg";
    ui->tabela->setItem(linha,2,new QTableWidgetItem(mystr));
    mystr=QString::number(x.getDistancia(),'f',2) + " Km";
    ui->tabela->setItem(linha,3,new QTableWidgetItem(mystr));
    mystr=QString::number(x.getTempo(),'f',2) + " min";
    ui->tabela->setItem(linha,4,new QTableWidgetItem(mystr));
    mystr=QString::number(x.getDistancia()/x.getTempo(),'f',2)+" Km/min";
    ui->tabela->setItem(linha,5,new QTableWidgetItem(mystr));
    mystr=QString::number(x.getPeso()*x.getTempo()*0.133,'f',2)+" Cal";
    ui->tabela->setItem(linha,6,new QTableWidgetItem(mystr));
    for(int i=0;i<7;i++){
         ui->tabela->item(linha,i)->setTextAlignment(Qt::AlignCenter);
    }
    ui->tabela->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void MainWindow::atualizarTabela()
{
    for(int i=ui->tabela->rowCount()-1;i>=0;i--){
        ui->tabela->removeRow(i);
    }
    for(int j=0;j<meu_pelotao.size();j++){
        inserir_Ciclista_tabela(j,meu_pelotao[j]);
    }
}

void MainWindow::printar_labels()
{
    ui->label_dp_distancia->setText(QString::number(meu_pelotao.calcular_desvioP_distancia(),'f',3));
    ui->label_dp_tempo->setText(QString::number(meu_pelotao.calcular_desvioP_tempo(),'f',3));
    ui->label_dp_velocidade->setText(QString::number(meu_pelotao.calcular_desvioP_velocidade(),'f',3));
    ui->label_med_distancia->setText(QString::number(meu_pelotao.calcular_media_distancia(),'f',3));
    ui->label_med_tempo->setText(QString::number(meu_pelotao.calcular_media_tempo(),'f',3));
    ui->label_med_velocidade->setText(QString::number(meu_pelotao.calcular_media_velocidade(),'f',3));
    ui->label_maior_distancia->setText(meu_pelotao.quem_maior_distancia());
    ui->label_menor_tempo_gasto->setText(meu_pelotao.quem_menor_tempo());
    ui->label_mais_veloz->setText(meu_pelotao.quem_maior_velocidade());

}

void MainWindow::set_label_default()
{
    ui->label_dp_distancia->setText("0.0");
    ui->label_dp_tempo->setText("0.0");
    ui->label_dp_velocidade->setText("0.0");
    ui->label_med_distancia->setText("0.0");
    ui->label_med_tempo->setText("0.0");
    ui->label_med_velocidade->setText("0.0");
    ui->label_maior_distancia->setText("X");
    ui->label_menor_tempo_gasto->setText("X");
    ui->label_mais_veloz->setText("X");
}

void MainWindow::on_botao_adicionar_clicked()
{
    if(!(ui->lineEdit_nome->text().isEmpty()||ui->lineEdit_idade->text().isEmpty()||ui->lineEdit_peso->text().isEmpty()||
         ui->lineEdit_tempo->text().isEmpty()||ui->lineEdit_distancia->text().isEmpty())){
       if(No_alpha(ui->lineEdit_idade->text()) && No_alpha(ui->lineEdit_peso->text()) &&
                No_alpha(ui->lineEdit_tempo->text()) && No_alpha(ui->lineEdit_distancia->text())){
      atleta.setNome(ui->lineEdit_nome->text());
      atleta.setIdade(ui->lineEdit_idade->text().toInt());
      atleta.setPeso(ui->lineEdit_peso->text().toDouble());
      atleta.setDistancia(ui->lineEdit_distancia->text().toDouble());
      atleta.setTempo(ui->lineEdit_tempo->text().toDouble());

      for(int i=0;i<meu_pelotao.size();i++){
          if(atleta.getNome()==meu_pelotao[i].getNome()){
              ui->lineEdit_nome->clear(); //limpa os line edits
              ui->lineEdit_peso->clear();
              ui->lineEdit_idade->clear();
              ui->lineEdit_distancia->clear();
              ui->lineEdit_tempo->clear();
              atleta.clear();
          }
      }

      ui->lineEdit_nome->clear(); //limpa os line edits
      ui->lineEdit_peso->clear();
      ui->lineEdit_idade->clear();
      ui->lineEdit_distancia->clear();
      ui->lineEdit_tempo->clear();

    if(!(atleta.getNome().isEmpty() || QString::number(atleta.getIdade()).isEmpty() ||
         QString::number(atleta.getPeso()).isEmpty() || QString::number(atleta.getDistancia()).isEmpty())
         || QString::number(atleta.getTempo()).isEmpty()){
        meu_pelotao.cadastrar_no_pelotao(atleta);
        printar_labels();
        inserir_Ciclista_tabela(ui->tabela->rowCount(),atleta);
}
       }else{
           ui->lineEdit_nome->clear(); //limpa os line edits
           ui->lineEdit_peso->clear();
           ui->lineEdit_idade->clear();
           ui->lineEdit_distancia->clear();
           ui->lineEdit_tempo->clear();
       }//if tudo ok com os lineEdits
    }//if slot nao vazio
}//botao adicionar
void MainWindow::on_botao_ordenar_nome_clicked()
{
    meu_pelotao.ordenar_por_nome();
    atualizarTabela();
}


void MainWindow::on_botao_ordenar_idade_clicked()
{
    meu_pelotao.ordenar_por_idade();
    atualizarTabela();
}

void MainWindow::on_botao_ordenar_peso_clicked()
{
    meu_pelotao.ordenar_por_peso();
    atualizarTabela();
}

void MainWindow::on_botao_ordenar_distancia_clicked()
{
    meu_pelotao.ordenar_por_distancia();
    atualizarTabela();
}

void MainWindow::on_botao_ordenar_tempo_clicked()
{
    meu_pelotao.ordenar_por_tempo();
    atualizarTabela();
}

void MainWindow::on_botao_ordenar_velocidade_clicked()
{
    meu_pelotao.ordenar_por_velocidade();
    atualizarTabela();
}

void MainWindow::on_botao_ordenar_calorias_clicked()
{
    meu_pelotao.ordenar_por_gasto_energetico();
    atualizarTabela();
}

void MainWindow::on_Carregar_triggered()
{

    QString archive = QFileDialog::getOpenFileName(this,"Pelotao","","CSV(*.csv)");
    meu_pelotao.clearPelotao();
    set_label_default();
    meu_pelotao.carregarPelotao(archive);

    for(int i=0;i<meu_pelotao.size();i++)
    {
    atleta.setNome(meu_pelotao[i].getNome());
    atleta.setIdade(meu_pelotao[i].getIdade());
    atleta.setPeso(meu_pelotao[i].getPeso());
    atleta.setDistancia(meu_pelotao[i].getDistancia());
    atleta.setTempo(meu_pelotao[i].getTempo());
    atleta.setVelocidade_media(meu_pelotao[i].getDistancia()/meu_pelotao[i].getTempo());
    atleta.setGasto_energetico(meu_pelotao[i].getPeso()*0.133*meu_pelotao[i].getTempo());
    inserir_Ciclista_tabela(ui->tabela->rowCount(),meu_pelotao[i]);
    atualizarTabela();
    printar_labels();
    }
}

void MainWindow::on_Salvar_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Pelotao","","CSV(*.csv)");
    meu_pelotao.salvarPelotao(nomeArquivo);

}

void MainWindow::on_tabela_cellDoubleClicked(int row, int column)
{
    ciclista temporario;
    if(column==0){
        bool ok;
        QMessageBox::StandardButton editar = QMessageBox::question(this, "Editar: ", "Alterar nome?");
        if(editar==QMessageBox::Yes){
            QString inputstr = QInputDialog::getText(this, "Alterar nome: ", "Nome: ", QLineEdit::Normal,"",&ok);
            if(ok && !inputstr.isEmpty()){
             temporario.setNome(inputstr);
             temporario.setIdade(meu_pelotao[row].getIdade());
             temporario.setPeso(meu_pelotao[row].getPeso());
             temporario.setDistancia(meu_pelotao[row].getDistancia());
             temporario.setTempo(meu_pelotao[row].getTempo());
             temporario.setVelocidade_media(meu_pelotao[row].getDistancia()/meu_pelotao[row].getTempo());
             temporario.setGasto_energetico(meu_pelotao[row].getPeso()*0.133*meu_pelotao[row].getTempo());

            meu_pelotao.erase(temporario);
            meu_pelotao.cadastrar_no_pelotao(temporario);
            ui->tabela->setItem(row,0,new QTableWidgetItem(temporario.getNome()));
            ui->tabela->item(row,0)->setTextAlignment(Qt::AlignCenter);
            printar_labels();
            atualizarTabela();
            }
        }else{
            atualizarTabela();
            }
    }
      else if(column==1){
        bool ok;
        QMessageBox::StandardButton editar = QMessageBox::question(this, "Editar: ", "Alterar Idade?");
        if(editar==QMessageBox::Yes){
            QString inputstr = QInputDialog::getText(this, "Alterar Idade: ", "Idade: ", QLineEdit::Normal,"",&ok);
            if(ok && !inputstr.isEmpty()){
             temporario.setNome(meu_pelotao[row].getNome());
             temporario.setIdade(inputstr.toInt());
             temporario.setPeso(meu_pelotao[row].getPeso());
             temporario.setDistancia(meu_pelotao[row].getDistancia());
             temporario.setTempo(meu_pelotao[row].getTempo());
             temporario.setVelocidade_media(meu_pelotao[row].getDistancia()/meu_pelotao[row].getTempo());
             temporario.setGasto_energetico(meu_pelotao[row].getPeso()*0.133*meu_pelotao[row].getTempo());

            meu_pelotao.erase(temporario);
            meu_pelotao.cadastrar_no_pelotao(temporario);
            ui->tabela->setItem(row,1,new QTableWidgetItem(QString::number(temporario.getIdade())));
            ui->tabela->item(row,1)->setTextAlignment(Qt::AlignCenter);
            printar_labels();
            atualizarTabela();
            }//se nao ta vazio
        }else{
            atualizarTabela();
              }
    }//se for coluna 1
          else if(column==2){
                bool ok;
                QMessageBox::StandardButton editar = QMessageBox::question(this, "Editar: ", "Alterar Peso?");
                if(editar==QMessageBox::Yes){
                    QString mystr, inputstr = QInputDialog::getText(this, "Alterar Peso: ", "Peso: ", QLineEdit::Normal,"",&ok);
                    if(ok && !inputstr.isEmpty()){
                     temporario.setNome(meu_pelotao[row].getNome());
                     temporario.setPeso(inputstr.toDouble());
                     temporario.setIdade(meu_pelotao[row].getIdade());
                     temporario.setDistancia(meu_pelotao[row].getDistancia());
                     temporario.setTempo(meu_pelotao[row].getTempo());
                     temporario.setVelocidade_media(meu_pelotao[row].getDistancia()/meu_pelotao[row].getTempo());
                     temporario.setGasto_energetico(meu_pelotao[row].getPeso()*0.133*meu_pelotao[row].getTempo());

                    meu_pelotao.erase(temporario);
                    meu_pelotao.cadastrar_no_pelotao(temporario);
                    mystr=QString::number(temporario.getPeso(),'f',2) + " Kg";
                    ui->tabela->setItem(row,2,new QTableWidgetItem(mystr));
                    ui->tabela->item(row,3)->setTextAlignment(Qt::AlignCenter);
                    printar_labels();
                    atualizarTabela();
                    }
         }else{
                atualizarTabela();
              }
            }
    else if(column==3){
          bool ok;
          QMessageBox::StandardButton editar = QMessageBox::question(this, "Editar: ", "Alterar Distancia?");
          if(editar==QMessageBox::Yes){
              QString mystr, inputstr = QInputDialog::getText(this, "Alterar Distancia: ", "Distancia: ", QLineEdit::Normal,"",&ok);
              if(ok && !inputstr.isEmpty()){
                 temporario.setNome(meu_pelotao[row].getNome());
                 temporario.setIdade(meu_pelotao[row].getIdade());
                 temporario.setPeso(meu_pelotao[row].getPeso());
                 temporario.setDistancia(inputstr.toDouble());
                 temporario.setTempo(meu_pelotao[row].getTempo());
                 temporario.setVelocidade_media(meu_pelotao[row].getDistancia()/meu_pelotao[row].getTempo());
                 temporario.setGasto_energetico(meu_pelotao[row].getPeso()*0.133*meu_pelotao[row].getTempo());

              meu_pelotao.erase(temporario);
              meu_pelotao.cadastrar_no_pelotao(temporario);
              mystr=QString::number(temporario.getDistancia(),'f',2) + " Km";
              ui->tabela->setItem(row,3,new QTableWidgetItem(mystr));
              ui->tabela->item(row,3)->setTextAlignment(Qt::AlignCenter);
              printar_labels();
              atualizarTabela();
              }
   }else{
        atualizarTabela();
        }
      }
        else if(column==4){
        bool ok;
        QMessageBox::StandardButton editar = QMessageBox::question(this, "Editar: ", "Alterar Tempo?");
        if(editar==QMessageBox::Yes){
            QString mystr, inputstr = QInputDialog::getText(this, "Alterar Tempo: ", "Tempo: ", QLineEdit::Normal,"",&ok);
            if(ok && !inputstr.isEmpty()){
                temporario.setNome(meu_pelotao[row].getNome());
                temporario.setIdade(meu_pelotao[row].getIdade());
                temporario.setPeso(meu_pelotao[row].getPeso());
                temporario.setDistancia(meu_pelotao[row].getDistancia());
                temporario.setTempo(inputstr.toDouble());
                temporario.setVelocidade_media(meu_pelotao[row].getDistancia()/meu_pelotao[row].getTempo());
                temporario.setGasto_energetico(meu_pelotao[row].getPeso()*0.133*meu_pelotao[row].getTempo());

            meu_pelotao.erase(temporario);
            meu_pelotao.cadastrar_no_pelotao(temporario);
            mystr = QString::number(temporario.getTempo(),'f',2) + " min";
            ui->tabela->setItem(row,4,new QTableWidgetItem(mystr));
            ui->tabela->item(row,4)->setTextAlignment(Qt::AlignCenter);
            printar_labels();
            atualizarTabela();
            }
 }else{
            atualizarTabela();
            }
    }
}

void MainWindow::on_botao_limpar_tabela_clicked()
{
    QMessageBox::StandardButton limpar_tabela = QMessageBox::question(this, "", "Limpar a tabela? (Perderá todos os dados)");
    if(limpar_tabela==QMessageBox::Yes){
    for(int i=ui->tabela->rowCount()-1;i>=0;i--){
        ui->tabela->removeRow(i);
    }
    meu_pelotao.clearPelotao();
    set_label_default();
    }else{
        atualizarTabela();
    }
}

