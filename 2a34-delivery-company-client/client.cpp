#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QSqlTableModel>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include <QDate>


Client::Client()
{

}


Client::Client( QString cin, QString nom,QString prenom, QString numtel,int annee,QString adresse,QString email)

{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->numtel=numtel;
    this->annee=annee;
    this->adresse=adresse;
    this->email=email;
}

QString Client::getcin(){return cin;}

QString Client::getnom(){return nom;}

QString Client::getprenom(){return prenom;}

QString Client::getnumtel(){return numtel;}

int Client::getannee(){return annee;}

QString Client::getadresse(){return adresse;}

QString Client::getemail(){return email;}

void Client::setcin(QString cin){this->cin=cin;}

void Client::setnom(QString nom){this->nom=nom;}

void Client::setprenom(QString prenom){this->prenom=prenom;}

void Client::setnumtel(QString numtel){this->numtel=numtel;}

void Client::setannee(int annee){this->annee=annee;}

void Client::setadresse(QString adresse){this->adresse=adresse;}



QString Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (cin, nom, prenom, numtel, annee, adresse, email) "
                  "VALUES (:cin, :nom, :prenom, :numtel, :annee, :adresse, :email)");

    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":numtel", numtel);
    query.bindValue(":annee", annee);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);

    if (query.exec())
    {
        return "";
    }
    else
    {
        return query.lastError().text();
    }
}


bool Client::supprimer(QString cin)
{
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (query.exec())
    {
        int rowsAffected = query.numRowsAffected();
        return rowsAffected > 0;
    }
    else
    {
        return false;
    }
}


QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM client");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Numtel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Annee"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Email"));

    return model;
}



bool Client::modifier(QString cin)
{
    QSqlQuery query;
    query.prepare("UPDATE client SET nom = :nom, prenom = :prenom, numtel = :numtel, annee = :annee, adresse = :adresse, email = :email WHERE CIN = :cin");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":numtel", numtel);
    query.bindValue(":annee", annee);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);

    if (query.exec())
    {
        int rowsAffected = query.numRowsAffected();
        return rowsAffected > 0;
    }
    else
    {
        return false;
    }
}


bool Client::retrieveClient(QString cin)
{
    if (cin <= 0)
    {
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.first())
    {

        this->cin = query.value(0).toString();
        this->nom = query.value(1).toString();
        this->prenom = query.value(2).toString();
        this->numtel = query.value(3).toString();
        this->annee = query.value(4).toInt();
        this->adresse = query.value(5).toString();
        this->email = query.value(6).toString();

        return true;
    }
    else
    {
        return false;
    }
}


QSqlQueryModel *Client::rechercherClient(const QString &searchValue)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE cin LIKE :searchValue OR nom LIKE :searchValue OR prenom LIKE :searchValue OR numtel LIKE :searchValue OR annee LIKE :searchValue OR adresse LIKE :searchValue OR email LIKE :searchValue");
    query.bindValue(":searchValue", "%" + searchValue + "%");

    QSqlQueryModel *model = new QSqlQueryModel();
    if (query.exec())
    {
        model->setQuery(query);
        return model;
    }
    else
    {
        delete model;
        return nullptr;
    }
}



void Client::exportToCSV(const QString &filePath)
{
    QSqlQuery query;
    query.exec("SELECT cin, nom, prenom, numtel, annee, adresse, email FROM client");

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        out << "CIN;Nom;Prenom;Numtel;Annee;Adresse;Email\n"; // Use semicolon as separator

        while (query.next())
        {
            out << query.value(0).toString() << ";"
                << query.value(1).toString() << ";"
                << query.value(2).toString() << ";"
                << query.value(3).toString() << ";"
                << query.value(4).toString() << ";"
                << query.value(5).toString() << ";"
                << query.value(6).toString() << "\n";
        }

        file.close();
        qDebug() << "Export to CSV with semicolon separator succeeded!";
    }
    else
    {
        qDebug() << "Export to CSV failed!";
    }
}



QSqlQueryModel *Client::trierAdressesParOrdreCroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY adresse ASC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des adresses triées : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}



QSqlQueryModel *Client::trierAdressesParOrdreDecroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY adresse DESC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des adresses triées par ordre décroissant : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}




QSqlQueryModel *Client::trierNomsParOrdreCroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY nom ASC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des noms triés par ordre croissant : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}




QSqlQueryModel *Client::trierNomsParOrdreDecroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY nom DESC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des noms triés par ordre décroissant : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}



QSqlQueryModel *Client::trierPrenomsParOrdreCroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY prenom ASC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des prénoms triés par ordre croissant : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}



QSqlQueryModel *Client::trierPrenomsParOrdreDecroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY prenom DESC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des prénoms triés par ordre décroissant : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}



QSqlQueryModel *Client::trierAnneesParOrdreCroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM client ORDER BY annee ASC");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des annees triés par ordre croissant : " << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}


QSqlQueryModel *Client::trierAnneesParOrdreDecroissant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM client ORDER BY annee DESC");
    query.exec();
    model->setQuery(query);

    return model;
}






