#include "Transaction.h"
#include "Client.h"
#include "Order.h"

Transaction::Transaction(int id, Client* c, Order* o, string method)
    : transactionId(id), client(c), order(o), paymentMethod(method) {
    this->transactionDate = time(NULL);
}

int Transaction::getTransactionId() {
    return transactionId;
}

string Transaction::getPaymentMethod() {
    return paymentMethod;
}

string Transaction::toString() {
    // Format the date
    char buffer[20];
    struct tm* timeinfo = localtime(&transactionDate);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", timeinfo);

    string clientName = (client != nullptr) ? client->getName() + " " + client->getSurname() : "Unknown Client";
    string orderDesc = (order != nullptr) ? order->orderDescription : "No Description";
    string paidStatus = (order != nullptr && order->isPaid) ? "Yes" : "No";

    return "\nTransaction ID: " + to_string(transactionId) +
        "\nDate: " + string(buffer) +
        "\nCustomer: " + clientName +
        "\nOrder: " + orderDesc +
        "\nMethod: " + paymentMethod +
        "\nPaid: " + paidStatus;
}

Transaction::~Transaction() {
    //We do not delete client or order here because they are managed by the Repo
}