#include "computers.h"

Computer::Computer()
{

}
Computer::Computer(int ID, string name, int year, string type, bool wasbuilt)
{
    this->ID = ID;
    this->name = name;
    this->year = year;
    this->type = type;
    this->wasbuilt = wasbuilt;
}
Computer::Computer(string name, int year, string type, int wasBuilt)
{
    this->year = year;
    this->name = name;
    this->type = type;
    this->wasbuilt = wasBuilt;
}
int Computer::getID()
{
    return ID;
}
string Computer::getName()
{
    return name;
}
int Computer::getYear()
{
    return year;
}
string Computer::getType()
{
    return type;
}
bool Computer::getWasbuilt()
{
    return wasbuilt;
}

