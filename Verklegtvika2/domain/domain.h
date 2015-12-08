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
    void SortComputers(char select);
    void DisplayVectorS();
    void DisplayVectorC();
    void RandomSciorComp(char select);

};

#endif // DOMAIN_H
