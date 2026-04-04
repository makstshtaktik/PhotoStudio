#include "PhotoPrinting.h"
#include <iostream>
using namespace std;

PhotoPrinting::PhotoPrinting(int photoSize) : Order(orderDescription, price, isFinished, isUrgent, FinishTill, OrderTime, isPaid), photoSize(photoSize)
{
}

string PhotoPrinting::toString()
{
    return "Printing photo of size: " + to_string(photoSize);
}

int PhotoPrinting::getPhotoSize()
{
    return photoSize;
}

void PhotoPrinting::setPhotoSize(int photoSize)
{
    this -> photoSize = photoSize;
}
