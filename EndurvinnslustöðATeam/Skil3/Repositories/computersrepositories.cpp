#include "Repositories/computersrepositories.h"

#include <sstream>

Computersrepositories::Computersrepositories()
{
    QString dbName = "database.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE","Comp");
    db.setDatabaseName(dbName);
}

vector<Computer> Computersrepositories::getAllComputers(string orderBy, bool orderAscending)
{
    stringstream sqlQuery;

    sqlQuery << "SELECT * FROM Computers ORDER BY " << orderBy << " " << ((orderAscending) ? "ASC" : "DESC");

    return queryComputer(sqlQuery.str());
}

vector<Computer> Computersrepositories::searchComputers(string searchString, string orderBy, bool orderAscending)
{
    stringstream sqlQuery;

    sqlQuery << "SELECT * FROM Computers WHERE " << orderBy << " LIKE '%" << searchString << "%' ORDER BY " << orderBy << " " << ((orderAscending) ? "ASC" : "DESC");

    return queryComputer(sqlQuery.str());
}

bool Computersrepositories::addComputer(Computer computer)
{
    db.open();

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO Computers (Name, Year, Type, Build) VALUES ('" << computer.getName() << "', " << computer.getType() << "', " << computer.getYear() << "', " << computer.getWasbuilt() << ")";

    bool success = query.exec(QString::fromStdString(sqlQuery.str()));

    db.close();
    return success;
}

bool Computersrepositories::removeComputer(Computer computer)
{
    db.open();

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM Computers WHERE id = " << computer.getID();

    bool success = query.exec(QString::fromStdString(sqlQuery.str()));

    db.close();
    return success;
}

vector<Computer> Computersrepositories::queryComputer(string sqlQuery)
{
    db.open();

    vector<Computer> comp;

    QSqlQuery query(db);
    query.exec(QString::fromStdString(sqlQuery));

    while(query.next())
    {
        int id = query.value("ID").toInt();
        string name = query.value("Name").toString().toStdString();
        int year = query.value("Year").toString().toInt();
        string type = query.value("type").toString().toStdString();
        bool wasbuilt = query.value("Build").toString().toInt();

        comp.push_back(Computer(id, name, year, type, wasbuilt));
    }

    db.close();
    return comp;
}

