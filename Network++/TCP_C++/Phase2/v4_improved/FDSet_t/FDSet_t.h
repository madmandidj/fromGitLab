#ifndef __FDSET_T_H__
#define __FDSET_T_H__

#include<sys/select.h>	//select()
#include<set>			//std::set
/*#include<tr1/memory>	//std::tr1::shared_ptr*/

#if (defined (__linux__))
#	include<tr1/memory>	//std::tr1::shared_ptr
#	define IS_LINUX 1
#elif (defined (__APPLE__))
#	include<memory>	//std::tr1::shared_ptr
#	define IS_APPLE 1
#endif

namespace netcpp
{
class FD_t;
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
	FDSet_t& operator=(const FDSet_t& _fdSet);
	~FDSet_t();
	void Clear();
	void Add(const FD_t& _fd);
	void Add(const SharedPtr_t& _socket);
	void Remove(const SharedPtr_t& _socket);
	bool IsFdActive(const SharedPtr_t& _socket) const;
	int GetActivity() const;
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


