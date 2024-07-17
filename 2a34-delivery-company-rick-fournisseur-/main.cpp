#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test = c.createconnect();

    if (test) {
        w.show();
        qDebug() << "Database is open. Connection successful.";
        QMessageBox::critical(nullptr, QObject::tr("Database is open"),
            QObject::tr("Connection successful.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        qDebug() << "Database is not open. Connection failed: " << QSqlDatabase::database().lastError().text();
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
            QObject::tr("Connection failed.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
