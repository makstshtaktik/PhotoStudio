#include "Photographer.h"
#include "Order.h"
using namespace std;

void Photographer::performOrder(Order order)
{
    order.isFinished = true;

}

void Photographer::useConsumables(std::vector<std::shared_ptr<Consumables>> consumable)
{
    consumable.clear();
}

Photographer::Photographer(string name, string surname): name(name), surname(surname)
{

}
