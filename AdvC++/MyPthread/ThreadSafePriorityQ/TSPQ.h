#ifndef __TSPQ_h__
#define __TSPQ_H__

#include "../SyncExceptions/SyncExceptions.h"
#include "../Mutex/Mutex.h"
#include "../Guard/Guard.h"
#include <boost/core/noncopyable.hpp>
#include<queue>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////
//////Thread-safe priority queue class
//template<class TYPE, class COMPARE>
//class TSPQ : private boost::noncopyable
//{
//public:
//	~TSPQ();
//	explicit TSPQ();
//	void Push(TYPE _element);
//	TYPE Top() const;
//	void Pop();
//	bool IsEmpty() const;
//private:
//	std::priority_queue<TYPE, std::vector<TYPE>, COMPARE> m_tspq;
//	mutable Mutex m_mutex;
//};
//////////////////////////////////////////////////////////////////////////
//////Thread-safe priority queue implementation
//template<class TYPE, class COMPARE>
//TSPQ<TYPE,COMPARE>::~TSPQ()
//{
// 	//Empty
//}

//template<class TYPE, class COMPARE>
//TSPQ<TYPE,COMPARE>::TSPQ()
//{
//	//Empty
//}

//template<class TYPE, class COMPARE>
//void TSPQ<TYPE,COMPARE>::Push(TYPE _element)
//{
//	Guard guard(m_mutex);
//	m_tspq.push(_element);
//}

//template<class TYPE, class COMPARE>
//TYPE TSPQ<TYPE,COMPARE>::Top() const
//{
//	Guard guard(m_mutex);
//	return m_tspq.top();
//}

//template<class TYPE, class COMPARE>
//void TSPQ<TYPE,COMPARE>::Pop()
//{
//	Guard guard(m_mutex);
//	m_tspq.pop();
//	return;
//}

//template<class TYPE, class COMPARE>
//bool TSPQ<TYPE,COMPARE>::IsEmpty() const
//{
//	Guard guard(m_mutex);
//	return m_tspq.empty();
//}

////////////////////////////////////////////////////////////////////////
////Thread-safe priority queue class
template<class TYPE>
class TSPQ : private boost::noncopyable
{
public:
	~TSPQ();
	explicit TSPQ();
	void Push(TYPE _element);
	TYPE Top() const;
	void Pop();
	bool IsEmpty() const;
private:
	std::priority_queue<TYPE> m_tspq;
	static Mutex m_mutex;
};
////////////////////////////////////////////////////////////////////////
////Thread-safe priority queue static member init
template<class TYPE>
Mutex TSPQ<TYPE>::m_mutex;

////////////////////////////////////////////////////////////////////////
////Thread-safe priority queue implementation
template<class TYPE>
TSPQ<TYPE>::~TSPQ()
{
 	//Empty
}

template<class TYPE>
TSPQ<TYPE>::TSPQ()
{
	//Empty
}

template<class TYPE>
void TSPQ<TYPE>::Push(TYPE _element)
{
	Guard guard(m_mutex);
	m_tspq.push(_element);
}

template<class TYPE>
TYPE TSPQ<TYPE>::Top() const
{
	Guard guard(m_mutex);
	return m_tspq.top();
}

template<class TYPE>
void TSPQ<TYPE>::Pop()
{
	Guard guard(m_mutex);
	m_tspq.pop();
	return;
}

template<class TYPE>
bool TSPQ<TYPE>::IsEmpty() const
{
	Guard guard(m_mutex);
	return m_tspq.empty();
}

}//namespace advcpp
#endif//#ifndef __TSPQ_h__

