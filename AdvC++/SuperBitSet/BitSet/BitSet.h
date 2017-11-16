#ifndef __BIT_SET_H__
#define __BIT_SET_H__
#include<cmath>
#include<stddef.h>
#include<climits>
#include<iostream>
//#include<limits.h>
namespace advcpp
{

template<size_t SIZE, class T = unsigned int>
class BitSet
{
public:
	~BitSet();
	BitSet();
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
	size_t	m_numOfBitContainers;
	T*		m_bitContainerArray;
};

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

template<size_t SIZE, class T>
BitSet<SIZE, T>::~BitSet()
{
	delete[] m_bitContainerArray;
}

template<size_t SIZE, class T>
BitSet<SIZE, T>::BitSet() 
{
	m_numOfBitContainers = ceil(((double)SIZE / (CHAR_BIT * sizeof(T))) );
	m_bitContainerArray = new T[m_numOfBitContainers];
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

template<size_t SIZE, class T>
bool BitSet<SIZE, T>::Get(size_t _bitIndex) const //Should throw
{
	T bitMask = 1;
	for (size_t index = 0; index <= (_bitIndex % (sizeof(T) * CHAR_BIT)); ++index)
	{
		bitMask = bitMask << 1;
	}
	size_t containerIndex = _bitIndex / (CHAR_BIT * sizeof(T));
	return m_bitContainerArray[containerIndex] & bitMask;
}

template<size_t SIZE, class T>
void BitSet<SIZE, T>::Set(bool _bitVal, size_t _bitIndex) //Should Throw
{
	T bitMask = 1;
	size_t index =0;
	size_t dummy = 0;
	for (index = 1; index < (_bitIndex % (sizeof(T) * CHAR_BIT)); ++index)
	{
//		++dummy;
		bitMask = bitMask << 1;
		std::cout << bitMask << std::endl;
		
	}
//	size_t containerIndex = _bitIndex / (CHAR_BIT * sizeof(T));
	size_t containerIndex = 0;
	while(_bitIndex >= (CHAR_BIT * sizeof(T)))
	{
		++containerIndex;
		_bitIndex -= (CHAR_BIT * sizeof(T));
	}
	m_bitContainerArray[containerIndex] = m_bitContainerArray[containerIndex] | bitMask;
	return;
}

















}
#endif //#ifndef __BIT_SET_H__

