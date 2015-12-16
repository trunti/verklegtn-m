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

    vector<Links> Relations();//nær í öll nöfnin af scientistum og tölvum úr connections töflunni í sql

    bool addLink(string scientistId, string computerId);//tengir saman tölvu og scientist
    bool removeLink(string RowId);//removear tengingu
private:
    QSqlDatabase db;
};

#endif // LINKREPOSITORY_H
