#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
#include "Order.h"
#include "Client.h"
#include "FilmDeveloping.h"
#include "PhotoPrinting.h"
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
    if (!in.is_open()) return;
    
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string token, idStr, type, desc;

        std::getline(ss, idStr, '|');
        std::getline(ss, type, '|');
        std::getline(ss, desc, '|');

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

        std::shared_ptr<Order> newOrder = nullptr;

        if (type == "Photo") {
            std::getline(ss, token, '|');
            int size = std::stoi(token);
            newOrder = std::make_shared<PhotoPrinting>(desc, price, finished, finishTill, orderTime, paid, size);
        }
        if (type == "Film") {
            std::getline(ss, token, '|');
            int length = std::stoi(token);
            newOrder = std::make_shared<FilmDeveloping>(desc, price, finished, finishTill, orderTime, paid, length);
        }
    else {
        auto o = std::make_shared<Order>(desc, price, finished, urgent, finishTill, orderTime, paid);
    }
        int id = std::stoi(idStr);
        orders[id] = newOrder;

        if (id >= counter) counter = id + 1;
    }
}
void loadClients() {

}
void saveOrder(std::shared_ptr<Order> o) {
    
    std::ofstream out(orderFile, std::ios::app);
    out << counter << "|" << o->orderDescription << "|"
        << o->getPrice() << "|"
        << o->isFinished << "|"
        << o->isUrgent << "|"
        << o->FinishTill << "|"
        << o->OrderTime << "|"
        << o->isPaid << "\n";
    if (auto p = std::dynamic_pointer_cast<PhotoPrinting>(o)) {
        out << "|" << p->getPhotoSize();
    }
    else if (auto f = std::dynamic_pointer_cast<FilmDeveloping>(o)) {
        out << "|" << f->getFilmLength();
    }
    out << "\n";
    orders[counter] = o;
    counter++;
}
//TBA: Clients, Consumables, Reports, Transactions, Photographers, Receptionists
//Function Integration
};

#endif