#include "Heap.h"
#include "PeriodicExecuter.h"
#include <stdlib.h>

typedef Heap PriorityQueue;

typedef struct PeriodicExecutor
{
	PriorityQueue*	m_priorityQ;
	size_t			m_runCycles;
	int				m_pauseRequest;
	const char*		m_name;
	clockid_t		m_clockID;
	/* add magic num? */
};


PeriodicExecutor* PeriodicExecutorCreate(const char* _name, clockid_t ​_clk_id)
{
	/*
	
	check valid param (is _name mandatory?)
	
	create periodic executer
	check create success
	
	create priority queue
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
	Destroy Priority Queue (can time and tasks be destroyed here as well?)
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
	
	*/
}


size_t PeriodicExecutorPause(PeriodicExecutor* _executor)
{
	/*
	
	*/
}




















