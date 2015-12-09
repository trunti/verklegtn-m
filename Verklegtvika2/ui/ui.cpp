#include "ui/ui.h"
#include "domain/domain.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

UI::UI(){
    mainMenu();
}

void UI::mainMenu(){
    cout << "########## THE COMPUTER SCIENTISTS DATABASE ##########" << endl;
    cout << endl;
    cout << "Please select 1-6 (You can always press Q to quit): " << endl;
    cout << endl;
    cout << "1: See list of scientists in the database." << endl;
    cout << "2: See list of computers in the database." << endl;
    cout << "3: See relationship between computers and scientists" << endl;
    cout << "4: Add new computer or scientists to database. " << endl;
    cout << "5: Search for scientists or computer." << endl;
    cout << "6: Get a random computer or scientist." << endl;

    InputForSelection();

    switch (selection){
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
        WhatToAdd();
        break;
    case '5':
        cleanScreen();
        cout << "####################### SEARCH #######################" << endl << endl;
        Search();
        break;
    case '6':
        cleanScreen();
        cout << "####################### RANDOM #######################" << endl << endl;
        RandomCorS();
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

void UI::cleanScreen(){
    system("CLS");
}

void UI::listScientists(){
    cout << "How should the list be sorted: " << endl << endl;
    cout << "1: By name (A-Z)" << endl;
    cout << "2: By name (Z-A)" << endl;
    cout << "3: By gender (M/F)" << endl;
    cout << "4: By gender (F/M)" << endl;
    cout << "5: By birth year" << endl;
    cout << "6: By birth year desc" << endl;
    cout << "7: By death year" << endl;
    cout << "8: By death year desc" << endl;
    cout << endl << "You can press 'M' to go back to MAIN or 'Q' to QUIT." << endl;

    InputForSelection();
    cleanScreen();

    switch (selection){
    case '1':
        cout << "################## SCIENTISTS (A-Z) ##################" << endl << endl;
        break;
    case '2':
        cout << "################## SCIENTISTS (Z-A) ##################" << endl << endl;
        break;
    case '3':
        cout << "################## SCIENTISTS (M-F) ##################" << endl << endl;
        break;
    case '4':
        cout << "################## SCIENTISTS (F-M) ##################" << endl << endl;
        break;
    case '5':
        cout << "################## SCIENTISTS (by birth year) ##################" << endl << endl;
        break;
    case '6':
        cout << "################## SCIENTISTS (by birth year desc) ##################" << endl << endl;
        break;
    case '7':
        cout << "################## SCIENTISTS (death year) ##################" << endl << endl;
        break;
    case '8':
        cout << "################## SCIENTISTS (death year desc) ##################" << endl << endl;
        break;
    case 'm':
    case 'M':
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
    SortScientists(selection);
    listScientistsRepeat();
}

void UI::listScientistsRepeat(){
    cout << endl << "Do you want to sort again? (Y/N)" << endl;
    cout << "You can press M to go back to the menu and Q to quit!" << endl;

    InputForSelection();

    if(selection == 'y' || selection == 'Y'){
        cleanScreen();
        cout << "##################### SCIENTISTS #####################" << endl << endl;
        listScientists();
    }
    SwitchForSelection();
    listScientistsRepeat();
}

void UI::listComputers(){
    cout << "How should the list be sorted: " << endl << endl;
    cout << "1: By name (A-Z)" << endl;
    cout << "2: By name (Z-A)" << endl;
    cout << "3: By build year" << endl;
    cout << "4: By build year DESC" << endl;
    cout << "5: By type" << endl;

    cout << endl << "You can press 'M' for MAIN or 'Q' to QUIT." << endl;

   InputForSelection();
   cleanScreen();

   switch (selection){
   case '1':
       cout << "################## COMPUTERS (A-Z) ###################" << endl << endl;
       break;
   case '2':
       cout << "################## COMPUTERS (Z-A) ###################" << endl << endl;
       break;
   case '3':
       cout << "################## COMPUTERS BY YEAR #################" << endl << endl;
       break;
   case '4':
       cout << "################ COMPUTERS BY YEAR DESC ##############" << endl << endl;
       break;
   case '5':
       cout << "################## COMPUTERS BY TYPE #################" << endl << endl;
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
   SortComputers(selection);
   listComputersRepeat();
}

void UI::listComputersRepeat(){
    cout << endl << "Do you want to sort again? (Y/N)" << endl;
    cout << "You can press M to go back to the menu and Q to quit!" << endl;

    InputForSelection();

    if(selection == 'y' || selection == 'Y'){
        cleanScreen();
        cout << "##################### COMPUTERS ######################" << endl << endl;
        listComputers();
    }
    SwitchForSelection();
    listComputersRepeat();
}

void UI::listRelationship(){
    cout << "How should the list be sorted: " << endl << endl;

    cout << "1: Select computer to see the scientist behind the machine." << endl;
    cout << "2: Select scientist to see his machines." << endl;
    cout << "3: Display full list." << endl;


    cout << endl << "You can press 'M' for MAIN or 'Q' to QUIT." << endl;

    InputForSelection();

    switch (selection){
    case '1':
        cleanScreen();
        cout << "################## FAMOUS COMPUTERS ##################" << endl << endl;
        SeeConnections(selection);
        ConnectComputer();
        break;
    case '2':
        cleanScreen();
        cout << "################## FAMOUS SCIENTISTS #################" << endl << endl;
        SeeConnections(selection);
        ConnectScientist();
        break;
    case '3':
        cleanScreen();
        cout << "################## All CONNECTIONS #################" << endl << endl;
        SeeConnections(selection);
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
    ConnectionsRepeat();
}
void UI::ConnectComputer(){
    int Comp;
    bool comp = true;
    cout << endl;
    cout << "Select a number to get connection: ";
    cin >> Comp;
    cout << endl;
    FindConnection(Comp,comp);

}
void UI::ConnectScientist(){
    int Scient;
    bool sci = false;
    cout << endl;
    cout << "Select a number to get connection: ";
    cin >> Scient;
    cout << endl;
    FindConnection(Scient,sci);
}
void UI::RepeatRandom(){
    cout << endl << "Another random scientist or computer? (Y/N)" << endl;
    cout << "You can press M to go back to the menu and Q to quit!" << endl;

    InputForSelection();

    if(selection == 'y' || selection == 'Y'){
        cleanScreen();
        cout << "####################### RANDOM #######################" << endl << endl;
        RandomCorS();
    }
    SwitchForSelection();
    RepeatRandom();
}
void UI::RandomCorS(){
    cout << "Want a random computer or scientist: " << endl << endl;

    cout << "1: Random computer." << endl;
    cout << "2: Random scientist." << endl;

    cout << endl << "You can press 'M' for MAIN or 'Q' to QUIT." << endl;

    InputForSelection();
    switch (selection){
    case '1':
        cleanScreen();
        cout << "################### RANDOM COMPUTER ###################" << endl << endl;
        RandomSciorComp(selection);
        RepeatRandom();
        break;
    case '2':
        cleanScreen();
        cout << "################### RANDOM SCIENTIST ##################" << endl << endl;
        RandomSciorComp(selection);
        RepeatRandom();
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
        RandomCorS();
        break;
    }
}
void UI::WhatToAdd()
{
    cout << "Which to you want to add?" << endl;
    cout << "1. Add a scientist to the database" << endl;
    cout << "2. Add a computer to the database" << endl;

    InputForSelection();
    cleanScreen();

    switch(selection){
    case '1':
        InputInfoScientist();
        break;
    case '2':
        InputInfoComputer();
        break;
    }
    AddToDatabaseRepeat();
}
void UI::InputInfoScientist(){
    string Name, Gender;
    int Born, Died;

    cin.ignore();

    cout << "################### ADDING SCIENTIST ##################" << endl << endl;

    cout << "Enter the name: ";
    getline(cin, Name);
    cout << "Enter gender(Male/Female): ";
    cin >> Gender;
    cout << "Born: ";
    cin >> Born;
    cout << "Year of death: ";
    cin >> Died;

    if(CorrectScientist(Name,Gender,Born,Died)){
        InputScientist(Name, Gender, Born, Died);
    }
    else{
        cout << endl;
        cout << "Something went wrong!" << endl;
        cout << "Make sure you put in the right information!" << endl;
    }

}
void UI::InputInfoComputer(){
    string Name, Type, Wasbuilt;
    int Year, choice;

    cin.ignore();

    cout << "################### ADDING COMPUTER ##################" << endl << endl;

    cout << "Name of computer: ";
    getline(cin, Name);
    cout << "Was it built(Yes/No)? ";
    cin >> Wasbuilt;
    if(Wasbuilt == "Yes" || Wasbuilt == "yes"){
        cout << "What year was it built? ";
        cin >> Year;
        cout << "What type of computer is it?" << endl;
        cout << "1. Mechanical" << endl;
        cout << "2. Transitor" << endl;
        cout << "3. Electronic" << endl;
        cout << "4. Electro-Mechanical" << endl;
        cout << "Select a type: ";
        cin >> choice;

        switch(choice){
        case 1:
            Type = "Mechanical";
            break;
        case 2:
            Type = "Transitor";
            break;
        case 3:
            Type = "Electronic";
            break;
        case 4:
            Type = "Electro-Mechanical";
            break;
        }
    }
    else{
        Year = 0;
        Type = "An idea, wasn't built";
    }

    if(CorrectComputer(Name,Year)){
        InputComputer(Name, Year, Type, Wasbuilt);
    }
    else{
        cout << endl;
        cout << "Something went wrong!" << endl;
        cout << "Make sure you put in the right information!" << endl;
    }
}
void UI::Search(){
    cout << "Please select 1-8 (You can always press Q to quit): " << endl;
    cout << endl;
    cout << "1: To search for scientists name." << endl;
    cout << "2: To search for scientists gender." << endl;
    cout << "3: To search for scientists death year." << endl;
    cout << "4: To search for scientists birth year." << endl;
    cout << "5: To search for computer name." << endl;
    cout << "6: To search for computer build year." << endl;
    cout << "7: To search for computer type." << endl;
    cout << "8: To search for if computer was built." << endl;

    InputForSelection();
    cleanScreen();
    switch (selection){
    case '1':
        cout << "################## SCIENTISTS NAME ##################" << endl << endl;
        SearchInput();
        break;
    case '2':
        cout << "################## SCIENTISTS GENDER ##################" << endl << endl;
        SearchInput();
        break;
    case '3':
        cout << "################## SCIENTISTS DEATH YEAR ##################" << endl << endl;
        SearchInput();
        break;
    case '4':
        cout << "################## SCIENTISTS BIRTH YEAR ##################" << endl << endl;
        SearchInput();
        break;
    case '5':
        cout << "################## COMPUTER NAME ##################" << endl << endl;
        SearchInput();
        break;
    case '6':
        cout << "################## COMPUTER YEAR ##################" << endl << endl;
        SearchInput();
        break;
    case '7':
        cout << "################## COMPUTER TYPE ##################" << endl << endl;
        SearchInput();
        break;
    case '8':
        cout << "################## COMPUTER BUILT ##################" << endl << endl;
        SearchInput();
        break;
    case 'm':
    case 'M':
        mainMenu();
        break;
    case 'q':
    case 'Q': return exit (-1);
        break;
    default:
        cleanScreen();
        cout << "Error: Invalid choice, try again!" << endl << endl;
        break;
    }
    SearchinPersons(selection, searchv);
    SearchRepeat();
}

void UI::SearchRepeat(){
    cout << endl << "Do you want to search again? (Y/N)" << endl;
    cout << "You can press M to go back to the menu and Q to quit!" << endl;

    InputForSelection();

    if(selection == 'y' || selection == 'Y'){
        cleanScreen();
        Search();
    }
    SwitchForSelection();
    SearchRepeat();
}
void UI::SwitchForSelection(){
    switch (selection){
    case 'N':
    case 'n':
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
    }
}
void UI::InputForSelection(){
    cout << endl;
    cout << "Selection: ";
    cin >> selection;
}
void UI::AddToDatabaseRepeat(){
    cout << endl << "Do you want to add person or computer? (Y/N)" << endl;
    cout << "You can press M to go back to the menu and Q to quit!" << endl;

    InputForSelection();

    if(selection == 'y' || selection == 'Y'){
        cleanScreen();
        WhatToAdd();
    }
    SwitchForSelection();
    AddToDatabaseRepeat();
}
void UI::SearchInput(){
    cout << "Enter search value: ";
    cin >> searchv;
}
void UI::ConnectionsRepeat(){
    cout << endl << "Do you want to see more connections? (Y/N)" << endl;
    cout << "You can press M to go back to the menu and Q to quit!" << endl;

    InputForSelection();

    if(selection == 'y' || selection == 'Y')
    {
        cleanScreen();
        listRelationship();
    }
    SwitchForSelection();
    SearchRepeat();
}
