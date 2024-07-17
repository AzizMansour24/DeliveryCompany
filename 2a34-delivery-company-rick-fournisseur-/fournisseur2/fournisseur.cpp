#include "fournisseur.h"
#include <qsqlquery.h>
#include <QtDebug>

Fournisseur::Fournisseur(int id_four ,QString nom,QString adresse,int note,QString produit,long Tel,QString Email)
    {
     this->nom = nom;
     this->id_four = id_four;
     this->produit = produit;
     this->adresse = adresse;
     this->Email = Email;
     this->note = 0;
     this->Tel = Tel;
}

Fournisseur::Fournisseur(){
    this->nom = "";
    this->id_four = 0;
    this->produit = "";
    this->adresse = "";
    this->Email = "";
    this->note = 0;
    this->Tel = 0;
}

    /*Setters*/
    void Fournisseur::setName(QString n){ this->nom = n;}
    void Fournisseur::setID(int id_four){this->id_four = id_four;}
    void Fournisseur::setProduit (QString prd){this->produit = prd;}
    void Fournisseur::setNote(int nte){this->note = nte;}
    void Fournisseur::setTel(long numT){this->Tel = numT;}
    void Fournisseur::setAddress(QString address){this->adresse = adresse;}
    void Fournisseur::setEmail(QString EMail){this->Email = Email;}
    /*Getters*/
    int Fournisseur::getNote(){return this->note;}
    long Fournisseur::getTel(){return this->Tel;}
    int Fournisseur::getID(){return this->id_four;}
    QString Fournisseur::getName(){return this->nom;}
    QString Fournisseur::getProduit(){return this->produit;}
    QString Fournisseur::getAddress(){return this->adresse;}
    QString Fournisseur::getEmail(){return this->Email;}
    /**/

    /*Key functions*/

    bool Fournisseur::addFournisseur()
    {
        QSqlQuery query;


        QString id_string = QString::number(id_four);
        QString Tel_string =  QString::number(Tel);
        query.prepare("INSERT INTO FOURNISSEUR (ID,NOM,ADRESSE,NOTE,PRODUIT,TELEPHONE,EMAIL)"
                      "VALUES(:id_four,:nom,:address,:note,:produit,:tel,:email)");
        query.bindValue(":id_four",id_string);
        query.bindValue(":nom",nom);
        query.bindValue(":address",note);
        query.bindValue(":note",adresse);
        query.bindValue(":produit",produit);
        query.bindValue(":tel",Tel_string); //numero de telephone convertee a long
        query.bindValue(":email",Email);
        return query.exec();
     }

bool Fournisseur::deleteFournisseur(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Delete from fournisseur ID= :id ");
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Fournisseur::readFournisseur()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from Fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRODUIT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("EMAIL"));

    return model;
}














