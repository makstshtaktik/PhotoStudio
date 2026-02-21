#include "ReceptionistReport.h"

vector<shared_ptr<Order>> orderlist;

ReceptionistReport::ReceptionistReport(int receptionistId, std::vector<std::shared_ptr<Order>> orderlist) :
    Report(reportId), receptionistId(receptionistId)
{

}

void ReceptionistReport::ordersDone(std::vector<std::shared_ptr<Order>> orderlist)
{
    for (auto order : orderlist)
    {
        cout << order->toString() << endl;
    }
}

int ReceptionistReport::calculateRevenue()
{
    int totalRevenue = 0;
    for (auto order : orderlist)
    {
        if (order->isPaid == true)
        {
            totalRevenue += order->getPrice();
        }
    }
    return totalRevenue;
}

string ReceptionistReport::toString()
{
    return "Receptionist Report: " + to_string(receptionistId);
}
