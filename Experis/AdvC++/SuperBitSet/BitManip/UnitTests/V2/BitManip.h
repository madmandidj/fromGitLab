#ifndef __BITMANIP_H__
#define __BITMANIP_H__

#include <stddef.h>
#include<iostream>
#include<climits>
namespace advcpp
{

///////////////////////////////////////////////////////////////////////////////
//CLASS DEFINTION
template<class T>
class BitManip
{
public:
	inline ~BitManip();
	inline explicit BitManip();
//	inline explicit BitManip(T* _bitsPtr); //Throws
	inline explicit BitManip(T& _bitsPtr); //Throws
	inline void 
	inline void Set(size_t _index);
	inline void Clear(size_t _index);
	inline bool Get(size_t _index); //TODO: change to const and make relevant data members mutable
protected:

private:
//	BitManip();
	BitManip(const BitManip& _bmnp);
	BitManip& operator=(const BitManip& _bmnp);
//	T* 				m_bitsPtr;
	T				m_bitsPtr;
	size_t 			m_numOfBits;
	T				m_mask;
	static const T 	m_mask_all_1;
};

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template <typename T> 
const T BitManip<T>::m_mask_all_1(-1);
template<class T>
std::ostream& operator<<(std::ostream& _os, const BitManip<T>& _bitManip);
template<class T>
std::ostream& operator<<(std::ostream& _os, BitManip<T>& _bitManip);

///////////////////////////////////////////////////////////////////////////////
//AUX FUNCTION DEFINITIONS
template<class T>
std::ostream& operator<<(std::ostream& _os, const BitManip<T>& _bitManip)
{
	std::cout << "|";
	for (size_t index = sizeof(T) * CHAR_BIT; index > 0 ; --index)
	{
		_os << (_bitManip.Get(index - 1));
	}
	std::cout << "|";
	return _os;
}

template<class T>
std::ostream& operator<<(std::ostream& _os, BitManip<T>& _bitManip)
{
	std::cout << "|";
	for (size_t index = sizeof(T) * CHAR_BIT; index > 0 ; --index)
	{
		_os << (_bitManip.Get(index - 1));
	}
	std::cout << "|";
	return _os;
}

///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<class T>
inline BitManip<T>::~BitManip()
{
	//Empty
}

template<class T>
inline BitManip<T>::BitManip() : m_bitsPtr(0), m_numOfBits(sizeof(T) * CHAR_BIT), m_mask(0)
{
	//Empty
}

template<class T>
inline BitManip<T>::BitManip(T& _bitsPtr) : m_bitsPtr(_bitsPtr), m_numOfBits(sizeof(T) * CHAR_BIT), m_mask(0)
{
	//Empty
}

template<class T>
inline void BitManip<T>::Set(size_t _index)
{
	if (_index >= m_numOfBits)
	{
		throw std::runtime_error("void BitManip<T>::Set(size_t _index), invalid index");
	} 

	m_mask = 1;
	
	for (size_t index = 0; index < _index; ++index)
	{
		m_mask = m_mask << 1;
	}

	m_bitsPtr = m_bitsPtr | m_mask; 
	
	return;
}

template<class T>
inline void BitManip<T>::Clear(size_t _index)
{
	if (_index >= m_numOfBits)
	{
		throw std::runtime_error("void BitManip<T>::Clear(size_t _index), invalid index");
	} 

	m_mask = 1;
	
	for (size_t index = 0; index < _index; ++index)
	{
		m_mask = m_mask << 1;
	}
	T bitMask3 = m_mask ^ m_mask_all_1;

	m_bitsPtr = m_bitsPtr & bitMask3; 
	
	return;
}

template<class T>
inline bool BitManip<T>::Get(size_t _index)
{
	if (_index >= m_numOfBits)
	{
		throw std::runtime_error("void BitManip<T>::Get(size_t _index), invalid index");
	} 
	
	m_mask = 1;
	
	for (size_t index = 0; index < _index; ++index)
	{
		m_mask = m_mask << 1;
	}

	return m_bitsPtr & m_mask;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
}//namespace advcpp
#endif //#ifndef __BITMANIP_H__



