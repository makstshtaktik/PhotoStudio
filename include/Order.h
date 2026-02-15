#include <iostream>
#include <ctime>
using namespace std
#ifndef ORDER_H

#define ORDER_H


class Order{
private: 
int price;
public:
int orderId;
string orderDescription;
bool isFinished;
bool isUrgent;
time_t FinishTill;
bool isPaid;

Order(int orderDescription, int price, bool isFinished, bool isUrgent, time_t FinishTill, bool isPaid);
virtual string toString();
int getPrice();
};
#endif