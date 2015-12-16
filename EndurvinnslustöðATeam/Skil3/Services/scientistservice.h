#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "Repositories/scientistsrepositories.h"
#include <string>
using namespace std;

class Scientistservice
{
public:
    Scientistservice();
    //verið að ná í allt úr data layer til að senda til UI
    vector<Scientist> getAllScientists(string orderBy, bool orderAscending);
    vector<Scientist> searchScientists(string searchString, string orderBy, bool orderAscending);
    vector<Scientist> RandomScientist();
    vector<Scientist> UpdateScientist(string WhatToUpdate,string Update,int ID);
    bool addScientist(Scientist scientist);
    bool removeScientist(Scientist scientist);

private:
    Scientistrepositories scientrepo;
};

#endif // SCIENTISTSERVICE_H
