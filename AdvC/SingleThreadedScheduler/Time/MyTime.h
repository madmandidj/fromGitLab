#ifndef __MYTIME_H__
#define __MYTIME_H__

typedef struct Time Time;

Time* TimeCreate(int _milliSecs);

void TimeGetCurrent(const clockid_t _clockID, Time* TimeCreate);

void TimeDestroy(Time*);

int	TimeCompare(const Time*, const Time*)

void TimeSleepUntil(const Time*)

void TimeAdd(Time* _result, const Time* _added);



#endif /* #ifndef __MYTIME_H__ */
