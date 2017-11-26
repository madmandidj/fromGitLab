#ifndef __GUARD_H__
#define __GUARD_H__

#include <boost/core/noncopyable.hpp>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////
////Forward declarations
class Mutex;

class Guard : private boost::noncopyable
{
public:
	~Guard();				//If fails, calls abort() -- Refer to Mutex
	Guard(Mutex& _mutex);	//If fails, calls abort() -- Refer to Mutex
private:
	Mutex& m_mutex;
};









}//namespace advcpp
#endif//#ifndef __GUARD_H__
