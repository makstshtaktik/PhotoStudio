#include "Client.h"

Client::Client(string name, string surname, string email) : name(name), surname(surname), email(email)
{
}

void Client::createOrder()
{
string orderDescription;
cin>>orderDescription;
string FinishTillst;
    cin>>FinishTillst;
Order order(orderDescription, FinishTillst);
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

string Client::getEmail()
{
    return email;
}

string Client::getSurname()
{
    return surname;
}
void Client::setName(string name)
{
    this->name = name;
}

void Client::setSurname(string surname)
{
    this->surname = surname;
}

void Client::setEmail(string email)
{
    this->email = email;
}

Client::~Client()
{

}
