#ifndef __MYTIME_H__
#define __MYTIME_H__

#include <time.h>

/*
TODO: Add documentation for this module and functions
*/

typedef struct Time Time;

Time* TimeCreate(); 

void TimeDestroy(Time* _time);

void TimeSetPeriod(Time* _time, int _milliSecs);

void TimeAdd(Time* _result, const Time* _added);

int	TimeCompare(const Time* _time1, const Time* _time2);

void TimeGetCurrent(Time* _time, const clockid_t _clockID);

void TimeSleepUntil(const Time* _time, const clockid_t _clockID);


#endif /* #ifndef __MYTIME_H__ */
