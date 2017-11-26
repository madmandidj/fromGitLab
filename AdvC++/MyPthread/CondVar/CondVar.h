#ifndef __CONDVAR_H__
#define __CONDVAR_H__

#include <boost/core/noncopyable.hpp>
#include <pthread.h>
#include<iostream>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Forward declarations
class Mutex;
//////////////////////////////////////////////////////////////////////////////////
////CondVar class
class CondVar : private boost::noncopyable 
{
public:
	~CondVar();
	explicit CondVar(Mutex& _mutex); //Throws: NoResources_Exc or NoMemory_Exc
	void Wait();
	void NotifyOne();
	void NotifyAll();
	
private:
	CondVar(const CondVar&);
	CondVar& operator=(const CondVar&);
	pthread_cond_t	m_condVar;
	Mutex&			m_mutex;
};













}//namespace advcpp
#endif//#ifndef __CONDVAR_H__

