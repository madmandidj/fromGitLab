#include "MyTime.h"


struct Time
{
	struct timespec	m_time;
};


Time* TimeCreate(int _milliSecs)
{
	/*
	
	Create Time* variable
	Check allocation success
	
	if _milliSecs < 0 
		return Time*
		
	else
		m_time = _milliSecs TODO: should store as usec?

	return Time*
	*/
}

void TimeDestroy(Time* _time)
{
	/*
	
	Check valid param
	
	free(_time)
	
	return
	
	*/
}


void TimeGetCurrent(const clockid_t _clockID, Time* _time)
{
	/*
	
	Check valid params
	
	get current time in nsec
	
	convert to usec /* TODO: can do this in timecreate and store as usec? */
	
	return
		
	*/
}


int	TimeCompare(const Time* _time1, const Time* _time2)
{
	/*
	
	Check valid params
	
	if _time1 < _time2
		return TRUE

	else
		return FALSE	
	
	*/
}


void TimeSleepUntil(const Time* _time)
{
	/*
	
	Check valid param
	
	usleep  (TODO: usleep is obsolete, use nanosleep instead?)
	
	return
	
	*/

}


void TimeAdd(Time* _result, const Time* _added)
{
	/*
	
	check valid params
	
	_result += _added  (TODO: Need to take care of carry value)
	
	return 
	
	*/
}




