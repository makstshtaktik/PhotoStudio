#include "Order.h"
#include <iostream>
using namespace std;

int Order::getPrice()
{
    return price;
}

Order::Order(string orderDescription): orderDescription(orderDescription)
{

}

string Order::toString()
{
    return "Order: " + orderDescription;
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
