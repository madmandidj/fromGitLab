#ifndef __NETCPP_EXCEPTIONS_H__
#define __NETCPP_EXCEPTIONS_H__

#include<exception>

namespace netcpp
{
#if (defined (__linux__))
#	define ENVIRONMENT_NOEXC _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
#	define ENVIRONMENT_NOEXC _NOEXCEPT
#endif

class NetCppExc : public std::exception{};

class EAGAIN_exc : NetCppExc
{
public:
	const char* what() const ENVIRONMENT_NOEXC
	{
		return "EAGAIN or EWOULDBLOCK";
	}
};

class ReceivedZeroBytes_exc : NetCppExc
{
public:
	const char* what() const ENVIRONMENT_NOEXC
	{
		return "read returned 0";
	}
};





}//namespace netcpp
#endif//#ifndef __NETCPP_EXCEPTIONS_H__

