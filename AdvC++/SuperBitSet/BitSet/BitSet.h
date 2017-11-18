#ifndef __BIT_SET_H__
#define __BIT_SET_H__

#include "../BitManip/BitManip.h"
#include "../BitRef/BitRef.h"
#include<cmath>
#include<iostream>
#include<exception>

namespace advcpp
{
///////////////////////////////////////////////////////////////////////////////
//CLASS DEFINTION
template<size_t SIZE, class T = unsigned int>
class BitSet
{
public:
	inline ~BitSet();
	inline explicit BitSet(); 										//Throws
	inline explicit BitSet(bool _boolArr[], size_t _numOfElements); //Throws
	inline BitSet& operator=(const BitSet& _bitSet);				//Throws
	inline size_t GetNumOfBits() const;
	inline size_t GetNumOfBitContainers() const;
	inline void Set(bool _bitVal, size_t _bitIndex); 				//Throws
	inline bool Get(size_t _bitIndex) const; 						//Throws
	inline size_t Count() const;									//Throws
	inline bool operator==(const BitSet& _bitSet) const;			//Throws
	inline bool operator[](size_t _bitIndex) const;					//Throws
	inline BitRef<T> operator[](size_t _bitIndex);					//Throws
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

private:
	inline BitSet(const BitSet& _bitSet);
	inline static BitSet<SIZE, T> DoBitwiseOp(const BitSet& _thisBitSet, const BitSet& _otherBitSet, char _operation);
	size_t				m_numOfBitContainers;
	T*					m_bitContainerArray;
	mutable BitManip<T> m_bitManip;
	static const size_t m_containerSize;
};

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template <size_t SIZE, class T> 
const size_t BitSet<SIZE, T>::m_containerSize(CHAR_BIT * sizeof(T));
template<size_t SIZE, class T>
inline std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE, T>& _bitSet);

///////////////////////////////////////////////////////////////////////////////
//AUX FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline std::ostream& operator<<(std::ostream& _os, const BitSet<SIZE, T>& _bitSet)
{
	for (size_t index = 1; index <= SIZE; ++index)
	{
		_os << (_bitSet.Get(index - 1));
	}
	return _os;
}

