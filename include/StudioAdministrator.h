#include <iostream>
#include 'Consumables.h'
using namespace std

#ifndef STUDIOADMINISTRATOR_H
#define STUDIOADMINISTRATOR_H

std::vector<std::shared_ptr<Consumable>> consumables;

class StudioAdministrator{
private:
string name;
string surname;
public:
int adminId;
string ToString();
void account(std::vector<std::shared_ptr<Consumable>> consumables);
StudioAdministrator(string name, string surname);
};
#endif