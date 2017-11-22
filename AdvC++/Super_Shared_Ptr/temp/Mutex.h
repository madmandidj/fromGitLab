#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <pthread.h>

class Mutex
{
public:
	Mutex();
	~Mutex();
	void Lock();
	void Unlock();
	
private:
	pthread_mutex_t m_mutex;
};

inline Mutex::Mutex()
{
	pthread_mutex_init(&m_mutex, 0);
}

inline Mutex::~Mutex()
{
	pthread_mutex_destroy(&m_mutex);
}

inline void Mutex::Lock()
{
	pthread_mutex_lock(&m_mutex);
}

inline void Mutex::Unlock()
{
	pthread_mutex_unlock(&m_mutex);
}

// -------------------------------------

class Guard
{
public:
	Guard(Mutex& _mutex);
	~Guard();
private:
	Mutex& m_mutex;
};

inline Guard::Guard(Mutex& _mutex)
: 	m_mutex(_mutex)
{
	m_mutex.Lock();
}

inline Guard::~Guard()
{
	m_mutex.Unlock();
}

#endif // __MUTEX_H__

