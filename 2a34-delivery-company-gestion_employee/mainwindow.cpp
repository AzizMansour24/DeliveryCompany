#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_chatbotwindow.h"
#include "BarChartItem.h"
#include "acces.h"
#include "arduino.h"
#include<Employee.h>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QSortFilterProxyModel>
#include <QCoreApplication>
#include <QPdfWriter>
#include <QPageSize>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlDatabase>
#include <QtCharts>
#include "chatbotwindow.h"
#include <QSqlError>
#include <QSerialPort>
using namespace std;
#include<iostream>
#include <QHeaderView>
#include <QDateTime>
#include <vector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow),

 chatbotWindow(new ChatbotWindow(this)), // Initialize the ChatbotWindow
 serial(new QSerialPort(this)) // Initialize QSerialPort before ui
{
    ui->setupUi(this);

    ui->la_cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_num->setValidator(new QIntValidator(0, 999999999, this));
    //ui->la_cin_2->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_2->setValidator(new QIntValidator(0, 999999999, this));
    QRegExpValidator* nameValidator = new QRegExpValidator(QRegExp("^[A-Za-zéèàêôùûçÉÈÀÊÔÙÛÇ\\s]+$"), this);
    ui->le_nom->setValidator(nameValidator);
    ui->le_prenom->setValidator(nameValidator);
   /* connect(ui->radioNumero, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled()));
     connect(ui->radioNom, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled()));
     connect(ui->radioPrenom, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled()));
     connect(ui->radioAdresse, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled()));
     connect(ui->radioPoste, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled()));*/
    ui->tabaff->setModel(E.afficher());
     connect(ui->pb_quitter, SIGNAL(clicked()), this, SLOT(retourAccesWindow()));
     // Connect the pb_chatbot button to open the ChatbotWindow
        connect(ui->pb_chatbot, SIGNAL(clicked()), this, SLOT(on_pb_chatbot_clicked()));
        // Connect the ChatbotWindow signal to handle the chatbot response
        connect(chatbotWindow, SIGNAL(chatbotQuestionAsked(QString)), this, SLOT(handleChatbotResponse(QString)));
        connect(this, SIGNAL(chatbotQuestionAsked(QString)), parent, SLOT(gestionChatbot(QString)));
       connect(this, SIGNAL(logoutButtonClicked()), this, SLOT(onDialogRejected()));

       connect(ui->lineEdit_4, &QLineEdit::returnPressed, this, &MainWindow::calculatePresenceForEnteredEmployee);
   connect(ui->pb_presence_2, &QPushButton::clicked, this, &MainWindow::calculatePresenceForEnteredEmployee);



       int ret = A.connect_arduino(); // Launch the connection to Arduino
       switch (ret) {
           case 0:
               qDebug() << "Arduino is available and connected to: " << A.getarduino_port_name();
               // Connect readyRead() signal to readSerialData() slot
               connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(readSerialData()));
               break;
           case 1:
               qDebug() << "Arduino is available but not connected to: " << A.getarduino_port_name();
               break;
           case -1:
               qDebug() << "Arduino is not available";

        break;
       }
}



