#ifndef SCIENTISTS_H
#define SCIENTISTS_H
#include <iostream>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QString>
using namespace std;

class Scientists
{
public:
    QSqlDatabase db;
    QString dbName = "database.sqlite";
    Scientists();
    void addScientist();
    string name;
    string gender;
    int born;
    int died;
};

#endif // SCIENTISTS_H
