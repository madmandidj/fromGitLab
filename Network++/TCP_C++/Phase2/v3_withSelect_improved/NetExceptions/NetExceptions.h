#ifndef __NETCPP_EXCEPTIONS_H__
#define __NETCPP_EXCEPTIONS_H__

#include<exception>
#include<string>
#include<sstream>

namespace netcpp
{
#if (defined (__linux__))
#	define ENVIRONMENT_NOEXC _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
#	define ENVIRONMENT_NOEXC _NOEXCEPT
#endif

class NetCppExc : public std::exception
{
public:
	NetCppExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	{
		std::string lineNumStr;
		std::ostringstream convert;
		convert << _lineNum;
		lineNumStr = convert.str();
		m_whatStr = "***NETEXCEPTION: File: " ;
		m_whatStr += _fileName;
		m_whatStr += " Line: ";
		m_whatStr += lineNumStr;
		m_whatStr += ", ";
		m_whatStr += _userStr;
	}
	virtual ~NetCppExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC
	{
		return m_whatStr.c_str();
	}
protected:
	std::string m_whatStr;
};
//Client Exceptions

//Server Exceptions

//General Exceptions

class EagainExc : NetCppExc
{
public:
	EagainExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~EagainExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetCppExc::what();}
};

class SocketCloseByPeerExc : NetCppExc
{
public:
	SocketCloseByPeerExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~SocketCloseByPeerExc() ENVIRONMENT_NOEXC{}
};

class SelectFailedExc : NetCppExc
{
public:
	SelectFailedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~SelectFailedExc() ENVIRONMENT_NOEXC{}
};


class SocketIsConnectedExc : NetCppExc
{
public:
	SocketIsConnectedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~SocketIsConnectedExc() ENVIRONMENT_NOEXC{}
};

class SocketIsDisconnectedExc : NetCppExc
{
public:
	SocketIsDisconnectedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~SocketIsDisconnectedExc() ENVIRONMENT_NOEXC{}
};

class SocketFailedExc : NetCppExc
{
public:
	SocketFailedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~SocketFailedExc() ENVIRONMENT_NOEXC{}
};

class ConnectFailedExc : NetCppExc
{
public:
	ConnectFailedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~ConnectFailedExc() ENVIRONMENT_NOEXC{}
};

class UnspecifiedErrnoExc : NetCppExc
{
public:
	UnspecifiedErrnoExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetCppExc(_fileName, _lineNum, _userStr){}
	virtual ~UnspecifiedErrnoExc() ENVIRONMENT_NOEXC{}
};

}//namespace netcpp
#endif//#ifndef __NETCPP_EXCEPTIONS_H__

