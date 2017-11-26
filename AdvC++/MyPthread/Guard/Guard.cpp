#include "Guard.h"
#include "../Mutex/Mutex.h"
#include<exception>
#include<cstdio>
namespace advcpp
{

Guard::~Guard()
{
	try
	{	
		m_mutex.Unlock();
	}catch(std::exception& _exc)
	{
		std::perror("~Guard() caught exception, program terminated");
		std::abort();
	}
}

Guard::Guard(Mutex& _mutex):m_mutex(_mutex)
{
	try
	{	
		m_mutex.Lock();
	}catch(std::exception& _exc)
	{
		std::perror("Guard() caught exception, program terminated");
		std::abort();
	}
}

}//namespace advcpp


