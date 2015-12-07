#include "data/data.h"
#include "data/scientists.h"
#include "data/computers.h"


Data::Data()
{

}
void Data::openDatabase()
{
    db.setDatabaseName(dbName);
    db.open();
}
void Data::SortByName()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Persons ORDER BY Name DESC");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Gender", QString::fromStdString("*"));
        query.bindValue("Born", QString::fromStdString("*"));
        query.bindValue("Died", QString::fromStdString("*"));
        query.exec();
        while(query.next())
            {
                name = query.value("Name").toString().toStdString();
                gender = query.value("Gender").toString().toStdString();
                born = query.value("Born").toUInt();
                died = query.value("Died").toUInt();
            }
}
void Data::SortByNameB()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Persons ORDER BY Name");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Gender", QString::fromStdString("*"));
        query.bindValue("Born", QString::fromStdString("*"));
        query.bindValue("Died", QString::fromStdString("*"));
        query.exec();
        while(query.next())
            {
                Scientists* pScientist = new Scientists();
                pScientist -> name = query.value("Name").toString().toStdString();
                pScientist -> gender = query.value("Gender").toString().toStdString();
                pScientist -> born = query.value("Born").toUInt();
                pScientist -> died = query.value("Died").toUInt();
                scient.push_back(pScientist);
                cout << scient[1] -> name;
            }
}
void Data::SortByGenderF()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Persons ORDER BY Gender");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Gender", QString::fromStdString("*"));
        query.bindValue("Born", QString::fromStdString("*"));
        query.bindValue("Died", QString::fromStdString("*"));
        query.exec();
        while(query.next())
            {
                Scientists* pScientist = new Scientists();
                pScientist -> name = query.value("Name").toString().toStdString();
                pScientist -> gender = query.value("Gender").toString().toStdString();
                pScientist -> born = query.value("Born").toUInt();
                pScientist -> died = query.value("Died").toUInt();
                scient.push_back(pScientist);
            }
}
void Data::SortByGenderM()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Persons ORDER BY Gender DESC");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Gender", QString::fromStdString("*"));
        query.bindValue("Born", QString::fromStdString("*"));
        query.bindValue("Died", QString::fromStdString("*"));
        query.exec();
        while(query.next())
            {
                Scientists* pScientist = new Scientists();
                pScientist -> name = query.value("Name").toString().toStdString();
                pScientist -> gender = query.value("Gender").toString().toStdString();
                pScientist -> born = query.value("Born").toUInt();
                pScientist -> died = query.value("Died").toUInt();
                scient.push_back(pScientist);
            }
}
void Data::SortByCpuName()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Computers ORDER BY Name");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Year", QString::fromStdString("*"));
        query.bindValue("Type", QString::fromStdString("*"));
        query.bindValue("Build", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toUInt();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
void Data::SortByCpuNameD()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Computers ORDER BY Name DESC");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Year", QString::fromStdString("*"));
        query.bindValue("Type", QString::fromStdString("*"));
        query.bindValue("Build", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toUInt();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
void Data::SortByCpuYear()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Computers ORDER BY Year");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Year", QString::fromStdString("*"));
        query.bindValue("Type", QString::fromStdString("*"));
        query.bindValue("Build", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toUInt();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
void Data::SortByCpuYearD()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Computers ORDER BY Year DESC");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Year", QString::fromStdString("*"));
        query.bindValue("Type", QString::fromStdString("*"));
        query.bindValue("Build", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toUInt();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
void Data::SortByCpuType()
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Computers ORDER BY Type");
        query.bindValue("Name", QString::fromStdString("*"));
        query.bindValue("Year", QString::fromStdString("*"));
        query.bindValue("Type", QString::fromStdString("*"));
        query.bindValue("Build", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toUInt();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
