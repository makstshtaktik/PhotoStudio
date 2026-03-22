#include "StudioAdministrator.h"
#include <numeric>
#include <algorithm>

StudioAdministrator::StudioAdministrator(string name, string surname): name(name), surname(surname)
{

}

void StudioAdministrator::account(std::vector<std::shared_ptr<Consumables>> consumables)
{
    for (auto consumable : consumables)
    {
        cout << "Name: " << consumable->getName() << "Quantity" + to_string(consumable->getQuantity()) + "\n";
    }
}

string StudioAdministrator::toString()
{
    return "Name: " + name + " Surname: " + surname;
}

int StudioAdministrator::calc_total(std::vector<Consumables*> consumables) {
    return std::accumulate(consumables.begin(), consumables.end(), 0,
        [](int sum, Consumables* c) {
            return sum + (c ? c->getPrice() : 0);
        }
    );
}

void StudioAdministrator::sort(std::vector<Consumables*> consumables) {
    std::sort(consumables.begin(), consumables.end(), [](Consumables* a, Consumables* b) {
        return a->getPrice() > b->getPrice();
        });
}
