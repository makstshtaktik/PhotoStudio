//
// Created by Admin on 21.02.2026.
//

#include "Consumables.h"
#include "Client.h"
#include "Repo.h"
using namespace std;

Consumables::Consumables(string name, int quantity): name(name), quantity(quantity)
{

}

void Consumables::addConsumable(Repo* repo, Consumables* consumable)
{
    repo->consumables.push_back(consumable);
}

void Consumables::removeConsumables(Repo* repo)
{
    repo->consumables.erase(repo->consumables.begin(), repo->consumables.end());
}

string Consumables::toString(){
	return "Consumable: " + name + "of quantity: " + std::to_string(quantity);
}
