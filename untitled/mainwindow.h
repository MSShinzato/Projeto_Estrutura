#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSalvar_clicked();

    void on_btnImprime_clicked();

    void on_btnSalvarForn_clicked();

    void on_btnImprime_2_clicked();

    void on_btnBuscaFunc_clicked();

    void on_btnRemover_clicked();

    void on_btnSalvarFunc_clicked();

    void on_btnRemover_2_clicked();

    void on_btnRemForn_clicked();

    void on_btnBusca_clicked();

    void on_btnInsMes_clicked();

    void on_btnRemMes_clicked();

    void on_btnMostrar_clicked();

    void on_btnAlterar_clicked();

    void on_btnAtualizaFunc_clicked();

private:
    Ui::MainWindow *ui;
    QString local_arquivo;
};
#endif // MAINWINDOW_H
