#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "acces.h"


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    acces accessWindow;
    MainWindow mainWindow;



    // Connectez le signal loginSuccessful à la slot show() de la fenêtre principale
    QObject::connect(&accessWindow, SIGNAL(loginSuccessful()), &mainWindow, SLOT(show()));
    // Connect the signals and slots
    // Connect the signal loginSuccessful to the slot onLoginSuccessful

    QObject::connect(&accessWindow, SIGNAL(loginButtonClicked()), &mainWindow, SLOT(show()));
    QObject::connect(&accessWindow, SIGNAL(loginSuccessful(QString)), &mainWindow, SLOT(onLoginSuccessful(QString)));

       QObject::connect(&mainWindow, SIGNAL(logoutButtonClicked()), &accessWindow, SLOT(show()));
    accessWindow.show();

    Connection c;
    bool test = c.createconnect();

    if (test)
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                              QObject::tr("connection successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
