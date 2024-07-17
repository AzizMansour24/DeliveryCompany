#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QDate>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int id_four ,QString nom,QString adresse,int note,QString produit,long Tel,QString Email);

    /*Setters*/
    void setName(QString n);
    void setID(int id_four);
    void setProduit (QString prd);
    void setTel(long tel);
    void setNote(int nte);
    void setAddress(QString adresse);
    void setEmail(QString Email);

    /*Getters*/
    QString getName();
    QString getProduit();
    int getID();
    QString getAddress();
    QString getEmail();
    long getTel();
    int getNote();


    /*CRUD */
    bool addFournisseur();
    QSqlQueryModel *readFournisseur();
    bool updateFournisseur(const Fournisseur &f);
    bool deleteFournisseur(int id);

private:
    QVector <Fournisseur> fournisseurs;
    QString nom,adresse,produit,Email;
    int note,id_four;
    long Tel;


};
#endif // FOURNISSEUR_H
