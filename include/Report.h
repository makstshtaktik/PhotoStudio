#include <iostream>
using namespace std;

#ifndef REPORT_H
#define REPORT_H

class Report{
protected: 
int reportId;
public:
    Report(int reportId);
virtual ~Report() = default;
virtual string toString();
};
#endif