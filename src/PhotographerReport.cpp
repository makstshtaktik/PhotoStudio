#include "PhotographerReport.h"
#include "Repo.h"
using namespace std;

PhotographerReport::PhotographerReport(int photographerId, string description, std::vector<Consumables *> consumables) :
    Report(reportId), description(description), consumables(consumables)
{

}

string PhotographerReport::toString()
{
    return "Report ID: " + to_string(reportId) + "Description: " + description + "Consumables left: ";
}
