#include "domain.h"
#include "data/scientists.h"

Domain::Domain()
{

}

void Domain::SortScientists(char select){
    clearvector();
    switch (select) {
    case '1':
        SortByName();
        dipslayvectorS();
        break;
    case '2':
        SortByNameB();
        dipslayvectorS();
        break;
    case '3':
        SortByGenderM();
        dipslayvectorS();
        break;
    case '4':
        SortByGenderF();
        dipslayvectorS();
    default:
        break;
    }
    close();
}

void SortComputers(){

}
void Domain::dipslayvectorS(){
    for(unsigned int i = 0; i < scient.size(); i++){
        cout << scient[i] -> name << " ";
        cout << scient[i] -> gender << " ";
        cout << scient[i] -> born << " ";
        cout << scient[i] -> died << endl;
    }
}
