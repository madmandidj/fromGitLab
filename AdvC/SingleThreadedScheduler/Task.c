#include "Task.h"

struct Task
{
	TaskFunction	m_taskFunc;
	void*		m_context;
	Time		m_nextTime;
	Time		m_interval;
	/* TODO: Finish time needed here? if not, then calculate nextTime immediately upon end of execution */
};


Task* TaskCreate(Task _task, void* _context, size_t _period_ms, const clockid_t m_clockID)
{
	/*
	
	Check valid params (TODO: What is minimum period possible?)
	
	Create task
	check create success
	
	set m_taskFunc
	
	set m_context
	
	calculate period in usec
	create
	set m_interval
	
	call TaskCalculateNext(), place into m_nextTime
	
	return Task*
		
	*/
}


void TaskDestroy(Task* _task)
{
	/*
	
	check valid params
	
	free(_task)
	
	return
	*/
}


void TaskCalculateNext(Task* _Task, const clockid_t m_clockID)
{
	/*
	
	check valid param
	
	TimeAdd(last finish time, interval)
	
	return
	
	*/
}


int	TaskExecute(Task* _task)
{
	/*
	
	check valid param
	
	call task function
	
	TaskCalculateNext() (TODO: should this be done here)
	
	return TRUE if another execution needed, FALSE if not
	
	*/
}


int	TaskCompare(Task* _task1, Task* _task2)
{
	/*
	
	check valid params
	
	TimeCompare(nextTime1, nextTime2)
	
	returns TRUE if nextTime1 < nextTime2, FALSE if not
	
	*/
}




















