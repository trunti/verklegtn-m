#include "scientists.h"
#include "Models/computers.h"

Scientist::Scientist()
{

}

Scientist::~Scientist()
{
    destroyComputers();
}

Scientist::Scientist(int ID, string name, string gender, int Byear, int Dyear)
{
    this->ID = ID;
    this->name = name;
    this->gender = gender;
    this->Byear = Byear;
    if(Dyear == 0)
    {
        this->Dyear = 2016;
    }
    else
    {
        this->Dyear = Dyear;
    }
}
Scientist::Scientist(string name, string gender, int Byear, int Dyear)
{
    this->name = name;
    this->gender = gender;
    this->Byear = Byear;
    this->Dyear = Dyear;
}
int Scientist::getID()
{
    return ID;
}

string Scientist::getName()
{
    return name;
}

string Scientist::getGender()
{
    return gender;
}

int Scientist::getByear()
{
    return Byear;
}

int Scientist::getDyear()
{
    return Dyear;
}

string Scientist::getAlive()
{
    return Alive;
}
void Scientist::destroyComputers()
{
    for (unsigned int i = 0; i < computers.size(); i++)
    {
        delete computers.at(i);
    }
}
vector<Computer*> Scientist::getComputers() const
{
    return computers;
}

void Scientist::setComputers(vector<Computer> newComputers)
{
    destroyComputers();

    for (unsigned int i = 0; i < newComputers.size(); i++)
    {
        Computer currentComputer;
        currentComputer = newComputers.at(i);
        this->computers.push_back(new Computer(currentComputer.getID(), currentComputer.getName(), currentComputer.getYear(), currentComputer.getType(),currentComputer.getWasbuilt()));
    }
}
