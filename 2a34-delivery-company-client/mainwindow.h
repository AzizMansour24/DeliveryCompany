#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlTableModel>
#include <QMainWindow>
#include "client.h"
#include <QPushButton>
#include <QLineEdit>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>



QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void exportClientDataToCSV_c();

    void on_pb_afficher_facture_tab_8_c_clicked();

private slots:
    void on_pb_ajouter_c_clicked();

    void on_pb_supprimer_c_clicked();

    void on_pb_retrieve_c_clicked();

    void on_pb_modifier_c_clicked();

    void on_pb_rechercher_c_clicked();

    void on_pb_export_csv_c_clicked();

    void generateAnneeStatistics_c();

    void generateAddressStatistics_c();

    void generateNameStatistics_c();

    void generateFirstNameStatistics_c();

    void on_pb_trier_adresses_c_clicked();

    void on_pb_trier_adresses_decroissant_c_clicked();

    void on_pb_trier_noms_croissant_c_clicked();

    void on_pb_trier_noms_decroissant_c_clicked();

    void on_pb_trier_prenoms_croissant_c_clicked();

    void on_pb_trier_prenoms_decroissant_c_clicked();

    void on_pb_trier_annees_croissant_c_clicked();

    void on_pb_trier_annees_decroissant_c_clicked();

    void calculatePoints_c();

    int getNumberOfOrders_c(const QString &cin);

    double getTotalOrderAmount_c(const QString &cin);


private:
    Ui::MainWindow *ui;
    Client Ctmp;
    Client C;
    QSqlTableModel *model;
    QLineEdit *cinLineEdit;
    QLabel *pointsLabel;


};
#endif // MAINWINDOW_H
