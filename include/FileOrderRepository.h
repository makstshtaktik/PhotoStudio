#pragma once
#include "IOrderRepository.h"
#include "../Entity/Order.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>

class FileOrderRepository : public IOrderRepository {
private:
    std::string filename;
    std::vector<Order> orders;

public:
    explicit FileOrderRepository(const std::string& file) : filename(file) {
        loadFromFile();
    }

    void add(Order order) override {
        orders.push_back(order);
        appendToFile(order);
    }

    std::vector<Order>& getAll() override {
        return orders;
    }

    void removeCompleted() {
        // Remove completed orders from memory
        orders.erase(std::remove_if(orders.begin(), orders.end(),
            [](const Order& o) { return o.isFinished(); }),
            orders.end());

        // Rewrite the file with remaining orders
        std::ofstream out(filename, std::ios::trunc);
        for (const auto& o : orders) {
            out << serialize(o) << "\n";
        }
        out.close();
    }

private:
    void appendToFile(const Order& order) {
        std::ofstream out(filename, std::ios::app);
        out << serialize(order) << "\n";
        out.close();
    }

    void loadFromFile() {
        std::ifstream in(filename);
        if (!in.is_open()) return;

        std::string line;
        while (std::getline(in, line)) {
            Order o = deserialize(line);
            orders.push_back(o);
        }
        in.close();
    }

    std::string serialize(const Order& order) {
        // Convert order to string for file storage
        std::stringstream ss;
        ss << order.getDescription() << "|"
            << order.getPrice() << "|"
            << order.isFinished() << "|"
            << order.isUrgent() << "|"
            << order.getFinishTill() << "|"
            << order.getOrderTime() << "|"
            << order.isPaid();
        return ss.str();
    }

    Order deserialize(const std::string& line) {
        std::stringstream ss(line);
        std::string token;

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

        return Order(desc, price, finished, urgent, finishTill, orderTime, paid);
    }
};