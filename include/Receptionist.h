#pragma once
#include <iostream>
#include <memory>

#include "Order.h"
using namespace std;

#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

class Receptionist{
private:
string name;
string surname;
public:
int receptionistId;

Receptionist(string name, string surname);
void recordOrder(shared_ptr<Order> order);
string toString();
};
#endif