#ifndef __MYTIME_H__
#define __MYTIME_H__

typedef struct Time Time;

Time* TimeCreate(int _milliSecs); /* better to save here as usec / nsec ?? */

void TimeDestroy(Time* _time);

void TimeGetCurrent(const clockid_t _clockID, Time* _time);

int	TimeCompare(const Time* _time1, const Time* _time2);

void TimeSleepUntil(const Time* _time);

void TimeAdd(Time* _result, const Time* _added);


#endif /* #ifndef __MYTIME_H__ */