MainWindow::~MainWindow()
{

    delete ui;

}
void MainWindow::configureAccessRights(const QString &roleUtilisateur) {


    // Désactivez tous les onglets par défaut
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->setTabEnabled(i, false);
    }

    // Activez les onglets spécifiques en fonction du rôle de l'utilisateur
    if (roleUtilisateur == "administrateur") {
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondesemployees), true);
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondesclients), true);
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondestransporteurs), true);
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondeproduit), true);
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondescommandes), true);
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondesfurnisseurs), true);

    } else if (roleUtilisateur == "gestion client") {
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondesclients), true);
    } else if (roleUtilisateur == "gestion de transporteurs") {
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondestransporteurs), true);
    } else if (roleUtilisateur == "gestion des commandes") {
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondescommandes), true);
    } else if (roleUtilisateur == "gestion de fournisseurs") {
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondesfurnisseurs), true);
    }else if (roleUtilisateur == "ressources humaine") {
        ui->tabWidget->setTabEnabled(ui->tabWidget->indexOf(ui->gestiondesemployees), true);
    }

}
void MainWindow::onLoginSuccessful(const QString &roleUtilisateur) {
      qDebug() << "Login successful. Role:" << roleUtilisateur;
    configureAccessRights(roleUtilisateur);
      this->show();
}
void MainWindow::on_pb_quitter_clicked()
{
    // Emit the signal to indicate the logout action
     emit logoutButtonClicked();
     // Close the main window
     this->close();
}
void MainWindow::on_pb_ajouter_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox { background-color: red; }" // Change the background color to red
                          "QMessageBox QLabel { color: white; }"); // Change the text color to white

    qDebug() << "Bouton d'ajout cliqué.";
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    int cin = ui->la_cin->text().toInt();
    int numero_de_tel = ui->le_num->text().toInt();
    QString adresse_email = ui->la_adresse->text();

    QString poste;

    // Vérifiez quel bouton radio est sélectionné
    if (ui->radioButton->isChecked()) {
        poste = "administrateur";
              } else if (ui->radioButton_2->isChecked()) {
                  poste = "gestion client";
              } else if (ui->radioButton_3->isChecked()) {
                  poste = "ressources humaine";
              } else if (ui->radioButton_4->isChecked()) {
                  poste = "gestion de transporteurs";
              } else if (ui->radioButton_5->isChecked()) {
                  poste = "gestion des commandes";
              } else if (ui->radioButton_6->isChecked()) {
                  poste = "gestion des fournisseurs";
              } else {
                  poste = "Aucun poste sélectionné";
    }

    QRegExp emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}");

    if (!emailRegex.exactMatch(adresse_email)) {
        msgBox.critical(this, "E-mail invalide", "Veuillez saisir une adresse e-mail valide.");
        return;
    }

    Employee E(cin, nom, prenom, poste, numero_de_tel, adresse_email);

    bool ajoutReussi = E.ajouter();
    if (ajoutReussi) {
        ui->tabaff->setModel(E.afficher());
        qDebug() << "Ajout réussi.";
        msgBox.information(this, "Ajout réussi", "L'employé a été ajouté avec succès.");

    } else {
        qDebug() << "Échec de l'ajout.";


           msgBox.critical(this, "Échec de l'ajout", "L'ajout de l'employé a échoué.");
    }
  }



void MainWindow::on_pb_supprimer_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox { background-color: white; }" // Change the background color to red
                          "QMessageBox QLabel { color: black; }"); // Change the text color to white

    Employee E1;
       E1.setcin(ui->la_cin_2->text().toInt());

       bool suppressionReussie = E1.supprimer(E1.getcin());

       if (suppressionReussie) {
           ui->tabaff->setModel(E.afficher());
            msgBox.information(this, "Suppression réussie", "L'employé a été supprimé avec succès.");
       } else {
           msgBox.critical(this, "Échec de la suppression", "La suppression de l'employé a échoué.");
       }
}


void MainWindow::on_pb_aff_clicked()
{
    ui->tabaff->setModel(E.afficher());
}

