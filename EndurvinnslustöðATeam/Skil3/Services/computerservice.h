#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "Repositories/computersrepositories.h"
#include <string>

using namespace std;

class Computerservice
{
public:
    Computerservice();
    //verið að ná í allt úr data layer til að senda til UI
    vector<Computer> getAllComputers(string orderBy, bool orderAscending);
    vector<Computer> searchComputers(string searchString, string orderBy, bool orderAscending);
    vector<Computer> RandomComputer();
    vector<Computer> UpdateComputer(string WhatToUpdate,string Update,int ID);
    bool addComputer(Computer computer);
    bool removeComputer(Computer computer);

private:
    Computersrepositories comprepo;
};

#endif // COMPUTERSERVICE_H
