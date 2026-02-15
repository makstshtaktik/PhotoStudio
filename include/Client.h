#include <iostream>
#include 'Order.h'
#ifndef CLIENT_H

#define CLIENT_H
using namespace std

class Client{
private: 
string name;
public:
string surname;
string email;
int clientId;

Client(string surname, string email);
string toString();
Order createOrder();
void payOrder(Order order);
};
#endif