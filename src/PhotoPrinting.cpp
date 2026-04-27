#include "PhotoPrinting.h"
#include <iostream>
using namespace std;

PhotoPrinting::PhotoPrinting(string orderDescription, int price, bool isFinished, time_t FinishTill, time_t OrderTime, bool isPaid, int photoSize) : Order(orderDescription, price, isFinished, isUrgent, FinishTill, OrderTime, isPaid), photoSize(photoSize)
{
}

string PhotoPrinting::toString()
{
    string deadlineStr;
    char buf[64] = {0};
    std::tm* tm = std::localtime(&FinishTill);
    if (tm) {
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);
        deadlineStr = buf;
    }
    return "Photo printing order of size: " + to_string(photoSize) + " till: " + deadlineStr;
}

int PhotoPrinting::getPhotoSize()
{
    return photoSize;
}

void PhotoPrinting::setPhotoSize(int photoSize)
{
    this->photoSize = photoSize;
}

PhotoPrinting::PhotoPrinting(string desc, string deadline, int photoSize)
    : Order(desc, deadline), photoSize(photoSize)
{
}

std::string PhotoPrinting::getType() {
    return "Photo";
}