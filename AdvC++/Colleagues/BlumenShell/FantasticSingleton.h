#ifndef FANTASTIC_SINGLETON_H_
#define FANTASTIC_SINGLETON_H_

#include "Mutex.h"
#include <tr1/memory>
#include <iostream>
#include <pthread.h>

template<class T>
class Singleton
{
public:
	static std::tr1::shared_ptr<T> GetInstance();
private:
	Singleton();
	static Mutex m_mutex;
	static int m_isConstructed;
	static std::tr1::shared_ptr<T> m_instance;
};

template<class T>
std::tr1::shared_ptr<T> Singleton<T>::m_instance;

template<class T>
Mutex Singleton<T>::m_mutex;

template<class T>
int Singleton<T>::m_isConstructed = 0;

template<class T>
std::tr1::shared_ptr<T> Singleton<T>::GetInstance()
{
	if(0 == __sync_fetch_and_and(&m_isConstructed, 1))
	{
		Guard guard(m_mutex);
		if(0 == __sync_fetch_and_and(&m_isConstructed, 1))
		{
			m_instance = std::tr1::shared_ptr<T>(new T);
			__sync_fetch_and_add (&m_isConstructed, 1);
		}
	}
	return m_instance;
}


#endif // FANTASTIC_SINGLETON_H_
