#ifndef DOMAIN_H
#define DOMAIN_H
#include <iostream>
#include "data/data.h"
#include <vector>
using namespace std;
class Scientists;
class Domain:Data
{
public:
    Domain();
    void SortScientists(int numb);
    void SortComputers();
    void dipslayvectorS();
    vector<Scientists*> blah;

};

#endif // DOMAIN_H
