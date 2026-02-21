//
// Created by Admin on 21.02.2026.
//

#include "Consumables.h"
using namespace std;

vector<shared_ptr<Consumables>> consumables;

Consumables::Consumables(string name, int quantity): name(name), quantity(quantity)
{

}

void Consumables::addConsumable(std::shared_ptr<Consumables> consumable)
{
    consumables.push_back(consumable);
}

void Consumables::removeConsumables()
{
    consumables.erase(consumables.begin(), consumables.end());
}
