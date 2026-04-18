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

void StudioAdministrator::recordphotographer(std::shared_ptr<Repo> repo, std::shared_ptr<Photographer> photographer)
{
    repo->photographers[repo->counterph] = photographer;
    repo->counterph++;
}

string StudioAdministrator::toString()
{
    return "Name: " + name + " " + " Surname: " + surname;
}

int StudioAdministrator::calc_total(std::vector<std::shared_ptr<Consumables>> consumables) {
    return std::accumulate(consumables.begin(), consumables.end(), 0,
        [](int sum, std::shared_ptr<Consumables> c) {
            return sum + (c ? c->getPrice() : 0);
        }
    );
}

void StudioAdministrator::sort(std::vector<std::shared_ptr<Consumables>> consumables) {
    std::sort(consumables.begin(), consumables.end(), [](std::shared_ptr<Consumables> a, std::shared_ptr<Consumables> b) {
        return a->getPrice() > b->getPrice();
        });
}

Photographer StudioAdministrator::findPhotographer(std::map<int, std::shared_ptr<Photographer>> photographers, int keyval)
{
    auto it = photographers.find(keyval);

    if (it != photographers.end()) {
        return *(it->second);
    }
}

void StudioAdministrator::recordreceptionist(std::shared_ptr<Repo> repo, std::shared_ptr<Receptionist> receptionist)
{
    repo->receptionists[repo->counterrp] = receptionist;
    repo->counterrp++;
}

Receptionist StudioAdministrator::findReceptionist(std::map<int, std::shared_ptr<Receptionist>> receptionists, int keyval)
{
    auto it = receptionists.find(keyval);

    if (it != receptionists.end()) {
        return *(it->second);
    }
}

void StudioAdministrator::createphotographer(std::shared_ptr<Repo> repo)
{
    string name, surname;

    cout << "Enter photographer name: ";
    cin >> name;

    cout << "Enter photographer surname: ";
    cin >> surname;

    std::shared_ptr<Photographer> photographer = make_shared<Photographer>(name, surname);

	recordphotographer(repo, photographer);

    cout << "Photographer added successfully!\n";
}

void StudioAdministrator::createreceptionist(std::shared_ptr<Repo> repo)
{
    string name, surname;

    cout << "Enter receptionist name: ";
    cin >> name;

    cout << "Enter receptionist surname: ";
    cin >> surname;

    std::shared_ptr<Receptionist> receptionist = make_shared<Receptionist>(name, surname);

    recordreceptionist(repo, receptionist);

    cout << "Receptionist added successfully!\n";
}

void StudioAdministrator::printReceptionistInfo(std::shared_ptr<Repo> repo, int id)
{
    Receptionist r = findReceptionist(repo->receptionists, id);
    cout << "Receptionist with id: " << id << " is: " << r.toString() << endl;
}

void StudioAdministrator::printPhotographerInfo(std::shared_ptr<Repo> repo, int id)
{
    Photographer p = findPhotographer(repo->photographers, id);
    cout << "Photographer with id: " << id << " is: " << p.toString() << endl;
}

void StudioAdministrator::createConsumable(std::shared_ptr<Repo> repo)
{
    string name;
    int quantity, price;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter quantity: " << endl;
    cin >> quantity;
    cout << "Enter price: " << endl;
    cin >> price;
    std::shared_ptr<Consumables> c = make_shared<Consumables>(Consumables(name, quantity, price));
    addConsumable(repo, c);
}


void StudioAdministrator::addConsumable(std::shared_ptr<Repo> repo, std::shared_ptr<Consumables> consumable)
{
    repo->consumables.push_back(consumable);
}

void StudioAdministrator::removeConsumable(std::shared_ptr<Repo> repo, string consumablename)
{

    repo->consumables.erase(std::remove_if(repo->consumables.begin(), repo->consumables.end(), [&](std::shared_ptr<Consumables> c) { return c->getName() == consumablename; }),
        repo->consumables.end()
    );
}

