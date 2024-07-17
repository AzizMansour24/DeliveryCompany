#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QSqlTableModel>
#include <QSqlError>

Client::Client()
{

}


Client::Client( int cin, QString nom,QString prenom, int numtel,int age,QString adresse,QString email)







{this->cin=cin;this->nom=nom; this->prenom=prenom; this->numtel=numtel;  this->age=age; this->adresse=adresse; this->email=email;}
int Client::getcin(){return cin;}
/*
QString Client::getnom(){return nom;}
QString Client::getprenom(){return prenom;}
int Client::getnumtel(){return numtel;}
int Client::getage(){return age;}
QString Client::getadresse(){return adresse;}
QString Client::getemail(){return email;}

void Client::setcin(int cin){this->cin=cin;}
void Client::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
void Client::setnumtel(int numtel){this->numtel=numtel;}
void Client::setage(int age){this->age=age;}
void Client::setadresse(QString adresse){this->adresse=adresse;}
void Client::setemail(QString email){this->email=email;}
*/


bool Client::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (cin,nom, prenom, numtel,  age, adresse, email) "
                  "VALUES (:cin,:nom, :prenom, :numtel,  :age, :adresse, :email)");
    QString numtel_string=QString::number(numtel);
    QString cin_string=QString::number(cin);
    QString age_string=QString::number(age);

          query.bindValue(":cin", cin);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":numtel", numtel);
          query.bindValue(":age", age);
          query.bindValue(":adresse", adresse);
          query.bindValue(":email", email);
       return query.exec();

}


bool Client::supprimer(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("Delete from client where CIN= :cin");
    query.bindValue(0,cin);
    //query.bindValue(":cin",res);
    return query.exec();
}


QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    //QSqlTableModel * model=new QSqlTableModel();
    model->setQuery("SELECT * FROM client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Numtel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Email"));

    return model;
}


bool Client::modifier(int cin)
{
    QSqlQuery query;
    query.prepare("UPDATE client SET nom = :nom, prenom = :prenom, numtel = :numtel, age = :age, adresse = :adresse, email = :email WHERE CIN = :cin");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":numtel", numtel);
    query.bindValue(":age", age);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);

    return query.exec();
}


