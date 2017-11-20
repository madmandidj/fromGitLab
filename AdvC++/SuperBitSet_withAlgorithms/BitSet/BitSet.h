#ifndef __BIT_SET_H__
#define __BIT_SET_H__

#include "BitSet_Helper.h"
#include <stddef.h>
#include<iostream>
#include<climits>
#include<algorithm>
#include<math.h>
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
		Bit(T* _element, size_t _index);
		Bit& operator=(bool _state);
		operator bool() const;

	private:
		T* 		m_element;
		size_t 	m_index;
	};
public:
	inline ~BitSet();
	inline explicit BitSet(); 										//Throws
	inline explicit BitSet(bool _boolArr[], size_t _numOfBools); 	//Throws
	inline BitSet(const BitSet& _bitSet);
	inline BitSet& operator=(const BitSet& _bitSet);				//Throws
	inline bool operator==(const BitSet& _bitSet) const;			//Throws
	inline bool operator[](size_t _bitIndex) const;					//Throws
	inline Bit operator[](size_t _bitIndex);						//Throws
	inline BitSet operator&(const BitSet& _bitSet) const;			//Throws
	inline BitSet& operator&=(const BitSet& _bitSet);				//Throws
	inline BitSet operator|(const BitSet& _bitSet) const;			//Throws
	inline BitSet& operator|=(const BitSet& _bitSet);				//Throws
	inline BitSet operator^(const BitSet& _bitSet) const;			//Throws
	inline BitSet& operator^=(const BitSet& _bitSet);				//Throws
	inline void operator<<(size_t _numOfShifts);					//Throws
	inline BitSet<SIZE,T>& Flip();									//Throws
	inline bool Any() const;										//Throws
	inline size_t GetElementSize() const;
	inline size_t GetNumOfElements() const;
	inline size_t GetNumOfBits() const;
	inline const T* const GetElementArray() const; //TODO: remove this
	//TODO:	//	inline size_t Count() const;									//Throws
	//TODO:	//	inline void operator>>(size_t index);							//Throws
	//TODO:	//	inline BitSet<SIZE,T>& Flip(size_t _bitIndex);					//Throws
	//TODO:	//	inline bool All() const;										//Throws
	//TODO:	//	inline bool None() const;										//Throws

private:
	T* m_elementArray;
};
///////////////////////////////////////////////////////////////////////////////
//CLASS BIT MEMBER FUNCTION DEFINITIONS
template <size_t SIZE, class T> 
BitSet<SIZE,T>::Bit::Bit(T* _element, size_t _index)
{
	if (0 == _element)
	{
		throw std::runtime_error("Bit(T* _element, size_t _index), invalid element");
	}
	m_element = _element;
	m_index = _index;
}

template <size_t SIZE, class T> 
typename BitSet<SIZE,T>::Bit& BitSet<SIZE,T>::Bit::operator=(bool _state)
{
	T mask1 = 1;
	mask1 = mask1 << m_index;
	*m_element = (true == _state) ? *m_element | mask1 : *m_element & ~mask1;
	return *this;
	
}

template <size_t SIZE, class T> 
BitSet<SIZE,T>::Bit::operator bool() const
{
	T mask1 = 1;
	mask1 = mask1 << m_index;
	return (*m_element & mask1);
}

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template <size_t SIZE, class T> 
const size_t BitSet<SIZE,T>::m_elementSize(CHAR_BIT * sizeof(T));
template <size_t SIZE, class T> 
const size_t BitSet<SIZE,T>::m_numOfElements(ceil((double)SIZE / m_elementSize));
template<size_t SIZE, class T>
inline std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE,T>& _bitSet);
///////////////////////////////////////////////////////////////////////////////
//STATIC AND AUX FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE,T>& _bitSet)
{
	for(size_t index = 0; index < SIZE; ++index)
	{
		std::cout << _bitSet[index];
	}

	return _os;
}
///////////////////////////////////////////////////////////////////////////////
//PRIVATE MEMBER FUNCTION DEFINITIONS

