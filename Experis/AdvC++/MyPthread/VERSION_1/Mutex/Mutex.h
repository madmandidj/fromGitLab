#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "pthread.h"
#include <boost/core/noncopyable.hpp>
#include<iostream>
namespace advcpp
{
class CondVar;
//////////////////////////////////////////////////////////////////////////////////
////Mutex class
class Mutex
{
public:
	~Mutex();		//Mutex is unlocked (if needed), then destroyed
	Mutex();
	bool Lock();	//Will block upon success
	bool Trylock();	//Will block upon success
	bool Unlock();	
	friend class advcpp::CondVar;
private:
	Mutex(const Mutex&);
	Mutex& operator=(const Mutex&);
	pthread_mutex_t	m_mutex;
};






















}//namespace advcpp
#endif//#ifndef __MUTEX_H__
