#include "StudioAdministrator.h"

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
