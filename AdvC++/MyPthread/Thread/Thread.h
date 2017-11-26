#ifndef __THREAD_H__
#define __THREAD_H__

#include "../SyncExceptions/SyncExceptions.h"
#include <boost/core/noncopyable.hpp>
#include <pthread.h>
namespace advcpp
{
////////////////////////////////////////////////////////////////////////
////Thread class
//template<class FUNC, class ARG>
//class Thread
//{
//public:
//	~Thread();
//	Thread(FUNC _func, ARG& _arg);
//	void Run();
//	void Join();
//private:
//	Thread(const Thread&);
//	Thread& operator=(const Thread&);
//	pthread_t	m_pthread;
//	FUNC		m_func;
//	ARG			m_arg;
//};


template<class T, void* (T::*Run)()>
class Thread  : private boost::noncopyable
{
public:
	explicit Thread(T* _objectPtr);
//	void Run();
	void Join();
private:
	static void* Trampoline(void* _objectPtr);
	pthread_t m_pthread;
};
////////////////////////////////////////////////////////////////////////
////Thread public function implementations
template<class T, void* (T::*Run)()>
Thread<T,Run>::Thread(T* _this)
{
	pthread_create(&m_pthread, 0, Trampoline, _this);
}

template<class T, void* (T::*Run)()>
void* Thread<T,Run>::Trampoline(void* _objectPtr)
{
	return (static_cast<T*>(_objectPtr)->*Run)();
}

template<class T, void* (T::*Run)()>
void Thread<T,Run>::Join()
{
	pthread_join(m_pthread, 0);
}













//template<class FUNC, class ARG>
//Thread<FUNC,ARG>::~Thread()
//{
//	//Empty
//}

//template<class FUNC, class ARG>
//Thread<FUNC,ARG>::Thread(FUNC _func, ARG& _arg):m_func(_func), m_arg(_arg)
//{
//	//TODO: Check NULL ??
//}

//template<class FUNC, class ARG>
//void Thread<FUNC,ARG>::Run()
//{
//	pthread_create(&m_pthread, 0, m_func, &m_arg);	
//}

//template<class FUNC, class ARG>
//void Thread<FUNC,ARG>::Join()
//{
//	pthread_join(m_pthread, 0);	
//}















}//namespace advcpp
#endif//#ifndef __THREAD_H__

