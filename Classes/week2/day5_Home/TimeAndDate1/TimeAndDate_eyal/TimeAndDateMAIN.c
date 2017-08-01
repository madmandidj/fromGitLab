#include <stdio.h>
#include <time.h>
#include "TimeAndDate.h"

int main()
{
    time_t time_date;
    struct tm *current_time;
    time_date = time(0);
    current_time = localtime(&time_date);
    cTime_t *myTime, *myTime2;
    cDate_t *myDate, *myDate2;
    int timeMode = 0;
    int dateMode = 1;
    int result;
    myTime = CreateNewTime();
    myTime2 = CreateNewTime();
    SetNewTime(myTime, current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    result = SetNewTime(myTime2, 2, 35, 0);
    PrintTime(myTime, timeMode);
    printf("\n");
    PrintTime(myTime2, timeMode);
    printf("\n");
    AddTime(myTime, myTime2);
    printf("\n");
    PrintTime(myTime, timeMode);
    myDate = CreateNewDate();
    result = SetNewDate(myDate, 30, 2, 1984);
    result = PrintDate(myDate, dateMode);
    printf("\n");
    result = IsLeapYear(myDate);
    printf("Leap year result: %d\n", result);
    DestroyDate(myDate);
    DestroyTime(myTime);
    return 0;
}