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
    Relation.clear();
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
                pScientist -> name = query.value("pName").toString().toStdString();
                pScientist -> gender = query.value("Gender").toString().toStdString();
                pScientist -> born = query.value("Born").toUInt();
                pScientist -> died = query.value("Died").toUInt();
                scient.push_back(pScientist);
            }
        close();
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
        close();
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
                pScientist -> name = query.value("pName").toString().toStdString();
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
            pScientist -> name = query.value("pName").toString().toStdString();
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
void Data::AddComputer(string name, int year, string type, string wasbuilt)
{
    openDatabase();

      QSqlQuery query;
      query.prepare("INSERT INTO Computers (Name, Year, Type, Build) VALUES (:Name, :Year, :Type, :Build)");
      query.bindValue(":Name", QString::fromStdString(name));
      query.bindValue(":Year", QString::number(year));
      query.bindValue(":Type", QString::fromStdString(type));
      if(wasbuilt == "Yes")
      {
          query.bindValue(":Build", QString::number(1));
      }
      if(wasbuilt == "No")
      {
          query.bindValue(":Build", QString::number(0));
      }
      query.exec();
      close();
}
void Data::AddScientist(string name, string gender, int born, int died)
{
    openDatabase();

      QSqlQuery query;
      query.prepare("INSERT INTO Persons (pName, Gender, Born, Died) VALUES (:Name, :Gender, :Born, :Died)");
      query.bindValue(":Name", QString::fromStdString(name));
      query.bindValue(":Gender", QString::fromStdString(gender));
      query.bindValue(":Born", QString::number(born));
      query.bindValue(":Died", QString::number(died));
      query.exec();
      close();
}
void Data::Connect()
{
   Connections connect;
  openDatabase();
      QSqlQuery query(db);
      query.prepare("select p.pname, c.name from Connections con join persons p on p.id = con.persons_id join computers c on c.id = con.computers_id");
      query.bindValue("con.persons_id", QString::fromStdString("*"));
      query.bindValue("con.computers_id", QString::fromStdString("*"));
      query.exec();
      while(query.next())
      {

          connect.Sciname = query.value("pname").toString().toStdString();
          connect.Compname = query.value("name").toString().toStdString();
          Relation.push_back(connect);
      }
      close();
}
