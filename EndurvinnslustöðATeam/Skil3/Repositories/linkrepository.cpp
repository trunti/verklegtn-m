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
vector<Links> linkrepository::Relations()
{
    Links link;
    db.open();
    vector<Links> relation;
    QSqlQuery query(db);
    query.prepare("select p.pname, c.name from Connections con join persons p on p.id = con.persons_id join computers c on c.id = con.computers_id");
    query.bindValue("con.persons_id", QString::fromStdString("*"));
    query.bindValue("con.computers_id", QString::fromStdString("*"));
    query.exec();

    while(query.next())
    {
        link.sciname = query.value("pname").toString().toStdString();
        link.compname = query.value("name").toString().toStdString();
        relation.push_back(link);
    }
    db.close();
    return relation;
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
    sqlQuery << "INSERT INTO Connections (persons_id, computers_id) VALUES ("
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
bool linkrepository::removeLink(string RowId)
{
   db.open();

   if (!db.isOpen())
   {
       return false;
   }

   QSqlQuery query(db);

   stringstream sqlQuery;
   sqlQuery << "DELETE FROM Connections WHERE id = " << RowId;

   if (!query.exec(QString::fromStdString(sqlQuery.str())))
   {
       return false;
   }

   db.close();

   return true;
}
