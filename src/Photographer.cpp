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

void Photographer::useConsumables(std::vector<std::shared_ptr<Consumables>> consumable)
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

string Photographer::toString() {
    return "Name: " + name + " " + "Surname: " + surname;
}

bool Photographer::completeOrder(std::shared_ptr<Repo> repo, int orderId) {
    std::lock_guard<std::mutex> lock(repo->repoMutex);

    auto it = repo->orders.find(orderId);
    if (it != repo->orders.end() && it->second != nullptr) {
        it->second->isFinished = true;
        return true;
    }
    return false;
}