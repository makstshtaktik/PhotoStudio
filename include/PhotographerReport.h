#include <iostream>
#include "Report.h"
#include "Order.h"
using namespace std
#ifndef REPORT_H

#define REPORT_H

std::vector<std::shared_ptr<Consumables>> consumables

class PhotographerReport: Report{
public:
int receptionistId;
void consumablesUsed(std::vector<std::shared_ptr<Consumables>> consumables);


PhotographerReport(int photographerId, std::vector<std::shared_ptr<Consumables>> consumables);
string toString() override;
};
#endif