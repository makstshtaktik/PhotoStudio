#include "PhotographerReport.h"
using namespace std;

PhotographerReport::PhotographerReport(int photographerId, string description, std::vector<std::shared_ptr<Consumables>> consumables) :
    Report(reportId)
{
    photographerId = photographerId;
    description = description;
}

string PhotographerReport::toString()
{
    return "Report ID: " + to_string(reportId) + "Description: " + description;
}
