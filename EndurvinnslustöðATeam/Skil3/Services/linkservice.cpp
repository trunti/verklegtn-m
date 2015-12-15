#include "linkservice.h"

using namespace std;

linkservice::linkservice()
{

}
bool linkservice::addLink(string scientistId, string computerId)
{
    return linkRepo.addLink(scientistId, computerId);
}

vector<Links> linkservice::Relation()
{
    return linkRepo.Relations();
}
