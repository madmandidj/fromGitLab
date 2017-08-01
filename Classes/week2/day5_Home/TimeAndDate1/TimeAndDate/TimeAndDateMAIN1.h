#ifndef TAD_H
#define TAD_H

struct cTime_t{
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;
};

struct cDate_t{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

typedef struct cDate_t cDate_t;
typedef struct cTime_t cTime_t;

int SetNewTime(cTime_t* myTime);
int PrintSeconds(cTime_t* myTime);
int PrintMinutes(cTime_t* myTime);
int PrintHours(cTime_t* myTime);
int PrintTime(cTime_t* myTime, int timeMode);
int AddTime(cTime_t* myTime1, cTime_t* myTime2);

int SetNewDate(cDate_t* myDate);
int PrintDay(cDate_t* myDate);
int PrintMonth(cDate_t* myDate);
int PrintYear(cDate_t* myDate);
int PrintDate(cDate_t* myDate, int dateMode);

#endif
