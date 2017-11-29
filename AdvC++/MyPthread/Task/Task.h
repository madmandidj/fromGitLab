#ifndef __TASK_H__
#define __TASK_H__

namespace advcpp
{

////////////////////////////////////////////////////////////////////////
////Task class
//template<class T>
class Task
{
public:
	virtual ~Task() = 0;
	explicit Task(T* _object); //TODO: Ask is there any meaning for explicit here?
	bool operator<(const Task* _otherTask) const;
private:
	T*	m_object; //TODO: how to store tasks of different types in the tspq?? boost::variant ?? boost::any??
};














}//namespace advcpp
#endif//#ifndef __TASK_H__

