#pragma once
#include <iostream>
#include <string>
#include <ctime>

// Forward declarations to avoid circular includes
class Client;
class Order;

using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
private:
    int transactionId;
    Client* client;
    Order* order;
    time_t transactionDate;
    string paymentMethod; // "Card" or "Cash"

public:
    Transaction(int id, Client* c, Order* o, string method);

    // Getters
    int getTransactionId();
    string getPaymentMethod();

    // Display function
    string toString();

    ~Transaction();
};

#endif