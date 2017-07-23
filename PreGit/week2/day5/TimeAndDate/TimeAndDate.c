#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TimeAndDate.h"
/*
TODO:/
- Check why first '0' for single digit "hour" doesnt print sometimes
*/
cTime_t *CreateNewTime()
{
    cTime_t *myTime;
    myTime = malloc(sizeof(cTime_t));
    if (myTime == NULL)
    {
        return NULL;
    }
    else
    {
        return myTime;
    }
}

int SetHors(cTime_t *myTime, int hors)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    else if (hors < MIN_HORS)
    {
        return FAIL_VAL;
    }
    else
    {
        myTime->hors = hors % (MAX_HORS);
    }
    return SUCCESS_VAL;
}

int SetMins(cTime_t *myTime, int mins)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    else if (mins < MIN_MINS)
    {
        return FAIL_VAL;
    }
    else
    {
        myTime->mins = mins % (MAX_MINS);
    }
    return SUCCESS_VAL;
}

int SetSecs(cTime_t *myTime, int secs)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    else if (secs < MIN_SECS)
    {
        return FAIL_VAL;
    }
    else
    {
        myTime->secs = secs % (MAX_SECS);
    }
    return SUCCESS_VAL;
}

int SetNewTime(cTime_t *myTime, int hors, int mins, int secs)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    int result = SetSecs(myTime, secs);
    if (result != SUCCESS_VAL)
    {
        return result;
    }
    result = SetMins(myTime, mins);
    if (result != SUCCESS_VAL)
    {
        return result;
    }
    result = SetHors(myTime, hors);
    if (result != SUCCESS_VAL)
    {
        return result;
    }
    return SUCCESS_VAL;
}

int PrintSeconds(cTime_t *myTime, int timeMode)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    if (timeMode == 0)
    {
        if (myTime->secs / 10 == 0 && myTime->hors % 24 >= 12)
        {
            printf("0%d PM", myTime->secs);
        }
        else if (myTime->secs / 10 == 0 && myTime->hors % 24 < 12)
        {
            printf("0%d AM", myTime->secs);
        }
        else if (myTime->hors % 24 >= 12)
        {
            printf("%d PM", myTime->secs);
        }
        else if (myTime->hors % 24 < 12)
        {
            printf("%d AM", myTime->secs);
        }
    }
    if (timeMode == 1)
    {
        if (myTime->secs / 10 == 0)
        {
            printf("0%d", myTime->secs);
        }
        else
        {
            printf("%d", myTime->secs);
        }
    }
    return SUCCESS_VAL;
}

int PrintMinutes(cTime_t *myTime)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    if (myTime->mins / 10 == 0)
    {
        printf("0%d", myTime->mins);
    }
    else
    {
        printf("%d", myTime->mins);
    }
    return SUCCESS_VAL;
}

int PrintHours(cTime_t *myTime, int timeMode)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }

    if (timeMode == 0)
    {
        if (myTime->hors / 10 == 0)
        {
            printf("0%d", myTime->hors);
        }
        else
        {
            printf("%d", myTime->hors % 12);
        }
    }
    if (timeMode == 1)
    {
        if (myTime->hors / 10 == 0)
        {
            printf("0%d", myTime->hors);
        }
        else
        {
            printf("%d", myTime->hors);
        }
    }
    return SUCCESS_VAL;
}

int PrintTime(cTime_t *myTime, int timeMode)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    if (timeMode > 1 || timeMode < 0)
    {
        return FAIL_VAL;
    }
    if (timeMode == 1)
    {
        PrintHours(myTime, timeMode);
        printf(":");
        PrintMinutes(myTime);
        printf(":");
        PrintSeconds(myTime, timeMode);
        printf("\n");
    }
    if (timeMode == 0)
    {
        PrintHours(myTime, timeMode);
        printf(":");
        PrintMinutes(myTime);
        printf(":");
        PrintSeconds(myTime, timeMode);
        printf("\n");
    }
    return SUCCESS_VAL;
}
/*
TODO:
- carry_mins and carry_hors doesnt work in all cases. Try values above MAX sec,min,hour values.
*/
int AddTime(cTime_t *myTime1, cTime_t *myTime2)
{
    if (myTime1 == NULL || myTime2 == NULL)
    {
        return ERROR_VAL;
    }
    int carry_mins = 0;
    int carry_hors = 0;
    myTime1->secs += myTime2->secs;
    carry_mins = myTime1->secs / MAX_SECS;
    myTime1->secs %= MAX_SECS;
    myTime1->mins += myTime2->mins + carry_mins;
    carry_hors = myTime1->mins / MAX_MINS;
    myTime1->mins %= MAX_MINS;
    myTime1->hors += myTime2->hors + carry_hors;
    myTime1->hors %= MAX_HORS;
    return SUCCESS_VAL;
}

