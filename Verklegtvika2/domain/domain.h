#ifndef DOMAIN_H
#define DOMAIN_H

#include "data/data.h"
#include <iostream>

using namespace std;

class Domain:Data

{
public:
    Domain();
    void SortScientists(char select);           // Tekur við skipun frá UI um hvernig skuli prenta út vísindamenn í gagnagrunni.
    void SortComputers(char select);            // Tekur við skipun frá UI um hvernig skuli prenta út tölvur í gagnagrunni.
    void DisplayVectorS();                      // Prentar út vísindamenn eftir ósk notenda.
    void DisplayVectorC();                      // Prentar út tölvur eftir ósk notenda.
    void RandomSciorComp(char select);          // Prentar út tölvu eða vísindamann af handahófi.
    void SearchinPersons(char select, string searchv);                     // Leitar að vísindamanni í gagnagrunni.
    void DisplayVectorConnection();             // Prentar út tengingarnar á milli vísindamanna og tölva.
    void SeeConnections(char select);           // Sýnir tengingar á milli vísindamanna og tölva af beiðni notanda.
    void InputScientist(string name, string gender, int born, int died); //Flytur a milli UI og Datalayer fyrir Scientist
    void InputComputer(string name, int year, string type, string wasbuilt);  //Fltur a milli UI og Datalayer fyrir Computer
    void OnlyCompName();
    void OnlySciName();
    void FindConnection(int numb, bool compconnection);
};

#endif // DOMAIN_H
