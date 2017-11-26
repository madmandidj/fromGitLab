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

void Mutex::Lock()
{
	int errVal;
	if (0 != (errVal = pthread_mutex_lock(&m_mutex)))
	{
		assert(errVal != EDEADLK && errVal != EINVAL);
		switch (errVal)
		{
			case EAGAIN:
				throw NoResources_Exc();
			default:
				break;
		}
	}
}

bool Mutex::Trylock()
{
	int errVal;
	if (0 != (errVal = pthread_mutex_trylock(&m_mutex)))
	{
		assert(errVal != EINVAL);
		switch (errVal)
		{
			case EBUSY:
				return false;
			case EAGAIN:
				throw NoResources_Exc();
			default:
				break;
		}
	}
	return true;
}

void Mutex::Unlock()
{
	int errVal;
	if (0 != (errVal = pthread_mutex_unlock(&m_mutex)))
	{
		assert(errVal != EINVAL && errVal != EPERM);
		switch (errVal)
		{
			case EAGAIN:
				throw NoResources_Exc();
			default:
				break;
		}
	}
}



}//namespace advcpp

