#include "Order.h"
#include <iostream>
using namespace std;

int Order::getPrice()
{
    return price;
}

Order::Order(string orderDescription, string FinishTillst) : orderDescription(orderDescription) {
    this->FinishTill = stol(FinishTillst);
    this->isPaid = false; 
    this->isFinished = false; 
    this->isUrgent = false; 
    this->orderId = 0;
	this->OrderTime = time(NULL);
    time_t timenow = time(NULL); 
    if (this->FinishTill - timenow >= 86400) 
    { 
        this->price = 10; } 
    else {
        this->isUrgent = true;
        this->price = 10 + 10 * 0.25;
    } 
}

string Order::toString()
{
    //time conversion
    char buffer[20];
    tm* timeinfo = localtime(&FinishTill);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    string dateStr(buffer);

    tm* timeinfo2 = localtime(&OrderTime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    string dateStr1(buffer);

    return "\nOrder: " + orderDescription +
        "\nPrice: (" + to_string(price) + ")" +
        "\nFinished: " + (isFinished ? "Yes" : "No") +
        "\nUrgent: " + (isUrgent ? "Yes" : "No") +
        "\nOrder Time: " + dateStr1 +
        "\nDeadline: " + dateStr +
        "\nPaid: " + (isPaid ? "Yes" : "No");
}


Order::Order(string orderDescription, double price, bool isFinished, bool isUrgent, time_t FinishTill, time_t OrderTime, bool isPaid)
{
    this ->orderDescription = orderDescription;
    this ->price = price;
    this ->isFinished = isFinished;
    this ->isUrgent = isUrgent;
    this ->FinishTill = FinishTill;
	this ->OrderTime = OrderTime;
    this ->isPaid = isPaid;
    this ->FinishTill = FinishTill;
}
