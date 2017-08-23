#include "MyTime.h"


struct Time
{
	struct timespec	m_time;
};


Time* TimeCreate(int _milliSecs)
{
	/*
	
	Allocate Time variable
	
	if _milliSecs < 0 
		return Time*
		
	else
		m_time = _milliSecs

	return Time*
	*/
}


void TimeGetCurrent(const clockid_t _clockID, Time* TimeCreate)
{
	/*
		
	*/
}







