#include "linkrepository.h"

#include <cstdlib>
#include <sstream>
#include <QString>

using namespace std;


linkrepository::linkrepository()
{
    QString connectionName = "link";

    if(QSqlDatabase::contains(connectionName))
    {
        db = QSqlDatabase::database(connectionName);
    }
    else
    {
    QString dbName = "database.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE",connectionName);
    db.setDatabaseName(dbName);
    }
}
bool linkrepository::addLink(string scientistId, string computerId)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO ScientistComputerConnections (scientistId, computerId) VALUES ("
             << "'" << scientistId << "', "
             << "'" << computerId << "'"
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}
