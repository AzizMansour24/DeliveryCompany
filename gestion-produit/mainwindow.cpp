#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduino.h"
#include <QMainWindow>
#include "produit.h"
#include<QMessageBox>
#include<QDebug>
#include <QSqlQuery>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocument>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "connection.h"
#include <QApplication>
#include <QStandardItem>
#include <QSqlError>
#include <QDebug>
#include <QTextDocument>
#include <QtCharts/QChart>
#include <QIntValidator>
#include <QPainter>
#include <QtCharts>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
       case(-1):qDebug() << "arduino is not available";
            break;
        }
        data=A.read_from_arduino();
     if(data=="1"){ui->lab->setText("1");}
     else if(data=="2"){ui->lab->setText("2");}
     else{ui->lab->setText("3");}
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked(){
    bool test;
    int ref=ui->lineEdit_ref->text().toInt(); //converted to int
    int quantite=ui->lineEdit_quantite->text().toInt();
    int prix=ui->lineEdit_prix->text().toFloat();
    QString nom=ui->lineEdit_nom->text();
    QString fournisseur=ui->lineEdit_fournisseur->text();
    QString categorie=ui->listWidget->currentItem()->text();
    produit P(ref,nom,categorie,quantite,fournisseur,prix);
    if (ref==0||quantite==0){
        test=false;
    }
    else if(P.rechercherfournisseur(fournisseur)==true){
         test=false;
    }
    else{
        test=P.ajouter();
      }
    if(test){
        ui->tableView->setModel(Etmp.afficher());                   //actualisation affichage
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("ajout effectué\n"
                                 "Click cancel to exit."),QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("ajout non effectué\n"
                                 "ref:fausse/existante"),QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_supp_clicked(){
    int ref=ui->lineEdit_ref2->text().toInt();
    bool test=Etmp.supprimer(ref);
    if(test){
        ui->tableView->setModel(Etmp.afficher());                        //actualisation affichage
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectué\n."),QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression non effectué\n"
                                 "Changer la référence."),QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_update_clicked(){
    int ref=ui->lineEdit_ref3->text().toInt();
    int ref2=ui->lineEdit_quantite3->text().toInt();
    int ref3=ui->lineEdit_prix3->text().toFloat();
    bool test=Etmp.modifier(ref,ref2,ref3);
    if(test){
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Modification Effectué\n"),QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Modification Non Effectué\n"
                                 "Changer la reference."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_rech_clicked(){
   int ref=ui->lineEdit_ref2->text().toInt();
   bool test=Etmp.rechercher(ref);
   if(test){
           ui->tableView->setModel(Etmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("Votre produit Existe!"),QMessageBox::Cancel);
       }
       else{
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("Votre produit n'existe pas!"),QMessageBox::Cancel);
       }
}
void MainWindow::on_pushButton_rech2_clicked(){
    int ref=ui->lineEdit_refch2->text().toInt();
    ui->tableView2->setModel(Etmp.chercher2(ref));


}
void MainWindow::on_pushButton_remise_clicked(){
    int ref=ui->lineEdit_refR->text().toInt();
    float r=ui->lineEdit_remise->text().toFloat();
    bool test=Etmp.rechercher(ref);
    if(test==true&&r>0){
        bool ex=Etmp.appliquer_remise(ref,r);
            ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Remise appliquée!"),QMessageBox::Cancel);
        }
   else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("Rééssayez la saisie"),QMessageBox::Cancel);
        }

}
void MainWindow::on_pushButton_stats_clicked()
{

    QChartView *chartView = new QChartView(this);
    QChart *chart = new QChart();
    double sumQuantite;
    QString categorie;
    QSqlQuery query;
    query.prepare("SELECT CATEGORIE, SUM(QUANTITE) AS SUM_QUANTITE FROM PRODUIT GROUP BY CATEGORIE");
    if (query.exec()) {
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0, 2000);
        chart->setAxisY(axisY);
        while (query.next()) {
            categorie = query.value("CATEGORIE").toString();
            sumQuantite = query.value("SUM_QUANTITE").toDouble();
            QBarSeries *series = new QBarSeries();
            QBarSet *setQuantite = new QBarSet("Quantite");
            *setQuantite << sumQuantite;
            series->append(setQuantite);
            chart->addSeries(series);
            //ajuster les axes
            series->attachAxis(axisY);
            axisX->append(categorie);
        }

        chart->setAxisX(axisX, chart->series().at(0));
    } else {
        qDebug() << "Failed to execute query or retrieve data.";
        return;
    }
    chartView->setChart(chart);

    //affichage du stat sur une nouvelle fenetre
    QMainWindow *chartWindow = new QMainWindow(this);
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(800, 600);
    chartWindow->show();
}
void MainWindow::on_pushButton_trie_clicked() {
    produit Etmp;
    ui->tableView->setModel(Etmp.sortNOM());
}
void MainWindow::on_pushButton_triQ_clicked() {
    produit Etmp;
    ui->tableView->setModel(Etmp.sortQUANTITE());
}
void MainWindow::on_pushButton_triP_clicked() {
    produit Etmp;
    ui->tableView->setModel(Etmp.sortPRIX());
}
void MainWindow::on_pushButtonPDF_clicked()

    {
        QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tableView->model()->rowCount();
                        const int columnCount = ui->tableView->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des produits</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tableView->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tableView->isColumnHidden(column)) {
                                                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);

}
void MainWindow::on_pushButton_cal_clicked(){
    int ref=ui->lineEdit_refE->text().toInt();
    float est=Etmp.calculer_estimation(ref);

    if(est>=0){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Calcul Effectué"),QMessageBox::Cancel);
        QString st=QString::number(est);
        ui->textEdit->setText(st);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("Rééssayez la saisie"),QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_rechcin_clicked(){
    int cin=ui->lineEdit_cin->text().toInt();
    QString cin1=QString::number(cin);    
    bool test=Etmp.rechercherclient(cin1);
    QByteArray cin2 = cin1.toUtf8();
    if(test){
            A.write_to_arduino(cin2);
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("command set"),QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("cin introuvable"),QMessageBox::Cancel);
    }

}
