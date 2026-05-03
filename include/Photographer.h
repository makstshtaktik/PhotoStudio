#include <iostream>
#include <memory>
#include <vector>

using namespace std;
#ifndef PHOTOGRAPHER_H

#define PHOTOGRAPHER_H
class Order;
class Repo;
class Consumables;

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
void useConsumables(std::vector<std::shared_ptr<Consumables>> consumables);
string toString();
void PhotographerHandler(std::shared_ptr<Repo> repo, int phchoice);
};
#endif