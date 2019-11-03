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

    void on_pushButton_clicked();

    void on_btnSalvarForn_clicked();

    void on_btnRemForn_clicked();

    void on_SalvarFuncio_clicked();

    void on_remFuncio_clicked();

    void on_btnBusca_clicked();

    void on_btnRemover_clicked();

    void on_AltFuncio_clicked();

    void on_pushButton_2_clicked();

    void on_btnImprime_2_clicked();

    void on_btnImprime_3_clicked();

    void on_pushButton_3_clicked();

    void on_altFuncio_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
