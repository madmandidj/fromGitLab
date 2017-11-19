#ifndef __BIT_SET_H__
#define __BIT_SET_H__
#include "stddef.h"
#include<iostream>
#include<climits>
namespace advcpp
{

///////////////////////////////////////////////////////////////////////////////
//CLASS DEFINTION
template<size_t SIZE, class T = unsigned int>
class BitSet
{
private:
	static const size_t m_elementSize;
	static const size_t	m_numOfElements;
	class Bit
	{
		public:
			Bit(T* _element, size_t _index)
			{
				if (0 == _element)
				{
					throw std::runtime_error("Bit(T* _element, size_t _index), invalid element");
				}
				m_element = _element;
				m_index = _index;
			}
			Bit& operator=(bool _state)
			{
				T mask1 = 1;
				mask1 = mask1 << m_index;
				*m_element = (true == _state) ? *m_element | mask1 : *m_element & ~mask1;
				return *this;
				
			}
			operator bool() const
			{
				T mask1 = 1;
				mask1 = mask1 << m_index;
				return (*m_element & mask1);
			}
		
		private:
			T* 		m_element;
			size_t 	m_index;
	};
public:
	inline ~BitSet();
	inline explicit BitSet(); 										//Throws
//	inline explicit BitSet(bool _boolArr[], size_t _numOfBools); 	//Throws
	inline BitSet& operator=(const BitSet& _bitSet);				//Throws
//	inline void Set(bool _bitVal, size_t _bitIndex); 				//Throws
//	inline bool Get(size_t _bitIndex) const; 						//Throws
	inline size_t Count() const;									//Throws
	inline bool operator==(const BitSet& _bitSet) const;			//Throws
	inline bool operator[](size_t _bitIndex) const;					//Throws
	inline Bit operator[](size_t _bitIndex);						//Throws
	inline BitSet operator&(const BitSet& _bitSet) const;			//Throws
	inline BitSet& operator&=(const BitSet& _bitSet);				//Throws
	inline BitSet operator|(const BitSet& _bitSet) const;			//Throws
	inline BitSet& operator|=(const BitSet& _bitSet);				//Throws
	inline BitSet operator^(const BitSet& _bitSet) const;			//Throws
	inline BitSet& operator^=(const BitSet& _bitSet);				//Throws
	inline void operator<<(size_t index);							//Throws
	inline void operator>>(size_t index);							//Throws
	inline BitSet<SIZE, T>& Flip(size_t _bitIndex);					//Throws
	inline BitSet<SIZE, T>& Flip();									//Throws
	inline bool Any() const;										//Throws
	inline bool All() const;										//Throws
	inline bool None() const;										//Throws
	inline size_t GetElementSize();
	inline size_t GetNumOfElements();

private:
	inline BitSet(const BitSet& _bitSet);
	T* m_elementArray;
};

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template <size_t SIZE, class T> 
const size_t BitSet<SIZE, T>::m_elementSize(CHAR_BIT * sizeof(T));
template <size_t SIZE, class T> 
const size_t BitSet<SIZE, T>::m_numOfElements((double)SIZE / m_elementSize);
template<size_t SIZE, class T>
inline std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE, T>& _bitSet);

///////////////////////////////////////////////////////////////////////////////
//STATIC AND AUX FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE, T>& _bitSet)
{
//	for (size_t index = 1; index <= SIZE; ++index)
//	{
////		_os << (_bitSet.Get(index - 1));
//	}
	for (size_t index = 1; index <= _bitSet.GetNumOfElements; ++index)
	{
		
	}	
	
	return _os;
}

///////////////////////////////////////////////////////////////////////////////
//PRIVATE MEMBER FUNCTION DEFINITIONS


///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline BitSet<SIZE, T>::~BitSet()
{
	delete[] m_elementArray;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>::BitSet() : m_elementArray(new T[m_numOfElements])
{
	//Empty
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE, T>::operator[](size_t _bitIndex) const 
{	
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator[](size_t _bitIndex) const, invalid index");
	}	
	
	size_t containerIndex = _bitIndex / m_elementSize;

	_bitIndex -= (containerIndex * m_elementSize);
	
	Bit bit(m_elementArray + containerIndex, _bitIndex);

	return bit();
}

template<size_t SIZE, class T>
inline typename BitSet<SIZE, T>::Bit BitSet<SIZE, T>::operator[](size_t _bitIndex)
{
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator[](size_t _bitIndex), invalid index");
	}
	
	size_t containerIndex = _bitIndex / m_elementSize;

	_bitIndex -= (containerIndex * m_elementSize);
	
	Bit bit(m_elementArray + containerIndex, _bitIndex);

	return bit;
}						











template<size_t SIZE, class T>
inline size_t BitSet<SIZE, T>::GetElementSize()
{
	return m_elementSize;
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE, T>::GetNumOfElements()
{
	return m_numOfElements;
}
}//namespace advcpp
#endif //#ifndef __BIT_SET_H__







