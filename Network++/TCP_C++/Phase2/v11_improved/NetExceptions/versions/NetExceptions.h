#ifndef __NETCPP_EXCEPTIONS_H__
#define __NETCPP_EXCEPTIONS_H__

#include<exception>
#include<string>
#include<sstream>

namespace netcpp
{
#if (defined (__linux__))
#	define ENVIRONMENT_NOEXC _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
#	define ENVIRONMENT_NOEXC _NOEXCEPT
#endif

class NetException : public std::exception
{
public:
	NetException(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
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
	virtual ~NetException() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC
	{
		return m_whatStr.c_str();
	}
protected:
	std::string m_whatStr;
};

class EagainExc : public NetException
{
public:
	EagainExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~EagainExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

class SocketCloseByPeerExc : public NetException
{
public:
	SocketCloseByPeerExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~SocketCloseByPeerExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

class SelectFailedExc : public NetException
{
public:
	SelectFailedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~SelectFailedExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};


class SocketIsConnectedExc : public NetException
{
public:
	SocketIsConnectedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~SocketIsConnectedExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

class SocketIsDisconnectedExc : public NetException
{
public:
	SocketIsDisconnectedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~SocketIsDisconnectedExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

class SocketFailedExc : public NetException
{
public:
	SocketFailedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~SocketFailedExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

class ConnectFailedExc : public NetException
{
public:
	ConnectFailedExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~ConnectFailedExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

class UnspecifiedErrnoExc : public NetException
{
public:
	UnspecifiedErrnoExc(const char* _fileName, int _lineNum, std::string _userStr) ENVIRONMENT_NOEXC
	:NetException(_fileName, _lineNum, _userStr){}
	virtual ~UnspecifiedErrnoExc() ENVIRONMENT_NOEXC{}
	virtual const char* what() const ENVIRONMENT_NOEXC {return NetException::what();}
};

}//namespace netcpp
#endif//#ifndef __NETCPP_EXCEPTIONS_H__

