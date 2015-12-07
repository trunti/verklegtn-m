#include "domain.h"
#include "data/scientists.h"
#include "data/computers.h"

Domain::Domain()
{

}

void Domain::SortScientists(char select){
    clearvector();
    switch (select) {
    case '1':
        SortSci("Select * FROM Persons Order By Name");
        displayvectorS();
        break;
    case '2':
        SortSci("SELECT * FROM Persons ORDER BY Name DESC");
        displayvectorS();
        break;
    case '3':
        SortSci("SELECT * FROM Persons ORDER BY Gender");
        displayvectorS();
        break;
    case '4':
        SortSci("SELECT * FROM Persons ORDER BY Gender DESC");
        displayvectorS();
    default:
        break;
    }
    close();
}

void SortComputers(){

}
void Domain::displayvectorS(){
    for(unsigned int i = 0; i < scient.size(); i++){
        cout << scient[i] -> name << " ";
        cout << scient[i] -> gender << " ";
        cout << scient[i] -> born << " ";
        cout << scient[i] -> died << endl;
    }
}
void Domain::displayvectorC(){
    for(unsigned int i = 0; i < comp.size(); i++){
        cout << comp[i] -> name << " ";
        cout << comp[i] -> year << " ";
        cout << comp[i] -> type << " ";
        cout << comp[i] -> built << endl;
    }
}
