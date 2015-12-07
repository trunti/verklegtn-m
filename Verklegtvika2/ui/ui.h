#ifndef UI_H
#define UI_H

// UI klasinn sér um samskipti við notenda og sækir upplýsingar í Domain klasann.

class UI
{
public:
    UI();
    void mainMenu();            // Aðalvalmynd - Býður notenda uppá að velja aðgerðir
    void cleanScreen();         // Hreinsar allt sem er á skjánum
private:
    void listScientists();      // Valmynd - Býður uppá mismunandi valmöguleika til að sýna vísindamenn í gagnagrunni.
    void listComputers();       // Valmynd - Býður uppá mismunandi valmöguleika til að sýna tölvur í gagnagrunni.
    void listRelationship();    // Valmynd - Býður upp á mismunandi valmöguleika til að skoða tengsl milli vísindamanna og tölva
    void selectComputerID();    // Býður uppá að velja vísindamann og athugar hvort ID til í gagnagrunni, skilar ID til baka ef það finnst.
    void selectSientistID();    // Býður uppá að velja tölvu og athugar hvort ID sé í gagnagrunni, skilar ID til baka ef það finnst.


};


#endif // UI_H
