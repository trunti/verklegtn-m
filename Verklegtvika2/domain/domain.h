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
    void SearchinPersons();                     // Leitar að vísindamanni í gagnagrunni
};

#endif // DOMAIN_H
