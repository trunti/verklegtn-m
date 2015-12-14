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

    vector<Scientist> getAllScientists(string orderBy, bool orderAscending);
    vector<Scientist> searchScientists(string searchString, string orderBy, bool orderAscending);
    vector<Scientist> RandomScientist();
    bool addScientist(Scientist scientist);
    bool removeScientist(Scientist scientist);

private:
    vector<Scientist> queryScientist(string sqlQuery);

    QSqlDatabase db;

};

#endif // SCIENTISTREPOS_H
