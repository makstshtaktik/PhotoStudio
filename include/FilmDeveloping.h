#pragma once
#include <iostream>
#include "Order.h"
using namespace std;
#ifndef FILMDEVELOPING_H

#define FILMDEVELOPING_H

class FilmDeveloping: public Order{
public:
int filmLength;
FilmDeveloping(int filmLength);
string toString() override;
std::string getType() override;
int getFilmLength();
FilmDeveloping(string orderDescription, int price, bool isFinished, time_t FinishTill, time_t OrderTime, bool isPaid, int filmLength);
FilmDeveloping(string desc, string deadline, int filmLength);
};
#endif