#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Consumables.h"
#include "Photographer.h"
#include "Receptionist.h"
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
void account(std::vector<Consumables*> consumable);
void recordphotographer(Repo* repo, Photographer* photographer);
StudioAdministrator(string name, string surname);
int calc_total(std::vector<Consumables*> consumables);
void sort(std::vector<Consumables*> consumables);
Photographer findPhotographer(std::map<int, Photographer*> photographers, int keyval);
void recordreceptionist(Repo* repo, Receptionist* receptionist);
Receptionist findReceptionist(std::map<int, Receptionist*> receptionists, int keyval);
void printReceptionistInfo(Repo* repo, int id);
void printPhotographerInfo(Repo* repo, int id);
};
#endif