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
        DisplayVectorS();
        break;
    case '2':
        SortSci("SELECT * FROM Persons ORDER BY Name DESC");
        DisplayVectorS();
        break;
    case '3':
        SortSci("SELECT * FROM Persons ORDER BY Gender");
        DisplayVectorS();
        break;
    case '4':

        SortSci("SELECT * FROM Persons ORDER BY Gender DESC");
        DisplayVectorS();
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
        DisplayVectorC();
        break;
    case '2':
        SortCpu("SELECT * FROM Computers ORDER BY Name DESC");
        DisplayVectorC();
        break;
    case '3':
        SortCpu("SELECT * FROM Computers ORDER BY Year");
        DisplayVectorC();
        break;
    case '4':
        SortCpu("SELECT * FROM Computers ORDER BY Year DESC");
        DisplayVectorC();
        break;
    case '5':
        SortCpu("SELECT * FROM Computers ORDER BY Type");
        DisplayVectorC();
        break;
    default:
        break;
    }
    close();
}
void Domain::DisplayVectorS(){
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
void Domain::DisplayVectorC(){
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
void Domain::RandomSciorComp(char select){
    clearvector();
    if(select == '1'){
        GetRandomComputer();
        DisplayVectorC();
    }
    if(select == '2'){
        GetRandomScientist();
        DisplayVectorS();
    }
    close();
}
void Domain::SearchinPersons()
{
    clearvector();
    char c;
    cout << "Enter c: ";
    cin >> c;
    switch (c) {
    case '1':
        SearchForSci("SELECT * FROM Persons WHERE Name LIKE '%'||:Name||'%'");
        DisplayVectorS();
        break;
    case '2':
        SearchForSci("SELECT * FROM Persons WHERE Gender LIKE '%'||:Gender||'%'");
        DisplayVectorS();
    case '3':
        SearchForSci("SELECT * FROM Persons WHERE Died LIKE '%'||:Died||'%'");
        DisplayVectorS();
    case '4':
        SearchForSci("SELECT * FROM Persons WHERE Born LIKE '%'||:Born||'%'");
        DisplayVectorS();
    case '5':
        SearchForCom("SELECT * FROM Computers WHERE Name LIKE '%'||:Name||'%'");
        DisplayVectorC();
        break;
    case '6':
        SearchForCom("SELECT * FROM Computers WHERE Year LIKE '%'||:Year||'%'");
        DisplayVectorC();
    case '7':
        SearchForCom("SELECT * FROM Computers WHERE Type LIKE '%'||:Type||'%'");
        DisplayVectorC();
    case '8':
        SearchForCom("SELECT * FROM Computers WHERE Build LIKE '%'||:Build||'%'");
        DisplayVectorC();
    default:
        break;
    }

}
