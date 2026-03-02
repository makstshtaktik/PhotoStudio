//
// Created by Admin on 21.02.2026.
//

#include "Consumables.h"
#include "Client.h"
#include "Repo.h"
#include <iostream>
#include <algorithm>
using namespace std;

Consumables::Consumables(string name, int quantity): name(name), quantity(quantity)
{

}

void Consumables::addConsumable(Repo* repo, Consumables* consumable)
{
    repo->consumables.push_back(consumable);
}

void Consumables::removeConsumables(string consumablename, Repo* repo)
{
    repo->consumables.erase(std::remove_if(repo->consumables.begin(), repo->consumables.end(), [&](Consumables* c) { return c->getName() == consumablename; }),
        repo->consumables.end()
    );
}

string Consumables::toString(){
	return "Consumable: " + name + "of quantity: " + std::to_string(quantity);
}

string Consumables::getName()
{
    return name;
}

int Consumables::getQuantity()
{
    return quantity;
}

void Consumables::setName(string name)
{
    this->name = name;
}
void Consumables::setQuantity(int quantity)
{
    this->quantity = quantity;
}