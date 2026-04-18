#include "Receptionist.h"
#include "Repo.h"
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;


Receptionist::Receptionist(string name, string surname): name(name), surname(surname)
{

}

void Receptionist::recordOrder(std::shared_ptr<Repo> repo, std::shared_ptr<Order> order) {
    repo->orders[repo->counter] = order;
    repo->counter++;
}

void Receptionist::recordClient(std::shared_ptr<Repo> repo, std::shared_ptr<Client> client) {
    repo->clients[repo->countercl] = client;
    repo->countercl++;
}

void Receptionist::recordTransaction(std::shared_ptr<Repo> repo, std::shared_ptr<Transaction> transaction) {
    repo->transactions[repo->countertr] = transaction;
    repo->countertr++;
}

string Receptionist::toString()
{
    return "Name: " + name + " " + "Surname: " + surname;
}

std::shared_ptr<Order> Receptionist::findOrders(std::map<int, std::shared_ptr<Order>> orders, int keyval) {
    auto it = orders.find(keyval);
    
    if (it != orders.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<Client> Receptionist::findClients(std::map<int, std::shared_ptr<Client>> clients, int keyval) {
    auto it = clients.find(keyval);

    if (it != clients.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<Transaction> Receptionist::findTransactions(std::map<int, std::shared_ptr<Transaction>> transactions, int keyval) {
    auto it = transactions.find(keyval);

    if (it != transactions.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<Client> Receptionist::findBySurname(std::shared_ptr<Repo> repo, string& surname)
{
    auto it = find_if(repo->clients.begin(), repo->clients.end(), [&surname](auto& pair) {return pair.second->surname == surname;});

    if (it != repo->clients.end()) {
        return it->second;
    }
    return nullptr;
}

void Receptionist::printOrderInfo(std::shared_ptr<Repo> repo, int id)
{
    std::shared_ptr<Order> o = findOrders(repo->orders, id);
    cout << "Order with id: " << id << " is: " << o->toString() << endl;
}

void Receptionist::printClientInfo(std::shared_ptr<Repo> repo, int id)
{
    std::shared_ptr<Client> c = findClients(repo->clients, id);
    cout << "Client with id: " << id << " is: " << c->toString() << endl;
}

void Receptionist::printTransactionInfo(std::shared_ptr<Repo> repo, int id)
{
    std::shared_ptr<Transaction> t = findTransactions(repo->transactions, id);
    cout << "Transaction with id: " << id << " is: " << t->toString() << endl;
}

void Receptionist::createTransaction(std::shared_ptr<Repo> repo, std::shared_ptr<Client> client, std::shared_ptr<Order> order, PayMode paymode)
{
    std::shared_ptr<Transaction> tr = make_shared<Transaction>(repo->countertr++, client, order, paymode);
    recordTransaction(repo, tr);

}

std::shared_ptr<Client> Receptionist::createClient(string clientSurname) {
    string name;
    string email;
    cout << "New user detected!\n";
    cout << "Enter your name: \n";
    cin >> name;
    cout << "Enter your email: \n";
    cin >> email;
    std::shared_ptr<Client> Cl = make_shared <Client>(name, clientSurname, email);
    return Cl;
}
