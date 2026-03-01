#include "Order.h"
#include <iostream>
using namespace std;

int Order::getPrice()
{
    return price;
}

Order::Order(string orderDescription, string FinishTillst): orderDescription(orderDescription)
{
    time_t FinishTill = stol(FinishTillst);
long int timefinint = static_cast<long int>(FinishTill);
    time_t timenow = time(NULL);
    long int timenowint = static_cast<long int>(timenow);
    if (timefinint - timenowint >= 86400)
    {
        this->price = 10;
    }
    else
    {
        this->isUrgent = true;
        this->price = 10*2;
    }
}

string Order::toString()
{
    return "Order: " + orderDescription + " price: (" + to_string(price) + ")" + " is finished: " + to_string(isFinished) + " is urgent: " + to_string(isUrgent) + " deadline: " + to_string(FinishTill) + " is paid: " + to_string(isPaid);
}

Order::Order(string orderDescription, int price, bool isFinished, bool isUrgent, time_t FinishTill, bool isPaid)
{
    this ->orderDescription = orderDescription;
    this ->price = price;
    this ->isFinished = isFinished;
    this ->isUrgent = isUrgent;
    this ->FinishTill = FinishTill;
    this ->isPaid = isPaid;
    this ->FinishTill = FinishTill;
}
