#include "computers.h"
#include "data/data.h"

Computers::Computers()
{

}
void Computers::addComputer()
{
    Data data;
    data.openDatabase();

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
      data.close();
}
