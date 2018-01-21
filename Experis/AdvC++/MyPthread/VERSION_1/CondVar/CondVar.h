#ifndef __CONDVAR_H__
#define __CONDVAR_H__

#include <pthread.h>
#include<iostream>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Forward declarations
class Mutex;

class CondVar
{
public:
	~CondVar();
	CondVar();
	void Wait(Mutex& _mutex);
	void NotifyOne();
	void NotifyAll();
	
private:
	CondVar(const CondVar&);
	CondVar& operator=(const CondVar&);
	pthread_cond_t	m_cond_t;
};













}//namespace advcpp
#endif//#ifndef __CONDVAR_H__

