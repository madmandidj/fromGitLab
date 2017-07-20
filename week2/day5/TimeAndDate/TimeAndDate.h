#ifndef TAD_H
#define TAD_H
#define FAIL_VAL 0
#define SUCCESS_VAL 1
#define ERROR_VAL -1
#define MAX_SECS 60
#define MIN_SECS 0
#define MAX_MINS 60
#define MIN_MINS 0
#define MAX_HORS 24
#define MIN_HORS 0
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MAX_DAY 31
#define MIN_DAY 1

struct cTime_t
{
    int secs;
    int mins;
    int hors;
};
struct cDate_t
{
    int day;
    int mnt;
    int yer;
};
typedef struct cDate_t cDate_t;
typedef struct cTime_t cTime_t;
/*
Allocates memory for new cTime_t object
Input:      void 
Output:     pointer to new cTime_t object
Error:      If no memory available, myTime = NULL
*/
cTime_t *CreateNewTime();
/*
Free memory of input cTime_t object
Input:      pointer to cTime_t object 
Output:     '1' if success, '-1' if no valid cTime_t pointer
Error:      If not valid cTime_t pointer return '-1'
*/
int DestroyTime(cTime_t *myTime);
/*
Set new time for cTime_t object
Input:      pointer to cTime_t object, int seconds, int minutes, int hours 
Output:     '1' if success, '0' if not valid time values, '-1' if no valid cTime_t pointer
Error:      If not valid cTime_t pointer return '-1'
*/
int SetNewTime(cTime_t *myTime, int hors, int mins, int secs);
/*
Print seconds stored in cTime_t object
Input:      pointer to cTime_t object
Output:     '1' if success, '-1' if no valid cTime_t pointer
Error:      If not valid cTime_t pointer return '-1'
*/
int PrintSeconds(cTime_t *myTime, int timeMode);
/*
Print minutes stored in cTime_t object
Input:      pointer to cTime_t object, timeMode
Output:     '1' if success, '-1' if no valid cTime_t pointer
Error:      If not valid cTime_t pointer return '-1'
*/
int PrintMinutes(cTime_t *myTime);
/*
Print hors stored in cTime_t object
Input:      pointer to cTime_t object, timeMode
Output:     '1' if success, '-1' if no valid cTime_t pointer
Error:      If not valid cTime_t pointer return '-1'
*/
int PrintHours(cTime_t *myTime, int timeMode);
/*
Prints cTime_t object's time in format selected by the value of timeMode
Input:      pointer to cTime_t object, integer timeMode (0= "00:00-11:59 AM/PM", 1= "00:00 - 23:59")
Output:     '1' if success, '0' if not valid timeMode, '-1' if no valid cTime_t pointer or timeMode invalid
Error:      If not valid cTime_t pointer return '-1'
*/
int PrintTime(cTime_t *myTime, int timeMode);
/*
Adds time values of two cTime_t objects
Input:      pointer to cTime_t object, pointer to cTime_t object
Output:     Addition result is placed in myTime1. Returns '1' if success, '-1' if no valid cTime_t pointers
Error:      If not valid cTime_t pointers return '-1'
*/
int AddTime(cTime_t *myTime1, cTime_t *myTime2);


/*
Allocates memory for new cDate_t object
Input:      void 
Output:     pointer to new cDate_t object
Error:      If no memory available, myDate = NULL
*/
cDate_t* CreateNewDate();
/*
Free memory of input cDate_t object
Input:      pointer to cDate_t object 
Output:     '1' if success, '-1' if no valid cDate_t pointer
Error:      If not valid cDate_t pointer return '-1'
*/
int DestroyDate(cDate_t *myDate);

int SetNewDate(cDate_t *myDate, int day, int mnt, int yer);

int PrintDay(cDate_t *myDate);

int PrintMonth(cDate_t *myDate, int dateMode);

int PrintYear(cDate_t *myDate);

int PrintDate(cDate_t *myDate, int dateMode);

int IsLeapYear(cDate_t* myDate);


#endif
