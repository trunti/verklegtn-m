#include "Scientistservice.h"

Scientistservice::Scientistservice()
{

}

vector<Scientist> Scientistservice::getAllScientists(string orderBy, bool orderAscending)
{
    return scientrepo.getAllScientists(orderBy, orderAscending);
}

vector<Scientist> Scientistservice::searchScientists(string searchString, string orderBy, bool orderAscending)
{
    if (searchString.length() > 0)
    {
        return scientrepo.searchScientists(searchString, orderBy, orderAscending);
    }
    else
    {
        return scientrepo.getAllScientists(orderBy, orderAscending);
    }
}

vector<Scientist> Scientistservice::RandomScientist()
{
    return scientrepo.RandomScientist();
}

bool Scientistservice::addStudent(Scientist scientist)
{
    return scientrepo.addScientist(scientist);
}

bool Scientistservice::removeScientist(Scientist scientist)
{
    return scientrepo.removeScientist(scientist);
}

