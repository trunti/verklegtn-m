#include "computers.h"

Computer::Computer(int ID, string name, int year, string type, bool wasbuilt)
{
    this->ID = ID;
    this->name = name;
    this->year = year;
    this->type = type;
    this->wasbuilt = wasbuilt;
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
