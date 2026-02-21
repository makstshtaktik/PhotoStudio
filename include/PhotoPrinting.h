#pragma once
#include <iostream>
#include "Order.h"
using namespace std;

#ifndef PHOTOPRINTING_H

#define PHOTOPRINTING_H
class PhotoPrinting: Order{
public:
int photoSize();

PhotoPrinting(int photoSize);
string toString() override;
};
#endif