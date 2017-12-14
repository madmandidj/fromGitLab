#ifndef __SOCKADDR_T_H__
#define __SOCKADDR_T_H__

#include <netinet/in.h>

namespace netcpp
{
//////////////////////////////////////////
//////// Linux: sockaddr type class
//////////////////////////////////////////
class SockAddrIn_t
{
public:
    explicit SockAddrIn_t();
    explicit SockAddrIn_t(short _family, unsigned short _port, const char* _addr);
    SockAddrIn_t(const SockAddrIn_t& _sin);
    SockAddrIn_t& operator=(const SockAddrIn_t& _sin);
    ~SockAddrIn_t();
    void SetSockAddrIn(short _family, unsigned short _port, const char* _addr);
    void SetFamily(short _family);
    void SetPort(unsigned short _port);
    void SetAddr(const char* _ip); //If NULL, set to INADDR_ANY
    sockaddr_in& GetRawSin() const;
private:
    sockaddr_in m_sin;
};

inline SockAddrIn_t::SockAddrIn_t()
{
	//Empty
}

inline SockAddrIn_t::~SockAddrIn_t()
{
	//Empty
}

}
#endif//#ifndef __SOCKADDR_T_H__