///////////////////////////////////////////////////////////////////////////////
//PRIVATE MEMBER FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline BitSet<SIZE, T>::BitSet(const BitSet& _bitSet)  : m_numOfBitContainers((double)SIZE / m_containerSize) 
							,m_bitContainerArray(new T[m_numOfBitContainers])
							,m_bitManip(m_bitContainerArray)
{
	*this = _bitSet;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T> BitSet<SIZE, T>::DoBitwiseOp(const BitSet<SIZE, T>& _thisBitSet, const BitSet<SIZE, T>& _otherBitSet, char _operation)
{
	BitSet<SIZE, T> bitSet;
	bool thisBitState;
	bool otherBitState;
	bool newBitState;
	
	switch (_operation)
	{
	case '|':
		for (size_t index = 0; index < SIZE; ++index)
		{
			thisBitState = _thisBitSet.Get(index);
			otherBitState = _otherBitSet.Get(index);
			newBitState = thisBitState | otherBitState;
			bitSet.Set(newBitState, index);	
		}
		break;
	case '^':
		for (size_t index = 0; index < SIZE; ++index)
		{
			thisBitState = _thisBitSet.Get(index);
			otherBitState = _otherBitSet.Get(index);
			newBitState = thisBitState ^ otherBitState;
			bitSet.Set(newBitState, index);	
		}
		break;
	default:
		for (size_t index = 0; index < SIZE; ++index)
		{
			thisBitState = _thisBitSet.Get(index);
			otherBitState = _otherBitSet.Get(index);
			newBitState = thisBitState & otherBitState;
			bitSet.Set(newBitState, index);	
		}
		break;
	}
	
	return bitSet;
}

///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<size_t SIZE, class T>
inline BitSet<SIZE, T>::~BitSet()
{
	delete[] m_bitContainerArray;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>::BitSet() : m_numOfBitContainers((double)SIZE / m_containerSize) 
							,m_bitContainerArray(new T[m_numOfBitContainers])
							,m_bitManip(m_bitContainerArray)
{
	//Empty
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>::BitSet(bool _boolArr[], size_t _numOfElements) : m_numOfBitContainers((double)SIZE / m_containerSize) 
							,m_bitContainerArray(new T[m_numOfBitContainers])
							,m_bitManip(m_bitContainerArray)
{
	if (_numOfElements != SIZE)
	{
		delete[] m_bitContainerArray;
		throw std::runtime_error("BitSet<SIZE, T>::BitSet(bool _boolArr[], size_t _numOfElements), invalid num of elements");
	}
	
	for (size_t index = 0; index < _numOfElements; ++index)
	{
		try
		{
			Set(_boolArr[index], index);
		}
		catch(std::exception& _exc)
		{
			delete[] m_bitContainerArray;
			throw;
		}
	}
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>& BitSet<SIZE, T>::operator=(const BitSet& _bitSet) 
{
	if (SIZE != _bitSet.GetNumOfBits())
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator=(const BitSet& _bitSet), invalid parameter");
	}	
	
	for (size_t index = 0; index < SIZE; ++index)
	{
		Set(_bitSet.Get(index), index);
	}
	
	return *this;
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
inline bool BitSet<SIZE, T>::Get(size_t _bitIndex) const 
{	
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE, T>::Get(size_t _bitIndex) const, invalid index");
	}	
	
	size_t containerIndex = _bitIndex / m_containerSize;
	
	while(_bitIndex >= m_containerSize)
	{
		_bitIndex -= m_containerSize;
	}

	m_bitManip.SetBitsPtr(m_bitContainerArray + containerIndex);
	
	return m_bitManip.Get(_bitIndex);
}

template<size_t SIZE, class T>
inline void BitSet<SIZE, T>::Set(bool _bitVal, size_t _bitIndex)
{
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE, T>::Set(bool _bitVal, size_t _bitIndex), invalid index");
	}
	
	size_t containerIndex = _bitIndex / m_containerSize;
	
	while(_bitIndex >= m_containerSize)
	{
		_bitIndex -= m_containerSize;
	}

	m_bitManip.SetBitsPtr(m_bitContainerArray + containerIndex);
	
	return (1 ==_bitVal) ? m_bitManip.Set(_bitIndex) : m_bitManip.Clear(_bitIndex);
}

template<size_t SIZE, class T>
inline size_t BitSet<SIZE, T>::Count() const
{
	size_t result = 0;
	bool bitState;
	
	for (size_t index = 0; index < SIZE; ++index)
	{
		bitState = (true == Get(index)) ? true : false;
		if (1 == bitState)
		{
			++result;
		}
	}
	
	return result;
}
template<size_t SIZE, class T>
inline bool BitSet<SIZE, T>::operator==(const BitSet& _bitSet) const
{
	for (size_t index = 0; index < SIZE; ++index)
	{
		if (Get(index) != _bitSet.Get(index))
		{
			return false;
		}
	}
	
	return true;
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE, T>::operator[](size_t _bitIndex) const
{
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator[](size_t _bitIndex) const, invalid index");
	}
	
	return Get(_bitIndex);
}

template<size_t SIZE, class T>
inline BitRef<T> BitSet<SIZE, T>::operator[](size_t _bitIndex)
{
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitRef<T> BitSet<SIZE, T>::operator[](size_t _bitIndex), invalid index");
	}
	
	size_t containerIndex = _bitIndex / m_containerSize;
	while(_bitIndex >= m_containerSize)
	{
		_bitIndex -= m_containerSize;
	}
	
	BitRef<T> bitRef(m_bitContainerArray + containerIndex, _bitIndex); 
	
	return bitRef;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T> BitSet<SIZE, T>::operator&(const BitSet<SIZE, T>& _bitSet) const
{
	if (SIZE != _bitSet.GetNumOfBits())
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator&(const BitSet& _bitSet), invalid parameter");
	}	
	
	BitSet<SIZE, T> bitSet;
	bitSet = DoBitwiseOp(*this, _bitSet, '&');
	return bitSet;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>& BitSet<SIZE, T>::operator&=(const BitSet<SIZE, T>& _bitSet)
{
	*this = *this & _bitSet;
	
	return *this;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T> BitSet<SIZE, T>::operator|(const BitSet<SIZE, T>& _bitSet) const
{
	if (SIZE != _bitSet.GetNumOfBits())
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator&(const BitSet& _bitSet), invalid parameter");
	}	
	
	BitSet<SIZE, T> bitSet;
	bitSet = DoBitwiseOp(*this, _bitSet, '|');
	return bitSet;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>& BitSet<SIZE, T>::operator|=(const BitSet<SIZE, T>& _bitSet)
{
	*this = *this | _bitSet;
	
	return *this;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T> BitSet<SIZE, T>::operator^(const BitSet<SIZE, T>& _bitSet) const
{
	if (SIZE != _bitSet.GetNumOfBits())
	{
		throw std::runtime_error("BitSet<SIZE, T>::operator&(const BitSet& _bitSet), invalid parameter");
	}	
	
	BitSet<SIZE, T> bitSet;
	bitSet = DoBitwiseOp(*this, _bitSet, '^');
	return bitSet;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>& BitSet<SIZE, T>::operator^=(const BitSet<SIZE, T>& _bitSet)
{
	*this = *this ^ _bitSet;
	
	return *this;
}

template<size_t SIZE, class T>
inline void BitSet<SIZE, T>::operator<<(size_t _numOfShifts)
{
	for (size_t shiftNum = 0; shiftNum < _numOfShifts; ++shiftNum)
	{
		for (size_t index = 0; index < SIZE - 1; ++index)
		{
			Set(Get(index + 1), index);
		}
	
		Set(false, SIZE - 1);
	}

	return;
}

template<size_t SIZE, class T>
inline void BitSet<SIZE, T>::operator>>(size_t _numOfShifts)
{
	for (size_t shiftNum = 0; shiftNum < _numOfShifts; ++shiftNum)
	{
		for (size_t index = SIZE - 1; index > 0; --index)
		{
			Set(Get(index - 1), index);
		}
	
		Set(false, 0);
	}

	return;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>& BitSet<SIZE, T>::Flip(size_t _bitIndex)
{	
	if (SIZE <= _bitIndex)
	{
		throw std::runtime_error("BitSet<SIZE, T>& BitSet<SIZE, T>::Flip(size_t _bitIndex), invalid index");
	}
	
	BitSet<SIZE, T> bitSet;
	bool bitState;
	
	bitState = Get(_bitIndex);
	
	Set(!bitState, _bitIndex);
	
	return *this;
}

template<size_t SIZE, class T>
inline BitSet<SIZE, T>& BitSet<SIZE, T>::Flip()
{	
	BitSet<SIZE, T> bitSet;
	bool bitState;
	
	for (size_t index = 0; index < SIZE; ++index)
	{
		bitState = Get(index);
	
		Set(!bitState, index);
	}
	
	return *this;
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE, T>::Any() const
{	
	for (size_t index = 0; index < SIZE; ++index)
	{
		if (true == Get(index))
		{
			return true;
		}
	}
	return false;
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE, T>::All() const
{	
	for (size_t index = 0; index < SIZE; ++index)
	{
		if (false == Get(index))
		{
			return false;
		}
	}
	return true;
}

template<size_t SIZE, class T>
inline bool BitSet<SIZE, T>::None() const
{	
	for (size_t index = 0; index < SIZE; ++index)
	{
		if (true == Get(index))
		{
			return false;
		}
	}
	return true;
}

}//namespace advcpp
#endif //#ifndef __BIT_SET_H__

