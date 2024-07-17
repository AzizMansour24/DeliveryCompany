#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"produit.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supp_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_rech_clicked();
    void on_pushButton_rech2_clicked();
    void on_pushButton_remise_clicked();
    void on_pushButton_stats_clicked();
    void on_pushButton_trie_clicked();
    void on_pushButton_triQ_clicked();
    void on_pushButton_triP_clicked();
    void on_pushButtonPDF_clicked();
    void on_pushButton_cal_clicked();
    void on_pushButton_rechcin_clicked();

private:
    Ui::MainWindow *ui;
    produit Etmp;
    QByteArray data;
    Arduino A;

};
#endif // MAINWINDOW_H
