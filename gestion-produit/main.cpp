#include "mainwindow.h"
#include <QApplication>
#include<QMessageBox>
#include"connection.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test){
        w.show();
        QMessageBox::information(nullptr,QObject::tr("Database Is Open"),
                                 QObject::tr("Connection Succesful\n"),QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Database Is Not Open"),
                              QObject::tr("Connection Failed\n"),QMessageBox::Cancel);
    }

    return a.exec();
}
