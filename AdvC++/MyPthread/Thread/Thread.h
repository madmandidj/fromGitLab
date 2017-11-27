#ifndef __THREAD_H__
#define __THREAD_H__

#include "../SyncExceptions/SyncExceptions.h"
#include "../Mutex/Mutex.h"
#include "../Guard/Guard.h"
#include <boost/core/noncopyable.hpp>
#include <pthread.h>
#if (defined (__linux__))
    #include <tr1/memory>
#elif (defined (__APPLE__))
    #include <memory>
#endif


#include<errno.h>
namespace advcpp
{
////////////////////////////////////////////////////////////////////////
////Thread class
template<class T, void* (T::*Run)()>
class Thread  : private boost::noncopyable
{
public:
	explicit Thread(T* _objectPtr); //Throws: NoResources_Exc
	void Join();
private:
	static void* StartThread(void* _objectPtr);			
	pthread_t 					m_pthread;
	T*							m_object;
//TODO: //	std::tr1::shared_ptr<T>		m_object;
};
////////////////////////////////////////////////////////////////////////
////Thread auxiliary function implementations
template<class T, void* (T::*Run)()>
void* Thread<T,Run>::StartThread(void* _objectPtr)
{
	return (static_cast<T*>(_objectPtr)->*Run)();
}
////////////////////////////////////////////////////////////////////////
////Thread public function implementations
template<class T, void* (T::*Run)()>
Thread<T,Run>::Thread(T* _this):m_object(_this)
{
	int errVal;
//	Guard guard(m_mutex);
	if (0 != (errVal = pthread_create(&m_pthread, 0, StartThread, m_object)))
	{	
		switch (errVal)
		{
			case EAGAIN:
				throw Thread_NoResources_Exc();
			default:
				break;
		}
	}
}

template<class T, void* (T::*Run)()>
void Thread<T,Run>::Join()
{
	pthread_join(m_pthread, 0);
}






}//namespace advcpp
#endif//#ifndef __THREAD_H__

