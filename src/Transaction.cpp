#include "Transaction.h"
#include "Client.h"
#include "Order.h"

Transaction::Transaction(int id, std::shared_ptr<Client> c, std::shared_ptr<Order> o, PayMode paymode)
    : transactionId(id), client(c), order(o), paymode(paymode) {
    this->transactionDate = time(NULL);
}

int Transaction::getTransactionId() {
    return transactionId;
}

int Transaction::getPaymentMethod() {
    return paymode;
}

void Transaction::setPaymentMethod(PayMode pm) {
    this->paymode = pm;
}

void Transaction::setTransactionId(int id) {
    this->transactionId = id;
}

string Transaction::toString() {
    // Format the date
    char buffer[20];
    struct tm* timeinfo = localtime(&transactionDate);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", timeinfo);

    string clientName = (client != nullptr) ? client->getName() + " " + client->getSurname() : "Unknown Client";
    string orderDesc = (order != nullptr) ? order->orderDescription : "No Description";
    string paidStatus = (order != nullptr && order->isPaid) ? "Yes" : "No";
    string pm = (paymode != 1) ? "Cash" : "Card";

    return "\nTransaction ID: " + to_string(transactionId) +
        "\nDate: " + string(buffer) +
        "\nCustomer: " + clientName +
        "\nOrder: " + orderDesc +
        "\nMethod: "+ pm +
        "\nPaid: " + paidStatus;
}

Transaction::~Transaction() {
    //We do not delete client or order here because they are managed by the Repo
}