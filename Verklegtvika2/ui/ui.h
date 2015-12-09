#ifndef UI_H
#define UI_H
#include "domain/domain.h"
// UI klasinn sér um samskipti við notenda og sækir upplýsingar í Domain klasann.

class UI : Domain
{
public:
    UI();
    void mainMenu();            // Aðalvalmynd - Býður notenda uppá að velja aðgerðir
    void cleanScreen();         // Hreinsar allt sem er á skjánum
private:
    char selection;
    string searchv;
    void listScientists();      // Valmynd - Býður uppá mismunandi valmöguleika til að sýna vísindamenn í gagnagrunni.
    void listScientistsRepeat();// Valmynd - Spyr hvort eigi að endurtaka fallið.
    void listComputers();       // Valmynd - Býður uppá mismunandi valmöguleika til að sýna tölvur í gagnagrunni.
    void listComputersRepeat(); // Valmynd - Spyr hvort eigi að endurtaka fallið.
    void listRelationship();    // Valmynd - Býður upp á mismunandi valmöguleika til að skoða tengsl milli vísindamanna og tölva
    void RandomCorS();          // Velur hvort þú viljir random tölvu eða nörd
    void RepeatRandom();        // Valmynd - Spyr hvort eigi að fá annan random, fara í Main eða hætta
    void InputInfoScientist();      // Setja nýjann tölvunarfræðing inn í gagnagrunninn frá notanda
    void InputInfoComputer();       // Setja nýjan tölvu inn í gagnagrunninn frá notanda
    void WhatToAdd();           // Adda Scientist eda tolvu
    void Search();
    void SearchRepeat();
    void SwitchForSelection();
    void InputForSelection();
    void AddToDatabaseRepeat();
    void ConnectComputer();
    void ConnectScientist();
    void SearchInput();
    void ConnectionsRepeat();
};


#endif // UI_H
