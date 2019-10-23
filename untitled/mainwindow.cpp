#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LDE.h"
#include <string>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    /*,int quant
,double preco
,string tam
,string nome*/
{
    ui->setupUi(this);
    ui->comboBoxTam->addItem("P");
    ui->comboBoxTam->addItem("M");
    ui->comboBoxTam->addItem("G");
    /*int quant;
    double preco;
    string tam;
    string nome;*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSalvar_clicked()
{
    /*nome = ui->txtProduto->text().toStdString();
    preco = ui->txtPreco->text().toDouble();
    quant = ui->txtQuant->text().toInt();
    tam = ui->comboBoxTam->currentText().toStdString();*/
    QMessageBox::information(this,"Inserção","Produto: "+ui->txtProduto->text()
                             +"\n"+"Preço: "+ui->txtPreco->text()+"\n"
                             +"Quantidade: "+ui->txtQuant->text()
                             +"\n"+"Tamanho: "+ui->comboBoxTam->currentText());
    LDE l;
    l.Insere(ui->txtProduto->text().toStdString(),
             ui->txtPreco->text().toDouble(),
             ui->comboBoxTam->currentText().toStdString(),
             ui->txtQuant->text().toInt());
    //ui->txtAreaProd->setText("Produto: " + ui->txtProduto->text()+"\n");
}
