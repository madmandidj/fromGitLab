#ifndef __FD_T_H__
#define __FD_T_H__

namespace netcpp
{
class FD_t
{
public:
	FD_t();
	FD_t(int _rawFd);
	FD_t& operator=(int _rawFd);
	bool operator<(int _rawFd) const;
	bool operator<(const FD_t& _fd) const;
	bool operator>(int _rawFd) const;
	bool operator>(const FD_t& _fd) const;
	bool operator==(int _rawFd) const;
	friend class FDSet_t;
	friend class Socket_t;
	friend class ServerSock;//TODO: remove when redundant
	friend class CommSock;//TODO: remove when redundant
	friend class ClientSock;//TODO: remove when redundant
	int GetRawFd() const;
private:
	int	m_rawFd;
};
}//namespace netcpp
#endif//#ifndef __FD_T_H__

