#ifndef __LOCK_H__
#define __LOCK_H__

#include<pthread.h>
#include<tr1/memory>

class Lock
{
public:
	~Lock();
	Lock(pthread_mutex_t* _mutex);
	
protected:

private:
	pthread_mutex_t* m_mutexPtr;
};

Lock::Lock(pthread_mutex_t* _mutex) : m_mutexPtr(_mutex)
{
	pthread_mutex_lock(m_mutexPtr);
}


Lock::~Lock()
{
	pthread_mutex_unlock(m_mutexPtr);
}























#endif//#ifndef __LOCK_H__

