#include "Guard.h"
#include "../Mutex/Mutex.h"
namespace advcpp
{

Guard::~Guard()
{
	m_mutex.Unlock();
}

Guard::Guard(Mutex& _mutex):m_mutex(_mutex)
{
	m_mutex.Lock();
}

}//namespace advcpp


