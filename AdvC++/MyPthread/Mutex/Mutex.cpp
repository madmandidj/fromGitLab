#include "Mutex.h"
#include "errno.h"
#include<stdio.h>
namespace advcpp
{








//////////////////////////////////////////////////////////////////////////////////
////Mutex public function definitions
Mutex::~Mutex()
{
	int errVal;
	if (0 != (errVal = pthread_mutex_destroy(&m_mutex)))
	{
		switch (errVal)
		{
			case EBUSY:
				pthread_mutex_unlock(&m_mutex);
				pthread_mutex_destroy(&m_mutex);
				break;
			case EINVAL:
				perror("Mutex Destructor Error");
				break;
		}
	}

}

Mutex::Mutex()
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

void Mutex::Lock()
{
	pthread_mutex_lock(&m_mutex);
}

void Mutex::Unlock()
{
	pthread_mutex_unlock(&m_mutex);
}

void Mutex::Trylock()
{
	pthread_mutex_trylock(&m_mutex);
}


}//namespace advcpp

