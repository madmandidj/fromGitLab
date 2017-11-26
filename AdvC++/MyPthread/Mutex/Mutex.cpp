#include "Mutex.h"
#include "../SyncExceptions/SyncExceptions.h"
#include <errno.h>
#include<stdio.h>
#include<assert.h>

namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Mutex public function definitions
Mutex::~Mutex()
{
	int errVal = pthread_mutex_destroy(&m_mutex);
	assert(0 == errVal);
}

Mutex::Mutex()
{
	int errVal;
	if (0 != (errVal = pthread_mutex_init(&m_mutex, 0)))
	{
		assert(errVal != EPERM && errVal != EBUSY && errVal != EINVAL);
		switch (errVal)
		{
			case EAGAIN:
				throw NoResources_Exc();
			case ENOMEM:
				throw NoMemory_Exc();
			default:
				break;
		}
	}
}

bool Mutex::Lock()
{
	return (0 == pthread_mutex_lock(&m_mutex));
}

bool Mutex::Trylock()
{
	return (0 == pthread_mutex_trylock(&m_mutex));
}

bool Mutex::Unlock()
{
	return (0 == pthread_mutex_unlock(&m_mutex));
}



}//namespace advcpp

