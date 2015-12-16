#include "computerservice.h"

Computerservice::Computerservice()
{

}

vector<Computer> Computerservice::getAllComputers(string orderBy, bool orderAscending)
{
    return comprepo.getAllComputers(orderBy, orderAscending);
}

vector<Computer> Computerservice::searchComputers(string searchString, string orderBy, bool orderAscending)
{
    if (searchString.length() > 0)
    {
        return comprepo.searchComputers(searchString, orderBy, orderAscending);
    }
    else
    {
        return comprepo.getAllComputers(orderBy, orderAscending);
    }
}
vector<Computer> Computerservice::UpdateComputer(string WhatToUpdate, string Update, int ID)
{
   return comprepo.UpdateComputer(WhatToUpdate,Update,ID);
}
vector<Computer> Computerservice::RandomComputer()
{
    return comprepo.RandomComputer();
}

bool Computerservice::addComputer(Computer computer)
{
    return comprepo.addComputer(computer);
}

bool Computerservice::removeComputer(Computer computer)
{
    return comprepo.removeComputer(computer);
}
