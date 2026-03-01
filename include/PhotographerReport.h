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
vector<Consumables*> consumables;


PhotographerReport(int photographerId, string description, std::vector<Consumables*> consumables);
string toString() override;
};
#endif