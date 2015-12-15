#ifndef LINKREPOSITORY_H
#define LINKREPOSITORY_H

#include <QtSql>
#include <vector>
#include <string>

using namespace std;

struct Links{
    string sciname;
    string compname;
};

class linkrepository
{
public:
    linkrepository();

    vector<Links> Relations();

    bool addLink(string scientistId, string computerId);
    bool removeLink(string scientistId, string computerId);
private:
    QSqlDatabase db;
};

#endif // LINKREPOSITORY_H
