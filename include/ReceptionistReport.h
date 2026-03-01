#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include "Repo.h"

#include "Report.h"
#include "Order.h"
using namespace std;

#ifndef RECEPTIONISTREPORT_H
#define RECEPTIONISTREPORT_H

class ReceptionistReport: Report{
public:
int receptionistId;
ReceptionistReport(int receptionistId, std::map<int, Order*> orders);
void ordersDone(std::map<int, Order*> orders);
int totalRevenue;

ReceptionistReport(int receptionistId, Order* orders);
string toString() override;
int calculateRevenue(map<int, Order*> orders);
};
#endif