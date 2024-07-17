#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QRegExpValidator>
#include <QDoubleValidator>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QSqlError>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDate>
#include <QComboBox>
#include <cmath>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_client->setModel(Ctmp.afficher());


    QRegExp regex("\\d{8}");

    ui->le_numtel_c->setValidator(new QRegExpValidator(regex, this));
    ui->le_cin_c->setValidator(new QRegExpValidator(regex, this));
    ui->le_cin_2_c->setValidator(new QRegExpValidator(regex, this));
    ui->le_numtel_3_c->setValidator(new QRegExpValidator(regex, this));
    ui->le_cin_3_c->setValidator(new QRegExpValidator(regex, this));

    ui->le_annee_c->setValidator(new QIntValidator(1,9999,this));
    ui->le_annee_3_c->setValidator(new QIntValidator(1,9999,this));

    QRegExpValidator* nameValidator = new QRegExpValidator(QRegExp("^[A-Za-zéèàêôùûçÉÈÀÊÔÙÛÇ\\s]+$"), this);
    ui->le_nom_c->setValidator(nameValidator);
    ui->le_prenom_c->setValidator(nameValidator);
    ui->le_nom_3_c->setValidator(nameValidator);
    ui->le_prenom_3_c->setValidator(nameValidator);


    connect(ui->pb_stat_annee_c, &QPushButton::clicked, this, &MainWindow::generateAnneeStatistics_c);
    connect(ui->pb_stat_adresse_c, &QPushButton::clicked, this, &MainWindow::generateAddressStatistics_c);
    connect(ui->pb_stat_nom_c, &QPushButton::clicked, this, &MainWindow::generateNameStatistics_c);
    connect(ui->pb_stat_prenom_c, &QPushButton::clicked, this, &MainWindow::generateFirstNameStatistics_c);

    connect(ui->pb_trier_adresses_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_adresses_c_clicked);
    connect(ui->pb_trier_adresses_decroissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_adresses_decroissant_c_clicked);
    connect(ui->pb_trier_noms_croissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_noms_croissant_c_clicked);
    connect(ui->pb_trier_noms_decroissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_noms_decroissant_c_clicked);
    connect(ui->pb_trier_prenoms_croissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_prenoms_croissant_c_clicked);
    connect(ui->pb_trier_prenoms_decroissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_prenoms_decroissant_c_clicked);
    connect(ui->pb_trier_annees_croissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_annees_croissant_c_clicked);
    connect(ui->pb_trier_annees_decroissant_c, &QPushButton::clicked, this, &MainWindow::on_pb_trier_annees_decroissant_c_clicked);

    ui->tab_6_c->setStyleSheet("background-color: #e5d6c4;");
    ui->tab_8_c->setStyleSheet("background-color: #e5d6c4;");

    QWidget *rightSideWidget = new QWidget(ui->tab_6_c);
    rightSideWidget->setObjectName("rightSideWidget");

    QVBoxLayout *rightSideLayout = new QVBoxLayout(rightSideWidget);

    cinLineEdit = new QLineEdit(rightSideWidget);
    cinLineEdit->setFixedSize(200, 50);

    QPushButton *calculateButton = new QPushButton("Calculer Points Fidélité", rightSideWidget);
    calculateButton->setFixedSize(200, 50);
    calculateButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e5d6c4;"
        "}"
        "QPushButton:hover {"
        "   background-color: #d1b399;"
        "}");

    pointsLabel = new QLabel("Points de fidélité :", rightSideWidget);

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculatePoints_c);
    rightSideLayout->addSpacing(100);
    rightSideLayout->addWidget(cinLineEdit);
    rightSideLayout->addSpacing(100);
    rightSideLayout->addWidget(calculateButton);
        rightSideLayout->addSpacing(100);
    rightSideLayout->addWidget(pointsLabel);

    QVBoxLayout *mainLayout = new QVBoxLayout(ui->tab_6_c);
    mainLayout->addSpacing(ui->tab_6_c->height() / 2 - rightSideWidget->height() / 2);
    mainLayout->addWidget(rightSideWidget, 0, Qt::AlignHCenter | Qt::AlignVCenter);
    mainLayout->addSpacing(ui->tab_6_c->height() / 2 - rightSideWidget->height() / 2);

    connect(ui->pb_afficher_facture_tab_8_c, &QPushButton::clicked, this, &MainWindow::on_pb_afficher_facture_tab_8_c_clicked);



}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_c_clicked()
{
    QString cin = ui->le_cin_3_c->text();
    QString nom = ui->le_nom_3_c->text();
    QString prenom = ui->le_prenom_3_c->text();
    QString numtel = ui->le_numtel_3_c->text();
    int annee = ui->le_annee_3_c->text().toInt();
    QString adresse = ui->le_adresse_3_c->text();
    QString email = ui->le_email_3_c->text();


    if (ui->le_cin_3_c->text().length() != 8 || ui->le_numtel_3_c->text().length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr("Champs invalides"),
                              QObject::tr("Le CIN et le numéro de téléphone doivent avoir exactement 8 chiffres."), QMessageBox::Ok);
        return;
    }

    if (cin < 8 || nom.isEmpty() || prenom.isEmpty() || numtel < 8 || annee < 1000 ||  adresse.isEmpty() || email.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Champs invalides"),
                              QObject::tr("Veuillez remplir tous les champs correctement."), QMessageBox::Ok);
        return;
    }


    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM client WHERE cin = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.next()) {
        int existingClientCount = query.value(0).toInt();

        if (existingClientCount > 0) {
            QMessageBox::critical(nullptr, QObject::tr("CIN déjà existant"),
                                  QObject::tr("Un client avec ce CIN existe déjà."), QMessageBox::Ok);
            return;
        }
    }

    QRegExp emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}");
    if (!emailRegex.exactMatch(email))
    {
        QMessageBox::critical(nullptr, QObject::tr("E-mail invalide"),
                              QObject::tr("Veuillez saisir une adresse e-mail valide."), QMessageBox::Ok);
        return;
    }

    Client C(cin, nom, prenom, numtel, annee, adresse, email);

    QString errorMsg = C.ajouter();

    if (errorMsg.isEmpty())
    {
        ui->tab_client->setModel(Ctmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QString errorMessage = "Ajout non effectué. Erreur : " + errorMsg;
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), errorMessage, QMessageBox::Cancel);
    }
}



