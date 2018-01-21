#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "pthread.h"
#include "../SyncExceptions/SyncExceptions.h"
#include <boost/core/noncopyable.hpp>
#include<iostream>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Forward declarations
class CondVar;
//////////////////////////////////////////////////////////////////////////////////
////Mutex class
class Mutex : private boost::noncopyable 
{
public:
	~Mutex();		
	Mutex();		//Throws: NoResources_Exc or NoMemory_Exc
	void Lock();	//Throws: NoResources_Exc	//TODO: Not Needed if not recursive mutex
	bool Trylock();	//Throws: NoResources_Exc	//TODO: Not Needed if not recursive mutex
	void Unlock();	//Throws: NoResources_Exc 	//TODO: Not Needed if not recursive mutex
	friend class advcpp::CondVar;
private:
	pthread_mutex_t	m_mutex;
};






















}//namespace advcpp
#endif//#ifndef __MUTEX_H__
