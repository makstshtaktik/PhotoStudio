#include "StudioAdministrator.h"
#include <numeric>
#include <algorithm>

StudioAdministrator::StudioAdministrator(string name, string surname): name(name), surname(surname)
{

}

void StudioAdministrator::account(std::vector<Consumables*> consumables)
{
    for (auto consumable : consumables)
    {
        cout << "Name: " << consumable->getName() << "Quantity" + to_string(consumable->getQuantity()) + "\n";
    }
}

void StudioAdministrator::recordphotographer(Repo* repo, Photographer* photographer)
{
    repo->photographers[repo->counterph] = photographer;
    repo->counterph++;
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

Photographer StudioAdministrator::findPhotographer(std::map<int, Photographer*> photographers, int keyval)
{
    auto it = photographers.find(keyval);

    if (it != photographers.end()) {
        return *(it->second);
    }
}

void StudioAdministrator::recordreceptionist(Repo* repo, Receptionist* receptionist)
{
    repo->receptionists[repo->counterrp] = receptionist;
    repo->counterrp++;
}

Receptionist StudioAdministrator::findReceptionist(std::map<int, Receptionist*> receptionists, int keyval)
{
    auto it = receptionists.find(keyval);

    if (it != receptionists.end()) {
        return *(it->second);
    }
}

void StudioAdministrator::printReceptionistInfo(Repo* repo, int id)
{
    Receptionist r = findReceptionist(repo->receptionists, id);
    cout << "Receptionist with id: " << id << " is: " << r.toString() << endl;
}

void StudioAdministrator::printPhotographerInfo(Repo* repo, int id)
{
    Photographer p = findPhotographer(repo->photographers, id);
    cout << "Photographer with id: " << id << " is: " << p.toString() << endl;
}

