#include "FD_t.h"

namespace netcpp
{
FD_t::FD_t():m_rawFd(0)
{
	//Empty
}

FD_t::FD_t(int _rawFd):m_rawFd(_rawFd)
{
	//Empty
}

FD_t& FD_t::operator=(int _rawFd)
{
	m_rawFd = _rawFd;
	return *this;
}

bool FD_t::operator<(int _rawFd) const
{
	return m_rawFd < _rawFd;
}

bool FD_t::operator<(const FD_t& _fd) const
{
	return m_rawFd < _fd.m_rawFd;
}

bool FD_t::operator>(int _rawFd) const
{
	return m_rawFd > _rawFd;
}

bool FD_t::operator>(const FD_t& _fd) const
{
	return m_rawFd > _fd.m_rawFd;
}

bool FD_t::operator==(int _rawFd) const
{
	return m_rawFd == _rawFd;
}

int FD_t::GetRawFd() const
{
	return m_rawFd;
}
}//namespace netcpp