void MainWindow::on_pb_modifier_clicked() {
    Employee E;

    // Obtenez le bouton radio sélectionné
    QString champ;
    if (ui->radioNumero->isChecked()) {
        champ = "numero";
    } else if (ui->radioNom->isChecked()) {
        champ = "nom";
    } else if (ui->radioPrenom->isChecked()) {
        champ = "prenom";
    } else if (ui->radioAdresse->isChecked()) {
        champ = "adresse";
    } else if (ui->radioPoste->isChecked()) {
        champ = "poste";
    }

    QString nouvelleValeur = ui->lineEdit->text(); // Nouvelle valeur à définir
    int cin = ui->lineEdit_2->text().toInt(); // CIN de l'employé

    if (champ.isEmpty()) {
        QMessageBox::critical(this, "Champ non sélectionné", "Veuillez sélectionner le champ à modifier.");
        return;
    }

    if (nouvelleValeur.isEmpty() || ui->lineEdit_2->text().isEmpty()) {
        QMessageBox::critical(this, "Champs vides", "Veuillez remplir les deux champs (nouvelle valeur et CIN) pour effectuer la modification.");
        return;
    }

    if (champ == "numero") {
        // Limiter la saisie à des chiffres uniquement
        ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));
    } else if (champ == "nom" || champ == "prenom") {
        // Autoriser uniquement les lettres et les espaces pour les champs "nom" et "prenom"
        QRegExpValidator nameValidator(QRegExp("^[A-Za-zéèàêôùûçÉÈÀÊÔÙÛÇ\\s]+$"), this);
        int pos = 0;
        if (nameValidator.validate(nouvelleValeur, pos) != QValidator::Acceptable) {
            QMessageBox::critical(this, "Nom ou prénom invalide", "Veuillez saisir un nom ou prénom valide.");
            return;
        }
    } else if (champ == "adresse") {
        QString adresse_email = ui->lineEdit->text();
        QRegExp emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}");

        if (!emailRegex.exactMatch(adresse_email)) {
            QMessageBox::critical(this, "E-mail invalide", "Veuillez saisir une adresse e-mail valide.");
            return;
        }
    } else if (champ == "poste") {
        // Vous pouvez ajouter ici la validation du champ "poste", par exemple en vérifiant s'il correspond à une liste de postes valides
        QStringList postesValides = {"administrateur", "gestion client", "ressources humaine", "gestion de transporteurs", "gestion des commandes", "gestion des fournisseurs"};
        if (!postesValides.contains(nouvelleValeur)) {
            QMessageBox::critical(this, "Poste invalide", "Veuillez sélectionner un poste valide.");
            return;
        }
    }

    bool modificationReussie = E.modifier(champ, nouvelleValeur, cin);

    if (modificationReussie) {
        ui->tabaff->setModel(E.afficher());
        QMessageBox::information(this, "Modification réussie", "La modification a été effectuée avec succès.");
    } else {
        QMessageBox::critical(this, "Échec de la modification", "La modification de l'employé a échoué.");
    }
}

void MainWindow::on_pushButton_30_clicked()
{
    // Create an instance of QPrinter to set custom printing parameters (if necessary)
    QPrinter printer;

    // Create an instance of QPrintDialog and pass the QPrinter as a parameter
    QPrintDialog printDialog(&printer, this);

    // Open the basic print dialog window
    if (printDialog.exec() == QDialog::Accepted) {
        // User clicked "OK" in the print dialog window
        // You can print your content here using the configured QPrinter
        // (e.g., QPainter to draw on the QPrinter)
        QPainter painter(&printer);
        painter.setRenderHint(QPainter::Antialiasing);

        // Fetch the data from your database (replace this with your actual query)
        QSqlQueryModel model;
        model.setQuery("SELECT CIN,NOM,PRENOM,POSTE,NUMERO,ADRESSE from EMPLOYEES"); // Modify the SQL query accordingly

        // Ensure the database query is successful
        if (model.lastError().isValid()) {
            qDebug() << "Database query error:" << model.lastError().text();
            return;  // Exit the function if there's an error
        }

        // Create a QTextDocument to hold the table
        QTextDocument document;

        // Create a QTextCursor to append content to the document
        QTextCursor cursor(&document);

        // Create a QTextTable to represent the table
        QTextTableFormat tableFormat;
        tableFormat.setBorder(2); // Set the table border
        tableFormat.setCellPadding(5); // Set cell padding
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);

        // Adjust the table size
        tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100)); // 100% width of the page

        QTextTable* table = cursor.insertTable(model.rowCount() + 1, model.columnCount(), tableFormat);

        // Set the header data
        for (int col = 0; col < model.columnCount(); ++col) {
            QTextTableCell headerCell = table->cellAt(0, col);
            QTextCursor cellCursor = headerCell.firstCursorPosition();
            cellCursor.insertText(model.headerData(col, Qt::Horizontal).toString());

            // Apply header styling, including font size
            QTextCharFormat headerFormat = cellCursor.charFormat();
            headerFormat.setFontWeight(QFont::Bold);
            headerFormat.setFontPointSize(14); // Adjust font size as needed
            headerCell.setFormat(headerFormat);
        }

        // Populate the table with data
        for (int row = 0; row < model.rowCount(); ++row) {
            for (int col = 0; col < model.columnCount(); ++col) {
                QTextTableCell dataCell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = dataCell.firstCursorPosition();
                cellCursor.insertText(model.record(row).value(col).toString());

                // Apply alternating row colors
                if (row % 2 == 0) {
                    QTextCharFormat cellFormat = cellCursor.charFormat();
                    cellFormat.setBackground(QColor(240, 240, 240)); // Light gray background
                    dataCell.setFormat(cellFormat);
                }
            }
        }

        // Render the QTextDocument to the painter
        document.drawContents(&painter);
    }
}

