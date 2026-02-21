#pragma once
#include <iostream>
#include "Order.h"
using namespace std;
#ifndef FILMDEVELOPING_H

#define FILMDEVELOPING_H

class FilmDeveloping: Order{
public:
int filmLength;
FilmDeveloping(int filmLength);
string toString() override;
};
#endif