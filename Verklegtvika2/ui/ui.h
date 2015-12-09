#ifndef UI_H
#define UI_H
#include "domain/domain.h"

// UI klasinn sér um samskipti við notenda og sækir upplýsingar í Domain klasann.

class UI : Domain
{
public:
    UI();
    void mainMenu();            // Aðalvalmynd - Býður notenda uppá að velja aðgerðir.
    void cleanScreen();         // Hreinsar allt sem er á skjánum.
private:
    char selection;
    string searchv;
    void listScientists();      // Valmynd - Býður uppá mismunandi valmöguleika til að sýna vísindamenn í gagnagrunni.
    void listScientistsRepeat();// Valmynd - Spyr hvort eigi að endurtaka fallið.
    void listComputers();       // Valmynd - Býður uppá mismunandi valmöguleika til að sýna tölvur í gagnagrunni.
    void listComputersRepeat(); // Valmynd - Spyr hvort eigi að endurtaka fallið.
    void listRelationship();    // Valmynd - Býður upp á mismunandi valmöguleika til að skoða tengsl milli vísindamanna og tölva.
    void RandomCorS();          // Velur hvort þú viljir random tölvu eða nörd.
    void RepeatRandom();        // Valmynd - Spyr hvort eigi að fá annan random, fara í Main eða hætta.
    void InputInfoScientist();  // Setja nýjann tölvunarfræðing inn í gagnagrunninn frá notanda.
    void InputInfoComputer();   // Setja nýjan tölvu inn í gagnagrunninn frá notanda.
    void WhatToAdd();           // Adda Scientist eda tölvu.
    void Search();              // Valmynd - Býður notenda að leitar í gagnagrunni.
    void SearchRepeat();        // Valmynd - Spyr hvort endurteki eigi leit.
    void SwitchForSelection();  // Túlkar skipuna frá notenda.
    void InputForSelection();   // Valmynd - Tekur við aðgarðarskipun frá notenda.
    void AddToDatabaseRepeat(); // Valmynd - Spyr hvort bæta eigi aftur við gagnagrunninn.
    void ConnectComputer();     // Valmynd - Spyr notenda um tölvu ID til að tenga við vísindamann.
    void ConnectScientist();    // Valmynd - Spyr notenda um vísindamanns ID til að tengja við tölvu.
    void SearchInput();         // Sendir áfram leitarfyrirspurn.
    void ConnectionsRepeat();   // Valmynd - Spyr hvort notandi vilji tengja saman aðra.
};


#endif // UI_H
