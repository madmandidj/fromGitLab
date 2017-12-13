#include "FD_t.h"

namespace netcpp
{

FD_t& FD_t::operator=(int _rawFd)
{
	m_rawFd = _rawFd;
	return *this;
}

bool FD_t::operator<(int _rawFd) const
{
	return m_rawFd < _rawFd;
}

bool FD_t::operator>(int _rawFd) const
{
	return m_rawFd > _rawFd;
}

bool FD_t::operator==(int _rawFd) const
{
	return m_rawFd == _rawFd;
}

int FD_t::GetRawFD() const
{
	return m_rawFd;
}

}//namespace netcpp
