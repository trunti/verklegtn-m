#ifndef LINKSERVICE_H
#define LINKSERVICE_H

#include "Repositories/linkrepository.h"

class linkservice
{
public:
    linkservice();
    //verið að ná í allt úr data layer til að senda til UI
    bool addLink(string scientistId, string computerId);
    bool removeLink(string RowId);
    vector<Links> Relation();

private:
    linkrepository linkRepo;
};

#endif // LINKSERVICE_H
