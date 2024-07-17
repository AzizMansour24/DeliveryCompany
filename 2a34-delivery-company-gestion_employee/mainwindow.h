#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<Employee.h>
#include<chatbotwindow.h>
#include <QMainWindow>
#include <QPrintDialog>
#include <QPrinter>
#include <QTableWidget>
#include <acces.h>
#include "arduino.h"
#include <QSerialPort>
#include <QStandardItemModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    //arduino
void readSerialData() ;
void processReceivedData(const QString& data);

    void on_pb_aff_clicked();

    void on_pb_modifier_clicked();


    void on_pushButton_30_clicked();

    void on_pushButton_33_clicked();

    void on_pb_recherche_clicked();

    void on_pb_statistiques_clicked();

    void on_pb_quitter_clicked();

    void on_pb_chatbot_clicked();
    void handleChatbotResponse(const QString &response);  // New slot to handle chatbot response

    void on_pb_presence_clicked();
void calculatePresenceForEmployee(const QString& cin);
void calculatePresenceForEnteredEmployee();
void on_pb_recherche_2_clicked();

void on_pb_presence_2_clicked();

public slots:
    void gestionChatbot(const QString &question);
       void onLoginSuccessful(const QString &roleUtilisateur);
       void retourAccesWindow();

signals:
    void logoutButtonClicked();
     void chatbotQuestionAsked(const QString &question);

private:
    Ui::MainWindow *ui;
    Employee E;
    QSqlQueryModel *model;
    ChatbotWindow *chatbotWindow;
    // Ajoutez une méthode privée pour vérifier les droits d'accès
    void configureAccessRights(const QString &roleUtilisateur);
       QSerialPort *serial;  // Declaration of QSerialPort instance

    Arduino A;
};


class PresenceTableModel : public QStandardItemModel {
public:
    PresenceTableModel(QObject *parent = nullptr);
    void calculatePresenceForEmployee(const QString& cin);

private:
    QMap<QDate, int> totalHoursData;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
