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
void recordOrder(std::shared_ptr<Repo> repo, std::shared_ptr<Order> order);
void recordClient(std::shared_ptr<Repo> repo, std::shared_ptr<Client> client);
void recordTransaction(std::shared_ptr<Repo> repo, std::shared_ptr<Transaction> transaction);
string toString();
std::shared_ptr<Order> findOrders(std::map<int, std::shared_ptr<Order>> orders, int keyval);
std::shared_ptr<Client> findClients(std::map<int, std::shared_ptr<Client>> clients, int keyval);
std::shared_ptr<Transaction> findTransactions(std::map<int, std::shared_ptr<Transaction>> transactions, int keyval);
std::shared_ptr<Client> findBySurname(std::shared_ptr<Repo> repo, string& surname);
void printOrderInfo(std::shared_ptr<Repo> repo, int id);
void printClientInfo(std::shared_ptr<Repo> repo, int id);
void printTransactionInfo(std::shared_ptr<Repo> repo, int id);
void createTransaction(std::shared_ptr<Repo> repo, std::shared_ptr<Client> client, std::shared_ptr<Order> order, PayMode paymode);
std::shared_ptr<Client> createClient(string clientSurname);
void receptionistHandler(std::shared_ptr<Repo> repo);
};
#endif