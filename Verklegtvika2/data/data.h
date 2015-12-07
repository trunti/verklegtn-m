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

class Scientists;
class Computers;

class Data
{
public:
    Data();
    QSqlDatabase db;
    QString dbName = "database.sqlite";
    void clearvector();
    void close();
    void SortSci(QString str);
    void openDatabase();
    void SortByCpuName();
    void SortByCpuNameA();
    void SortByCpuYear();
    void SortByCpuYearD();
    void SortByCpuType();
    void Search();
    vector<Scientists*> scient;
    vector<Computers*> comp;
private:
    int born, died, year;
    string name, gender, type, str;
};

#endif // DATA_H


