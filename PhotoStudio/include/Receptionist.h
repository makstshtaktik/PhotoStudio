#pragma once
#include <iostream>
#include <memory>

#include "Order.h"
#include "Client.h"
#include "Repo.h"
using namespace std;

#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
class Order;

class Receptionist{
private:
string name;
string surname;
public:
int receptionistId;

Receptionist(string name, string surname);
void recordOrder(Repo* repo, Order* order);
string toString();
Order findOrders(std::map<int, Order*> orders, int keyval);
Client findClients(std::map<int, Client*> clients, int keyval);
};
#endif