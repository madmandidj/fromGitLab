#ifndef __SYNC_EXCEPTIONS_H__
#define __SYNC_EXCEPTIONS_H__

#include<exception>
namespace advcpp
{

class NoResources_Exc : public std::exception
{
public:
	const char* what() const _NOEXCEPT;
};

class NoMemory_Exc : public std::exception
{
public:
	const char* what() const _NOEXCEPT;
};






}//namespace advcpp
#endif//#ifndef __SYNC_EXCEPTIONS_H__
