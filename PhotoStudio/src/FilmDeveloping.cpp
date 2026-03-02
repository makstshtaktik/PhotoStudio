#include "FilmDeveloping.h"
#include <iostream>
using namespace std;

string FilmDeveloping::toString()
{
    return "Film Developing order";
}

FilmDeveloping::FilmDeveloping(int filmLength) : Order(orderDescription, price, isFinished, isUrgent, FinishTill, OrderTime, isPaid), filmLength(filmLength)
{
}
