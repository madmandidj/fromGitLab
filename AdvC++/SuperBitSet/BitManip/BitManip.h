#ifndef __BITMANIP_H__
#define __BITMANIP_H__

#include <stddef.h>
#include<iostream>
#include<climits>
namespace advcpp
{

template<class T>
class BitManip
{
public:
	~BitManip();
	BitManip(T* _bitsPtr); //Throws
	void Set(size_t _index);
	void Clear(size_t _index);
	bool Get(size_t _index);
protected:

private:
	T* 				m_bitsPtr;
	size_t 			m_numOfBits;
//	const T m_mask_all_1;
	T				m_mask;
	static const T 	m_mask_all_1;
};

template <typename T> const T BitManip<T>::m_mask_all_1(-1);

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

template<class T>
BitManip<T>::~BitManip()
{
	//Empty
}

template<class T>
BitManip<T>::BitManip(T* _bitsPtr) : m_bitsPtr(_bitsPtr), m_numOfBits(sizeof(T) * CHAR_BIT)
{
	if (0 == _bitsPtr)
	{
		throw std::runtime_error("BitManip<T>::BitManip(T* _bitsPtr), invalid parameter");
	}
}

template<class T>
void BitManip<T>::Set(size_t _index)
{
	if (_index >= m_numOfBits)
	{
		throw std::runtime_error("void BitManip<T>::Set(size_t _index), invalid index");
	} 
	
//	T bitMask = 1;
//	size_t index =0;
//	for (size_t index = 0; index < _index; ++index)
//	{
//		bitMask = bitMask << 1;
//	}
//	*m_bitsPtr = *m_bitsPtr | bitMask; 
	m_mask = 1;
	
	for (size_t index = 0; index < _index; ++index)
	{
		m_mask = m_mask << 1;
	}
	
	*m_bitsPtr = *m_bitsPtr | m_mask; 
	
	return;
}

template<class T>
void BitManip<T>::Clear(size_t _index)
{
	if (_index >= m_numOfBits)
	{
		throw std::runtime_error("void BitManip<T>::Set(size_t _index), invalid index");
	} 
	
//	T bitMask1 = 1;
//	size_t index = 0;
//	for (size_t index = 0; index < _index; ++index)
//	{
//		bitMask1 = bitMask1 << 1;
//	}
//	T bitMask3 = bitMask1 ^ m_mask_all_1;
//	*m_bitsPtr = *m_bitsPtr & bitMask3; 
//	return;
	
	m_mask = 1;
	
	for (size_t index = 0; index < _index; ++index)
	{
		m_mask = m_mask << 1;
	}
	T bitMask3 = m_mask ^ m_mask_all_1;
	
	*m_bitsPtr = *m_bitsPtr & bitMask3; 
	
	return;
	
	// 0101
	// 1111 ^
	// 0100 
	// 1011
	// 
}

template<class T>
bool BitManip<T>::Get(size_t _index)
{
//	T bitMask = 1;
//	size_t index =0;
//	for (size_t index = 0; index < _index; ++index)
//	{
//		bitMask = bitMask << 1;
//	}
//	return *m_bitsPtr & bitMask;

	m_mask = 1;
	
	for (size_t index = 0; index < _index; ++index)
	{
		m_mask = m_mask << 1;
	}
	return *m_bitsPtr & m_mask;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}//namespace advcpp
#endif //#ifndef __BITMANIP_H__



