#include "Processor.h"

#define PROCESSOR_MAGIC 0x0C111111

struct Processor
{
	unsigned int 		m_magicNum;
	unsigned int		m_numOfThreads;
	pthread_t*			m_threadIDs;
	Subscriber			m_subscriber;
	Operator			m_operator;
};



Processor* ProcessorCreate(unsigned int _numOfThreads)
{
	Processor* proc;
	
	proc = malloc(sizeof(Processor));
	if (!proc)
	{
		return NULL;
	}
	
	proc->m_numOfThreads = _numOfThreads;
	
	proc->m_threadIDs = malloc(proc->m_numOfThreads * sizeof(pthread_t));
	if (!proc->m_threadIDs)
	{
		free(proc);
		return NULL;
	}
	
	proc->m_magicNum = PROCESSOR_MAGIC;

	return proc;
}







void ProcessorDestroy(Processor* _proc)
{
	if (!_proc)
	{
		return;
	}
	
	free(proc->m_threadIDs);
	free(proc);
	return;
}





typedef void* (*ThreadRoutine)(void*);

int ProcessorRun(Processor* _proc)



