void MainWindow::on_pb_supprimer_c_clicked()
{
    QString cinText = ui->le_cin_2_c->text();
    if (cinText.length() != 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("CIN invalide"),
                              QObject::tr("Le CIN doit comporter exactement 8 chiffres."), QMessageBox::Ok);
        return;
    }

    QString cin_2_c = cinText;
    bool test = Ctmp.supprimer(cin_2_c);

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_client->setModel(Ctmp.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_modifier_c_clicked()
{
    QString cin = ui->le_cin_c->text();
    QString nom = ui->le_nom_c->text();
    QString prenom = ui->le_prenom_c->text();
    QString numtel = ui->le_numtel_c->text();
    int annee = ui->le_annee_c->text().toInt();
    QString adresse = ui->le_adresse_c->text();
    QString email = ui->le_email_c->text();

    Client C(cin, nom, prenom, numtel, annee, adresse, email);

    if (cin < 8 || nom.isEmpty() || prenom.isEmpty() || numtel < 8 || annee < 1000 ||  adresse.isEmpty() || email.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Champs invalides"),
                              QObject::tr("Veuillez remplir tous les champs correctement."), QMessageBox::Ok);
        return;
    }

    QRegExp emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}");
    if (!emailRegex.exactMatch(email))
    {
        QMessageBox::critical(nullptr, QObject::tr("E-mail invalide"),
                              QObject::tr("Veuillez saisir une adresse e-mail valide."), QMessageBox::Ok);
        return;
    }

    bool test = C.modifier(cin);

    if (test)
    {
        ui->tab_client->setModel(Ctmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                 QObject::tr("Modification effectuée avec succès.\n""Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                              QObject::tr("Échec de la modification.\n""Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}




void MainWindow::on_pb_retrieve_c_clicked()
{
    QString cinText = ui->le_cin_c->text();
    if (cinText.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Champ CIN Vide"),
                              QObject::tr("Veuillez saisir un numéro CIN valide."), QMessageBox::Ok);
        return;
    }

    QString cin = cinText;
    Client C;

    if (C.retrieveClient(cin))
    {

        ui->le_nom_c->setText(C.getnom());
        ui->le_prenom_c->setText(C.getprenom());
        ui->le_numtel_c->setText(C.getnumtel());
        ui->le_annee_c->setText(QString::number(C.getannee()));
        ui->le_adresse_c->setText(C.getadresse());
        ui->le_email_c->setText(C.getemail());

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Client Not Found"),
                              QObject::tr("Aucun client trouvé avec le numéro CIN spécifié."), QMessageBox::Ok);
    }
}



