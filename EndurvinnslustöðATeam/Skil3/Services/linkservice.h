#ifndef LINKSERVICE_H
#define LINKSERVICE_H

#include "Repositories/linkrepository.h"

class linkservice
{
public:
    linkservice();

    bool addLink(string scientistId, string computerId);
    vector<Links> Relation();
private:
    linkrepository linkRepo;
};

#endif // LINKSERVICE_H
