#include <iostream>
#include 'Consumables.h'
using namespace std
#ifndef PHOTOGRAPHER_H

#define PHOTOGRAPHER_H

std::vector<std::shared_ptr<Consumable>> consumables

class Photographer{
private:
string name;
string surname;
public:
int photographerId;
Photograpger(string name, string surname);
void takeOrder(Order order);
void performOrder(Order order);
void useConsumables(std::vector<std::shared_ptr<Consumable>> consumables);
};
#endif