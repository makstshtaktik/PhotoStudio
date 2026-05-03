#include "Client.h"
#include "Order.h"
#include "PhotoPrinting.h"
#include "FilmDeveloping.h"
#include <sstream>

Client::Client(string name, string surname, string email)
{
    this->name = name;
    this->surname = surname;
    this->email = email;
}

std::shared_ptr<Order> Client::createOrder()
{
    try {
        std::string description;
        int year{ 0 }, month{ 0 }, day{ 0 }, typechoice{ 0 };

        cout << "Enter order description: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!getline(cin, description) || description.empty()) {
            throw std::runtime_error("Invalid description");
        }

        cout << "Enter deadline (YYYY MM DD): ";
        std::string dateLine;
        getline(cin, dateLine);

        // Parse the date string
        std::stringstream dateStream(dateLine);
        if (!(dateStream >> year >> month >> day)) {
            throw std::invalid_argument("Date must be numeric (YYYY MM DD).");
        }
        cout << "DEBUG: year=" << year << " month=" << month << " day=" << day << endl;

        // Validate date ranges
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2000) {
            throw std::invalid_argument("Invalid date range (YYYY should be >= 2000, MM: 1-12, DD: 1-31).");
        }

        //time conversion
        tm timeinfo = {};
        timeinfo.tm_year = year - 1900;   //1900
        timeinfo.tm_mon = month - 1;     //0-based
        timeinfo.tm_mday = day;
        timeinfo.tm_isdst = -1;  

        time_t deadline = mktime(&timeinfo);
        if (deadline == -1) {
            throw std::runtime_error("Invalid date provided.");
        }
        std::string deadlineStr = to_string(deadline);

        std::string dateStr = [&timeinfo]() {
            char buffer[20];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeinfo);
            return std::string(buffer);
            }();

        cout << "Choose order type:\n";
        cout << "1. Photo Printing\n";
        cout << "2. Film developing\n";
        if (!(cin >> typechoice)) throw std::invalid_argument("Choice must be a number.");
        if (typechoice == 1) {
            int photoSize;
            cout << "Enter photo size (in cm): ";
            if (!(cin >> photoSize)) throw std::invalid_argument("Size must be numeric.");

            std::shared_ptr<Order> order(new PhotoPrinting(description, dateStr, photoSize));
            return order;
        }
        else if (typechoice == 2) {
            int filmSize;
            if (!(cin >> filmSize)) throw std::invalid_argument("Length must be numeric.");
            cin >> filmSize;
            std::shared_ptr<Order> order(new FilmDeveloping(description, dateStr, filmSize));

            return order;
        }
        else {
            throw std::out_of_range("Invalid order type choice.");
        }
    }
    catch (const std::exception& e) {
        cerr << "Error creating order: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return nullptr;
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