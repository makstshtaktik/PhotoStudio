#pragma once
#include <iostream>

#include "Order.h"
#ifndef CLIENT_H

#define CLIENT_H
using namespace std;

class Order;
class Client{
    string name;
    string email;
public:
    string surname;

Client(string name, string surname, string email);
string toString();
void createOrder();
void payOrder(Order order);
    string getName();
    string getSurname();
    string getEmail();
    void setName(string name);
    void setSurname(string surname);
    void setEmail(string email);
    ~Client();
};
#endif