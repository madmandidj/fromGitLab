#ifndef __SOCKADDR_T_H__
#define __SOCKADDR_T_H__
namespace netcpp
{
//////////////////////////////////////////
//////// Linux: sockaddr type class
//////////////////////////////////////////
class SockAddr_t
{
public:
    explicit SockAddr_t();
    explicit SockAddr_t(short _family, unsigned short _port, const char* _port);
    SockAddr_t(const SockAddr_t& _sin);
    SockAddr_t& operator=(const SockAddr_t& _sin);
    ~SockAddr_t();
    SetSockAddr(short _family, unsigned short _port, const char* _port);
    SetFamily(short _family);
    SetPort(unsigned short _port);
    SetAddr(const char* _ip); //If NULL, set to INADDR_ANY
private:
    sockaddr_in m_sin;
};



}
#endif//#ifndef __SOCKADDR_T_H__
