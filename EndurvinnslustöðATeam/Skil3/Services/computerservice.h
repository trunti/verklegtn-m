#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "Repositories/computersrepositories.h"
#include <string>

using namespace std;

class Computerservice
{
public:
    Computerservice();

    vector<Computer> getAllComputers(string orderBy, bool orderAscending);
    vector<Computer> searchComputers(string searchString, string orderBy, bool orderAscending);

    bool addComputer(Computer computer);
    bool removeComputer(Computer computer);

private:
    Computersrepositories comprepo;
};

#endif // COMPUTERSERVICE_H