void MainWindow::on_pb_presence_clicked()
{
    // Create an instance of QPrinter to set custom printing parameters (if necessary)
    QPrinter printer;

    // Create an instance of QPrintDialog and pass the QPrinter as a parameter
    QPrintDialog printDialog(&printer, this);

    // Open the basic print dialog window
    if (printDialog.exec() == QDialog::Accepted) {
        // User clicked "OK" in the print dialog window
        // You can print your content here using the configured QPrinter
        // (e.g., QPainter to draw on the QPrinter)
        QPainter painter(&printer);
        painter.setRenderHint(QPainter::Antialiasing);

        // Fetch the data from your database (replace this with your actual query)
        QSqlQueryModel model;
        model.setQuery("SELECT * FROM HEURESTRAVAIL"); // Modify the SQL query accordingly

        // Ensure the database query is successful
        if (model.lastError().isValid()) {
            qDebug() << "Database query error:" << model.lastError().text();
            return;  // Exit the function if there's an error
        }

        // Create a QTextDocument to hold the table
        QTextDocument document;

        // Create a QTextCursor to append content to the document
        QTextCursor cursor(&document);

        // Create a QTextTable to represent the table
        QTextTableFormat tableFormat;
        tableFormat.setBorder(2); // Set the table border
        tableFormat.setCellPadding(5); // Set cell padding
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);

        // Adjust the table size
        tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100)); // 100% width of the page

        QTextTable* table = cursor.insertTable(model.rowCount() + 1, model.columnCount(), tableFormat);

        // Set the header data
        for (int col = 0; col < model.columnCount(); ++col) {
            QTextTableCell headerCell = table->cellAt(0, col);
            QTextCursor cellCursor = headerCell.firstCursorPosition();
            cellCursor.insertText(model.headerData(col, Qt::Horizontal).toString());

            // Apply header styling, including font size
            QTextCharFormat headerFormat = cellCursor.charFormat();
            headerFormat.setFontWeight(QFont::Bold);
            headerFormat.setFontPointSize(14); // Adjust font size as needed
            headerCell.setFormat(headerFormat);
        }

        // Populate the table with data
        for (int row = 0; row < model.rowCount(); ++row) {
            for (int col = 0; col < model.columnCount(); ++col) {
                QTextTableCell dataCell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = dataCell.firstCursorPosition();
                cellCursor.insertText(model.record(row).value(col).toString());

                // Apply alternating row colors
                if (row % 2 == 0) {
                    QTextCharFormat cellFormat = cellCursor.charFormat();
                    cellFormat.setBackground(QColor(240, 240, 240)); // Light gray background
                    dataCell.setFormat(cellFormat);
                }
            }
        }

        // Render the QTextDocument to the painter
        document.drawContents(&painter);
    }
}
void MainWindow::on_pushButton_33_clicked()
{
    // Récupérez le texte sélectionné dans le ComboBox (Trier par : Nom, Prénom)
    QString trierPar = ui->comboBox_4->currentText();

    // Créez une requête SQL pour trier les données par nom ou prénom
    QString query;

    if (trierPar == "nom (ordre alphébétique)") {
        query = "SELECT * FROM EMPLOYEES ORDER BY NOM";
    } else if (trierPar == "prénom(ordre alphébétique)") {
        query = "SELECT * FROM EMPLOYEES ORDER BY PRENOM";
    }else if (trierPar == "CIN (ordre numérique croissant)") {
        query = "SELECT * FROM EMPLOYEES ORDER BY CIN";
    } else if (trierPar == "CIN (ordre numérique décroissant)") {
        query = "SELECT * FROM EMPLOYEES ORDER BY CIN DESC";
    } else if (trierPar == "poste(ordre alphébétique)") {
    query = "SELECT * FROM EMPLOYEES ORDER BY POSTE";
    }


    // Créez un modèle QSqlQueryModel
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécutez la requête
    model->setQuery(query);

    // Définissez le modèle QSqlQueryModel sur le QTableView
    ui->tabaff->setModel(model);

    // Mettez à jour l'affichage du QTableView
    ui->tabaff->update();
}





