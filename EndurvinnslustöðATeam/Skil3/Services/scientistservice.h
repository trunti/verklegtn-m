#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "Repositories/scientistsrepositories.h"
#include <string>
using namespace std;

class Scientistservice
{
public:
    Scientistservice();

    vector<Scientist> getAllScientists(string orderBy, bool orderAscending);
    vector<Scientist> searchScientists(string searchString, string orderBy, bool orderAscending);
    vector<Scientist> RandomScientist();

    bool addStudent(Scientist scientist);
    bool removeScientist(Scientist scientist);

private:
    Scientistrepositories scientrepo;
};

#endif // SCIENTISTSERVICE_H
