#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QDebug>
#include <QSqlTableModel>
#include <QStringList>

class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,int,QString,QString);

    QString getcin();
    QString getnom();
    QString getprenom();
    QString getnumtel();
    int getannee();
    QString getadresse();
    QString getemail();
    int getpoints_bonus();
    void setcin(QString);
    void setnom(QString);
    void setprenom(QString);
    void setnumtel(QString);
    void setannee(int);
    void setadresse(QString);
    void setemail(QString);
    void setpoints_bonus(int);

    QString ajouter();

    QSqlQueryModel* afficher();

    //QSqlTableModel* afficher();


    bool supprimer(QString);

    bool retrieveClient (QString);

    bool modifier(QString);

    QSqlQueryModel *rechercherClient(const QString &searchValue);

    void exportToCSV(const QString &filePath);


QSqlQueryModel* trierAdressesParOrdreCroissant();

QSqlQueryModel* trierAdressesParOrdreDecroissant();

QSqlQueryModel* trierNomsParOrdreCroissant();

QSqlQueryModel* trierNomsParOrdreDecroissant();

QSqlQueryModel* trierPrenomsParOrdreCroissant();

QSqlQueryModel* trierPrenomsParOrdreDecroissant();

QSqlQueryModel* trierAnneesParOrdreCroissant();

QSqlQueryModel *trierAnneesParOrdreDecroissant();



private:
    int annee;
    QString cin,nom, prenom,numtel, adresse, email;

};

#endif // CLIENT_H
