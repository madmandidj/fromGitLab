#ifndef __FD_T_H__
#define __FD_T_H__
namespace netcpp
{
//////////////////////////////////////////
//////// Linux: file descriptor type class
//////////////////////////////////////////
class FD_t
{
public:
	explicit FD_t();
	FD_t(const FD_t& _fd);
	FD_t& operator=(const FD_t& _fd);
	FD_t& operator=(int _rawFD);
	~FD_t();
private:
	int	m_nativeFd;
};













}//namespace netcpp
#endif//#ifndef __FD_T_H__