void MainWindow::on_pb_rechercher_c_clicked()
{
    QString searchValue = ui->le_rechercher_c->text();

    if (searchValue.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Champ de recherche vide"),
            QObject::tr("Veuillez saisir votre recherche."), QMessageBox::Ok);
    } else {
        QSqlQueryModel *searchResults = Ctmp.rechercherClient(searchValue);

        if (searchResults) {
            ui->tab_client->setModel(searchResults);
            QMessageBox::information(nullptr, QObject::tr("Recherche réussie"),
                QObject::tr("Résultats de la recherche affichés."), QMessageBox::Ok);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Aucun résultat"),
                QObject::tr("Aucun résultat trouvé avec la valeur de recherche spécifiée."), QMessageBox::Ok);
        }
    }
}


void MainWindow::exportClientDataToCSV_c()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Export to CSV", QString(), "CSV Files (*.csv)");
    if (!filePath.isEmpty())
    {
        Ctmp.exportToCSV(filePath);
        QMessageBox::information(this, "Export Successful", "Client data has been exported to a CSV file.");
    }
}


void MainWindow::on_pb_export_csv_c_clicked()
{
    exportClientDataToCSV_c();
}


void MainWindow::generateAnneeStatistics_c()
{
    QSqlQuery query;
    query.prepare("SELECT annee, COUNT(*) as count FROM client GROUP BY annee");

    if (query.exec())
    {
        QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

        while (query.next())
        {
            QString annee = query.value(0).toString();
            int count = query.value(1).toInt();
            qDebug() << "Annee: " << annee << ", Count: " << count;
            QtCharts::QBarSet *barSet = new QtCharts::QBarSet(annee);
            *barSet << count;
            series->append(barSet);
        }

        QtCharts::QChart *chart = new QtCharts::QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques par âge");
        chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

        QtCharts::QCategoryAxis *axisX = new QtCharts::QCategoryAxis();
        axisX->setLabelsPosition(QtCharts::QCategoryAxis::AxisLabelsPositionOnValue);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(chartView);
        dialog->setLayout(layout);
        dialog->resize(800, 600);
        dialog->exec();
    }
}


void MainWindow::generateAddressStatistics_c()
{
    QSqlQuery query;
    query.prepare("SELECT adresse, COUNT(*) as count FROM client GROUP BY adresse");

    if (query.exec())
    {
        QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

        while (query.next())
        {
            QString address = query.value(0).toString();
            int count = query.value(1).toInt();
            qDebug() << "Address: " << address << ", Count: " << count;
            QtCharts::QBarSet *barSet = new QtCharts::QBarSet(address);
            *barSet << count;
            series->append(barSet);
        }

        QtCharts::QChart *chart = new QtCharts::QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques par adresse");
        chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

        QtCharts::QCategoryAxis *axisX = new QtCharts::QCategoryAxis();
        axisX->setLabelsPosition(QtCharts::QCategoryAxis::AxisLabelsPositionOnValue);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(chartView);
        dialog->setLayout(layout);
        dialog->resize(800, 600);
        dialog->exec();
    }
}


void MainWindow::generateNameStatistics_c()
{
    QSqlQuery query;
    query.prepare("SELECT nom, COUNT(*) as count FROM client GROUP BY nom");

    if (query.exec())
    {
        QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

        while (query.next())
        {
            QString name = query.value(0).toString();
            int count = query.value(1).toInt();
            qDebug() << "Name: " << name << ", Count: " << count;
            QtCharts::QBarSet *barSet = new QtCharts::QBarSet(name);
            *barSet << count;
            series->append(barSet);
        }

        QtCharts::QChart *chart = new QtCharts::QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques par nom");
        chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

        QtCharts::QCategoryAxis *axisX = new QtCharts::QCategoryAxis();
        axisX->setLabelsPosition(QtCharts::QCategoryAxis::AxisLabelsPositionOnValue);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(chartView);
        dialog->setLayout(layout);
        dialog->resize(800, 600);
        dialog->exec();
    }
}


