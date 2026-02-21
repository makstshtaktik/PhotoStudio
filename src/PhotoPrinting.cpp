#include "PhotoPrinting.h"
#include <iostream>
using namespace std;

PhotoPrinting::PhotoPrinting(int photoSize) : Order(orderDescription, price, isFinished, isUrgent, FinishTill, isPaid)
{
    photoSize = photoSize;
}

int PhotoPrinting::photoSize()
{
    return photoSize();
}

string PhotoPrinting::toString()
{
    return "Printing photo of size: " + to_string(photoSize());
}
