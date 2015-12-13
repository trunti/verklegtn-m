#include "scientists.h"

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
Scientist::Scientist(int ID, string name, string gender, int Byear)
{
    this->ID = ID;
    this->name = name;
    this->gender = gender;
    this->Byear = Byear;
    Alive = "Alive!";
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
