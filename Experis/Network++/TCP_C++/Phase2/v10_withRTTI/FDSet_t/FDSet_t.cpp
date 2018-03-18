#include "FDSet_t.h"
#include "../FD_t/FD_t.h"
#include "../Socket_t/Socket_t.h"
#include "../NetExceptions/NetExceptions.h"
#include <stdexcept>
#include <iostream>
#include <unistd.h>

namespace netcpp
{
//size_t FDSet_t::m_maxNumOfFd = 1000;

FDSet_t::FDSet_t():m_maxFdVal(0)
{
	Clear();
}

FDSet_t::~FDSet_t()
{
	//Empty
}

void FDSet_t::Clear()
{
	FD_ZERO(&m_fdSet);
}

bool FDSet_t::Add(const FD_t& _fd)
{
	FD_SET(_fd.m_rawFd, &m_fdSet);
	if (_fd.m_rawFd > m_maxFdVal)
	{
		m_maxFdVal = _fd.m_rawFd;
	}
	m_fdVals.insert(_fd);
	return true;
}

bool FDSet_t::Add(const SharedPtr_t& _socket)
{
	return Add(_socket.get()->m_fd);
}

bool FDSet_t::Remove(const SharedPtr_t& _socket)
{
	FD_CLR((_socket.get())->m_fd.m_rawFd, &m_fdSet);
	if ((_socket.get())->m_fd.m_rawFd == m_maxFdVal)
	{
		SetNewMaxFdVal((_socket.get())->m_fd);
	}	
	return true;
}

bool FDSet_t::IsFdActive(const SharedPtr_t& _socket) const
{
	return FD_ISSET(_socket.get()->m_fd.m_rawFd, &m_workingFdSet);
}

int FDSet_t::GetActivity() const
{
	m_workingFdSet = m_fdSet;
	int activity = select(m_maxFdVal + 1, &m_workingFdSet, NULL, NULL, NULL);
	if (activity == -1)
	{
		throw SelectFailedExc(__FILE__, __LINE__, "select() returned -1");
	}
	return activity;
} 

void FDSet_t::SetNewMaxFdVal(const FD_t& _fd)
{
	std::cout << "maxFdVal pre upper-bound " << m_maxFdVal << std::endl;
//	m_maxFdVal = (m_fdVals.upper_bound(_fd))->m_rawFd;
	m_maxFdVal = (--(m_fdVals.end()))->m_rawFd;
	std::cout << "maxFdVal post upper-bound " << m_maxFdVal << std::endl;
//	sleep(2);
}

}//namespace netcpp
