#include <iostream>
#include "Order.h"
using namespace std

#ifndef PHOTOPRINTING_H

#define PHOTOPRINTING_H
class PhotoPriniting: Order{
public:
int photoSize();

PhotoPriniting(int photoSize);
string toString() override;
};
#endif