int DestroyTime(cTime_t *myTime)
{
    if (myTime == NULL)
    {
        return ERROR_VAL;
    }
    free(myTime);
    return SUCCESS_VAL;
}

cDate_t *CreateNewDate()
{
    cDate_t *myDate;
    myDate = malloc(sizeof(cDate_t));
    if (myDate == NULL)
    {
        return NULL;
    }
    else
    {
        return myDate;
    }
}

int SetYear(cDate_t *myDate, int yer)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    else
    {
        myDate->yer = yer;
    }
    return SUCCESS_VAL;
}

int SetMonth(cDate_t *myDate, int mnt)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    else if (mnt > MAX_MONTH || mnt < MIN_MONTH)
    {
        return FAIL_VAL;
    }
    else
    {
        myDate->mnt = mnt;
    }
    return SUCCESS_VAL;
}

int SetDay(cDate_t *myDate, int day)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    else if (day > MAX_DAY || day < MIN_DAY)
    {
        return FAIL_VAL;
    }
    else
    {
        myDate->day = day;
    }
    return SUCCESS_VAL;
}

int SetNewDate(cDate_t *myDate, int day, int mnt, int yer)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    int result = SetDay(myDate, day);
    if (result != SUCCESS_VAL)
    {
        return result;
    }
    result = SetMonth(myDate, mnt);
    if (result != SUCCESS_VAL)
    {
        return result;
    }
    result = SetYear(myDate, yer);
    if (result != SUCCESS_VAL)
    {
        return result;
    }
    return SUCCESS_VAL;
}

int PrintDay(cDate_t *myDate)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    if (myDate->day / 10 == 0)
    {
        printf("0%d", myDate->day);
    }
    else
    {
        printf("%d", myDate->day);
    }
    return SUCCESS_VAL;
}

int PrintMonth(cDate_t *myDate, int dateMode)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    if (dateMode < 0 || dateMode > 1)
    {
        return ERROR_VAL;
    }
    switch (dateMode)
    {
    default:
        if (myDate->mnt / 10 == 0)
        {
            printf("0%d", myDate->mnt);
        }
        else
        {
            printf("%d", myDate->mnt);
        }
        break;
    case 0:
        switch (myDate->mnt)
        {
        case 1:
            printf("Jan");
            break;
        case 2:
            printf("Feb");
            break;
        case 3:
            printf("Mar");
            break;
        case 4:
            printf("Apr");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("Jun");
            break;
        case 7:
            printf("Jul");
            break;
        case 8:
            printf("Aug");
            break;
        case 9:
            printf("Sep");
            break;
        case 10:
            printf("Oct");
            break;
        case 11:
            printf("Nov");
            break;
        case 12:
            printf("Dec");
            break;
        }
        break;
    }
    return SUCCESS_VAL;
}

int PrintYear(cDate_t *myDate)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    printf("%d", myDate->yer);
    return SUCCESS_VAL;
}

int PrintDate(cDate_t *myDate, int dateMode)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    if (dateMode < 0 || dateMode > 1)
    {
        return ERROR_VAL;
    }
    switch (dateMode)
    {
    default:
        PrintDay(myDate);
        printf("/");
        PrintMonth(myDate, dateMode);
        printf("/");
        PrintYear(myDate);
        printf("\n");
        break;
    case 1:
        PrintMonth(myDate, dateMode);
        printf("/");
        PrintDay(myDate);
        printf("/");
        PrintYear(myDate);
        printf("\n");
        break;
    }
    return SUCCESS_VAL;
}

int IsLeapYear(cDate_t *myDate)
{
    if (myDate->yer % 4 != 0)
    {
        return FAIL_VAL;
    }
    else if (myDate->yer % 100 != 0)
    {
        return SUCCESS_VAL;
    }
    else if (myDate->yer % 400 != 0)
    {
        return FAIL_VAL;
    }
    else
    {
        return SUCCESS_VAL;
    }
}

int DestroyDate(cDate_t *myDate)
{
    if (myDate == NULL)
    {
        return ERROR_VAL;
    }
    free(myDate);
    return SUCCESS_VAL;
}
