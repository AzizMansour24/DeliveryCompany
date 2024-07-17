#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_le_btAdd_clicked()
{

    QString nom = ui->le_nom->text();
    int id_four = ui->le_id_four->text().toInt();
    long Tel = ui->le_Tel->text().toInt();
    QString produit = ui->le_produit->text();
    QString adresse = ui->le_adresse->text();
    QString Email = ui->le_email->text();
    int note = ui->le_note->text().toInt();


    Fournisseur f(id_four,nom,adresse,note,produit,Tel,Email);

    bool test=f.addFournisseur();

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK")
                     ,QObject::tr("Ajout effectué\n"
                                  "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Click Cancel to exit."),QMessageBox::Cancel);


}
