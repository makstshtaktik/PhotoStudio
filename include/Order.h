#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef ORDER_H

#define ORDER_H


class Order{
protected:
double price;
public:
virtual ~Order() = default;
int orderId;
string orderDescription;
bool isFinished = false;
bool isUrgent = false;
time_t FinishTill;
time_t OrderTime;
bool isPaid;
Order(string orderDescription, double price, bool isFinished, bool isUrgent, time_t FinishTill, time_t OrderTime, bool isPaid);
virtual string toString();
int getPrice();
Order(string orderDescription, string FinishTill);
};
#endif