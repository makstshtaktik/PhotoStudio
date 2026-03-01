#include "Report.h"
using namespace std;

Report::Report(int reportId, string description): reportId(reportId), description(description)
{

}

string Report::toString()
{
    return "Report: " + to_string(reportId) + "Description: " + description;
}

string Report::getDescription()
{
    return description;
}

int Report::getReportId()
{
    return reportId;
}

void Report::setReportId(int reportId)
{
    this->reportId = reportId;
}

void Report::setDescription(string description)
{
    this->description = description;
}