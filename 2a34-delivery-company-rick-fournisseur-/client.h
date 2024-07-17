#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QDebug>


class Client
{
public:
    Client();
    Client(int,QString,QString,int,int,QString,QString);
    Client(QString,QString,int,int,QString,QString);
    int getcin();

    QString getnom();
    QString getprenom();
    int getnumtel();
    int getage();
    QString getadresse();
    QString getemail();

   /* QString getnom(int cin);
       QString getprenom(int cin);
       int getnumtel(int cin);
       int getage(int cin);
       QString getadresse(int cin);
       QString getemail(int cin);
       */
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setnumtel(int);
    void setage(int);
    void setadresse(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);


private:
    int cin,numtel,age;
    QString nom, prenom, adresse, email;


};

#endif // CLIENT_H
