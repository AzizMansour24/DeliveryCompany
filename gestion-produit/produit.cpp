#include "produit.h"

bool produit::ajouter(){


    QSqlQuery query;
    QString res=QString::number(ref);//convert id into a qstring res
    QString res2=QString::number(quantite);
    QString res3=QString::number(prix);
    query.prepare("INSERT INTO PRODUIT(ref,nom,categorie,quantite,fournisseur,prix) VALUES(:ref, :nom, :categorie, :quantite, :fournisseur , :prix)");  //preparation requete d insertion INSERT
    query.bindValue(":ref",res);
    query.bindValue(":nom",nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":quantite",res2);
    query.bindValue(":fournisseur",fournisseur);
    query.bindValue(":prix",res3);
    return query.exec();

}
bool produit::supprimer(int ref){
    if (ref==0||quantite==0) {

            return false;
        }
    if(rechercher(ref)==true){
    QSqlQuery query;
    QString res=QString::number(ref);
    query.prepare("Delete from produit where ref= :ref"); //requete de supression DELETE , WHERE: recherche de l emplacement
    query.bindValue(":ref",res);
    return query.exec();
    }
    else
        return false;

}
QSqlQueryModel *produit::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produit");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
    return model;
}
bool produit::modifier(int ref,int ref2,float ref3){
    if(ref==0||ref2==0||ref3==0)
        return false;
    if(rechercher(ref)==true){
    QSqlQuery query;
    QString res=QString::number(ref);
    QString res2=QString::number(ref2);
    QString res3=QString::number(ref3);
    query.prepare("Update produit SET quantite= :quantite ,prix= :prix where ref= :ref");
    query.bindValue(":ref",res);
    query.bindValue(":quantite",res2);
    query.bindValue(":prix",res3);
    return query.exec();}
    else
        return false;
}
bool produit::rechercher(int ref) {
    QSqlQuery query;
    QString res = QString::number(ref);
    query.prepare("SELECT ref FROM produit WHERE ref = :ref");
    query.bindValue(":ref", res);

    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}
QSqlQueryModel *produit::chercher2(int ref){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
     QString res = QString::number(ref);
    query.prepare("SELECT * FROM produit WHERE REF= :REF");
    query.bindValue(":REF",res);
    query.exec();
    model->setQuery(query);
    return model;
}
bool produit::rechercherfournisseur(QString res) {
    QSqlQuery query;
    query.prepare("SELECT ID FROM fournisseur WHERE ID = :res");
    query.bindValue(":ID", res);

    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}
bool produit::appliquer_remise(int ref, float r) {
    QSqlQuery query;
    QString res = QString::number(ref);
    query.prepare("SELECT prix FROM produit WHERE ref = :ref");
    query.bindValue(":ref", res);
    if (query.exec() && query.next()) {
        double prix1 = query.value("prix").toDouble();
        double nouvprix = prix1 - (prix1 * r / 100.0);
        query.prepare("UPDATE produit SET prix = :prix WHERE ref = :ref");
        query.bindValue(":ref", res);
        query.bindValue(":prix", nouvprix);
    }
        if (query.exec()) {
            return true;
        }
        else{

    return false; }
}
QSqlQueryModel* produit::sortNOM()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
        return model;
}
QSqlQueryModel* produit::sortQUANTITE()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT ORDER BY QUANTITE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
        return model;
}
QSqlQueryModel* produit::sortPRIX(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT ORDER BY PRIX ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
        return model;
}
float produit::calculer_estimation(int ref){
    QSqlQuery query;
    QString res = QString::number(ref);
    query.prepare("SELECT prix,quantite FROM produit WHERE ref = :ref");
    query.bindValue(":ref", res);
    float e=-1;
    float p=query.value("prix").toFloat();
    int q=query.value("quantite").toInt();
    if (query.exec() && query.next()) {
        e=p*q;
    }
    return -1;
}
bool produit::rechercherclient(QString res) {
    QSqlQuery query;
    query.prepare("SELECT CIN FROM client WHERE CIN = :res");
    query.bindValue(":res", res);

    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}
