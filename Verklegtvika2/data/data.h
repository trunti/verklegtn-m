// Hefur samskipti við gagnagrunn og les inn í computers- og scientists klasana.
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QString>
using namespace std;


class Data
{
public:
    Data();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "database.sqlite";
    void SortByName();
    void SortByNameB();
    void SortByGenderF();
    void SortByGenderM();
    void SortByCpuName();
    void openDatabase();
    void SortByCpuNameD();
    void SortByCpuYear();
    void SortByCpuYearD();
    void SortByCpuType();
private:
    int born, died, year;
    string name, gender, type;
};

#endif // DATA_H


