#include <Employee.h>
#include <connection.h>
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlError>
#include <QString>
#include <QMessageBox>
#include <QSslConfiguration>



#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>

Employee::Employee() {
    cin = 0;
    prenom = " ";
    nom = " ";
    poste=" ";
    numero_de_tel = 0;
    adresse_email = " ";
    mot_de_passe = " ";
    RFID = " ";
}

Employee::Employee(int cin, QString nom, QString prenom, QString poste, int numero_de_tel, QString adresse_email) {
    this->cin = cin;
    this->nom = nom;
    this->prenom = prenom;
    this->poste = poste;
    this->adresse_email = adresse_email;
    this->numero_de_tel = numero_de_tel;
    this->mot_de_passe = genererMotDePasseAleatoire(); // Générer un mot de passe aléatoire lors de la création de l'employé
}

int Employee::getcin() { return cin; }
QString Employee::getnom() { return nom; }
QString Employee::getprenom() { return prenom; }
QString Employee::getPoste() const {
    return poste;
}
int Employee::getnumtel() { return numero_de_tel;}
QString Employee::getadresseemail() { return adresse_email;}

void Employee::setcin(int cin) { this->cin = cin;}
void Employee::setnom(QString nom) { this->nom = nom;}
void Employee::setprenom(QString prenom) { this->prenom = prenom;}
void Employee::setPoste(const QString& poste) {
    this->poste = poste;
}
QString Employee::getRFID() const {
        return RFID;  // Replace "RFID" with the actual member variable storing RFID in your class.
    }
void Employee::setnumtel(int numero_de_tel) { this->numero_de_tel = numero_de_tel;}
void Employee::setadresseemail(QString adresse_email) { this->adresse_email = adresse_email;}
bool Employee::numeroDeTelephoneExiste(int numero_de_tel) {
    QSqlQuery query;
    query.prepare("SELECT CIN FROM EMPLOYEES WHERE NUMERO = :numero_de_tel");
    query.bindValue(":numero_de_tel", numero_de_tel);

    if (query.exec()) {
        return query.next(); // Si une ligne est trouvée, le numéro de téléphone existe
    } else {
        // Gérer les erreurs de requête ici
        return false;
    }
}

bool Employee::adresseEmailExiste(const QString& adresse_email) {
    QSqlQuery query;
    query.prepare("SELECT CIN FROM EMPLOYEES WHERE ADRESSE = :adresse_email");
    query.bindValue(":adresse_email", adresse_email);

    if (query.exec()) {
        return query.next(); // Si une ligne est trouvée, l'adresse Gmail existe
    } else {
        // Gérer les erreurs de requête ici
        return false;
    }
}
QString Employee::genererMotDePasseAleatoire() {
    const QString caracteresPermis = "0123456789";
    QString motDePasseAleatoire;
    int longueurMotDePasse = 8;

    // Utilisez le chrono de haut niveau pour obtenir un moment en temps en millisecondes
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::mt19937 gen(seed); // Initialisez le générateur de nombres aléatoires avec la graine basée sur le temps

    std::uniform_int_distribution<int> distribution(0, caracteresPermis.length() - 1);

    for (int i = 0; i < longueurMotDePasse; ++i) {
        int index = distribution(gen);
        motDePasseAleatoire += caracteresPermis.at(index);
    }

    return motDePasseAleatoire;
}

bool Employee::ajouter() {
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString tel_string = QString::number(numero_de_tel);
    QString randomPassword = genererMotDePasseAleatoire();

    // Validation des données
    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || adresse_email.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Veuillez remplir tous les champs.");
        return false;
    }

    // Vérification d'unicité du numéro de téléphone
    if (numero_de_tel > 0 && numeroDeTelephoneExiste(numero_de_tel)) {
        // Le numéro de téléphone existe déjà, afficher un message d'erreur
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Le numéro de téléphone existe déjà.");
        return false;
    }

    // Vérification d'unicité de l'adresse Gmail
    if (!adresse_email.isEmpty() && adresseEmailExiste(adresse_email)) {
        // L'adresse Gmail existe déjà, afficher un message d'erreur
        QMessageBox::critical(nullptr, "Erreur d'ajout", "L'adresse Gmail existe déjà.");
        return false;
    }

    // Préparation de la requête
    query.prepare("INSERT INTO EMPLOYEES (CIN, NOM, PRENOM, POSTE, NUMERO, ADRESSE, MOT_DE_PASSE) "
                  "VALUES (:cin, :nom, :prenom, :poste, :numero_de_tel, :adresse_email, :mot_de_passe)");

    // Liaison des valeurs
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":numero_de_tel", tel_string);
    query.bindValue(":adresse_email", adresse_email);
    query.bindValue(":mot_de_passe", randomPassword);

    // Exécution de la requête
    if (!query.exec()) {
        // Gestion des erreurs
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Erreur lors de l'ajout de l'employé : " + query.lastError().text());
        return false;
    }

 /* // Envoi d'un e-mail à l'employé avec le mot de passe
    QString sujet = "Nouveau compte créé";
    QString corps = "Votre mot de passe est : " + randomPassword;
    envoyerEmail(adresse_email, sujet, corps);
*/


    return true;
}

