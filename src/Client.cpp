#include "Client.h"

Client::Client(string name, string surname, string email) : name(name), surname(surname), email(email)
{
}

void Client::createOrder()
{
string orderDescription;
cin>>orderDescription;
Order order(orderDescription);
}

void Client::payOrder(Order order)
{
    order.isPaid = true;
}

string Client::toString()
{
    return "Client with name: " + name + " surname" + surname + " email" + email;
}

string Client::getName()
{
    return name;
}