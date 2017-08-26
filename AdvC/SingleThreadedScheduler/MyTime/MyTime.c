#include "MyTime.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>


struct Time
{
	struct timespec	m_time;
};


Time* TimeCreate()
{

	Time* time;
	
	if (!(time = malloc(sizeof(Time))))
	{
		return NULL;
	}

	return time;
}






void TimeDestroy(Time* _time)
{
	if (!_time)
	{
		return;
	}
	
	free(_time);
	
	return;
}






void TimeSetPeriod(Time* _time, int _milliSecs)
{
	if (!_time)
	{
		return;
	}
	
	if (0 < _milliSecs)
	{
		_time->m_time.tv_sec = (time_t)(_milliSecs / 1000);
		_time->m_time.tv_nsec = (long)((_milliSecs % 1000) * 1000000);
	}
	else
	{
		_time->m_time.tv_sec = 0;
		_time->m_time.tv_nsec = 0;
	}
	
	return;
}





void TimeGetCurrent(Time* _time, const clockid_t _clockID)
{
	if (!_time)
	{
		return;
	}
	
	clock_gettime(_clockID, &(_time->m_time));
	
	return;
}





int	TimeCompare(const Time* _time1, const Time* _time2)
{
	if (!_time1 || !_time2)
	{
		return -1;
	}
	
	if (_time1->m_time.tv_sec < _time2->m_time.tv_sec)
	{
		return 1;
	}
	
	if (_time1->m_time.tv_sec == _time2->m_time.tv_sec)
	{
		if (_time1->m_time.tv_nsec < _time2->m_time.tv_nsec)
		{
			return 1;
		}
	}
	
	return 0;
}





void TimeSleepUntil(const Time* _time, const clockid_t _clockID)
{

	if (!_time)
	{
		return;
	}
	
	/*nanosleep(&(_time->m_time), NULL);*/
	clock_nanosleep(_clockID, TIMER_ABSTIME, &(_time->m_time), NULL);
	
	return;
}





void TimeAdd(Time* _result, const Time* _added)
{
	long nSec;
	if (!_result || !_added)
	{
		return;
	}
	
	_result->m_time.tv_sec += _added->m_time.tv_sec;
	
	nSec = _result->m_time.tv_nsec + _added->m_time.tv_nsec;
	if (nSec / 1000000000 > 0)
	{
		++(_result->m_time.tv_sec);
		_result->m_time.tv_nsec += nSec % 10;
		return;
	}
	_result->m_time.tv_nsec = nSec;
	
	return;
}




