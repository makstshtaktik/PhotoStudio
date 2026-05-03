#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <memory>

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
    std::shared_ptr<Client> client;
    std::shared_ptr<Order> order;
    time_t transactionDate;

public:
    PayMode paymode;
    Transaction(int id, std::shared_ptr<Client> c, std::shared_ptr<Order> o, PayMode method);

    int getTransactionId();
    int getPaymentMethod();

    std::shared_ptr<Client> getClient();
    std::shared_ptr<Order> getOrder();

    void setTransactionId(int tid);
    void setPaymentMethod(PayMode pm);

    string toString();

    ~Transaction();
};

#endif