
#include "PeriodicExecuter.h"
#include <stdlib.h>

typedef Heap PriorityQueue;

typedef struct PeriodicExecutor
{
	PriorityQueue*	m_priorityQ;
	size_t			m_runCycles; /* TODO: is redundant? look at PErun()  */
	int				m_pauseRequest;
	const char*		m_name;
	clockid_t		m_clockID;
	/* TODO: add magic num? */
};


PeriodicExecutor* PeriodicExecutorCreate(const char* _name, clockid_t ​_clk_id)
{
	/*
	
	check valid param (TODO: is _name mandatory?)
	
	create periodic executer
	check create success
	
	create priority queue (TODO: HeapBuild with TaskCompare as parameter?)
	check create success
	
	set runCycles 0
	set pauseRequest 0
	set name
	set clockID
	
	return PeriodicExecutor*
	
	*/
}


void PeriodicExecutorDestroy(PeriodicExecutor* _executor)
{
	/*
	
	check valid param
	
	Destroy Time objects
	Destroy Tasks
	Destroy Priority Queue (TODO: can time and tasks be destroyed here as well? ANSWER: probably not)
	Destroy Periodic executer
	
	Destroy 
	
	*/
}


int PeriodicExecutorAdd(PeriodicExecutor* _executor, TaskFunction _task, void* _context, int _period_ms)
{
	/*
	check valid params
	
	TaskCreate()
	check create success
	
	add task to PriorityQueue
	
	TODO: what does return value represent here?
	*/
}


size_t PeriodicExecutorRun(PeriodicExecutor* _executor)
{
	/*
	
	check valid param
	
	while PQ not empty
		TaskExecute
		increment run cycles count
		
		if pauseRequest
			PeriodicExecutorPause
	
	return run cycles count
	*/
}


size_t PeriodicExecutorPause(PeriodicExecutor* _executor)
{
	/*
		check valid param
		
		TODO: option to add additional task 
		
		TODO: how to get out of paused state?
		
		return size of PQ
		
	*/
}




















