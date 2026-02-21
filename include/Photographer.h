#include <iostream>
#include <memory>
#include <vector>

#include "Order.h"
#include "Consumables.h"
using namespace std;
#ifndef PHOTOGRAPHER_H

#define PHOTOGRAPHER_H

class Photographer{
private:
string name;
string surname;
public:
int photographerId;
Photographer(string name, string surname);
void performOrder(Order order);
void useConsumables(std::vector<std::shared_ptr<Consumables>> consumables);
};
#endif