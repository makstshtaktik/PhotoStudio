#include "Client.h"
#include "Order.h"

Client::Client(string name, string surname, string email)
{
    this->name = name;
    this->surname = surname;
    this->email = email;
}

std::shared_ptr<Order> Client::createOrder()
{
    std::string description;
    int year, month, day;

    cout << "Enter order description: ";
    cin >> description;

    cout << "Enter deadline (YYYY MM DD): ";
    cin >> year >> month >> day;

    //time conversion
    tm timeinfo = {};
    timeinfo.tm_year = year - 1900;   //1900
    timeinfo.tm_mon = month - 1;     //0-based
    timeinfo.tm_mday = day;

    time_t deadline = mktime(&timeinfo);
    std::string deadlineStr = to_string(deadline);

    std::shared_ptr<Order> order(new Order(description, deadlineStr));

    return order;
}

void Client::payOrder(std::shared_ptr<Order> order)
{
    if (order) {
        order->isPaid = true;
    }
}

string Client::toString()
{
    return "Client with name: " + name + " " + "surname: " + surname + " " + "email: " + email;
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

