
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_client->setModel(Ctmp.afficher());
    /*
    ui->le_numtel->setValidator(new QIntValidator(99999999,99999999,this));
    ui->le_cin->setValidator(new QIntValidator(99999999,99999999,this));
    ui->le_age->setValidator(new QIntValidator(9,99,this));
    */
    //ui->tab_2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numtel=ui->le_numtel->text().toInt();
    int age=ui->le_age->text().toInt();
    QString adresse=ui->le_adresse->text();
    QString email=ui->le_email->text();

    Client C(cin,nom,prenom,numtel,age,adresse,email);

    bool test=C.ajouter();
    if(test)
    {
        //ui->tab_client->setModel(Ctmp.afficher());
        {QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tab_client->setModel(Ctmp.afficher());
        }
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_supprimer_clicked()
{
    int cin_2=ui->le_cin_2->text().toInt();
    bool test=Ctmp.supprimer(cin_2);

    if(test)
    {
        //ui->tab_client->setModel(Ctmp.afficher());
        {QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_client->setModel(Ctmp.afficher());
        }
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression non effectuée\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_modifier_clicked()
{

    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numtel=ui->le_numtel->text().toInt();
    int age=ui->le_age->text().toInt();
    QString adresse=ui->le_adresse->text();
    QString email=ui->le_email->text();


    Client C(cin,nom,prenom,numtel,age,adresse,email);

    bool test=C.modifier(cin);

    if(test)
    {            ui->tab_client->setModel(Ctmp.afficher());

        {QMessageBox::information(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

