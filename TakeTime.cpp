#include "TakeTime.h"
#include <iostream>
#include <ctime>
#include <time.h>

TakeTime::TakeTime()
{
    time_t czas;
    struct tm* data;
    time(&czas);
    data = localtime(&czas);
    strftime(hourMinutes, 80, "%H:%M", data);
    strftime(yearMonthDay, 80, "%Y-%m-%d", data);
    //std::cout << hourMinutes;
    //std::cout << yearMonthDay;
}
