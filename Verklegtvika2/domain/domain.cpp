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

void Domain::SortComputers(char select){
    clearvector();
    switch (select) {
    case '1':
        SortCpu("SELECT * FROM Computers ORDER BY Name");
        displayvectorC();
        break;
    case '2':
        SortCpu("SELECT * FROM Computers ORDER BY Name DESC");
        displayvectorC();
        break;
    case '3':
        SortCpu("SELECT * FROM Computers ORDER BY Year");
        displayvectorC();
        break;
    case '4':
        SortCpu("SELECT * FROM Computers ORDER BY Year DESC");
        displayvectorC();
    default:
        break;
    }
    close();
}
void Domain::displayvectorS(){
    cout << "Name" << "\t\t\t\t" << "Gender" << "\t\t" << "Born" << "\t" << "Dead" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(unsigned int i = 0; i < scient.size(); i++){
        cout << "| ";
        cout << scient[i] -> name << "\t";
        if(scient[i] -> name.size() < 22){
            cout << "\t";
            if(scient[i] -> name.size() < 14){
                    cout << "\t";
            }
        }
        cout << scient[i] -> gender << "\t\t";
        cout << scient[i] -> born << "\t";
        if(scient[i] -> died == 0){
            cout << "Alive!";
        }else{
        cout << scient[i] -> died;
        }
        cout << "\t |" << endl;
        cout << "------------------------------------------------------------------" << endl;

    }
}
void Domain::displayvectorC(){
    cout << "Name" << "\t\t\t" << "Year" << "\t" << "Type" << "\t\t\t" << "Built" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(unsigned int i = 0; i < comp.size(); i++){
        cout << "| ";
        cout << comp[i] -> name << "\t";
        if(comp[i] -> name.size() < 16)
            cout << "\t";
            if(comp[i] -> name.size() < 6){
                    cout << "\t";
            }
        cout << comp[i] -> year << "\t";
        cout << comp[i] -> type << "\t";
        if(comp[i] -> type.size() < 13)
            cout << "\t";
        cout << comp[i] -> built << endl;
    cout << "------------------------------------------------------------------" << endl;
    }
}
