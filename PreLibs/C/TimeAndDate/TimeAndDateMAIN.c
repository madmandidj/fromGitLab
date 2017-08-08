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
    int myhours;
    int mymins;
    int mysecs;
    int myday;
    int mymonth;
    int myyear;
    int menu = 1;
    int leapyear = 0;

    while (menu > 0)
    {
        printf("select:\n1\tCreate Time\n2\tSet Time\n3\tPrint Time\n4\tAdd Time\n5\tDestroy Time\n\n6\tCreate Date\n7\tSet Date\n8\tPrint Date\n9\tDestroy Date\n10\tIs A Leap Year?\n0\tEXIT\n\n");
        scanf("%d", &menu);
        switch (menu)
        {
        default:
            if (myDate != NULL)
            {
                DestroyDate(myDate);
            }
            if (myDate2 != NULL)
            {
                DestroyDate(myDate2);
            }
            if (myTime != NULL)
            {
                DestroyTime(myTime);
            }
            if (myTime2 != NULL)
            {
                DestroyTime(myTime2);
            }
            break;
        case 1:
            printf("Select time object # to create: 1 or 2\n");
            scanf("%d", &result);
            if (result == 1)
            {
                myTime = CreateNewTime();
            }
            if (result == 2)
            {
                myTime2 = CreateNewTime();
            }
            break;
        case 2:
            printf("Select object to set new time: 1 or 2\n");
            scanf("%d", &result);
            printf("Enter hours\n");
            scanf("%d", &myhours);
            printf("Enter minutes\n");
            scanf("%d", &mymins);
            printf("Enter seconds\n");
            scanf("%d", &mysecs);
            if (result == 1)
            {
                SetNewTime(myTime, myhours, mymins, mysecs);
            }
            if (result == 2)
            {
                SetNewTime(myTime2, myhours, mymins, mysecs);
            }
            break;
        case 3:
            printf("Select object to print time: 1 or 2\n");
            scanf("%d", &result);
            printf("Enter time mode 0 or 1\n");
            scanf("%d", &timeMode);
            if (result == 1)
            {
                PrintTime(myTime, timeMode);
            }
            if (result == 2)
            {
                PrintTime(myTime2, timeMode);
            }
            break;
        case 4:
            printf("Select object to store added time in: 1 or 2");
            scanf("%d", &result);
            if (result == 1)
            {
                AddTime(myTime, myTime2);
            }
            if (result == 2)
            {
                AddTime(myTime2, myTime);
            }
            break;
        case 5:
            printf("Select time object to destroy: 1 or 2");
            scanf("%d", &result);
            if (result == 1)
            {
                if (myTime != NULL)
                {
                    DestroyTime(myTime);
                }
            }
            if (result == 2)
            {
                if (myTime2 != NULL)
                {
                    DestroyTime(myTime2);
                }
            }
            break;
        case 6:
            printf("Select Date object # to create: 1 or 2\n");
            scanf("%d", &result);
            if (result == 1)
            {
                myDate = CreateNewDate();
            }
            if (result == 2)
            {
                myDate2 = CreateNewDate();
            }
            break;
        case 7:
            printf("Select object to set new date: 1 or 2\n");
            scanf("%d", &result);
            printf("Enter year\n");
            scanf("%d", &myyear);
            printf("Enter month\n");
            scanf("%d", &mymonth);
            printf("Enter day\n");
            scanf("%d", &myday);
            if (result == 1)
            {
                SetNewDate(myDate, myday, mymonth, myyear);
            }
            if (result == 2)
            {
                SetNewDate(myDate2, myday, mymonth, myyear);
            }
            break;
        case 8:
            printf("Select object to print date: 1 or 2\n");
            scanf("%d", &result);
            printf("Enter date mode 0 or 1\n");
            scanf("%d", &dateMode);
            if (result == 1)
            {
                PrintDate(myDate, dateMode);
            }
            if (result == 2)
            {
                PrintDate(myDate2, dateMode);
            }
            break;
        case 9:
            printf("Select date object to destroy: 1 or 2");
            scanf("%d", &result);
            if (result == 1)
            {
                if (myDate != NULL)
                {
                    DestroyDate(myDate);
                }
            }
            if (result == 2)
            {
                if (myDate2 != NULL)
                {
                    DestroyDate(myDate2);
                }
            }
            break;
        case 10:
            printf("Select date object to check leap year: 1 or 2");
            scanf("%d", &result);
            if (result == 1)
            {
                if (myDate != NULL)
                {
                    leapyear = IsLeapYear(myDate);
                    printf("Leap year result: %d\n", leapyear);
                }
            }
            if (result == 2)
            {
                if (myDate2 != NULL)
                {
                    leapyear = IsLeapYear(myDate2);
                    printf("Leap year result: %d\n", leapyear);
                }
            }
            break;
        }
    }
    return 0;
}