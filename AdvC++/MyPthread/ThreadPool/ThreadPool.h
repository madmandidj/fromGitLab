#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "../SyncExceptions/SyncExceptions.h"
#include "../Thread/Thread.h"
#include "../ThreadSafePriorityQ/TSPQ.h"
#include <boost/core/noncopyable.hpp>
namespace advcpp
{

class Task;
class Runnable;

class ThreadPool : private boost::noncopyable 
{
public:
	~ThreadPool();
	explicit ThreadPool(size_t _numOfThreads);
	Add(Task* _task, int _priority);
	Shutdown();
private:
	static bool 									m_shouldShutdown;
	advcpp::TSPQ<Task>								m_tspq;
	std::vector< Thread<Runnable, &Runnable::Run> > m_threadContainer;
};














}//namespace advcpp
#endif//#ifndef __THREADPOOL_H__

