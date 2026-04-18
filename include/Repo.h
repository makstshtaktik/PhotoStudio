#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
#include "Order.h"
#include "Client.h"
#include <memory>

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
private:
    std::string orderFile = "orders.txt";
    std::string clientFile = "clients.txt";

public:
int counter = 0;
    int countercl = 0;
    int countertr = 0;
    int counterph = 0;
    int counterrp = 0;
    std::map<int, std::shared_ptr<Order>> orders;
    std::map<int, std::shared_ptr<Client>> clients;
std::vector<std::shared_ptr<Consumables>> consumables;
std::vector<std::shared_ptr<Report>> reports;
std::map<int, std::shared_ptr<Transaction>> transactions;
std::map<int, std::shared_ptr<Photographer>> photographers;
std::map<int, std::shared_ptr<Receptionist>> receptionists;
Repo(){
    loadOrders();
    loadClients();
}
void loadOrders() {
    std::ifstream in(orderFile);
    std::string token;
    if (!in.is_open()) return;
    int id = std::stoi(token);
    
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::getline(ss, token, '|');
        std::string desc = token;

        std::getline(ss, token, '|');
        double price = std::stod(token);

        std::getline(ss, token, '|');
        bool finished = (token == "1");

        std::getline(ss, token, '|');
        bool urgent = (token == "1");

        std::getline(ss, token, '|');
        time_t finishTill = std::stoll(token);

        std::getline(ss, token, '|');
        time_t orderTime = std::stoll(token);

        std::getline(ss, token, '|');
        bool paid = (token == "1");

        if (id >= counter) counter = id + 1;
    }
}
void loadClients() {

}
void saveOrder(std::shared_ptr<Order> o) {
    orders[counter] = o;
    std::ofstream out(orderFile, std::ios::app);
    out << counter << "|" << o->orderDescription << "|"
        << o->getPrice() << "|"
        << o->isFinished << "|"
        << o->isUrgent << "|"
        << o->FinishTill << "|"
        << o->OrderTime << "|"
        << o->isPaid << "\n";
    out.close();
    counter++;
}
//TBA: Clients, Consumables, Reports, Transactions, Photographers, Receptionists
//Function Integration
};

#endif