#include <iostream>
using namespace std

#ifndef REPORT_H
#define REPORT_H

class Report{
protected: 
int reportId;
public:
virtual string toString();
};
#endif