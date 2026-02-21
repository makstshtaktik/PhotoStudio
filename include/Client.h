#pragma once
#include <iostream>
#include "Order.h"
#ifndef CLIENT_H

#define CLIENT_H
using namespace std;

class Client{

private:
    string name;
public:
string surname;
string email;

Client(string name, string surname, string email);
string toString();
void createOrder();
void payOrder(Order order);
    string getName();
};
#endif