void MainWindow::on_pb_recherche_clicked()
{
    // Récupérez l'attribut de recherche sélectionné dans la ComboBox
    QString attribut = ui->comboBox_2->currentText();

    // Récupérez le texte saisi dans lineedit_3
    QString rechercheText = ui->lineEdit_3->text();

    // Créez une requête SQL dynamique pour effectuer la recherche
    QString query = "SELECT CIN,NOM,PRENOM,POSTE,NUMERO,ADRESSE FROM EMPLOYEES WHERE ";

    if (attribut == "nom") {
        // Utilisez un validateur pour s'assurer que le champ nom ne contient que des lettres et espaces
        QRegExpValidator nameValidator(QRegExp("^[A-Za-zéèàêôùûçÉÈÀÊÔÙÛÇ\\s]+$"), this);
        int pos = 0;
        if (nameValidator.validate(rechercheText, pos) != QValidator::Acceptable) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez saisir un nom valide.");
            return;
        }
        query += "NOM LIKE '%" + rechercheText + "%'";
    } else if (attribut == "prenom") {
        // Utilisez un validateur pour s'assurer que le champ prénom ne contient que des lettres et espaces
        QRegExpValidator nameValidator(QRegExp("^[A-Za-zéèàêôùûçÉÈÀÊÔÙÛÇ\\s]+$"), this);
        int pos = 0;
        if (nameValidator.validate(rechercheText, pos) != QValidator::Acceptable) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez saisir un prénom valide.");
            return;
        }
        query += "PRENOM LIKE '%" + rechercheText + "%'";
    } else if (attribut == "cin") {
        // Vérifiez si la saisie est un nombre
        bool isNumber;
        rechercheText.toInt(&isNumber);
        if (!isNumber) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez saisir un numéro de CIN valide.");
            return;
        }
        query += "CIN = " + rechercheText;
    } else if (attribut == "poste") {
        // Utilisez un validateur pour s'assurer que le champ poste correspond à une liste de postes valides
        QStringList postesValides = {"administrateur", "gestion client", "ressources humaine", "gestion de transporteurs", "gestion des commandes", "gestion des fournisseurs"};
        if (!postesValides.contains(rechercheText)) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez sélectionner un poste valide.");
            return;
        }
        query += "POSTE LIKE '%" + rechercheText + "%'";
    } else if (attribut == "adresse") {
        // Utilisez un validateur pour s'assurer que le champ adresse correspond à une adresse Gmail valide
        QRegExpValidator emailValidator(QRegExp("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}"), this);
        int pos = 0;
        if (emailValidator.validate(rechercheText, pos) != QValidator::Acceptable) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez saisir une adresse Gmail valide.");
            return;
        }
        query += "ADRESSE LIKE '%" + rechercheText + "%'";
    } else if (attribut == "numero") {
        // Vérifiez si la saisie est un nombre
        bool isNumber;
        rechercheText.toInt(&isNumber);
        if (!isNumber) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez saisir un numéro valide.");
            return;
        }
        query += "NUMERO = " + rechercheText;
    }

    // Créez un modèle QSqlQueryModel
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécutez la requête
    model->setQuery(query);

    // Définissez le modèle QSqlQueryModel sur le QTableView
    ui->tabaff->setModel(model);

    // Mettez à jour l'affichage du QTableView
    ui->tabaff->update();
}

