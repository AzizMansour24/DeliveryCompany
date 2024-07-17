#include "connection.h"
connection::connection(){}
bool connection::createconnection(){
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet");
    db.setUserName("aziz");
    db.setPassword("aziz123");
    if(db.open())
        test=true;
    return test;
}
void connection::closeconnection(){db.close();}
