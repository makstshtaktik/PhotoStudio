#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Consumables.h"
#include "Report.h"
using namespace std;
#ifndef PHOTOGRAPHERREPORT_H

#define PHOTOGRAPHERREPORT_H

class PhotographerReport: Report{
public:
int receptionistId;
string description;


PhotographerReport(int photographerId, string description, std::vector<std::shared_ptr<Consumables>> consumables);
string toString() override;
};
#endif