void MainWindow::on_pb_statistiques_clicked()
{
    // Execute the query to obtain the statistics data
    QString query = "SELECT POSTE, COUNT(*) FROM EMPLOYEES GROUP BY POSTE";

    QSqlQueryModel model;
    model.setQuery(query);

    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();
    QChartView *chartView = new QChartView(chart);

    QBarSet *barSet = new QBarSet("Nombre d'employés par poste");
    QStringList categories; // Store job position names

    for (int i = 0; i < model.rowCount(); ++i) {
        QString poste = model.record(i).value("POSTE").toString();
        int nombreDemployes = model.record(i).value(1).toInt();

        *barSet << nombreDemployes;
        categories << poste; // Add the job position name
    }

    series->append(barSet);
    chart->addSeries(series);
    chart->setTitle("Statistiques du nombre d'employés par poste");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Configure the chart size
    chartView->setMinimumSize(625, 325);
    chartView->setMaximumSize(700, 400);

    // Create categories (job position names) for the x-axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create a value axis for the y-axis
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a placeholder QWidget
    QWidget *chartContainer = new QWidget;
    chartContainer->setLayout(new QVBoxLayout);
    chartContainer->layout()->addWidget(chartView);

    // Set the QWidget as the central widget of QGraphicsView
    ui->graphicsView_4->setScene(new QGraphicsScene(ui->graphicsView_4));
    ui->graphicsView_4->scene()->addWidget(chartContainer);
}




void MainWindow::gestionChatbot(const QString &question) {

    QString reponse;

    if (question.contains("comment ça va", Qt::CaseInsensitive)) {
           qDebug() << "Question contains 'comment ça va'";
           reponse = "Je vais bien, merci!";
       } else if (question.contains(" nom", Qt::CaseInsensitive)) {
           qDebug() << "Question contains ' nom'";
           reponse = "Je suis un chatbot!";
       } else if (question.contains("livraison", Qt::CaseInsensitive)) {
           qDebug() << "Question contains 'livraison'";
           reponse = "La livraison des produits est gérée de manière intelligente pour assurer une efficacité maximale.";
       } else if (question.contains("horaires de travail", Qt::CaseInsensitive)) {
           qDebug() << "Question contains 'horaires de travail'";
           reponse = "Les horaires de travail sont définis conformément aux politiques de l'entreprise.";
       } else if (question.contains("congés", Qt::CaseInsensitive)) {
           qDebug() << "Question contains 'congés'";
           reponse = "Les demandes de congé peuvent être soumises via le système de gestion des employés.";
       } else if (question.contains("produit endommagé", Qt::CaseInsensitive)) {
           qDebug() << "Question contains 'produit endommagé'";
           reponse = "En cas de produit endommagé, veuillez contacter le service client pour obtenir de l'aide.";
       } else {
           qDebug() << "Unknown question";
           reponse = "Désolé, je ne comprends pas la question.";
       }

    // Emit the signal to handle the chatbot response
    emit chatbotQuestionAsked(reponse);
       QMessageBox::information(this, "Assistance virtuelle", reponse);
}

