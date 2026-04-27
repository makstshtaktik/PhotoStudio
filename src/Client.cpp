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

std::shared_ptr<Order> Client::createOrder()
{
    std::string description;
    int year, month, day, typechoice{};

    cout << "Enter order description: ";
    cin.ignore();
    getline(cin, description);

    cout << "Enter deadline (YYYY MM DD): ";
    cin >> year >> month >> day;

    //time conversion
    tm timeinfo = {};
    timeinfo.tm_year = year - 1900;   //1900
    timeinfo.tm_mon = month - 1;     //0-based
    timeinfo.tm_mday = day;

    time_t deadline = mktime(&timeinfo);
    std::string deadlineStr = to_string(deadline);

    std::string dateStr = [&timeinfo]() {
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeinfo);
        return std::string(buffer);
        }();

    cout << "Choose order type:\n";
    cout << "1. Photo Printing\n";
    cout << "2. Film developing\n";
	cin >> typechoice;
    if (typechoice == 1) {
		int photoSize;
		cout << "Enter photo size (in cm): ";
		cin >> photoSize;

        std::shared_ptr<Order> order(new PhotoPrinting(description, dateStr, photoSize));
        return order;
    }
	else if (typechoice == 2) {
        int filmSize;
        cout << "Enter film length (in cm): ";
        cin >> filmSize;
        std::shared_ptr<Order> order(new FilmDeveloping(description, dateStr, filmSize));
        return order;
    }
    else {
        cout << "Invalid choice.\n";
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

