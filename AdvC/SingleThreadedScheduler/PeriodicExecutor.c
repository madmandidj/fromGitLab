
#include "./PriorityQ/PriorityQ.h"
#include "./Task/Task.h"
#include "PeriodicExecutor.h"
#include <string.h>

#define PE_MAGICNUM 0xCDDDEEEE

struct PE
{
	size_t 			m_magicNum;
	PQ*				m_pq;
	size_t			m_runCycles;
	int				m_pauseRequest;
	char			m_name[64];
	clockid_t		m_clockID;
};






PE* PeriodicExecutor_Create(const char* _name, clockid_t _clk_id)
{
	/*
	TODO: should creation of vector be done in PQ scope?
	*/
	Vector* vec;
	PE* pe;
	
	if (!(pe = malloc(sizeof(PE))))
	{
		return NULL;
	}
	
	if (!(vec = VecCreate(10, 5)))
	{
		return NULL;
	}
	
	if (!(pe->m_pq = PQBuild(vec, (LessThanComparator)TaskCompare)))
	{
		return NULL;
	}
	
	pe->m_runCycles = 0;
	pe->m_pauseRequest = 0;
	strcpy(pe->m_name, _name);
	pe->m_clockID = _clk_id;
	pe->m_magicNum = PE_MAGICNUM;

	return pe;
}






void PeriodicExecutor_Destroy(PE* _executor)
{
	Vector* vec;
	
	if (!_executor)
	{
		return;
	}	
	/*
	TODO: should destruction of vector be done in PQ scope?
	*/
	vec = PQDestroy(&(_executor->m_pq));
	VecDestroy(&vec, (ElementDestroy)TaskDestroy);
	_executor->m_magicNum = 0;
	free(_executor);
	
	return;
}






int PeriodicExecutor_Add(PE* _executor, TaskFunction _taskFunc, void* _context, int _period_ms)
{
	Task* task;
	
	if (!_executor || !_taskFunc)
	{
		return 1;
	}
	
	if (!(task = TaskCreate(_taskFunc, _context, _period_ms, _executor->m_clockID)))
	{
		return 1;
	}
	
	if (PQ_SUCCESS != PQInsert(_executor->m_pq, task))
	{
		return 1;
	}
	
	return 0;
}






size_t PeriodicExecutor_Run(PE* _executor)
{
	Task* task;
	int result;
	
	if (!_executor)
	{
		return 0;
	}
	
	_executor->m_pauseRequest = 0;
	
	while(0 < PQSize(_executor->m_pq))
	{
		task = PQExtract(_executor->m_pq);
		result = TaskExecute(task, _executor->m_clockID);
		++(_executor->m_runCycles);
		if (0 == result)
		{
			TaskGetNextRunTime(task, _executor->m_clockID);
			PQInsert(_executor->m_pq, task);
		}
		if (0 != _executor->m_pauseRequest)
		{
			break;
		}
	}
	
	return _executor->m_runCycles;
}






size_t PeriodicExecutor_Pause(PE* _executor)
{
	if (!_executor)
	{
		return 0;
	}
	
	_executor->m_pauseRequest = 1;
	
	return PQSize(_executor->m_pq);
}




