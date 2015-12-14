#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Computer;

class Scientist
{
public:
    Scientist();
    ~Scientist();
    Scientist(int ID,string name, string gender, int Byear,int Dyear);
    Scientist(string name, string gender, int Byear, int Dyear);

    int getID();
    string getName();
    string getGender();
    int getByear();
    int getDyear();
    string getAlive();

    vector<Computer*> getComputers() const;
    void setComputers(vector<Computer> computers);

private:
    void destroyComputers();

    int ID;
    string name;
    string gender;
    int Byear;
    int Dyear;
    string Alive;

    vector<Computer*> computers;

};

#endif // SCIENTIST_H
