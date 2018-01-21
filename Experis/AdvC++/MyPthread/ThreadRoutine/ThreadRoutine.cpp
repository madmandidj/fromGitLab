#include "ThreadRoutine.h"
namespace advcpp
{
bool ThreadRoutine::m_shouldShutdown = false;

ThreadRoutine::ThreadRoutine(advcpp::TSPQ<Task>& _tspqRef):m_tspqRef(_tspqRef)
{
	//Empty
}

ThreadRoutine::~ThreadRoutine()
{
	//Empty
}

void* ThreadRoutine::Run()
{
	while(!m_shouldShutdown)
	{
		//Pseudo:
		/*
		Mark this thread as waiting
		Pop task from PQ
		Mark this thread as working
		Run task
		*/
	}
}


}//namespace advcpp


