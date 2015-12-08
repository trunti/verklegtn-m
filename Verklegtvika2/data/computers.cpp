#include "computers.h"
#include "data/data.h"

Computers::Computers()
{

}
void Computers::addComputer()
{
    Data data;
    data.openDatabase();

   cout << "Name: ";
   getline(cin, name);
   cout << "Year: ";
   cin >> year;
   cout << "Type: ";
   cin >> type;
   cout << "Build: ";
   cin >> built;

      QSqlQuery query;
       query.prepare("INSERT INTO Computers (Name, Gender, Born, Died) VALUES (:Name, :Year, :Type, :Build)");
       query.bindValue(":Name", QString::fromStdString(name));
       query.bindValue(":Year", QString::number(year));
       query.bindValue(":Type", QString::fromStdString(type));
       query.bindValue(":Died", QString::number(built));
       query.exec();
       data.close();
}
