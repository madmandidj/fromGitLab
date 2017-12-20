#ifndef __FDSET_T_H__
#define __FDSET_T_H__

#include "../FD_t/FD_t.h"
#include <sys/select.h>	//select()
#include <set>			//std::set

#if (defined (__linux__))
#	include<tr1/memory>	//std::tr1::shared_ptr
#	define IS_LINUX 1
#elif (defined (__APPLE__))
#	include<memory>	//std::tr1::shared_ptr
#	define IS_APPLE 1
#endif

namespace netcpp
{
//class FD_t;
class Socket_t;
#ifdef IS_LINUX
typedef std::tr1::shared_ptr<Socket_t> SharedPtr_t;
#endif
#ifdef IS_APPLE
typedef std::shared_ptr<Socket_t> SharedPtr_t;
#endif
/////////////////////////////////////////////
//////// File descriptor set class definition
/////////////////////////////////////////////
class FDSet_t
{
public:
	explicit FDSet_t();
	~FDSet_t();
	void Clear();
	bool Add(const FD_t& _fd);
	bool Add(const SharedPtr_t& _socket);
	bool Remove(const SharedPtr_t& _socket);
	bool IsFdActive(const SharedPtr_t& _socket) const;
	int GetActivity() const;
private:
	void SetNewMaxFdVal(const FD_t& _fd);
	FDSet_t& operator=(const FDSet_t& _fdSet);
private:
	fd_set m_fdSet;
	mutable fd_set m_workingFdSet;
//	int m_maxFdVal;
	FD_t m_maxFdVal;
	std::set<FD_t> m_fdVals;
};


}//namespace netcpp
#endif//#ifndef __FDSET_T_H__

