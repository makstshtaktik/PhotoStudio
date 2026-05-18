#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
#include <memory>
#include <mutex>

class Client;
class Consumables;
class Order;
class Report;
class Transaction;
class Photographer;
class Receptionist;
class PhotoPrinting;
class FilmDeveloping;
using namespace std;

#ifndef REPO_H

#define REPO_H

class Repo{
private:
    std::string orderFile = "orders.txt";
    std::string clientFile = "clients.txt";
    std::string consumableFile = "consumables.txt";
    std::string reportFile = "reports.txt";
    std::string transactionFile = "transactions.txt";
    std::string photographerFile = "photographers.txt";
    std::string receptionistFile = "receptionists.txt";

public:
    int counter = 0;
    int countercl = 0;
    int countertr = 0;
    int counterph = 0;
    int counterrp = 0;
    int counterrec = 1;

    std::map<int, std::shared_ptr<Order>> orders;
    std::map<int, std::shared_ptr<Client>> clients;
std::vector<std::shared_ptr<Consumables>> consumables;
std::vector<std::shared_ptr<Report>> reports;
std::map<int, std::shared_ptr<Transaction>> transactions;
std::map<int, std::shared_ptr<Photographer>> photographers;
std::map<int, std::shared_ptr<Receptionist>> receptionists;
std::mutex repoMutex;
Repo();
void loadOrders();
void loadClients();
void loadConsumables();
void loadPhotographers();
void loadReceptionists();
void loadTransactions();
void loadReports();
void saveOrder(std::shared_ptr<Order> o);
void saveClient(std::shared_ptr<Client> c);
void savePhotographer(std::shared_ptr<Photographer> p);
void saveReceptionist(std::shared_ptr<Receptionist> r);
void saveReport(std::shared_ptr<Report> r);
void saveTransaction(std::shared_ptr<Transaction> t);
void saveConsumable(std::shared_ptr<Consumables> c);
~Repo();
};

#endif