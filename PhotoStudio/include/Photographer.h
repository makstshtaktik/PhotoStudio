#include <iostream>
#include <memory>
#include <vector>

#include "Order.h"
#include "Consumables.h"
using namespace std;
#ifndef PHOTOGRAPHER_H

#define PHOTOGRAPHER_H
class Order;

class Photographer{
string name;
string surname;
public:
    string getName();
    string getSurname();
    void setName(string name);
    void setSurname(string surname);
Photographer(string name, string surname);
void performOrder(Order order);
void useConsumables(std::vector<Consumables* > consumables);
};
#endif