#include "CondVar.h"
#include "../Mutex/Mutex.h"
#include<stdio.h>
#include<errno.h>

namespace advcpp
{


CondVar::~CondVar()
{
	int errVal;
	if (0 != (errVal = pthread_cond_destroy(&m_cond_t)))
	{
		switch (errVal)
		{
			case EBUSY:
				perror("CondVar DTOR, EBUSY!");
				break;
			case EINVAL:
				perror("CondVar DTOR, EINVAL!");
				break;
			case EAGAIN:
				perror("CondVar DTOR, EAGAIN!");
				break;
			case ENOMEM:
				perror("CondVar DTOR, ENOMEM!");
				break;	
		}
	}
}

CondVar::CondVar()
{
	int errVal;
	if (0 != (errVal = pthread_cond_init(&m_cond_t, 0)))
	{
		switch (errVal)
		{
			case EBUSY:
				perror("CondVar CTOR, EBUSY!");
				break;
			case EINVAL:
				perror("CondVar CTOR, EINVAL!");
				break;
		}
	}
}

void CondVar::Wait(Mutex& _mutex)
{
	pthread_cond_wait(&m_cond_t, &_mutex.m_mutex);
}

void CondVar::NotifyOne()
{
	pthread_cond_signal(&m_cond_t);
}

void CondVar::NotifyAll()
{
	pthread_cond_broadcast(&m_cond_t);
}





















}//namespace advcpp

