#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LDE.h"
#include"Les.h"
#include"LDE.h"
#include"Arvore.h"
#include"Heap.h"
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
    les = new LES<string>(50);
    lde = new LDE<int>;
    arv = new ArvBin<int>;
    h = new Heap<int, 50>();
    ui->setupUi(this);
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
    arv->Insere(ui->txtValor->text().toInt(),ui->txtQuant->text().toInt(),ui->txtPreco->text().toFloat(),ui->txtProduto->text().toStdString());
    //h->insere();
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_btnSalvarForn_clicked()
{
    les->Insere(ui->txtForn->text().toStdString());
}

void MainWindow::on_btnRemForn_clicked()
{
    les->Remove(ui->txtRemForn->text().toStdString());
}

void MainWindow::on_SalvarFuncio_clicked()
{
    lde->Insere(ui->quatFuncio->text().toInt(),ui->nomeFuncio->text().toStdString());
}

void MainWindow::on_btnImprime_clicked()
{
     arv->ImprimeMenor(arv->raiz);
     QString r = QString::fromStdString(arv->getOut());
     ui->txtAreaProd->append(r);
     r =  QString::number(arv->getOut2());
     ui->txtAreaProd->append(r);
     r =  QString::number(arv->getOut3());
     ui->txtAreaProd->append(r);
     r =  QString::number(arv->getOut4());
     ui->txtAreaProd->append(r);
}

void MainWindow::on_remFuncio_clicked()
{
    lde->Altera(ui->txtRemFuncio->text().toStdString(),2,0);
}

void MainWindow::on_btnBusca_clicked()

{
    arv->Busca(ui->txtBusca->text().toInt());
    QString s = QString::fromStdString(arv->getOut());
    ui->textBrowser->append(s);
    s =  QString::number(arv->getOut2());
    ui->textBrowser->append(s);
    s =  QString::number(arv->getOut3());
    ui->textBrowser->append(s);

}

void MainWindow::on_btnRemover_clicked()
{
    arv->Remove(ui->txtRemove->text().toInt());
}

void MainWindow::on_AltFuncio_clicked()
{
    lde->Altera(ui->txtRemFuncio->text().toStdString(),1,ui->altFuncio->text().toInt());
}


void MainWindow::on_pushButton_2_clicked()
{
    arv->Altera(arv->raiz,ui->txtAltNome->text().toStdString());
}

void MainWindow::on_btnImprime_2_clicked()
{

    QString s;
    for (int i = 0; i < les->getN(); i++) {
        s =  QString::fromStdString(les->getV(i));
        ui->txtAreaForn->append(s);
    }

}

void MainWindow::on_btnImprime_3_clicked()
{
    QString t;
    QString u;
    lde->Imprime();
    for(int i=0;i < lde->getN();i++){
       t =  QString::fromStdString(lde->getX(i));
       u =  QString::number(lde->getY(i));
       ui->txtAreaFuncio->append(t);
       ui->txtAreaFuncio->append(u);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    les->Salva();
    lde->Salvar();
    ui->txtConf->append("Salvo");
}

void MainWindow::on_altFuncio_clicked()
{
    lde->Altera(ui->txtRemFuncio->text().toStdString(),1,ui->altFuncio->text().toInt());
}


