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

enum PayMode {
    cash = 0,
    card = 1
};

class Transaction {
private:
    int transactionId;
    Client* client;
    Order* order;
    time_t transactionDate;
    PayMode paymode;

public:
    Transaction(int id, Client* c, Order* o, PayMode method);

    // Getters
    int getTransactionId();
    int getPaymentMethod();

    void setTransactionId(int tid);
    void setPaymentMethod(PayMode pm);

    // Display function
    string toString();

    ~Transaction();


};

#endif