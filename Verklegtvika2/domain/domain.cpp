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
        SortByName();
        displayvectorS();
        break;
    case '2':
        SortByNameB();
        displayvectorS();
        break;
    case '3':
        SortByGenderM();
        displayvectorS();
        break;
    case '4':
        SortByGenderF();
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
