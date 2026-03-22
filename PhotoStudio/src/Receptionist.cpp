#include "Receptionist.h"
#include "Repo.h"
#include <numeric>
#include <functional>
#include <algorithm>
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

Order Receptionist::findOrders(std::map<int, Order*> orders, int keyval) {
    auto it = orders.find(keyval);
    
    if (it != orders.end()) {
        return *(it->second);
    }
}

Client Receptionist::findClients(std::map<int, Client*> clients, int keyval) {
    auto it = clients.find(keyval);

    if (it != clients.end()) {
        return *(it->second);
    }
}
