#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"

Connection::Connection(){}

bool Connection::createConnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    db.setDatabaseName("Source_ProjetA");
    db.setUserName("rick");
    db.setPassword("esprit18");
    if(db.open()) test = true;
    return test;
}
void Connection::closeConnection(){db.close();}
