#pragma once

#include <vector>
#include <map>

class Client;
class Consumables;
class Order;
class Report;
class Transaction;
class Photographer;
class Receptionist;
using namespace std;

#ifndef REPO_H

#define REPO_H

class Repo{
public:
int counter = 0;
    int countercl = 0;
    int countertr = 0;
    int counterph = 0;
    int counterrp = 0;
    std::map<int, Order *> orders;
    std::map<int, Client*> clients;
std::vector<Consumables *> consumables;
std::vector<Report *> reports;
std::map<int, Transaction*> transactions;
std::map<int, Photographer*> photographers;
std::map<int, Receptionist*> receptionists;
};

#endif