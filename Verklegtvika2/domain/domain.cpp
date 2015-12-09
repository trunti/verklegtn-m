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
        SortSci("Select * FROM Persons Order By pName");
        DisplayVectorS();
        break;
    case '2':
        SortSci("SELECT * FROM Persons ORDER BY pName DESC");
        DisplayVectorS();
        break;
    case '3':
        SortSci("SELECT * FROM Persons ORDER BY Gender");
        DisplayVectorS();
        break;
    case '4':
        SortSci("SELECT * FROM Persons ORDER BY Gender DESC");
        DisplayVectorS();
        break;
    case '5':
        SortSci("SELECT * FROM Persons ORDER BY Born");
        DisplayVectorS();
        break;
    case '6':
        SortSci("SELECT * FROM Persons ORDER BY Born DESC");
        DisplayVectorS();
        break;
    case '7':
        SortSci("SELECT * FROM Persons ORDER BY Died");
        DisplayVectorS();
        break;
    case '8':
        SortSci("SELECT * FROM Persons ORDER BY Died DESC");
        DisplayVectorS();
        break;
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
        cout << "  ";
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
        cout << "\t  " << endl;
        cout << "------------------------------------------------------------------" << endl;

    }
}
void Domain::DisplayVectorC(){
    cout << "Name" << "\t\t\t" << "Year" << "\t" << "Type" << "\t\t\t" << "Built" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(unsigned int i = 0; i < comp.size(); i++){
        cout << "  ";
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
        if(comp[i] -> built){
            cout << "Yes!" << endl;
        }else{
            cout << "No!" << endl;
        }
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
void Domain::SearchinPersons(char select, string searchv)
{
    clearvector();
    switch (select) {
    case '1':
        SearchForSci("SELECT * FROM Persons WHERE pName LIKE '%'||:Name||'%'", searchv);
        DisplayVectorS();
        break;
    case '2':
        SearchForSci("SELECT * FROM Persons WHERE Gender LIKE '%'||:Gender||'%'", searchv);
        DisplayVectorS();
        break;
    case '3':
        SearchForSci("SELECT * FROM Persons WHERE Died LIKE '%'||:Died||'%'", searchv);
        DisplayVectorS();
        break;
    case '4':
        SearchForSci("SELECT * FROM Persons WHERE Born LIKE '%'||:Born||'%'", searchv);
        DisplayVectorS();
        break;
    case '5':
        SearchForCom("SELECT * FROM Computers WHERE Name LIKE '%'||:Name||'%'", searchv);
        DisplayVectorC();
        break;
    case '6':
        SearchForCom("SELECT * FROM Computers WHERE Year LIKE '%'||:Year||'%'", searchv);
        DisplayVectorC();
        break;
    case '7':
        SearchForCom("SELECT * FROM Computers WHERE Type LIKE '%'||:Type||'%'", searchv);
        DisplayVectorC();
        break;
    case '8':
        SearchForCom("SELECT * FROM Computers WHERE Build LIKE '%'||:Build||'%'", searchv);
        DisplayVectorC();
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
    close();
}
void Domain::InputScientist(string name, string gender, int born, int died)
{
        AddScientist(name, gender, born, died);
}
bool Domain::CorrectScientist(string name,string gender,int byear, int dyear){
    if(name == ""){
        return false;
    }
    if(gender != "Male" || gender != "Female"){
        return false;
    }
    if(byear > dyear){
        return false;
    }
    if(byear <= 1500){
        return false;
    }
    if(dyear > 2015){
        return false;
    }

    return true;
}

void Domain::InputComputer(string name, int year, string type, string wasbuilt)
{
    AddComputer(name, year, type, wasbuilt);
}
bool Domain::CorrectComputer(string name,int year){
    if(name == ""){
        return false;
    }
    if(year == 0){
        return true;
    }
    if(year <= 1500 || year > 2015){
        return false;
    }

    return true;
}

void Domain::SeeConnections(char select){
    clearvector();
    Connect();
    if(select == '1'){
        OnlyCompName();
    }
    if(select == '2'){
        OnlySciName();
    }
    if(select == '3'){
        DisplayVectorConnection();
    }
    close();
}
void Domain::OnlyCompName(){
    SortCpu("SELECT * From Computers");
    for(unsigned int i = 0; i < comp.size(); i++){
        cout << i+1 << "\t" << comp[i] -> name << endl;
    }
    close();
}
void Domain::OnlySciName(){
    SortSci("SELECT * From Persons");
    for(unsigned int i = 0; i < scient.size(); i++){
        cout << i+1 << ".\t" << scient[i] -> name << endl;
    }
    close();
}
void Domain::DisplayVectorConnection(){
    for(unsigned int i = 0; i < Relation.size(); i++){
        cout << Relation[i].Sciname << " ";
        cout << Relation[i].Compname << endl;
    }
}
void Domain::FindConnection(int numb, bool compconnection){
    clearvector();
    bool found = false;
    if(compconnection){
        SortCpu("SELECT * From Computers");
        Connect();
        cout << comp[numb - 1] -> name << " is connected to: " << endl;
        for(unsigned int i = 0; i < Relation.size(); i++){
            if(comp[numb - 1] -> name == Relation[i].Compname){
                cout << "--------------------------------------------" << endl;
                cout << Relation[i].Sciname << endl;
                found = true;
            }
        }
    }
    if(!compconnection){
        SortSci("SELECT * From Persons");
        Connect();
        cout << scient[numb - 1] -> name << " is connceted to: " << endl;
        for(unsigned int i = 0; i < Relation.size(); i++){
            if(scient[numb - 1] -> name == Relation[i].Sciname){
                cout << "--------------------------------------------" << endl;
                cout << Relation[i].Compname << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "--------------------------------------------" << endl;
        cout << "Not connected to anything!" << endl;
    }
}


