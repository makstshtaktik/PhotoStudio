#pragma once
#include <iostream>
#include "Order.h"
using namespace std;

#ifndef PHOTOPRINTING_H

#define PHOTOPRINTING_H
class PhotoPrinting: public Order{
    int photoSize;
public:
    int getPhotoSize();
    void setPhotoSize(int photoSize);
PhotoPrinting(string desc, string deadline, int photoSize);
std::string getType() override;
PhotoPrinting(string orderDescription, int price, bool isFinished, time_t FinishTill, time_t OrderTime, bool isPaid, int photoSize);
string toString() override;
};
#endif