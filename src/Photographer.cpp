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
    std::lock_guard<std::mutex> lock(repo->repoMutex);
    
    if (phchoice == 1) {
        cout << "\n--- ASSIGNED ORDERS ---\n";
        if (repo->orders.empty()) {
            cout << "No orders assigned.\n";
            return;
        }
        for (auto& o : repo->orders) {
            cout << "ID: " << o.first << " | " << o.second->toString() << endl;
        }
    }
    else if (phchoice == 2) {
        int id;
        cout << "Enter Order ID to finish: ";
        if (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ID format.\n";
            return;
        }

        auto it = repo->orders.find(id);
        if (it != repo->orders.end() && it->second != nullptr) {
            it->second->isFinished = true;
            cout << "Order #" << id << " marked as completed.\n";
        }
        else {
            cout << "Order ID " << id << " not found.\n";
        }
    }
}
