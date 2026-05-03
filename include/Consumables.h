#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Repo.h"

using namespace std;

#ifndef CONSUMABLES_H
#define CONSUMABLES_H

class Consumables {
    string name;
    int quantity;
    int price;
public:
    string getName();
    int getQuantity();
    int getPrice();
    void setQuantity(int quantity);
    void setName(string name);
    void setPrice(int price);
    Consumables(string name, int quantity, int price);
    string toString();
};
#endif