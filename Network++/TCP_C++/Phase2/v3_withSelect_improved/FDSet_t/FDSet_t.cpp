#include "FDSet_t.h"
#include "../NetExceptions/NetExceptions.h"
#include<stdexcept>

namespace netcpp
{
size_t FDSet_t::m_maxNumOfFd = 1000;

FDSet_t::FDSet_t():m_maxFdVal(0), m_numOfFd(0)
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

void FDSet_t::Add(const FD_t& _fd)
{
	if(m_fdVals.size() == m_maxNumOfFd)
	{
		throw std::runtime_error("FDSet_t Add() full capacity for Fd");
	}
	FD_SET(_fd.m_rawFd, &m_fdSet);
	if (_fd.m_rawFd > m_maxFdVal)
	{
		m_maxFdVal = _fd.m_rawFd;
	}
	m_fdVals.insert(_fd);
}

void FDSet_t::Add(const std::tr1::shared_ptr<Socket_t>& _socket)
{
	if(m_fdVals.size() == m_maxNumOfFd)
	{
		throw std::runtime_error("FDSet_t Add() full capacity for Fd");
	}
	FD_SET((_socket.get())->m_fd.m_rawFd, &m_fdSet);
	if ((_socket.get())->m_fd.m_rawFd > m_maxFdVal)
	{
		m_maxFdVal = (_socket.get())->m_fd.m_rawFd;
	}
	m_fdVals.insert((_socket.get())->m_fd);
}

//void FDSet_t::Remove(const FD_t& _fd)
//{
//	if(m_fdVals.size() == 0)
//	{
//		throw std::runtime_error("FDSet_t Remove() No fd in set");
//	}
//	FD_CLR(_fd.m_rawFd, &m_fdSet);
//	if (_fd.m_rawFd == m_maxFdVal)
//	{
//		SetNewMaxFdVal(_fd);
//	}
//}

void FDSet_t::Remove(const std::tr1::shared_ptr<Socket_t>& _socket)
{
	if(m_fdVals.size() == 0)
	{
		throw std::runtime_error("FDSet_t Remove() No fd in set");
	}
	FD_CLR((_socket.get())->m_fd.m_rawFd, &m_fdSet);
	if ((_socket.get())->m_fd.m_rawFd == m_maxFdVal)
	{
		SetNewMaxFdVal((_socket.get())->m_fd);
	}
}

//bool FDSet_t::IsFdActive(const FD_t& _fd) const
//{
//	return FD_ISSET(_fd.m_rawFd, &m_workingFdSet);
//}

bool FDSet_t::IsFdActive(const std::tr1::shared_ptr<Socket_t>& _socket) const
{
	return FD_ISSET(_socket.get()->m_fd.m_rawFd, &m_workingFdSet);
}

int FDSet_t::GetActivity() const
{
	m_workingFdSet = m_fdSet;
	int activity = select(m_maxFdVal + 1, &m_workingFdSet, NULL, NULL, NULL);
	if (activity == -1)
	{
//		throw std::runtime_error("FDSet_t GetActivity() select returned -1");
		throw SelectFailedExc(__FILE__, __LINE__, "select() returned -1");
	}
	return activity;
} 

void FDSet_t::SetNewMaxFdVal(const FD_t& _fd)
{
	m_maxFdVal = (m_fdVals.upper_bound(_fd))->m_rawFd;
}

}//namespace netcpp

