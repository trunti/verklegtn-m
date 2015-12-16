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
    vector<Computer> getAllComputers(string orderBy, bool orderAscending);//nær í allar tölvur
    vector<Computer> searchComputers(string searchString, string orderBy, bool orderAscending);//leitar í gagnagrunni eftir notanda
    vector<Computer> RandomComputer();//nær í random tölvu
    vector<Computer> UpdateComputer(string WhatToUpdate, string Update, int ID);//editar í gagnagrunni eftir því sem notend vill breyta
    bool addComputer(Computer computer);//bætir við tölvu
    bool removeComputer(Computer computer);//eyðir tölvu

private:
    vector<Computer> queryComputer(string sqlQuery);//setur allt í vector

    QSqlDatabase db;
};

#endif // COMPUTERSREPOSITORIES_H
