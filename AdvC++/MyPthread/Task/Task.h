#ifndef __TASK_H__
#define __TASK_H__

namespace advcpp
{

template<class T>
////////////////////////////////////////////////////////////////////////
////Task class
class Task
{
public:
	~Task();
	explicit Task(T* _object); //TODO: Ask is there any meaning for explicit here?
	bool operator<(const Task* _otherTask) const;
private:
	T*	m_object; //TODO: how to store tasks of different types in the tspq?? boost::variant ?? boost::any??
};














}//namespace advcpp
#endif//#ifndef __TASK_H__

