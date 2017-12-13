#ifndef __CLIENTCPP_H__
#define __CLIENTCPP_H__
#include "ClientSock.h"
namespace netcpp
{
class Client
{
public:
	explicit Client();
	~Client();
	int Connect(int _port, const char* _ip);
	int Disconnect();
	void Run();
	
protected:

private:
	int Send(void* _data, size_t _length) const;
	int Receive() const;
	Client(const Client&);
	ClientSock m_clientSock;
};




}//namespace netcpp
#endif//#ifndef __CLIENTCPP_H__

