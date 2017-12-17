#ifndef __SOCKET_T_H__
#define __SOCKET_T_H__

#include "../FD_t/FD_t.h"
#include "../SockAddrIn_t/SockAddrIn_t.h"

namespace netcpp
{
class Socket_t
{
public:
	explicit Socket_t();
	virtual ~Socket_t();
	FD_t Accept();
	void Connect();
	void Close();
	int Send(void* _data, size_t _length, int _flags) const;
//	size_t Receive() const;
	ssize_t Receive() const;
	void Socket(int _family, int _type, int _protocol);
	void SetSockOpt(int _level, int _optName, int _optVal);
	void Bind();
	void Listen(size_t _backLog);
	void ThrowIfConnected(const char* _fileName, int _lineNum, const char* _userStr) const;
	void ThrowIfDisconnected(const char* _fileName, int _lineNum, const char* _userStr) const;
	void ThrowIfIsServerSocket(const char* _fileName, int _lineNum, const char* _userStr) const;
	void ThrowIfNotServerSocket(const char* _fileName, int _lineNum, const char* _userStr) const;
	friend class FDSet_t;
protected:
	FD_t 			m_fd;
	SockAddrIn_t	m_sin;
	bool			m_isConnected;
	mutable char m_buffer[256]; //This should be Msg_t
private:
	Socket_t(const Socket_t& _socket);
	Socket_t& operator=(const Socket_t& _socket);
};
}//namespace netcpp
#endif//#ifndef __SOCKET_T_H__




