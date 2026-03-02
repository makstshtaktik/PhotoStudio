#include "Photographer.h"
#include "Order.h"
#include "Consumables.h"
#include "Repo.h"
#include <iostream>
using namespace std;

void Photographer::performOrder(Order order)
{
    order.isFinished = true;

}

void Photographer::useConsumables(std::vector<Consumables *> consumable)
{
    consumable.clear();
}

Photographer::Photographer(string name, string surname): name(name), surname(surname)
{

}

string Photographer::getName()
{
    return name;
}

string Photographer::getSurname()
{
    return surname;
}

void Photographer::setSurname(string surname)
{
    this->surname = surname;
}

void Photographer::setName(string name)
{
    this->name = name;
}
