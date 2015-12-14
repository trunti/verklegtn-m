#ifndef LINKREPOSITORY_H
#define LINKREPOSITORY_H

#include <QtSql>
#include <vector>
#include <string>

using namespace std;

class linkrepository
{
public:
    linkrepository();

    bool addLink(string scientistId, string computerId);
private:
    QSqlDatabase db;
};

#endif // LINKREPOSITORY_H
