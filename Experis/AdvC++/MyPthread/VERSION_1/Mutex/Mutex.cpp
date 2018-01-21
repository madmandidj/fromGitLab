#include "Mutex.h"
#include "errno.h"
#include<stdio.h>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Mutex public function definitions
Mutex::~Mutex() //TODO: Do assert and/or throw where relevant
{
	int errVal;
	if (0 != (errVal = pthread_mutex_destroy(&m_mutex)))
	{
		switch (errVal)
		{
			case EBUSY:
				pthread_mutex_unlock(&m_mutex); //TODO: this is me handling a bug of a user so should not do this
				pthread_mutex_destroy(&m_mutex);
				perror("Mutex Destructor Error"); 
				break;
			case EINVAL:
				perror("Mutex Destructor Error");
				break;
		}
	}

}

Mutex::Mutex() //TODO: Do assert and/or throw where relevant
{
	int errVal;
	
	if (0 != (errVal = pthread_mutex_init(&m_mutex, 0)))
	{
		switch (errVal)
		{
			case EAGAIN:
				perror("Mutex Constructor Error");
				break;
			case ENOMEM:
				perror("Mutex Constructor Error");
				break;
			case EPERM:
				perror("Mutex Constructor Error");
				break;
			case EBUSY:
				perror("Mutex Constructor Error");
				break;
			case EINVAL:
				perror("Mutex Constructor Error");
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

