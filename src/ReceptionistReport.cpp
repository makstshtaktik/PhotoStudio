#include "ReceptionistReport.h"
#include "Repo.h"

ReceptionistReport::ReceptionistReport(int receptionistId, std::map<int, Order*> orders) :
    Report(reportId), receptionistId(receptionistId)
{

}

void ReceptionistReport::ordersDone(std::map<int, Order*> orders)
{
    for (auto const& [id, orderPtr] : orders)
    {
        cout << orderPtr->toString() << endl;
    }
}

int ReceptionistReport::calculateRevenue(std::map<int, Order*> orders)
{
    int totalRevenue = 0;
    for (auto const& [id, orderPtr] : orders)
    {
        if (orderPtr->isPaid == true)
        {
            totalRevenue += orderPtr->getPrice();
        }
    }
    return totalRevenue;
}

string ReceptionistReport::toString()
{
    return "Receptionist Report: " + to_string(receptionistId) + " Total revenue:" + to_string(calculateRevenue({}));
}
