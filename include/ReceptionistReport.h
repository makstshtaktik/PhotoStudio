#include <iostream>
#include "Report.h"
#include "Order.h"
using namespace std

#ifndef RECEPTIONISTREPORT_H
#define RECEPTIONISTREPORT_H

std::vector<std::shared_ptr<Order>> orders;

class ReceptionistReport: Report{
public:
int receptionistId;
void ordersDone(std::vector<std::shared_ptr<Order>> orders);
int totalRevenue;

ReceptionistReport(int receptionistId, std::vector<std::shared_ptr<Order>> orders);
string toString() override;
int calculateRevenue();
};
#endif