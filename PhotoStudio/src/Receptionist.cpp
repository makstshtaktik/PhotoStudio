#include "Receptionist.h"
#include "Repo.h"
using namespace std;


Receptionist::Receptionist(string name, string surname): name(name), surname(surname)
{

}

void Receptionist::recordOrder(Repo* repo, Order* order) {
    repo->orders[repo->counter] = order;
    repo->counter++;
}

string Receptionist::toString()
{
    return "Name: " + name + " Surname: " + surname;
}
