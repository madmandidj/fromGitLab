#ifndef __THREADROUTINE_H__
#define __THREADROUTINE_H__

#include "../SyncExceptions/SyncExceptions.h"
#include "../Thread/Thread.h"
#include "../ThreadSafePriorityQ/TSPQ.h"
#include <boost/core/noncopyable.hpp>

namespace advcpp
{
////////////////////////////////////////////////////////////////////////
////ThreadRoutine class
class ThreadRoutine : private boost::noncopyable 
{
public:
	explicit ThreadRoutine(advcpp::TSPQ<Task>& _tspqRef);
	~ThreadRoutine();
	void* Run();
private:
	static bool m_shouldShutdown;
	advcpp::TSPQ<Task>&	m_tspqRef;
};









}//namespace advcpp
#endif//#ifndef __THREADROUTINE_H__

