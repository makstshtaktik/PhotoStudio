#pragma once
#include <iostream>
using namespace std;
#ifndef ORDER_H

#define ORDER_H


class Order{
protected:
int price;
public:
virtual ~Order() = default;
int orderId;
string orderDescription;
bool isFinished = false;
bool isUrgent = false;
time_t FinishTill;
bool isPaid;
Order(string orderDescription, int price, bool isFinished, bool isUrgent, time_t FinishTill, bool isPaid);
virtual string toString();
int getPrice();
Order(string orderDescription, string FinishTill);
};
#endif