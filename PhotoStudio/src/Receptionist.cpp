#include "Receptionist.h"
#include "Repo.h"
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;


Receptionist::Receptionist(string name, string surname): name(name), surname(surname)
{

}

void Receptionist::recordOrder(Repo* repo, Order* order) {
    repo->orders[repo->counter] = order;
    repo->counter++;
}

void Receptionist::recordClient(Repo* repo, Client* client) {
    repo->clients[repo->countercl] = client;
    repo->countercl++;
}

void Receptionist::recordTransaction(Repo* repo, Transaction* transaction) {
    repo->transactions[repo->countertr] = transaction;
    repo->countertr++;
}

string Receptionist::toString()
{
    return "Name: " + name + " Surname: " + surname;
}

Order Receptionist::findOrders(std::map<int, Order*> orders, int keyval) {
    auto it = orders.find(keyval);
    
    if (it != orders.end()) {
        return *(it->second);
    }
}

Client Receptionist::findClients(std::map<int, Client*> clients, int keyval) {
    auto it = clients.find(keyval);

    if (it != clients.end()) {
        return *(it->second);
    }
}

Transaction Receptionist::findTransactions(std::map<int, Transaction*> transactions, int keyval) {
    auto it = transactions.find(keyval);

    if (it != transactions.end()) {
        return *(it->second);
    }
}

void Receptionist::printOrderInfo(Repo* repo, int id)
{
    Order o = findOrders(repo->orders, id);
    cout << "Order with id: " << id << " is: " << o.toString() << endl;
}

void Receptionist::printClientInfo(Repo* repo, int id)
{
    Client c = findClients(repo->clients, id);
    cout << "Order with id: " << id << " is: " << c.toString() << endl;
}

void Receptionist::printTransactionInfo(Repo* repo, int id)
{
    Transaction t = findTransactions(repo->transactions, id);
    cout << "Order with id: " << id << " is: " << t.toString() << endl;
}
