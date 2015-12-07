#include "domain.h"
#include "data/scientists.h"

Domain::Domain()
{

}

void Domain::SortScientists(int numb){
    switch (numb) {
    case 1:
        cout << "blah";
        SortByNameB();
        dipslayvectorS();
        break;
    default:
        break;
    }
}

void SortComputers(){

}
void Domain::dipslayvectorS(){
    for(unsigned int i = 0; i < scient.size(); i++){
        cout << scient[i] -> name;
        cout << scient[i] -> gender;
        cout << scient[i] -> born;
        cout << scient[i] -> died << endl;
    }
}
