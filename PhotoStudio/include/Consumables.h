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
    string name;
    int quantity;
public:
    string getName();
    int getQuantity();
    void setQuantity(int quantity);
    void setName(string name);
Consumables(string name, int quantity);
void addConsumable(Repo* repo, Consumables* consumable);
void removeConsumables(string consumablename, Repo* repo);
string toString();
};
#endif