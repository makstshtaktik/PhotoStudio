#include <iostream>
using namespace std
#ifndef CONSUMABLES_H

#define CONSUMABLES_H
std::vector<std::shared_ptr<Consumable>> consumables
class Consumables{
public:
string name;
int quantity;
Consumables(string name, int quantity);
Consumables addConsumable();
void removeConsumable(Consumable consumable);
};
#endif