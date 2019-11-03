#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LDE.h"
#include "LES.h"
#include "arvore.h"
#include "heap.h"
#include "fila.h"
#include <string>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
/*
 * MSShinzato - Aluno: Marcelo Shinji Shinzato RA: 22.118.013-6
 * Projeto27 - Aluno: Lucas Souza Valverde RA: 22.118.125-8
 * Kaike-R - Aluno: Kaike RA:22.118.116-7
 *
 * Os botões que seriam para abrir os arquivos não estão funcionando
 * Porém as informações estão sendo salvas nos arquivos
*/
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxTam->addItem("P");
    ui->comboBoxTam->addItem("M");
    ui->comboBoxTam->addItem("G");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSalvar_clicked()
{
    QMessageBox::information(this,"Inserção","Produto: "+ui->txtProduto->text()
                             +"\n"+"Preço: "+ui->txtPreco->text()+"\n"
                             +"Quantidade: "+ui->txtQuant->text()
                             +"\n"+"Tamanho: "+ui->comboBoxTam->currentText());
    ArvBin<int> arv;
    arv.Insere(ui->txtPrio->text().toInt(),ui->txtQuant->text().toInt(),ui->txtPreco->text().toFloat(),ui->txtProduto->text().toStdString(),ui->comboBoxTam->currentText().toStdString());
    arv.imprime();
}
void MainWindow::on_btnImprime_clicked()
{
    /*local_arquivo="";
    QString filtro = "Abrir todos arquivos(*.*) ;; Arquivos de texto(*.txt)";
    QString nome_arquivo=QFileDialog::getOpenFileName(this,"Abrir",QDir::homePath(),filtro);
    QFile arq(nome_arquivo);
    local_arquivo=nome_arquivo;
    if(!arq.open(QFile::ReadOnly)|QFile::Text){
        QMessageBox::warning(this,"Erro","Não foi possível abrir este arquivo...");
        return;
    }
    QTextStream entrada(&arq);
    QString texto = entrada.readAll();
    ui->txtAreaForn->setText(texto);
    arq.close();*/
    ArvBin<int> arv;
    arv.Ler_arquivo();
}

void MainWindow::on_btnSalvarForn_clicked()
{
    LES le(50);
    le.Insere(ui->txtForn->text().toStdString());
    QMessageBox::information(this,"Inserção","Fornecedor: "+ui->txtForn->text());
    le.Salva();
}

void MainWindow::on_btnImprime_2_clicked()
{
    /*QString filtro = "Abrir todos arquivos(*.*) ;; Arquivos de texto(*.txt)";
    QString nome_arquivo=QFileDialog::getOpenFileName(this,"Abrir",QDir::homePath(),filtro);
    QFile arq(nome_arquivo);
    local_arquivo=nome_arquivo;
    if(!arq.open(QFile::ReadOnly)|QFile::Text){
        QMessageBox::warning(this,"Erro","Não foi possível abrir este arquivo...");
        return;
    }
    QTextStream entrada(&arq);
    QString texto = entrada.readAll();
    ui->txtAreaForn->setText(texto);
    arq.close();*/
    LES le(50);
    le.Ler_arquivo();
}

void MainWindow::on_btnBuscaFunc_clicked()
{

}

void MainWindow::on_btnRemover_clicked()
{
    ArvBin<int> arv;
    arv.recebeNome(ui->txtRemPrio->text().toInt(),ui->txtRemove->text().toStdString());
    QMessageBox::information(this,"Remoção","Produto removido com sucesso! :D");
    arv.imprime();
}

void MainWindow::on_btnSalvarFunc_clicked()
{
    LDE<int> l;
    l.Insere(ui->txtFunc_3->text().toStdString(),ui->txtQuantFunc->text().toInt());
    l.Salvar();
}

void MainWindow::on_btnRemover_2_clicked()
{
    LDE<int> l;
    l.Remove(ui->txtFuncDemonio->text().toStdString());
    QMessageBox::information(this,"Remoção","Funcionário removido com sucesso! :D");
    l.Salvar();
}

void MainWindow::on_btnRemForn_clicked()
{
    LES le(50);
    le.Remove(ui->txtRemForn->text().toStdString());
    le.Salva();
}

void MainWindow::on_btnBusca_clicked()
{

}

void MainWindow::on_btnInsMes_clicked()
{
    Fila f(12);
    f.Enfileira(ui->txtFuncMes->text().toStdString());
    f.Imprime();
}

void MainWindow::on_btnRemMes_clicked()
{
    Fila f(12);
    f.Desenfileira();
    f.Imprime();
}

void MainWindow::on_btnMostrar_clicked()
{
    Fila f(12);
    f.Imprime();
}

void MainWindow::on_btnAlterar_clicked()
{
    LDE<int> l;
    l.Altera(ui->txtFuncDemonio->text().toStdString(),ui->txtDemonio->text().toInt());
    QMessageBox::information(this,"Alteração","Funcionário alterado com sucesso! :D");
    l.Imprime();
    l.Salvar();
    /*
     *
     *      O método altera não está alterando no arquivo de demonio.txt
     *      Testamos no Dev e alterou na LDE, mas no Qt Creator o demonio.txt não quis alterar
     *
    */
}

void MainWindow::on_btnAtualizaFunc_clicked()
{
    LDE<int> l;
    l.Ler_arquivo();
}