void MainWindow::generateFirstNameStatistics_c()
{
    QSqlQuery query;
    query.prepare("SELECT prenom, COUNT(*) as count FROM client GROUP BY prenom");

    if (query.exec())
    {
        QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

        while (query.next())
        {
            QString firstName = query.value(0).toString();
            int count = query.value(1).toInt();
            qDebug() << "First Name: " << firstName << ", Count: " << count;
            QtCharts::QBarSet *barSet = new QtCharts::QBarSet(firstName);
            *barSet << count;
            series->append(barSet);
        }

        QtCharts::QChart *chart = new QtCharts::QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques par prénom");
        chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

        QtCharts::QCategoryAxis *axisX = new QtCharts::QCategoryAxis();
        axisX->setLabelsPosition(QtCharts::QCategoryAxis::AxisLabelsPositionOnValue);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(chartView);
        dialog->setLayout(layout);
        dialog->resize(800, 600);
        dialog->exec();
    }
}


void MainWindow::on_pb_trier_adresses_c_clicked()
{
    QSqlQueryModel *sortedAddressesModel = Ctmp.trierAdressesParOrdreCroissant();

    if (sortedAddressesModel)
    {
        ui->tab_client->setModel(sortedAddressesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des adresses."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_adresses_decroissant_c_clicked()
{
    QSqlQueryModel *sortedAddressesModel = Ctmp.trierAdressesParOrdreDecroissant();

    if (sortedAddressesModel)
    {
        ui->tab_client->setModel(sortedAddressesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des adresses par ordre décroissant."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_noms_croissant_c_clicked()
{
    QSqlQueryModel *sortedNamesModel = Ctmp.trierNomsParOrdreCroissant();

    if (sortedNamesModel)
    {
        ui->tab_client->setModel(sortedNamesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des noms par ordre croissant."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_noms_decroissant_c_clicked()
{
    QSqlQueryModel *sortedNamesModel = Ctmp.trierNomsParOrdreDecroissant();

    if (sortedNamesModel)
    {
        ui->tab_client->setModel(sortedNamesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des noms par ordre décroissant."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_prenoms_croissant_c_clicked()
{
    QSqlQueryModel *sortedFirstNamesModel = Ctmp.trierPrenomsParOrdreCroissant();

    if (sortedFirstNamesModel)
    {
        ui->tab_client->setModel(sortedFirstNamesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des prénoms par ordre croissant."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_prenoms_decroissant_c_clicked()
{
    QSqlQueryModel *sortedFirstNamesModel = Ctmp.trierPrenomsParOrdreDecroissant();

    if (sortedFirstNamesModel)
    {
        ui->tab_client->setModel(sortedFirstNamesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des prénoms par ordre décroissant."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_annees_croissant_c_clicked()
{
    QSqlQueryModel *sortedAnneesModel = Ctmp.trierAnneesParOrdreCroissant();

    if (sortedAnneesModel)
    {
        ui->tab_client->setModel(sortedAnneesModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de tri"),
                              QObject::tr("Erreur lors du tri des annees par ordre croissant."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_trier_annees_decroissant_c_clicked()
{
    QSqlQueryModel *sortedAnneesModel = Ctmp.trierAnneesParOrdreDecroissant();
    ui->tab_client->setModel(sortedAnneesModel);
}




int MainWindow::getNumberOfOrders_c(const QString &cin)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM COMMANDE WHERE cin_client = :cin");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return -1;
    }
    if (query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Aucun résultat trouvé.";
        return 0;
    }
}

double MainWindow::getTotalOrderAmount_c(const QString &cin)
{
    QSqlQuery query;
    query.prepare("SELECT SUM(montant) FROM COMMANDE WHERE cin_client = :cin");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return -1;
    }
    if (query.next()) {
        return query.value(0).toDouble();
    } else {
        qDebug() << "Aucun résultat trouvé.";
        return 0;
    }
}

void MainWindow::calculatePoints_c()
{
    qDebug() << "calculatePoints() called";

    QString cin = cinLineEdit->text();
    qDebug() << "CIN: " << cin;

    if (cin.length() != 8) {
        pointsLabel->setText("CIN invalide.");
        return;
    }

    double totalOrderAmount = getTotalOrderAmount_c(cin);
    qDebug() << "Total Order Amount: " << totalOrderAmount;

    if (totalOrderAmount < 0) {
        pointsLabel->setText("Erreur lors de la récupération du montant des commandes.");
        return;
    }

    // Round up to the nearest multiple of 200 before converting to loyalty points
    double loyaltyPointsRaw = std::ceil(totalOrderAmount / 200) * 50;
    int loyaltyPoints = static_cast<int>(loyaltyPointsRaw);

    qDebug() << "Loyalty Points (raw): " << loyaltyPointsRaw;
    qDebug() << "Loyalty Points (rounded): " << loyaltyPoints;

    pointsLabel->setText("Points de fidélité : " + QString::number(loyaltyPoints));
    if (loyaltyPoints >= 500) {
        QMessageBox congratulationsMessageBox(QMessageBox::Information, "Notez bien!", "Ce client est devenu un client fidèle! Il doit recevoir des surprises dans ses prochaines commandes.", QMessageBox::Ok, this);
        QLabel* informativeLabel = congratulationsMessageBox.findChild<QLabel*>("qt_msgbox_informative_text");
        if (informativeLabel) {
            informativeLabel->setStyleSheet("color: black;");
        }
        congratulationsMessageBox.setStyleSheet("background-color: #e5d6c4; color: black;");
        congratulationsMessageBox.setPalette(QPalette(QColor("#e5d6c4")));

        QAbstractButton* okButton = congratulationsMessageBox.button(QMessageBox::Ok);
        if (okButton) {
            okButton->setStyleSheet("background-color: #e5d6c4; color: black;");
        }

        congratulationsMessageBox.exec();
    } else if (loyaltyPoints >= 400) {
        QMessageBox encouragementMessageBox(QMessageBox::Information, "Notez bien!", "Ce client est proche d'atteindre le statut de client fidèle!", QMessageBox::Ok, this);
        QLabel* informativeLabel = encouragementMessageBox.findChild<QLabel*>("qt_msgbox_informative_text");
        if (informativeLabel) {
            informativeLabel->setStyleSheet("color: black;");
        }
        encouragementMessageBox.setStyleSheet("background-color: #e5d6c4; color: black;");
        encouragementMessageBox.setPalette(QPalette(QColor("#e5d6c4")));

        QAbstractButton* okButton = encouragementMessageBox.button(QMessageBox::Ok);
        if (okButton) {
            okButton->setStyleSheet("background-color: #e5d6c4; color: black;");
        }

        encouragementMessageBox.exec();
    }
}



void MainWindow::on_pb_afficher_facture_tab_8_c_clicked()
{
    QString cin = ui->cin9_c->text();

    if (cin.length() != 8 || !cin.toInt())
    {
        QMessageBox::critical(nullptr, QObject::tr("CIN incorrect"),
                              QObject::tr("Veuillez saisir un numéro CIN valide de 8 chiffres."), QMessageBox::Ok);
        return;
    }

    QString nom, prenom, numtel, adresse;
    QSqlQuery clientQuery;
    clientQuery.prepare("SELECT nom, prenom, numtel, adresse FROM CLIENT WHERE cin = :cin");
    clientQuery.bindValue(":cin", cin);

    if (clientQuery.exec() && clientQuery.next())
    {
        nom = clientQuery.value(0).toString();
        prenom = clientQuery.value(1).toString();
        numtel = clientQuery.value(2).toString();
        adresse = clientQuery.value(3).toString();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Client non trouvé"),
                              QObject::tr("Aucun client trouvé avec le CIN spécifié."), QMessageBox::Ok);
        return;
    }

    QDialog *dialog = new QDialog(this);
    dialog->setMinimumSize(1000, 800); // Enlarged the widget size
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QLabel *cinLabel = new QLabel(QString("Commandes du CIN : %1").arg(cin));
    cinLabel->setFont(QFont("Arial", 18, QFont::Bold));
    cinLabel->setStyleSheet("color: #336699");
    cinLabel->setAlignment(Qt::AlignHCenter);
    layout->addWidget(cinLabel);

    layout->addSpacing(20);
    QLabel *nomLabel = new QLabel(QString("Nom : %1").arg(nom));
    QLabel *prenomLabel = new QLabel(QString("Prénom : %1").arg(prenom));
    QLabel *numtelLabel = new QLabel(QString("Numéro de téléphone : %1").arg(numtel));
    QLabel *adresseLabel = new QLabel(QString("Adresse : %1").arg(adresse));

    nomLabel->setFont(QFont("Arial", 14, QFont::Normal));
    prenomLabel->setFont(QFont("Arial", 14, QFont::Normal));
    numtelLabel->setFont(QFont("Arial", 14, QFont::Normal));
    adresseLabel->setFont(QFont("Arial", 14, QFont::Normal));

    layout->addWidget(nomLabel);
    layout->addWidget(prenomLabel);
    layout->addWidget(numtelLabel);
    layout->addWidget(adresseLabel);

    layout->addSpacing(20);

    QWidget *tableWidgetContainer = new QWidget(dialog);
    QVBoxLayout *tableLayout = new QVBoxLayout(tableWidgetContainer);

    QTableWidget *tableWidget = new QTableWidget();
    tableWidget->setColumnCount(7);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Ref Commande" << "Ref Produit" << "Description" << "Quantité" << "Date Commande" << "Statut" << "Montant");

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QFont tableFont("Arial", 13);
    tableWidget->setFont(tableFont);

    tableLayout->addWidget(tableWidget);
    layout->addWidget(tableWidgetContainer);
    layout->addSpacing(20);

    // Create a new dialog for input
    QDialog *inputDialog = new QDialog(this);
    QVBoxLayout *inputLayout = new QVBoxLayout(inputDialog);

    QLabel *yearLabel = new QLabel("Année de commande:");
    QLineEdit *yearLineEdit = new QLineEdit();
    QPushButton *validerButton = new QPushButton("Valider");

    inputLayout->addWidget(yearLabel);
    inputLayout->addWidget(yearLineEdit);
    inputLayout->addWidget(validerButton);

    connect(validerButton, &QPushButton::clicked, [=]() {
        // Get the entered year
        QString year = yearLineEdit->text();

        // Add the year condition to the query
        QString queryStr = "SELECT ref_commande, ref_produit, description, quantite, date_commande, montant, statut "
                           "FROM COMMANDE "
                           "WHERE cin_client = :cin AND year = :year";

        QSqlQuery query;
        query.prepare(queryStr);
        query.bindValue(":cin", cin);
        query.bindValue(":year", year.toInt());

        if (query.exec())
        {
            double totalMontant = 0.0;

            while (query.next())
            {
                QString ref_commande = query.value(0).toString();
                QString ref_produit = query.value(1).toString();
                QString description = query.value(2).toString();
                QString quantite = query.value(3).toString();
                QString date_commande = query.value(4).toString();
                QString montantStr = query.value(5).toString();
                QString statut = query.value(6).toString();

                int rowPosition = tableWidget->rowCount();
                tableWidget->insertRow(rowPosition);

                tableWidget->setItem(rowPosition, 0, new QTableWidgetItem(ref_commande));
                tableWidget->setItem(rowPosition, 1, new QTableWidgetItem(ref_produit));
                tableWidget->setItem(rowPosition, 2, new QTableWidgetItem(description));
                tableWidget->setItem(rowPosition, 3, new QTableWidgetItem(quantite));
                tableWidget->setItem(rowPosition, 4, new QTableWidgetItem(date_commande));
                tableWidget->setItem(rowPosition, 5, new QTableWidgetItem(statut));
                tableWidget->setItem(rowPosition, 6, new QTableWidgetItem(montantStr));

                qApp->processEvents();

                bool conversionOK;
                double montantDouble = montantStr.toDouble(&conversionOK);
                if (conversionOK) {
                    totalMontant += montantDouble;
                } else {
                    qDebug() << "Erreur de conversion du montant en double!";
                }
            }

            tableWidget->resizeColumnsToContents();
            QLabel *montantLabel = new QLabel(QString("Montant total : %1").arg(totalMontant));
            montantLabel->setFont(QFont("Arial", 14, QFont::Bold));
            montantLabel->setAlignment(Qt::AlignRight);
            layout->addWidget(montantLabel);
            layout->addSpacing(20);

            QWidget *recommandationContainer = new QWidget(dialog);
            QVBoxLayout *recommandationLayout = new QVBoxLayout(recommandationContainer);

            QLabel *titreRecommandationLabel = new QLabel("<font color='#336699'><b><u>Conseils de Bien-Être :</u></b></font>");
            titreRecommandationLabel->setFont(QFont("Arial", 18, QFont::Bold));
            recommandationLayout->addWidget(titreRecommandationLabel);
            recommandationLayout->addSpacing(10);

            int anneeNaissance = 0;
            QSqlQuery anneeQuery;
            anneeQuery.prepare("SELECT annee FROM CLIENT WHERE cin = :cin");
            anneeQuery.bindValue(":cin", cin);

            if (anneeQuery.exec() && anneeQuery.next())
            {
                anneeNaissance = anneeQuery.value(0).toInt();
            }

            int age = QDate::currentDate().year() - anneeNaissance;
            QString recommandationText;
            if (age >= 18 && age < 25)
            {
                recommandationText = "Pour la tranche d'âge de 18 à 25 ans, nous vous suggérons :<br>"
                                     "- Adoptez une alimentation équilibrée et variée.\n"
                                     "- Encouragez la consommation de fruits, légumes et sources de protéines maigres.<br>"
                                     "- Privilégiez les aliments riches en nutriments pour soutenir la croissance et le développement.";
            }
            else if (age >= 25 && age < 35)
            {
                recommandationText = "Pour la tranche d'âge de 25 à 35 ans, nous vous suggérons :<br>"
                                     "- Maintenez une alimentation équilibrée pour soutenir un mode de vie actif.<br>"
                                     "- Intégrez des aliments riches en fibres pour favoriser la santé digestive.<br>"
                                     "- Assurez-vous d'inclure des sources de calcium pour la santé osseuse.";
            }
            else if (age >= 35 && age < 50)
            {
                recommandationText = "Pour la tranche d'âge de 35 à 50 ans, nous vous suggérons :<br>"
                                     "- Mettez l'accent sur la santé cardiaque en choisissant des graisses saines et en surveillant la consommation de sel.<br>"
                                     "- Incluez des aliments riches en antioxydants pour soutenir la santé cellulaire.<br>"
                                     "- Maintenez une consommation adéquate de calcium et de vitamine D pour la santé des os.";
            }
            else if (age >= 50 && age < 65)
            {
                recommandationText = "Pour la tranche d'âge de 50 à 65 ans, nous vous suggérons :<br>"
                                     "- Priorisez les sources de protéines maigres pour soutenir la masse musculaire.<br>"
                                     "- Surveillez la consommation de calories tout en maintenant une alimentation nutritive.<br>"
                                     "- Assurez-vous d'avoir suffisamment de fibres pour soutenir la santé digestive.";
            }
            else if (age >= 65)
            {
                recommandationText = "Pour la tranche d'âge de 65 ans et plus, nous vous suggérons :<br>"
                                     "- Maintenez une alimentation équilibrée et adaptée aux besoins énergétiques.<br>"
                                     "- Assurez-vous d'obtenir suffisamment de vitamines B12 et D, qui peuvent être plus difficiles à absorber avec l'âge.<br>"
                                     "- Priorisez les aliments riches en nutriments pour soutenir la santé générale.";
            }
            else
            {
                recommandationText = "Nous n'avons pas de recommandations spécifiques pour votre âge.";
            }

            QLabel *recommandationLabel = new QLabel("<font color='#102c57'>" + recommandationText + "</font>");
            recommandationLabel->setFont(QFont("Arial", 14, QFont::Normal));
            recommandationLayout->addWidget(recommandationLabel);
            layout->addWidget(recommandationContainer);
            recommandationLayout->addSpacing(20);
            dialog->setStyleSheet("background-color: #e5d6c4;");
            dialog->exec();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur de récupération des données"),
                                  QObject::tr("Erreur lors de la récupération des données de la facture."), QMessageBox::Ok);
        }
    });

    // Display the input dialog
    inputDialog->exec();
}

