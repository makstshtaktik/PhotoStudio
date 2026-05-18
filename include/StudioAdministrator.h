#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
void account(std::vector<std::shared_ptr<Consumables>> consumable);
void recordphotographer(std::shared_ptr<Repo> repo, std::shared_ptr<Photographer> photographer);
StudioAdministrator(string name, string surname);
int calc_total(std::vector<std::shared_ptr<Consumables>> consumables);
void sort(std::vector<std::shared_ptr<Consumables>> consumables);
Photographer findPhotographer(std::map<int, std::shared_ptr<Photographer>> photographers, int keyval);
void recordreceptionist(std::shared_ptr<Repo> repo, std::shared_ptr<Receptionist> receptionist);
Receptionist findReceptionist(std::map<int, std::shared_ptr<Receptionist>> receptionists, int keyval);
void createphotographer(std::shared_ptr<Repo> repo, string name, string surname);
void createreceptionist(std::shared_ptr<Repo> repo, string name, string surname);
void printReceptionistInfo(std::shared_ptr<Repo> repo, int id);
void printPhotographerInfo(std::shared_ptr<Repo> repo, int id);
void createConsumable(std::shared_ptr<Repo> repo, string name, int quantity, int price);
void removeConsumable(std::shared_ptr<Repo> repo, string consumablename);
};
#endif