bool Employee::supprimer(int cin) {
    QSqlQuery query;

    // Vérifier d'abord si l'employé avec le CIN donné existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYEES WHERE CIN = :cin");
    checkQuery.bindValue(":cin", cin);
    if (checkQuery.exec() && checkQuery.next()) {
        int rowCount = checkQuery.value(0).toInt();
        if (rowCount == 0) {
            // L'employé n'existe pas, renvoyer un échec
            return false;
        }
    } else {
        // Erreur lors de la vérification, renvoyer un échec
        return false;
    }

    // Si l'employé existe, effectuer la suppression
    query.prepare("DELETE FROM EMPLOYEES WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    return query.exec();
}

QSqlQueryModel* Employee::afficher() {
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select CIN,NOM,PRENOM,POSTE,NUMERO,ADRESSE from EMPLOYEES");


   return model;
}
bool Employee::cinExiste(int cin) {
    QSqlQuery query;
    query.prepare("SELECT CIN FROM EMPLOYEES WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (query.exec()) {
        return query.next(); // Si une ligne est trouvée, le CIN existe
    } else {
        // Gérer les erreurs de requête ici
        return false;
    }
}


bool Employee::modifier(const QString& champ, const QString& nouvelleValeur, int cin) {
    QSqlQuery query;
    QString queryStr;

    if (champ == "cin") {
        queryStr = "UPDATE EMPLOYEES SET CIN = :nouvelleValeur WHERE CIN = :cin";
    } else if (champ == "nom") {
        queryStr = "UPDATE EMPLOYEES SET NOM = :nouvelleValeur WHERE CIN = :cin";
    } else if (champ == "prenom") {
        queryStr = "UPDATE EMPLOYEES SET PRENOM = :nouvelleValeur WHERE CIN = :cin";
    } else if (champ == "poste") {
        queryStr = "UPDATE EMPLOYEES SET POSTE = :nouvelleValeur WHERE CIN = :cin";
    } else if (champ == "numero") {
        queryStr = "UPDATE EMPLOYEES SET NUMERO = :nouvelleValeur WHERE CIN = :cin";
    } else if (champ == "adresse") {
        queryStr = "UPDATE EMPLOYEES SET ADRESSE = :nouvelleValeur WHERE CIN = :cin";
    }

    query.prepare(queryStr);
    query.bindValue(":nouvelleValeur", nouvelleValeur);
    query.bindValue(":cin", cin);

    return query.exec();
}
QString Employee::getStoredPassword(const QString& identifiant) {
    QSqlQuery query;
    query.prepare("SELECT MOT_DE_PASSE FROM EMPLOYEES WHERE CIN = :cin");
    query.bindValue(":cin", identifiant);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        // Gérer les erreurs de requête ici
        return QString(); // Retourner une chaîne vide si la requête échoue
    }
}




/*void Employee::sendEmail(QSslSocket& socket, const QString& command, const QString& expectedResponse) {
    socket.write(command.toUtf8() + "\r\n");
    socket.waitForBytesWritten();
    qDebug() << socket.readAll();

    if (!expectedResponse.isEmpty()) {
        if (!socket.waitForReadyRead()) {
            qDebug() << "Error waiting for response";
            return;
        }

        QByteArray response = socket.readAll().trimmed();
        if (response != expectedResponse.toUtf8()) {
            qDebug() << "Unexpected response:" << response;
        }
    }
}

void Employee::envoyerEmail(const QString& destinataire, const QString& sujet, const QString& corps) {

    // Configuration du serveur MTP
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;  // Le port dépend du serveur SMTP

    // Adresse e-mail et mot de passe pour l'authentification SMTP
    QString expediteur = "deliverysmart31@gmail.com";  // Remplacez par votre adresse Gmail
    QString motDePasse = "1q2w3e,4r5t6y";  // Remplacez par votre mot de passe Gmail

    // Création du socket SSL pour le protocole sécurisé
    QSslSocket socket;

    // Configuration SSL
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_2); // Utilisez la version SSL appropriée
    socket.setSslConfiguration(sslConfig);

    // Connexion au serveur SMTP
    socket.connectToHostEncrypted(smtpServer, smtpPort);

    if (!socket.waitForConnected()) {
        qDebug() << "Échec de la connexion au serveur SMTP";
        return;
    }

    // Lecture de la bannière du serveur
    qDebug() << socket.readAll();

    // Envoi de la commande EHLO pour démarrer la session SMTP
    sendEmail(socket, "EHLO localhost", "");

    // Authentification
    sendEmail(socket, "AUTH LOGIN", "");
    sendEmail(socket, expediteur.toUtf8().toBase64(), "");
    sendEmail(socket, motDePasse.toUtf8().toBase64(), "");

    // Envoi du courriel
    sendEmail(socket, "MAIL FROM: <" + expediteur + ">", "");
    sendEmail(socket, "RCPT TO: <" + destinataire + ">", "");

    // Commencer la section de données
    sendEmail(socket, "DATA", "");

    // Corps de l'e-mail
    sendEmail(socket, "Subject: " + sujet, "");
    sendEmail(socket, "From: " + expediteur, "");
    sendEmail(socket, "To: " + destinataire, "");
    sendEmail(socket, "", ""); // Ligne vide entre les en-têtes et le corps
    sendEmail(socket, corps, "");

    // Fin de la section de données
    sendEmail(socket, ".", "");

    // Fermeture de la connexion
    sendEmail(socket, "QUIT", "221");

    if (!socket.waitForConnected()) {
        qDebug() << "Échec de la connexion au serveur SMTP après envoi";
        return;
    }
}*/

bool Employee::rechercherParRFID(const QString& rfid) {
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEES WHERE RFID = :rfid");
    query.bindValue(":rfid", rfid);

    if (query.exec() && query.next()) {
        // Employee found
        // Retrieve and store employee information if needed
        this->setcin(query.value("CIN").toInt());
        this->setnom(query.value("NOM").toString());
        this->setprenom(query.value("PRENOM").toString());
        this->setPoste(query.value("POSTE").toString());
        this->setnumtel(query.value("NUMERO").toInt());
        this->setadresseemail(query.value("ADRESSE").toString());
        return true;
    } else {
        // Employee not found
        return false;
    }
}
