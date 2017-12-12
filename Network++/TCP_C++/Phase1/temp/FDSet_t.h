#ifndef __FDSET_T_H__
#define __FDSET_T_H__

#include "FD_t.h"

namespace netcpp
{
/////////////////////////////////////////////
//////// File descriptor set class definition
/////////////////////////////////////////////
class FDSet_t
{
public:
	explicit FDSet_t();
	FDSet_t(const FDSet_t& _fdSet);
	FDSet_t& operator=(const FDSet_t& _fdSet);
	~FDSet_t();
	bool Add(const FD_t& _fd);
	bool Remove(const FD_t& _fd);
	bool IsActive(const FD_t& _fd);
private:
	
}


}//namespace netcpp
#endif//#ifndef __FDSET_T_H__


