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
//	TYPE Top() const;
//	void Pop();
//	bool IsEmpty() const;
	TYPE& Pop();
private:
	std::priority_queue<TYPE> m_tspq;
//	static Mutex m_mutex;
	mutable Mutex 	m_mutex;
	mutable CondVar	m_condVar; 
};
////////////////////////////////////////////////////////////////////////
////Thread-safe priority queue implementation
template<class TYPE>
TSPQ<TYPE>::~TSPQ()
{
 	//Empty
}

template<class TYPE>
TSPQ<TYPE>::TSPQ():m_condVar(m_mutex)
{
	//Empty
}

template<class TYPE>
void TSPQ<TYPE>::Push(TYPE& _element)
{
	Guard guard(m_mutex);
	m_tspq.push(_element);
}

template<class TYPE>
TYPE& TSPQ<TYPE>::Pop()
{
	Guard guard(m_mutex);
	
	m_tspq.pop();
	return;
}


//template<class TYPE>
//TYPE TSPQ<TYPE>::Top() const
//{
//	Guard guard(m_mutex);
//	return m_tspq.top();
//}

//template<class TYPE>
//void TSPQ<TYPE>::Pop()
//{
//	Guard guard(m_mutex);
//	m_tspq.pop();
//	return;
//}

//template<class TYPE>
//bool TSPQ<TYPE>::IsEmpty() const
//{
//	Guard guard(m_mutex);
//	return m_tspq.empty();
//}

}//namespace advcpp
#endif//#ifndef __TSPQ_H__

