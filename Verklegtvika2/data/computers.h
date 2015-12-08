#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <iostream>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QString>
using namespace std;

class Computers
{
public:
    QSqlDatabase db;
    QString dbName = "database.sqlite";
    Computers();
    void addComputer();
    string name;
    int year;
    string type;
    string built;
};

#endif // COMPUTERS_H
