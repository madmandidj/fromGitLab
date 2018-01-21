#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
namespace advcpp
{
////////////////////////////////////////////////////////////////////////
////Forward declarations

////////////////////////////////////////////////////////////////////////
////Thread class
template<class FUNC, class ARG>
class Thread
{
public:
	~Thread();
	Thread(FUNC _func, ARG& _arg);
	void Run();
	void Join();
private:
	Thread(const Thread&);
	Thread& operator=(const Thread&);
	pthread_t	m_pthread;
	FUNC		m_func;
	ARG			m_arg;
};
////////////////////////////////////////////////////////////////////////
////Thread public function implementations
template<class FUNC, class ARG>
Thread<FUNC,ARG>::~Thread()
{
	//Empty
}

template<class FUNC, class ARG>
Thread<FUNC,ARG>::Thread(FUNC _func, ARG& _arg):m_func(_func), m_arg(_arg)
{
	//TODO: Check NULL ??
}

template<class FUNC, class ARG>
void Thread<FUNC,ARG>::Run()
{
	pthread_create(&m_pthread, 0, m_func, &m_arg);	
}

template<class FUNC, class ARG>
void Thread<FUNC,ARG>::Join()
{
	pthread_join(m_pthread, 0);	
}






}//namespace advcpp
#endif//#ifndef __THREAD_H__

