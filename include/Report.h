#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef REPORT_H
#define REPORT_H

class Report{
private: 
int reportId;
string description;
public:
int getReportId();
string getDescription();
void setReportId(int reportId);
void setDescription(string description);
Report(int reportId, string description);
~Report() = default;
string toString();
};
#endif