#pragma once

#include <vector>
#include <map>

using namespace std;

#ifndef REPO_H

#define REPO_H

class Consumables;
class Order;

class Repo{
public:
int counter = 0;
std::vector<Consumables *> consumables;
std::map<int, Order *> orders;
};

#endif