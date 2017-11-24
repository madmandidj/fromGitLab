#ifndef __GUARD_H__
#define __GUARD_H__

namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Forward declarations
class Mutex;

class Guard
{
public:
	~Guard();
	Guard(Mutex& _mutex);
private:
	Guard(const Guard&);
	Guard& operator=(const Guard&);
	Mutex& m_mutex;
};









}//namespace advcpp
#endif//#ifndef __GUARD_H__
