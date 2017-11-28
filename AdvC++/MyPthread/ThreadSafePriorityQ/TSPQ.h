#ifndef __TSPQ_H__
#define __TSPQ_H__

#include "../SyncExceptions/SyncExceptions.h"
#include "../Mutex/Mutex.h"
#include "../Guard/Guard.h"
#include "../CondVar/CondVar.h"
#include <boost/core/noncopyable.hpp>
#include<queue>
namespace advcpp
{
////////////////////////////////////////////////////////////////////////
////Thread-safe priority queue class
template<class TYPE>
class TSPQ : private boost::noncopyable
{
public:
	~TSPQ();
	explicit TSPQ();
	void Push(TYPE& _element);
	const TYPE& Pop();
private:
	std::priority_queue<TYPE> m_tspq;
	mutable Mutex 	m_mutex;
	mutable CondVar	m_condVar;
	size_t			m_numOfElem; 
};
////////////////////////////////////////////////////////////////////////
////Thread-safe priority queue implementation
template<class TYPE>
TSPQ<TYPE>::~TSPQ()
{
 	//Empty
}

template<class TYPE>
TSPQ<TYPE>::TSPQ():m_condVar(m_mutex), m_numOfElem(0)
{
	//Empty
}

template<class TYPE>
void TSPQ<TYPE>::Push(TYPE& _element)
{
	Guard guard(m_mutex);
	m_tspq.push(_element);
	if (1 == ++m_numOfElem)
	{
		m_condVar.NotifyAll();
	}
	
}

template<class TYPE>
const TYPE& TSPQ<TYPE>::Pop()
{
	Guard guard(m_mutex);
	while (!m_numOfElem)
	{
		m_condVar.Wait();
		m_mutex.Lock();
	}
	const TYPE& objRef = m_tspq.top();
	m_tspq.pop();
	return objRef;
}


}//namespace advcpp
#endif//#ifndef __TSPQ_H__