void MainWindow::on_pb_chatbot_clicked()
{
    // Show the ChatbotWindow when the button is clicked
    chatbotWindow->show();
}

void MainWindow::handleChatbotResponse(const QString &response)
{
    // Handle the chatbot response, for example, by displaying it in a message box
    QMessageBox::information(this, "Assistance virtuelle", response);
}
void MainWindow::retourAccesWindow() {
    // Emit the logoutButtonClicked signal to trigger the slot in 'acces'
    emit logoutButtonClicked();
    // Close the main window
    this->close();
}


void MainWindow::readSerialData() {
    static QString dataBuffer;  // Static variable to store incomplete messages between function calls

    QByteArray newData = A.read_from_arduino();
    dataBuffer += QString::fromUtf8(newData);

    // Check for complete messages in the buffer
    while (dataBuffer.contains("\r\n")) {
        // Extract one complete message
        int endIndex = dataBuffer.indexOf("\r\n");
        QString completeMessage = dataBuffer.left(endIndex).trimmed();
        dataBuffer = dataBuffer.mid(endIndex + 2);  // Remove processed message from the buffer

        qDebug() << "Received Data: " << completeMessage;

        // Process the complete message
        processReceivedData(completeMessage);
    }
}


void MainWindow::processReceivedData(const QString& data) {
    if (data.contains("ID RFID: ")) {
        // Extract RFID from the received data
        QString rfidString = data.mid(data.indexOf("ID RFID: ") + 9).trimmed();

        // Search for employee in the "EMPLOYEES" table
        Employee employee;
        if (employee.rechercherParRFID(rfidString)) {
            qDebug() << "Employee Found - CIN: " << employee.getcin() << " nom: " << employee.getnom() << " prenom: " << employee.getprenom() << " RFID: " << rfidString;

            // Get the current date and time
            QDate currentDate = QDate::currentDate();
            QTime currentTime = QTime::currentTime();

            // Create the entry timestamp
            QDateTime entryDateTime(currentDate, currentTime);

            // Check if the RFID has an existing entry in the database
            QSqlQuery existingEntryQuery;
            existingEntryQuery.prepare("SELECT ID_EMPLOYEE, HEUREENTREE, HEURESORTIE FROM HEURESTRAVAIL WHERE ID_EMPLOYEE = ? AND HEURESORTIE IS NULL");
            existingEntryQuery.addBindValue(employee.getcin());

            if (existingEntryQuery.exec() && existingEntryQuery.next()) {
                // Update the existing entry with exit time
                QSqlQuery updateExitTimeQuery;
                updateExitTimeQuery.prepare("UPDATE HEURESTRAVAIL SET HEURESORTIE = ? WHERE ID_EMPLOYEE = ? AND HEURESORTIE IS NULL");
                updateExitTimeQuery.addBindValue(entryDateTime.toString("yyyy-MM-dd H:m:s"));
                updateExitTimeQuery.addBindValue(employee.getcin());

                if (updateExitTimeQuery.exec()) {
                    qDebug() << "Exit Record Updated";

                    // Display exit record message
                    QString exitMessage = employee.getnom() + " " + employee.getprenom() + " a quitté à " + entryDateTime.toString("HH:mm");
                    qDebug() << exitMessage;

                    // Show QMessageBox with exit record message
                    QMessageBox::information(this, "Sortie enregistrée", exitMessage);
                } else {
                    qDebug() << "Exit Record Update Failed" << updateExitTimeQuery.lastError().text();
                }
            } else {
                // Insert a new row for entry
                QSqlQuery entryInsertQuery;
                entryInsertQuery.prepare("INSERT INTO HEURESTRAVAIL (ID_EMPLOYEE, HEUREENTREE) VALUES (?, ?)");
                entryInsertQuery.addBindValue(employee.getcin());
                entryInsertQuery.addBindValue(entryDateTime.toString("yyyy-MM-dd H:m:s"));

                if (entryInsertQuery.exec()) {
                    qDebug() << "Entry Record Inserted";

                    // Display entry record message
                    QString entryMessage = employee.getnom() + " " + employee.getprenom() + " est arrivé à " + entryDateTime.toString("HH:mm");
                    qDebug() << entryMessage;

                    // Show QMessageBox with entry record message
                    QMessageBox::information(this, "Entrée enregistrée", entryMessage);
                } else {
                    qDebug() << "Entry Record Insert Failed" << entryInsertQuery.lastError().text();
                }
            }
        } else {
            qDebug() << "No employee found with this RFID identifier";
        }
    } else {
        qDebug() << "Invalid data format";
    }
}


