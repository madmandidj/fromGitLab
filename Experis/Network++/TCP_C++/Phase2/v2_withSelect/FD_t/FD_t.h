#ifndef __FD_T_H__
#define __FD_T_H__
namespace netcpp
{
//////////////////////////////////////////
//////// File descriptor class definition
//////////////////////////////////////////
class FD_t
{
public:
/*	FD_t& operator=(const FD_t& _fd);*/
	FD_t();
	FD_t(int _rawFd);
	FD_t& operator=(int _rawFd);
	bool operator<(int _rawFd) const;
	bool operator<(const FD_t& _fd) const;
	bool operator>(int _rawFd) const;
	bool operator==(int _rawFd) const;
	int GetRawFD() const;
	friend class FDSet_t;
private:
	int	m_rawFd;
};


}//namespace netcpp
#endif//#ifndef __FD_T_H__

