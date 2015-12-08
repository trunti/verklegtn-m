#include "scientists.h"
#include "data/data.h"

Scientists::Scientists()
{

}
void Scientists::addScientist()
{
    Data data;
    data.openDatabase();

   cout << "Name: ";
   getline(cin, name);
   cout << "Gender: ";
   cin >> gender;
   cout << "Born: ";
   cin >> born;
   cout << "Died: ";
   cin >> died;

      QSqlQuery query;
       query.prepare("INSERT INTO Persons (Name, Gender, Born, Died) VALUES (:Name, :Gender, :Born, :Died)");
       query.bindValue(":Name", QString::fromStdString(name));
       query.bindValue(":Gender", QString::fromStdString(gender));
       query.bindValue(":Born", QString::number(born));
       query.bindValue(":Died", QString::number(died));
       query.exec();
       data.close();
}
