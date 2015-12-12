#ifndef COMPUTERSREPOSITORIES_H
#define COMPUTERSREPOSITORIES_H
#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include "Models/computers.h"


class Computersrepositories
{
public:
    Computersrepositories();

    vector<Computer> getAllComputers(string orderBy, bool orderAscending);
    vector<Computer> searchComputers(string searchString, string orderBy, bool orderAscending);
    bool addComputer(Computer computer);
    bool removeComputer(Computer computer);

private:
    vector<Computer> queryComputer(string sqlQuery);

    QSqlDatabase db;
};

#endif // COMPUTERSREPOSITORIES_H
