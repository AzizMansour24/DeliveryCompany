#include "mainwindow.h"
#include "connection.h"
#include "fournisseur.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


   Connection c;

   bool test = c.createConnection();
   if(test)
   {
   w.show();
   QMessageBox::information(nullptr,QObject::tr("Database is opened"),
                       QObject::tr("connection success. \n Click to exit"),QMessageBox::Cancel);
   }
   else {

       QMessageBox::critical(nullptr,QObject::tr("Database is not opened"),
                           QObject::tr("connection failed. \n Click to exit"),QMessageBox::Cancel);
       }


    return a.exec();
}
