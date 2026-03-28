#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Consumables.h"
#include "Photographer.h"
using namespace std;

#ifndef STUDIOADMINISTRATOR_H
#define STUDIOADMINISTRATOR_H

class StudioAdministrator{
private:
string name;
string surname;
public:
int adminId;
string toString();
void account(std::vector<std::shared_ptr<Consumables>> consumable);
StudioAdministrator(string name, string surname);
int calc_total(std::vector<Consumables*> consumables);
void sort(std::vector<Consumables*> consumables);
Photographer findPhotographer(std::map<int, Photographer*> photographers, int keyval);
};
#endif