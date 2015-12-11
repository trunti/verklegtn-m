// Hefur samskipti við gagnagrunn og les inn í computers- og scientists klasana.

#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QString>
using namespace std;

class Scientists;
class Computers;

struct Connections {
   string Sciname;
   string Compname;
};

class Data
{
public:
   Data();                                                                  // Sjálfgefinn smiður
   QSqlDatabase db;
   QString dbName = "database.sqlite";                                      // Gagnagrunnur.
   void clearvector();                                                      // Hreinsar út af skjá.
   void close();                                                            // Lokar gagnagrunn.
   void GetScientists(QString str);                                         // Tekur við skipun frá domain um það hvernig eigi að flokka vísindamenn í gagnagrunni.
   void openDatabase();                                                     // Opnar gagnargrunn.
   void GetComputers(QString str);                                          // Tekur við skipun frá domain um hvernig eigi að flokka tölvur í gagnagrunni.
   void GetRandomScientist();                                               // Sækir vísindamann af handahófi úr gagnagrunni.
   void GetRandomComputer();                                                // Sækir tölvu af handahófi úr gagnagrunni.
   void SearchForSci(QString str, string searchv);                          // Tekur við skipun frá domain og vinnur úr henni í gagnagrunni við leit að ákv. vísindamanni.
   void SearchForCom(QString str, string searchv);                          // Tekur við skipun frá domain og vinnur úr henni í gagnagrunni við leit að ákv. tölvu.
   void AddScientist(string name, string gender, int born, int died);       // Flytur upplýsingar um nýjann vísindamann inn í gagnagrunn.
   void AddComputer(string name, int year, string type, string wasbuilt);   // Flytur upplýsingar um nýjann tölvur inn í gagnagrunn.
   void Connect();                                                          // Sér um að tengja saman upplýsingar.
   vector<Connections> Relation;                                            // Fylki sem geymir upplýsingaru um tengingar milli vísindamanna og tölva.
   vector<Scientists*> scient;                                              // Fylki sem geymir upplýsingar um vísindamenn.
   vector<Computers*> comp;                                                 // Fylki sem geymir upplýsingar um tölvur.
private:
   int born, died, year;
   string name, gender, type, str;
};

#endif // DATA_H


