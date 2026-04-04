#pragma once
#include <iostream>
#include <memory>

#include "Order.h"
#include "Client.h"
#include "Transaction.h"
#include "Repo.h"
using namespace std;

#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
class Order;
class Client;
class Transaction;

class Receptionist{
private:
string name;
string surname;
public:
int receptionistId;

Receptionist(string name, string surname);
void recordOrder(Repo* repo, Order* order);
void recordClient(Repo* repo, Client* client);
void recordTransaction(Repo* repo, Transaction* transaction);
string toString();
Order findOrders(std::map<int, Order*> orders, int keyval);
Client findClients(std::map<int, Client*> clients, int keyval);
Transaction findTransactions(std::map<int, Transaction*> transactions, int keyval);
bool findBySurname(Repo* repo, string& surname);
void printOrderInfo(Repo* repo, int id);
void printClientInfo(Repo* repo, int id);
void printTransactionInfo(Repo* repo, int id);
void createTransaction(Repo* repo, Client* client, Order* order, PayMode paymode);
};
#endif