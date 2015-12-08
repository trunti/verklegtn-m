#include "data/data.h"
#include "data/scientists.h"
#include "data/computers.h"


Data::Data()
{

}
void Data::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.open();
}
void Data::clearvector(){
    scient.clear();
    comp.clear();
}
void Data::close(){
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
}

void Data::SortSci(QString str)
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare(str);
        query.bindValue("Name", QString::fromStdString("*"));
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

void Data::SortCpu(QString str)
{
    openDatabase();
        QSqlQuery query(db);
        query.prepare(str);
        query.bindValue("Name", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toString().toStdString();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
void Data::GetRandomScientist(){
    openDatabase();
        QSqlQuery query(db);
        query.prepare("Select * FROM Persons ORDER BY RANDOM() LIMIT 1");
        query.bindValue("Name", QString::fromStdString("*"));
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
void Data::GetRandomComputer(){
    openDatabase();
        QSqlQuery query(db);
        query.prepare("Select * FROM Computers ORDER BY RANDOM() LIMIT 1");
        query.bindValue("Name", QString::fromStdString("*"));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toString().toStdString();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
void Data::SearchForSci(QString str)
{
    openDatabase();
        QSqlQuery query(db);
        string s;
        cout << "Enter s: ";
        cin >> s;
        query.prepare(str);
        query.bindValue(":Name", QString::fromStdString(s));
        query.bindValue(":Gender", QString::fromStdString(s));
        query.bindValue(":Died", QString::fromStdString(s));
        query.bindValue(":Born", QString::fromStdString(s));
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
void Data::SearchForCom(QString str)
{
    openDatabase();
        QSqlQuery query(db);
        string s;
        cout << "Enter s: ";
        cin >> s;
        query.prepare(str);
        query.bindValue(":Name", QString::fromStdString(s));
        query.bindValue(":Type", QString::fromStdString(s));
        query.bindValue(":Year", QString::fromStdString(s));
        query.bindValue(":Build", QString::fromStdString(s));
        query.exec();
        while(query.next())
        {
            Computers* pComputers = new Computers();
            pComputers -> name = query.value("Name").toString().toStdString();
            pComputers -> year = query.value("Year").toUInt();
            pComputers -> type = query.value("Type").toString().toStdString();
            pComputers -> built = query.value("Build").toBool();
            comp.push_back(pComputers);
        }
}
