#pragma once

#ifndef ORDER_H

#define ORDER_H

#include <iostream>
#include <string>
#include <ctime>

class Order{
protected:
double price;
public:
virtual ~Order() = default;
int orderId;
std::string orderDescription;
bool isFinished = false;
bool isUrgent = false;
time_t FinishTill;
time_t OrderTime;
bool isPaid;
Order(std::string orderDescription, double price, bool isFinished, bool isUrgent, time_t FinishTill, time_t OrderTime, bool isPaid);
virtual std::string toString();
double getPrice();
Order(std::string orderDescription, std::string FinishTill);
virtual std::string getType();
};
#endif