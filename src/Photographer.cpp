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

void Photographer::PhotographerHandler(std::shared_ptr<Repo> repo, int phchoice) {
    if (phchoice == 1) {
        cout << "\n--- ASSIGNED ORDERS ---\n";
        for (auto& o : repo->orders) {
            cout << "ID: " << o.first << " | " << o.second->toString() << endl;
        }
    }
    else if (phchoice == 2) {
        int id;
        cout << "Enter Order ID to finish: ";
        cin >> id;

        if (repo->orders.find(id) != repo->orders.end()) {
            repo->orders[id]->isFinished = true;
            cout << "Order marked as completed.\n";
        }
        else {
            cout << "Order not found.\n";
        }
    }
}
