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
PhotoPrinting(int photoSize);
string toString() override;
};
#endif