#pragma once
#include "FilmDeveloping.h"
#include <iostream>
using namespace std;

string FilmDeveloping::toString()
{
    return "Film Developing order";
}

FilmDeveloping::FilmDeveloping(string orderDescription, int price, bool isFinished, time_t FinishTill, time_t OrderTime, bool isPaid, int filmLength) : Order(orderDescription, price, isFinished, isUrgent, FinishTill, OrderTime, isPaid), filmLength(filmLength)
{
}

FilmDeveloping::FilmDeveloping(string desc, string deadline, int filmLength) : Order(desc, deadline), filmLength(filmLength)
{
}

std::string FilmDeveloping::getType() {
    return "Film";
}

int FilmDeveloping::getFilmLength() {
    return filmLength;
}