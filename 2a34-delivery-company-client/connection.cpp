#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("GestionClient");
db.setUserName("yasmine");
db.setPassword("yasmine");

if (db.open())
test=true;

    return  test;

}
