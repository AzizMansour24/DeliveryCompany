#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class produit
{
    QString nom,fournisseur,categorie;
    int ref,quantite;
    float prix;
public:
    //CONSTRUCTEUR
    produit(){};
    produit(int r,QString n,QString c,int q,QString f,float p){ref=r;quantite=q;nom=n;fournisseur=f;categorie=c;prix=p;}
    //Accesseurs
    QString getNom(){return nom;}
    QString getFournissuer(){return fournisseur;}
    QString getCategorie(){return categorie;}
    int getRef(){return ref;}
    int getQuantite(){return quantite;}
    int getPrix(){return prix;}
    //mutateurs
    void setNom(QString n){nom=n;}
    void setFournisseur(QString f){fournisseur=f;}
    void setCategorie(QString n){categorie=n;}
    void setRef(int i){ref=i;}
    void setQuantite(int i){quantite=i;}
    void setPrix(float i){prix=i;}
    //CRUD
    bool ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int);
    bool modifier(int,int,float);
    bool rechercher(int ref);
    QSqlQueryModel* chercher2(int ref);
    bool rechercherfournisseur(QString res);
    bool appliquer_remise(int ref,float r);
    QSqlQueryModel* sortNOM();
    QSqlQueryModel* sortQUANTITE();
    QSqlQueryModel* sortPRIX();
    float calculer_estimation(int ref);
    bool rechercherclient(QString res);
};

#endif // PRODUIT_H
