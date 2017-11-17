#ifndef __BIT_SET_H__
#define __BIT_SET_H__
#include "../BitManip/BitManip.h"
#include<cmath>
#include<stddef.h>
#include<climits>
#include<iostream>
#include<exception>
//#include<limits.h>


/*
BitSet(size_t _numOfBits)
op[] 
set/get
count() (return num of bits on)
ostream <<
op&  	&=
op|	|=
op^	^=
op~	~=
any()
all()
none()
*/

namespace advcpp
{

///////////////////////////////////////////////////////////////////////////////
//CLASS DEFINTION
template<size_t SIZE, class T = unsigned int>
class BitSet
{
public:
	~BitSet();
	BitSet(); // Throws
	//TODO:	BitSet(bool _boolArr[]); 
	inline size_t GetNumOfBits() const;
	inline size_t GetNumOfBitContainers() const;
	void Set(bool _bitVal, size_t _bitIndex); //Should Throw
	bool Get(size_t _bitIndex) const; //Should throw
	size_t Count() const;
protected:

private:
	BitSet(const BitSet& _bitSet);
	BitSet& operator=(const BitSet& _bitSet);
	size_t		m_numOfBitContainers;
	T*			m_bitContainerArray;
	mutable BitManip<T> m_bitManip;
	size_t		m_currentContainer;
	static const size_t m_containerSize;
};

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template <size_t SIZE, class T> 
const size_t BitSet<SIZE, T>::m_containerSize(CHAR_BIT * sizeof(T));
template<size_t SIZE, class T>
std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE, T>& _bitSet);

///////////////////////////////////////////////////////////////////////////////
//AUX FUNCTION DEFINITIONS
template<size_t SIZE, class T>
std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE, T>& _bitSet)
{
	T tempT = 1;
	for (size_t index = 1; index <= SIZE; ++index)
	{
		_os << (_bitSet.Get(index - 1));
	}
	return _os;
	
}

///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<size_t SIZE, class T>
BitSet<SIZE, T>::~BitSet()
{
	delete[] m_bitContainerArray;
}

template<size_t SIZE, class T>
BitSet<SIZE, T>::BitSet() : m_numOfBitContainers((double)SIZE / m_containerSize) 
							,m_bitContainerArray(new T[m_numOfBitContainers])
							,m_bitManip(m_bitContainerArray)
{
	//Empty
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE, T>::GetNumOfBits() const
{
	return SIZE;
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE, T>::GetNumOfBitContainers() const
{
	return m_numOfBitContainers;
}

//template<size_t SIZE, class T>
//bool BitSet<SIZE, T>::Get(size_t _bitIndex) const //Should throw
//{
//	T bitMask = 1;
//	for (size_t index = 0; index < (_bitIndex % (sizeof(T) * CHAR_BIT)); ++index)
//	{
//		bitMask = bitMask << 1;
//	}
//	size_t containerIndex = _bitIndex / (CHAR_BIT * sizeof(T));
//	return m_bitContainerArray[containerIndex] & bitMask;
//}
template<size_t SIZE, class T>
bool BitSet<SIZE, T>::Get(size_t _bitIndex) const //Should throw
{
	size_t containerIndex = _bitIndex / m_containerSize;
	
	while(_bitIndex >= m_containerSize)
	{
		_bitIndex -= m_containerSize;
	}

	m_bitManip.SetBitsPtr(m_bitContainerArray + containerIndex);
	
	return m_bitManip.Get(_bitIndex);
}

template<size_t SIZE, class T>
void BitSet<SIZE, T>::Set(bool _bitVal, size_t _bitIndex) //Should throw
{
	size_t containerIndex = _bitIndex / m_containerSize;
	
	while(_bitIndex >= m_containerSize)
	{
		_bitIndex -= m_containerSize;
	}

	m_bitManip.SetBitsPtr(m_bitContainerArray + containerIndex);
	
	return (1 ==_bitVal) ? m_bitManip.Set(_bitIndex) : m_bitManip.Clear(_bitIndex);
}





//template<size_t SIZE, class T>
//void BitSet<SIZE, T>::Set(bool _bitVal, size_t _bitIndex) //Should Throw
//{
//	T bitMask = 1;
//	size_t index =0;
//	size_t dummy = 0;
//	for (index = 0; index < (_bitIndex % (sizeof(T) * CHAR_BIT)); ++index)
//	{
////		++dummy;
//		bitMask = bitMask << 1;
//		std::cout << bitMask << std::endl;
//		
//	}
////	size_t containerIndex = _bitIndex / (CHAR_BIT * sizeof(T));
//	size_t containerIndex = 0;
//	while(_bitIndex >= m_containerSize)
//	{
//		++containerIndex;
//		_bitIndex -= m_containerSize;
//	}
//	m_bitContainerArray[containerIndex] = m_bitContainerArray[containerIndex] | bitMask;
//	return;
//}

















}
#endif //#ifndef __BIT_SET_H__

