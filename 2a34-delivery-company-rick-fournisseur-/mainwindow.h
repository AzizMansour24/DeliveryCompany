#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlTableModel>
#include <QMainWindow>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   void on_pb_ajouter_clicked();

   void on_pb_supprimer_clicked();

   void on_pb_modifier_clicked();


private:
    Ui::MainWindow *ui;
    Client Ctmp;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H