#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <memory>
#include <string>

#include "Order.h"
using namespace std;

class Client{
protected:
    std::string name;
    std::string email; 
public:
    std::string surname;

    Client(std::string name, std::string surname, std::string email);
    string toString();
    
    std::shared_ptr<Order> createOrder(std::string description, int year, int month, int day, int typechoice, double physicalSpec);

    void payOrder(std::shared_ptr<Order> order);
    string getName();
    string getSurname();
    string getEmail();
    void setName(string name);
    void setSurname(string surname);
    void setEmail(string email);
    ~Client();
};

#endif