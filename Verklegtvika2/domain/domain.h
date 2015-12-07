#ifndef DOMAIN_H
#define DOMAIN_H
#include <iostream>
#include "data/data.h"
#include <vector>
using namespace std;
class Domain:Data
{
public:
    Domain();
    void SortScientists(char select);
    void SortComputers();
    void displayvectorS();
    void displayvectorC();

};

#endif // DOMAIN_H
