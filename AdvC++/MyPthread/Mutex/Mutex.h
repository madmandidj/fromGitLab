#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "pthread.h"
#include<iostream>
namespace advcpp
{

class CondVar;
//////////////////////////////////////////////////////////////////////////////////
////Mutex class
class Mutex
{
public:
	~Mutex();
	Mutex();
	void Lock();	//TODO:Change return type if errors required
	void Unlock();	//TODO:Change return type if errors required
	void Trylock();	//TODO:Change return type if errors required
	friend class advcpp::CondVar;
private:
	Mutex(const Mutex&);
	Mutex& operator=(const Mutex&);
	pthread_mutex_t	m_mutex;
//	const unsigned int m_numOfReps; //Num of times to repeat try unlock upon destroy if resource is busy
//	const unsigned int m_repPeriod; //Period in microseconds of try unlock cycles
};






















}//namespace advcpp
#endif//#ifndef __MUTEX_H__
