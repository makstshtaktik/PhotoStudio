#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Repo.h"
class Consumables;
using namespace std;
#ifndef CONSUMABLES_H

#define CONSUMABLES_H
class Consumables{
public:
string name;
int quantity;
Consumables(string name, int quantity);
void addConsumable(Repo* repo, Consumables* consumable);
void removeConsumables(Repo* repo);
string toString();
};
#endif