#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
#include "smtp.h"

class Employee {
private:
    QString nom, prenom;
    int cin;
    QString poste;
    int numero_de_tel;
    QString adresse_email;
    QString mot_de_passe;

public:
    //constructers
    Employee();
    Employee(int cin, QString nom, QString prenom,  QString poste, int numero_de_tel, QString adresse_email);
    //getters
    int getcin();
    QString getnom();
    QString getprenom();
    QString genererMotDePasseAleatoire();
    int getnumtel();
    QString getadresseemail();
    QString getPoste() const;
    //setters
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setPoste(const QString& poste);
    QString getRFID() const;

    void setnumtel(int);
    void setadresseemail(QString);

    QString getStoredPassword(const QString& identifiant);

    //fonctionalités de base relatives
    bool numeroDeTelephoneExiste(int numero_de_tel);
    bool adresseEmailExiste(const QString& adresse_email);
    bool ajouter();

    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool cinExiste(int cin);
    bool modifier(const QString& champ, const QString& nouvelleValeur, int cin);
   bool rechercherParRFID(const QString& rfid);
    void sendEmail(QSslSocket& socket, const QString& command, const QString& expectedResponse);
private:
       QString RFID;
    void envoyerEmail(const QString& destinataire, const QString& sujet, const QString& corps);
};

#endif // EMPLOYEE_H
