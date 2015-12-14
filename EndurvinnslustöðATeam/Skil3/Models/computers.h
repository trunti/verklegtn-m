#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Computer
{
public:
    Computer(int ID, string name, int year, string type, bool wasbuilt);
    Computer(string name, int year, string type, int wasBuilt);

    int getID();
    string getName();
    int getYear();
    string getType();
    bool getWasbuilt();

private:
    int ID;
    string name;
    int year;
    string type;
    bool wasbuilt;
    int wasBuilt;

};

#endif // COMPUTERS_H
