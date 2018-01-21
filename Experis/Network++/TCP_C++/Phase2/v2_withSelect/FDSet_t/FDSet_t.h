#ifndef __FDSET_T_H__
#define __FDSET_T_H__

#include "../FD_t/FD_t.h"
#include "../Socket_t/Socket_t.h"
#include<stddef.h>
#include <sys/select.h>
#include<set>
#include<tr1/memory>

namespace netcpp
{
/////////////////////////////////////////////
//////// File descriptor set class definition
/////////////////////////////////////////////
class FDSet_t
{
public:
	explicit FDSet_t();
/*	FDSet_t(const FDSet_t& _fdSet);*/
	FDSet_t& operator=(const FDSet_t& _fdSet);
	~FDSet_t();
	void Clear();
	void Add(const FD_t& _fd);
	void Add(const std::tr1::shared_ptr<Socket_t>& _socket);
	void Remove(const FD_t& _fd);
	void Remove(const std::tr1::shared_ptr<Socket_t>& _socket);
	bool IsFdActive(const FD_t& _fd) const;
	bool IsFdActive(const std::tr1::shared_ptr<Socket_t>& _socket) const;
	int GetActivity() const;
/*	friend class Socket_t;*/
private:
	void SetNewMaxFdVal(const FD_t& _fd);
private:
	fd_set m_fdSet;
	mutable fd_set m_workingFdSet;
	int m_maxFdVal;
	size_t m_numOfFd;
	static size_t m_maxNumOfFd;
	std::set<FD_t> m_fdVals;
};


}//namespace netcpp
#endif//#ifndef __FDSET_T_H__


