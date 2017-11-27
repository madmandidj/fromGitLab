#include "CondVar.h"
#include "../Mutex/Mutex.h"
#include "../SyncExceptions/SyncExceptions.h"
#include<stdio.h>
#include<errno.h>
#include<assert.h>

namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////CondVar public function definitions
CondVar::~CondVar()
{
	int errVal = pthread_cond_destroy(&m_condVar);
	assert(0 == errVal);
}

CondVar::CondVar(Mutex& _mutex):m_mutex(_mutex)
{
	int errVal;
	if (0 != (errVal = pthread_cond_init(&m_condVar, 0)))
	{
		assert(errVal != EBUSY && errVal != EINVAL);
		switch (errVal)
		{
			case EAGAIN:
				throw CondVar_NoResources_Exc();
			case ENOMEM:
				throw CondVar_NoMemory_Exc();
			default:
				break;
		}
	}
}

void CondVar::Wait()
{
	int errVal = pthread_cond_wait(&m_condVar, &m_mutex.m_mutex);
	assert(0 == errVal);
}

void CondVar::NotifyOne()
{
	int errVal = pthread_cond_signal(&m_condVar);
	assert(0 == errVal);
}

void CondVar::NotifyAll()
{
	int errVal = pthread_cond_broadcast(&m_condVar);
	assert(0 == errVal);
}





















}//namespace advcpp