///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline BitSet<SIZE,T>::~BitSet()
{
	delete[] m_elementArray;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>::BitSet() : m_elementArray(new T[m_numOfElements])
{
	//Empty
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>::BitSet(bool _boolArr[], size_t _numOfBits) : m_elementArray(new T[m_numOfElements])
{
	if (_numOfBits != SIZE)
	{
		delete[] m_elementArray;
		throw std::runtime_error("BitSet<SIZE,T>::BitSet(bool _boolArr[], size_t _numOfBits), invalid num of elements");
	}
	
	for (size_t index = 0; index < _numOfBits; ++index)
	{
		try
		{
			(*this)[index] = _boolArr[index];
		}
		catch(std::exception& _exc)
		{
			delete[] m_elementArray;
			throw;
		}
	}
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>::BitSet(const BitSet& _bitSet)
{
	*this = _bitSet;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>& BitSet<SIZE,T>::operator=(const BitSet& _bitSet)
{
	if (SIZE != _bitSet.GetNumOfBits())
	{
		throw std::runtime_error("BitSet<SIZE,T>::operator=(const BitSet& _bitSet), invalid parameter");
	}	
	
//	std::copy(_bitSet.m_elementArray, _bitSet.m_elementArray + _bitSet.m_numOfElements, m_elementArray);
	std::copy(_bitSet.m_elementArray, _bitSet.m_elementArray + _bitSet.m_numOfElements - 1, m_elementArray);
	
	size_t numOfBitsInLastElem = SIZE % m_elementSize;
	
	if (0 != numOfBitsInLastElem)
	{
		for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
		{		
			(*this)[index] = _bitSet[index];
		}
	}
	
	return *this;
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE,T>::operator==(const BitSet& _bitSet) const
{
	size_t numOfBitsInLastElem = SIZE % m_elementSize;
	
	if (0 != numOfBitsInLastElem)
	{
		if (true == std::equal(m_elementArray, m_elementArray + m_numOfElements - 1, 
				_bitSet.m_elementArray, advcpp::BitSet_Op_ISEQUAL<T>())) //TODO: Check if functor is actually needed in this case
		{
			for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
			{		
				if ((*this)[index] != _bitSet[index])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
	else
	{
		return std::equal(m_elementArray, m_elementArray + m_numOfElements, 
				_bitSet.m_elementArray, advcpp::BitSet_Op_ISEQUAL<T>()); //TODO: Check if functor is actually needed in this case
	}
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE,T>::operator[](size_t _bitIndex) const 
{	
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE,T>::operator[](size_t _bitIndex) const, invalid index");
	}	
	size_t containerIndex = _bitIndex / m_elementSize;
	
	_bitIndex -= (containerIndex * m_elementSize);
	
	T mask1 = 1;
	
	mask1 = mask1 << _bitIndex;
	
	return (*(m_elementArray + containerIndex) & mask1);
}

template<size_t SIZE, class T>
inline  typename BitSet<SIZE,T>::Bit BitSet<SIZE,T>::operator[](size_t _bitIndex)
{
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE,T>::operator[](size_t _bitIndex), invalid index");
	}
	
	size_t containerIndex = _bitIndex / m_elementSize;

	_bitIndex -= (containerIndex * m_elementSize);
	
	Bit bit(m_elementArray + containerIndex, _bitIndex);

	return bit;
}						

template<size_t SIZE, class T>
inline BitSet<SIZE,T> BitSet<SIZE,T>::operator&(const BitSet& _bitSet) const
{
	BitSet<SIZE,T> bs;
	size_t numOfBitsInLastElem = SIZE % m_elementSize;

	advcpp::Do_BitSet_OP<SIZE,T>(this->m_elementArray, _bitSet.m_elementArray, bs.m_elementArray, m_numOfElements, BitSet_Op_AND<T>());
	
	if (0 != numOfBitsInLastElem)
	{
		for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
		{		
			(bs)[index] = (*this)[index] & _bitSet[index];
		}
	}				
	return bs;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>& BitSet<SIZE,T>::operator&=(const BitSet& _bitSet)
{
	*this = *this & _bitSet;
	return *this;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T> BitSet<SIZE,T>::operator|(const BitSet& _bitSet) const
{
	BitSet<SIZE,T> bs;
	size_t numOfBitsInLastElem = SIZE % m_elementSize;

	advcpp::Do_BitSet_OP<SIZE,T>(this->m_elementArray, _bitSet.m_elementArray, bs.m_elementArray, m_numOfElements, BitSet_Op_OR<T>());
	
	if (0 != numOfBitsInLastElem)
	{
		for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
		{		
			(bs)[index] = (*this)[index] | _bitSet[index];
		}
	}				
	return bs;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>& BitSet<SIZE,T>::operator|=(const BitSet& _bitSet)
{
	*this = *this | _bitSet;
	return *this;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T> BitSet<SIZE,T>::operator^(const BitSet& _bitSet) const
{
	BitSet<SIZE,T> bs;
	size_t numOfBitsInLastElem = SIZE % m_elementSize;

	advcpp::Do_BitSet_OP<SIZE,T>(this->m_elementArray, _bitSet.m_elementArray, bs.m_elementArray, m_numOfElements, BitSet_Op_XOR<T>());
	
	if (0 != numOfBitsInLastElem)
	{
		for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
		{		
			(bs)[index] = (*this)[index] ^ _bitSet[index];
		}
	}				
	return bs;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>& BitSet<SIZE,T>::operator^=(const BitSet& _bitSet)
{
	*this = *this ^ _bitSet;
	return *this;
}

template<size_t SIZE, class T>
inline void BitSet<SIZE,T>::operator<<(size_t _numOfShifts)
{
	for (size_t shiftNum = 0; shiftNum < _numOfShifts; ++shiftNum)
	{
		for (size_t index = 0; index < SIZE - 1; ++index)
		{
			//TODO: Double check why this doesnt work: // (*this)[index] = (*this)[index + 1];
			bool newVal = (*this)[index + 1];
			(*this)[index] = newVal; 
		}
		(*this)[SIZE - 1] = 0;
	}

	return;
}

template<size_t SIZE, class T>
inline BitSet<SIZE,T>& BitSet<SIZE,T>::Flip()
{
	std::for_each(m_elementArray, m_elementArray + m_numOfElements - 1, BitSet_Op_FLIP<T>());

	size_t numOfBitsInLastElem = SIZE % m_elementSize;
	
	if (0 != numOfBitsInLastElem)
	{
		for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
		{		
			(*this)[index] = ~(*this)[index];
		}
	}
	
	return *this;
}	

template<size_t SIZE, class T>
inline bool BitSet<SIZE,T>::Any() const
{
	if ((m_elementArray + m_numOfElements - 1) == (std::find_if(m_elementArray, m_elementArray + m_numOfElements - 1, BitSet_Op_GETBITVAL<T>())))
	{
		size_t numOfBitsInLastElem = SIZE % m_elementSize;
	
		if (0 != numOfBitsInLastElem)
		{
			for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
			{		
				if (1 == (*this)[index])
				{
					return true;
				}
			}
		}
		return false;
	}
	return true;
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE,T>::GetElementSize() const
{
	return m_elementSize;
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE,T>::GetNumOfElements() const
{
	return m_numOfElements;
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE,T>::GetNumOfBits() const
{
	return SIZE;
}

template<size_t SIZE, class T>
inline const T* const BitSet<SIZE,T>::GetElementArray() const
{
	return m_elementArray;
}

}//namespace advcpp
#endif //#ifndef __BIT_SET_H__







































