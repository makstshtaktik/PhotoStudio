#include "Report.h"
using namespace std;

Report::Report(int reportId): reportId(reportId)
{

}

string Report::toString()
{
    return "Report: " + to_string(reportId);
}
