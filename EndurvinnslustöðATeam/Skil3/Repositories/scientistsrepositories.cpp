#include "Repositories/scientistsrepositories.h"
#include "Models/computers.h"
#include "Models/scientists.h"

#include <cstdlib>
#include <sstream>
#include <QString>
using namespace std;

Scientistrepositories::Scientistrepositories()
{
    QString connectionName = "Scient";

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

vector<Scientist> Scientistrepositories::getAllScientists(string orderBy, bool orderAscending)
{
    stringstream sqlQuery;

    sqlQuery << "SELECT * FROM Persons ORDER BY " << orderBy << " " << ((orderAscending) ? "ASC" : "DESC");

    return queryScientist(sqlQuery.str());
}

vector<Scientist> Scientistrepositories::searchScientists(string searchString, string orderBy, bool orderAscending)
{
    stringstream sqlQuery;

    sqlQuery << "SELECT * FROM Persons WHERE " << orderBy << " LIKE '%" << searchString << "%' ORDER BY " << orderBy << " " << ((orderAscending) ? "ASC" : "DESC");

    return queryScientist(sqlQuery.str());
}

vector<Scientist> Scientistrepositories::RandomScientist()
{
    stringstream sqlQuery;

    sqlQuery << "Select * FROM Persons ORDER BY RANDOM() LIMIT 1";

    return queryScientist(sqlQuery.str());
}

vector<Scientist> Scientistrepositories::UpdateScientist(string WhatToUpdate, string Update, int ID)
{
    stringstream sqlQuery;

    sqlQuery << "Update Persons Set " << WhatToUpdate << "='" << Update <<"' Where Id=" << ID;

    return queryScientist(sqlQuery.str());
}

bool Scientistrepositories::addScientist(Scientist scientist)
{
    db.open();

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO Persons (pName, Gender, Born, Died) VALUES ('" << scientist.getName() << "', '" << scientist.getGender() << "', " << scientist.getByear() << ", " << scientist.getDyear() << ")";

    bool success = query.exec(QString::fromStdString(sqlQuery.str()));

    db.close();
    return success;
}

bool Scientistrepositories::removeScientist(Scientist scientist)
{
    db.open();

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM Persons WHERE id = " << scientist.getID();

    bool success = query.exec(QString::fromStdString(sqlQuery.str()));

    db.close();
    return success;
}

vector<Scientist> Scientistrepositories::queryScientist(string sqlQuery)
{
    db.open();

    vector<Scientist> scient;

    QSqlQuery query(db);
    query.exec(QString::fromStdString(sqlQuery));

    while(query.next())
    {
        int id = query.value("ID").toInt();
        string name = query.value("pName").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int Byear = query.value("Born").toString().toInt();
        int Dyear = query.value("Died").toString().toInt();

        scient.push_back(Scientist(id, name, gender, Byear, Dyear));
    }

    db.close();
    return scient;
}
vector<Computer> Scientistrepositories::queryComputersByScientist(Scientist scientist)
{
    vector<Computer> computers;

    db.open();

    if (!db.isOpen())
    {
        return computers;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "SELECT s.* FROM ScientistComputerConnections scc ";
    sqlQuery << "JOIN Computers c ";
    sqlQuery << "ON c.id = scc.computerId ";
    sqlQuery << "WHERE scc.scientistId = " << scientist.getID();

    query.exec(QString::fromStdString(sqlQuery.str()));

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int yearBuilt = query.value("Year").toInt();
        bool wasbuilt = query.value("build").toBool();

        computers.push_back(Computer(id, name, yearBuilt, type, wasbuilt ));
    }

    return computers;
}
