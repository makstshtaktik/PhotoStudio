#pragma once
#include <iostream>
#include <memory>
#include <vector>
class Consumables;
using namespace std;
#ifndef CONSUMABLES_H

#define CONSUMABLES_H
class Consumables{
public:
string name;
int quantity;
Consumables(string name, int quantity);
void addConsumable(std::shared_ptr<Consumables> consumable);
void removeConsumables();
};
#endif