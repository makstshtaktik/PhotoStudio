#include "Client.h"
#include "Order.h"
#include "PhotoPrinting.h"
#include "FilmDeveloping.h"

Client::Client(string name, string surname, string email)
{
    this->name = name;
    this->surname = surname;
    this->email = email;
}

std::shared_ptr<Order> Client::createOrder(std::string description, int year, int month, int day, int typechoice, double physicalSpec)
{
    try {
        tm timeinfo = {};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;

        time_t deadline = mktime(&timeinfo);
        if (deadline == -1) {
            throw std::runtime_error("Invalid date provided.");
        }
        std::string dateStr = [&timeinfo]() {
            char buffer[20];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeinfo);
            return std::string(buffer);
            }();

        if (typechoice == 1) {
            return std::make_shared<PhotoPrinting>(description, dateStr, physicalSpec);
        }
        else if (typechoice == 2) {
            return std::make_shared<FilmDeveloping>(description, dateStr, static_cast<int>(physicalSpec));
        }
        else {
            throw std::out_of_range("Invalid order type choice.");
        }
    }
    catch (const std::exception& e) {
        throw;
    }
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

