#include "acces.h"
#include "ui_acces.h"
#include "Employee.h"

#include<QSqlQuery>
#include<QtDebug>

acces::acces(QWidget *parent) : QDialog(parent), ui(new Ui::acces)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(logoutButtonClicked()), this, SLOT(onDialogRejected()));

}

acces::~acces()
{
    delete ui;
}

QString acces::getUsername() const
{
    return ui->line_id->text();
}

QString acces::getPassword() const
{
    return ui->line_motdepasse->text();
}


void acces::on_pb_login_clicked()
{

    qDebug() << "Login button clicked.";
    QString identifiant = getUsername();
    QString motDePasse = getPassword();

    // Créer une instance de la classe Employee
    Employee employee;

    // Vérifier si l'employé existe dans le tableau 'employees' de la base de données
    bool employeeExists = employee.cinExiste(identifiant.toInt());

    if (employeeExists) {
        // L'employé existe, récupérer le mot de passe stocké
        QString storedPassword = employee.getStoredPassword(identifiant);

        if (!storedPassword.isEmpty()) {
            // Vérifier le mot de passe
            bool passwordCorrect = (storedPassword == motDePasse);

            if (passwordCorrect) {
                // Informations correctes, émettre le signal loginSuccessful

                               // Retrieve the role (poste) of the employee
                 QSqlQuery checkQuery;
                checkQuery.prepare("SELECT POSTE FROM EMPLOYEES WHERE CIN = :cin");
                checkQuery.bindValue(":cin", identifiant);

               QString roleUtilisateur;
               if (checkQuery.exec() && checkQuery.next()) {
                   roleUtilisateur = checkQuery.value(0).toString();
               }

                          qDebug() << "RoleUtilisateur111111: " << roleUtilisateur;
                               // Emit the loginSuccessful signal with the roleUtilisateur
                             emit loginSuccessful(roleUtilisateur);

                            // Close the login window
                                           close();
            } else {
                // Mot de passe incorrect, afficher un message d'erreur
                QMessageBox::critical(this, "Erreur d'authentification", "Mot de passe incorrect.");
            }
        } else {
            // Le mot de passe est vide dans la base de données, afficher un message d'erreur
            QMessageBox::critical(this, "Erreur d'authentification", "Le mot de passe est vide.");
        }
    } else {
        // Employé inexistant, afficher un message d'erreur
        QMessageBox::critical(this, "Erreur d'authentification", "Employé inexistant.");
    }
}
void acces::onDialogRejected()
{


    // Effacez le contenu des champs d'identifiant et de mot de passe
    ui->line_id->clear();
    ui->line_motdepasse->clear();
}
