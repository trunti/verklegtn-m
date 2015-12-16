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
    vector<Computer> RandomComputer();
    vector<Computer> UpdateComputer(string WhatToUpdate, string Update, int ID);
    bool addComputer(Computer computer);
    bool removeComputer(Computer computer);

private:
    vector<Computer> queryComputer(string sqlQuery);
    vector<Scientist> queryScientistsByComputer(Computer computer);

    QSqlDatabase db;
};

#endif // COMPUTERSREPOSITORIES_H
