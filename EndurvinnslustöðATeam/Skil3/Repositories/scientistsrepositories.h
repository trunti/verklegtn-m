#ifndef SCIENTISTREPOS_H
#define SCIENTISTREPOS_H
#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include "Models/scientists.h"


class Scientistrepositories
{
public:
    Scientistrepositories();

    vector<Scientist> getAllScientists(string orderBy, bool orderAscending);//nær í alla scientist
    vector<Scientist> searchScientists(string searchString, string orderBy, bool orderAscending);//leitar eftir því sem notandi vill
    vector<Scientist> RandomScientist();//nær í random scientist
    vector<Scientist> UpdateScientist(string WhatToUpdate, string Update, int ID);//editar í gagnagrunn eftir notenda
    bool addScientist(Scientist scientist);//bætir við í gagnagrunn
    bool removeScientist(Scientist scientist);//eyðir úr gagnagrunni

private:
    vector<Scientist> queryScientist(string sqlQuery);


    QSqlDatabase db;

};

#endif // SCIENTISTREPOS_H
