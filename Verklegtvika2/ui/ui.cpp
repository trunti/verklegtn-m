#include "ui/ui.h"
#include "domain/domain.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

UI::UI()
{

}

void UI::mainMenu()
{
    char selection;

    cout << "########## THE COMPUTER SCIENTISTS DATABASE ##########" << endl;
    cout << endl;
    cout << "Please select 1-5 (You can always press Q to quit): " << endl;
    cout << endl;
    cout << "1: See list of scientists in the database." << endl;
    cout << "2: See list of computers in the database." << endl;
    cout << "3: See relationship between computers and scientists" << endl;
    cout << "4: Add new computer or scientists to database. " << endl;
    cout << "5: Search for scientists or computer." << endl;

    cout << endl;
    cout << "Selection: ";
    cin >> selection;

    switch (selection)
    {
    case '1':
        cleanScreen();
        cout << "##################### SCIENTISTS #####################" << endl << endl;
        listScientists();
        break;
    case '2':
        cleanScreen();
        cout << "##################### COMPUTERS ######################" << endl << endl;
        listComputers();
        break;
    case '3':
        cleanScreen();
        cout << "#### RELATIONSHIP BTWEEN COMPUTERS AND SCIENTISTS ####" << endl << endl;
        listRelationship();
        break;
    case '4':
        cleanScreen();
        cout << "################## ADD TO DATABASE ###################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem baetir vid gagnagrunnin"  << endl;
        break;
    case '5':
        cleanScreen();
        cout << "####################### SEARCH #######################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem leitar i gagnagrunninum." << endl;
        break;
    case 'q':
    case 'Q': return exit (-1);
        break;
    default:
        cleanScreen();
        cout << "Error: Invalid choice, try again!" << endl << endl;
        mainMenu();
        break;
    }
}

void UI::cleanScreen()
{
    system("CLS");
}

void UI::listScientists()
{
    char selection;

    cout << "How should the list be sorted: " << endl << endl;
    cout << "1: By name (A-Z)" << endl;
    cout << "2: By name (Z-A)" << endl;
    cout << "3: By gender (M/F)" << endl;
    cout << "4: By gender (F/M)" << endl;
    cout << "5: By..." << endl;

    cout << endl << "You can press 'M' to go back to MAIN or 'Q' to QUIT." << endl;

    cout << endl;
    cout << "Selection: ";
    cin >> selection;

    switch (selection)
    {
    case '1':
        cleanScreen();
        cout << "################## SCIENTISTS (A-Z) ##################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem  synir visindamenn i stafrofsrod" << endl;
        break;
    case '2':
        cleanScreen();
        cout << "################## SCIENTISTS (Z-A) ##################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem  sýnir vísindamenn i ofugri stafrofsrod" << endl;
        break;
    case '3':
        cleanScreen();
        cout << "################## SCIENTISTS (M-F) ##################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem synir visindamenn eftir kyni, kk-kvk" << endl;
        break;
    case '4':
        cleanScreen();
        cout << "################## SCIENTISTS (F-M) ##################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem synir visindamenn eftir kyni, kvk-kk" << endl;
        break;
    case '5':
        cleanScreen();
        cout << "################## SCIENTISTS (...) ##################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem synir visindamenn eftir..." << endl;
        break;
    case 'm':
    case 'M':
        cleanScreen();
        mainMenu();
        break;
    case 'q':
    case 'Q': return exit (-1);
        break;
    default:
        cleanScreen();
        cout << "Error: Invalid choice, try again!" << endl << endl;
        listScientists();
        break;
    }
}

void UI::listComputers()
{
    char selection;

    cout << "How should the list be sorted: " << endl << endl;
    cout << "1: By name (A-Z)" << endl;
    cout << "2: By name (Z-A)" << endl;
    cout << "3: By build year" << endl;
    cout << "5: By..." << endl;

    cout << endl << "You can press 'M' for MAIN or 'Q' to QUIT." << endl;

    cout << endl;
    cout << "Selection: ";
    cin >> selection;

    switch (selection)
    {
    case '1':
        cleanScreen();
        cout << "################## COMPUTERS (A-Z) ###################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem  synir tolvur i stafrofsrod" << endl;
        break;
    case '2':
        cleanScreen();
        cout << "################## COMPUTERS (Z-A) ###################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem  sýnir tolvur i ofugri stafrofsrod" << endl;
        break;
    case '3':
        cleanScreen();
        cout << "################## COMPUTERS BY YEAR #################" << endl << endl;
        cout << "Skipta mer tu fyrir fallid sem synir tolvur eftir byggingar ari" << endl;
        break;
    case '4':
        cleanScreen();
        cout << "################## COMPUTERS (...) ###################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem synir tolvur eftir..." << endl;
        break;
    case 'm':
    case 'M':
        cleanScreen();
        mainMenu();
        break;
    case 'q':
    case 'Q': return exit (-1);
        break;
    default:
        cleanScreen();
        cout << "Error: Invalid choice, try again!" << endl << endl;
        listComputers();
        break;
    }
}

void UI::listRelationship()
{
    char selection;

    cout << "How should the list be sorted: " << endl << endl;

    cout << "1: Select computer to see the scientist behinde the machine." << endl;
    cout << "2: Select scientist to see his machines." << endl;
    cout << "3: Display full list." << endl;


    cout << endl << "You can press 'M' for MAIN or 'Q' to QUIT." << endl;

    cout << endl;
    cout << "Selection: ";
    cin >> selection;

    switch (selection)
    {
    case '1':
        cleanScreen();
        cout << "################## FAMOUS COMPUTERS ##################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem synir lista af tölvum og ID numer" << endl;
        selectComputerID();
        break;
    case '2':
        cleanScreen();
        cout << "################## FAMOUS SCIENTISTS #################" << endl << endl;
        cout << "Skipta mer ut fyrir fallid sem  sýnir lista af visindamonnum og ID numer" << endl;
        selectSientistID();
        break;
    case 'm':
    case 'M':
        cleanScreen();
        mainMenu();
        break;
    case 'q':
    case 'Q': return exit (-1);
        break;
    default:
        cleanScreen();
        cout << "Error: Invalid choice, try again!" << endl << endl;
        listRelationship();
        break;
    }
}

void UI::selectComputerID()
{
    int id;

    cout << "ID: ";
    cin >> id;
    cout << "Skipta mer ut fyrir fallid sem synir tolvu og venslada visindamenn" << endl;

}

void UI::selectSientistID()
{
    int id;

    cout << "ID: ";
    cin >> id;
    cout << "Skipta mer ut fyrir fallid sem synir visindamann og vensladar tolvur" << endl;
}


