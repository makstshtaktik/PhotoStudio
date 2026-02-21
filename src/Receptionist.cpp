#include "Receptionist.h"

#include <memory>
#include <vector>
using namespace std;

vector<std::shared_ptr<Order>> orders;

Receptionist::Receptionist(string name, string surname): name(name), surname(surname)
{

}

void Receptionist::recordOrder(std::shared_ptr<Order> order)
{
    orders.push_back(order);
}

string Receptionist::toString()
{
    return "Name: " + name + " Surname: " + surname;
}
