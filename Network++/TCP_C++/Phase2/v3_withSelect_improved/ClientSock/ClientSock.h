#ifndef __CLIENTSOCK_H__
#define __CLIENTSOCK_H__

#include "../Socket_t/Socket_t.h"

namespace netcpp
{
class ClientSock : public Socket_t
{
public:
	explicit ClientSock();
	virtual ~ClientSock();
	ClientSock& operator=(const FD_t& _fd);
	void Connect(int _port, const char* _ip);
	void Disconnect();
	int Send(void* _data, size_t _length) const;
	int Receive() const;
	friend class Client;
protected:
////    Inherited:
////	FD_t 			m_fd;
////	SockAddrIn_t	m_sin;
////	bool			m_isConnected;
private:
	ClientSock(const ClientSock&);
	ClientSock& operator=(const ClientSock&);
	mutable char m_buffer[256];
};
}//namespace netcpp
#endif//#ifndef __CLIENTSOCK_H__
