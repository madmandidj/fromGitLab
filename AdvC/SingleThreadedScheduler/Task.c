
#include "Task.h"
#include "MyTime.h"
#include <stdlib.h>

struct Task
{
	TaskFunction	m_taskFunc;
	void*			m_context;
	Time*			m_nextRunTime;
	Time*			m_runPeriod;
};


Task* TaskCreate(TaskFunction _taskFunc, void* _context, int _periodMillis, const clockid_t _clockID)
{	
	Task* task;	
		
	if (!_taskFunc)
	{
		return NULL;
	}
	
	if (!(task = malloc(sizeof(Task))))
	{
		return NULL;
	}
	
	task->m_taskFunc = _taskFunc;
	task->m_context = _context;
	
	if (!(task->m_runPeriod = TimeCreate()))
	{
		return NULL;
	}
	TimeSetPeriod(task->m_runPeriod, _periodMillis);
	
	if (!(task->m_nextRunTime = TimeCreate()))
	{
		return NULL;
	}
	TaskGetNextRunTime(task, _clockID);
	
	return task;
}


void TaskDestroy(Task* _task)
{
	if (!_task)
	{
		return;
	}
	
	TimeDestroy(_task->m_runPeriod);
	TimeDestroy(_task->m_nextRunTime);
	free(_task);
	
	return;
}


void TaskGetNextRunTime(Task* _task, const clockid_t _clockID)
{
	if (!_task)
	{
		return;
	}
	
	TimeGetCurrent(_task->m_nextRunTime, CLOCK_REALTIME);
	TimeAdd(_task->m_nextRunTime, _task->m_runPeriod);
	
	return;
}


int	TaskExecute(Task* _task, const clockid_t _clockID)
{
	if (!_task)
	{
		return 1;
	}
	
	TimeSleepUntil(_task->m_nextRunTime, _clockID);
	return _task->m_taskFunc(_task->m_context);	
}


int	TaskCompare(Task* _task1, Task* _task2)
{
	if (!_task1 || !_task2)
	{
		return -1;
	}
	
	return TimeCompare(_task1->m_nextRunTime, _task2->m_nextRunTime);
}




















