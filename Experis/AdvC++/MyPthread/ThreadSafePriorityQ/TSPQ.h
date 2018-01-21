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
//	const TYPE& Pop(TYPE* _poppedObj);
	void Pop(TYPE* _poppedObj);
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
	try
	{
		m_tspq.push(_element);
	}catch(std::exception& _exc)
	{
		//DO something
	}
	
	if (1 == ++m_numOfElem)
	{
		std::cout << "Going to notify All" <<std::endl;
		m_condVar.NotifyAll();
	}	
}

template<class TYPE>
void TSPQ<TYPE>::Pop(TYPE* _poppedObj)
{
	Guard guard(m_mutex);
	while (!m_numOfElem)
	{
		std::cout << "Going to wait" <<std::endl;
		m_condVar.Wait();
		std::cout << "Woke up" <<std::endl;
//		m_mutex.Lock();
//		std::cout << "Locked Mutex" <<std::endl;
	}
	try
	{
		*_poppedObj= m_tspq.top();	
	}catch(std::exception _exc)
	{
		//DO something
	}
	try
	{
		m_tspq.pop();	
	}catch(std::exception _exc)
	{
		//DO something
	}
	--m_numOfElem;
}


}//namespace advcpp
#endif//#ifndef __TSPQ_H__

