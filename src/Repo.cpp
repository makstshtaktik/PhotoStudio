#include "Repo.h"
#include "Order.h"
#include "Client.h"
#include "Transaction.h"
#include "Consumables.h"
#include "Report.h"
#include "Photographer.h"
#include "Receptionist.h"
#include "PhotoPrinting.h"
#include "FilmDeveloping.h"
#include <fstream>
#include <sstream>

Repo::Repo() {
    loadOrders();
    loadClients();
    loadConsumables();
    loadPhotographers();
    loadReceptionists();
    loadTransactions();
    loadReports();
}

void Repo::loadOrders() {
    std::ifstream in(orderFile);

    if (!in.is_open()) {
        cerr << "Warning: Could not open orders file. Starting with empty database." << endl;
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        try {
            std::stringstream ss(line);
            std::string token, idStr, type, desc;

            if (!std::getline(ss, idStr, '|') || !std::getline(ss, type, '|') || !std::getline(ss, desc, '|'))
                throw std::runtime_error("Malformed line header");

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
        catch (const std::invalid_argument& e) {
            std::cerr << "Parsing error in line: " << line << " - " << e.what() << std::endl;
            continue;
        }
    }
}
void Repo::loadClients() {
    std::ifstream in(clientFile);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, name, surname, email;
        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, surname, '|');
        std::getline(ss, email, '|');

        int id = std::stoi(idStr);
        clients[id] = std::make_shared<Client>(name, surname, email);
        if (id >= countercl) countercl = id + 1;
    }
}
void Repo::saveOrder(std::shared_ptr<Order> o) {
    std::ofstream out(orderFile, std::ios::app);

    out << counter << "|"
        << o->getType() << "|"
        << o->orderDescription << "|"
        << o->getPrice() << "|"
        << o->isFinished << "|"
        << o->isUrgent << "|"
        << o->FinishTill << "|"
        << o->OrderTime << "|"
        << o->isPaid;

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
void Repo::loadConsumables() {
    std::ifstream in(consumableFile);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name, qty, price;
        std::getline(ss, name, '|');
        std::getline(ss, qty, '|');
        std::getline(ss, price, '|');
        consumables.push_back(std::make_shared<Consumables>(name, std::stoi(qty), std::stoi(price)));
    }
}
void Repo::loadPhotographers() {
    std::ifstream in(photographerFile);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, name, surname;
        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, surname, '|');
        int id = std::stoi(idStr);
        photographers[id] = std::make_shared<Photographer>(name, surname);
        if (id >= counterph) counterph = id + 1;
    }
}
void Repo::loadReceptionists() {
    std::ifstream in(receptionistFile);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, name, surname;
        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, surname, '|');
        int id = std::stoi(idStr);
        receptionists[id] = std::make_shared<Receptionist>(name, surname);
        if (id >= counterrec) counterrec = id + 1;
    }
}
void Repo::loadTransactions() {
    std::ifstream in(transactionFile);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, cIdStr, oIdStr, payStr;
        std::getline(ss, idStr, '|');
        std::getline(ss, cIdStr, '|');
        std::getline(ss, oIdStr, '|');
        std::getline(ss, payStr, '|');

        int tid = std::stoi(idStr);
        auto client = clients[std::stoi(cIdStr)];
        auto order = orders[std::stoi(oIdStr)];
        transactions[tid] = std::make_shared<Transaction>(tid, client, order, static_cast<PayMode>(std::stoi(payStr)));
        if (tid >= countertr) countertr = tid + 1;
    }
}
void Repo::loadReports() {
    std::ifstream in(reportFile);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, desc;
        std::getline(ss, idStr, '|');
        std::getline(ss, desc, '|');
        int id = std::stoi(idStr);
        reports.push_back(std::make_shared<Report>(id, desc));
        if (id >= counterrp) counterrp = id + 1;
    }
}

Repo::~Repo()
{
    std::lock_guard<std::mutex> lock(repoMutex);
}
