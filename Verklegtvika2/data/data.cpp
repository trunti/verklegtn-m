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
void Data::Search()
{
    cout << "Enter search value: ";
    cin >> str;
    openDatabase();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Persons WHERE Name LIKE '%'||:Name||'%'");
        query.bindValue(":Name", QString::fromStdString(str));
        query.exec();
        while(query.next())
            {
                name = query.value("Name").toString().toStdString();
                gender = query.value("Gender").toString().toStdString();
                born = query.value("Born").toUInt();
                died = query.value("Died").toUInt();
                cout << name << endl;
                cout << gender << endl;
                cout << born << endl;
                cout << died << endl;
            }
        query.prepare("SELECT * FROM Persons WHERE Gender LIKE '%'||:Gender||'%'");
        query.bindValue(":Gender", QString::fromStdString(str));
        query.exec();
        while(query.next())
            {
                name = query.value("Name").toString().toStdString();
                gender = query.value("Gender").toString().toStdString();
                born = query.value("Born").toUInt();
                died = query.value("Died").toUInt();
                cout << name << endl;
                cout << gender << endl;
                cout << born << endl;
                cout << died << endl;
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