void MainWindow::calculatePresenceForEmployee(const QString& cin) {
    // Fetch presence data from the database for the specified employee
    QSqlQueryModel presenceModel;
    presenceModel.setQuery("SELECT ID_EMPLOYEE, HEUREENTREE, HEURESORTIE FROM HEURESTRAVAIL WHERE ID_EMPLOYEE = '" + cin + "'");

    // Ensure the database query is successful
    if (presenceModel.lastError().isValid()) {
        qDebug() << "Database query error:" << presenceModel.lastError().text();
        return;  // Exit the function if there's an error
    }

    // Create a QMap to store total seconds for each date
    QMap<QDate, int> totalSecondsData;  // Date -> Total Seconds

    // Process the presence data and calculate total seconds for each date
    for (int row = 0; row < presenceModel.rowCount(); ++row) {
        QDateTime entranceDateTime = presenceModel.record(row).value("HEUREENTREE").toDateTime();
        QDateTime exitDateTime = presenceModel.record(row).value("HEURESORTIE").toDateTime();

        // Ensure the entrance and exit times are valid
        if (entranceDateTime.isValid() && exitDateTime.isValid()) {
            // Calculate the time duration for the current entry in seconds
            int durationSeconds = entranceDateTime.secsTo(exitDateTime);

            // Update the total seconds for the date
            totalSecondsData[entranceDateTime.date()] += durationSeconds;
        }
    }

    // Display the presence data and total hours
    for (const QDate& date : totalSecondsData.keys()) {
        int totalSeconds = totalSecondsData[date];
        QTime totalHours = QTime(0, 0).addSecs(totalSeconds);
        qDebug() << "CIN: " << cin << " Date: " << date.toString("yyyy-MM-dd") << " Total Hours: " << totalHours.toString("hh:mm:ss");
    }

    // Set the presence data model for the tabaff view
    QStringList headerLabels = {"Date", "Total Hours"};
    QStandardItemModel *presenceModelForView = new QStandardItemModel(totalSecondsData.size(), 2, this);
    presenceModelForView->setHorizontalHeaderLabels(headerLabels);

    int row = 0;
    for (const QDate& date : totalSecondsData.keys()) {
        int totalSeconds = totalSecondsData[date];
        QTime totalHours = QTime(0, 0).addSecs(totalSeconds);
        presenceModelForView->setItem(row, 0, new QStandardItem(date.toString("yyyy-MM-dd")));
        presenceModelForView->setItem(row, 1, new QStandardItem(totalHours.toString("hh:mm:ss")));
        row++;
    }

    ui->tabaff->setModel(presenceModelForView);
}

void MainWindow::calculatePresenceForEnteredEmployee() {
    // Get the entered CIN from lineEdit_4
    QString enteredCIN = ui->lineEdit_4->text().trimmed();

    // Check if the entered CIN is not empty
    if (!enteredCIN.isEmpty()) {
        // Call the calculatePresenceForEmployee function
        calculatePresenceForEmployee(enteredCIN);
    } else {
        // Handle case where CIN is empty
        qDebug() << "Please enter a valid CIN.";
    }
}

void MainWindow::on_pb_presence_2_clicked() {
    // Call the function to calculate and display presence for the entered employee
    calculatePresenceForEnteredEmployee();
}
