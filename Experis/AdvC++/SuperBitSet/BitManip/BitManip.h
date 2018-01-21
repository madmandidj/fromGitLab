#ifndef __BIT_MANIP_H__
#define __BIT_MANIP_H__

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
	inline explicit BitManip(T* _bitsPtr); 	//Throws
	inline void SetBitsPtr(T* _bitsPtr);	//Throws
	inline void Set(size_t _index);			//Throws
	inline void Clear(size_t _index); 		//Throws
	inline bool Get(size_t _index) const; 	//Throws
	static const size_t GetBitsInType();
protected:

private:
	BitManip();
	BitManip& operator=(const BitManip& _bmnp);
	T* 					m_bitsPtr;
	mutable T			m_maskT1;
	mutable T			m_maskT2;
	static const T 		m_mask_all_1;
	static const size_t m_bitsInType;
};

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template <typename T> 
const T BitManip<T>::m_mask_all_1(-1);
template <typename T> 
const size_t BitManip<T>::m_bitsInType(sizeof(T) * CHAR_BIT);
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
	for (size_t index = BitManip<T>::GetBitsInType(); index > 0 ; --index)
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
	for (size_t index = BitManip<T>::GetBitsInType(); index > 0 ; --index)
	{
		_os << (_bitManip.Get(index - 1));
	}
	std::cout << "|";
	return _os;
}

///////////////////////////////////////////////////////////////////////////////
//PRIVATE MEMBER FUNCTION DEFINITIONS

///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<class T>
inline BitManip<T>::~BitManip()
{
	//Empty
}

template<class T>
inline BitManip<T>::BitManip(T* _bitsPtr)
{
	SetBitsPtr(_bitsPtr);
}

template<class T>
inline void BitManip<T>::SetBitsPtr(T* _bitsPtr)
{
	if (0 == _bitsPtr)
	{
		throw std::runtime_error("BitManip<T>::BitManip(T* _bitsPtr), invalid parameter");
	}
	
	m_bitsPtr = _bitsPtr;
}


template<class T>
inline void BitManip<T>::Set(size_t _index)
{
	if (_index >= m_bitsInType)
	{
		throw std::runtime_error("void BitManip<T>::Set(size_t _index), invalid index");
	} 

	m_maskT1 = 1;

	m_maskT1 = m_maskT1 << _index;
	
	*m_bitsPtr = *m_bitsPtr | m_maskT1; 
	
	return;
}

template<class T>
inline void BitManip<T>::Clear(size_t _index)
{
	if (_index >= m_bitsInType)
	{
		throw std::runtime_error("void BitManip<T>::Clear(size_t _index), invalid index");
	} 

	m_maskT1 = 1;

	m_maskT1 = m_maskT1 << _index;

	m_maskT2 = m_maskT1 ^ m_mask_all_1;
	
	*m_bitsPtr = *m_bitsPtr & m_maskT2; 
	
	return;
}

template<class T>
inline bool BitManip<T>::Get(size_t _index) const
{
	if (_index >= m_bitsInType)
	{
		throw std::runtime_error("void BitManip<T>::Get(size_t _index), invalid index");
	} 
	
	m_maskT1 = 1;

	m_maskT1 = m_maskT1 << _index;

	return *m_bitsPtr & m_maskT1;
}	
	
	
template<class T>
inline const size_t BitManip<T>::GetBitsInType()
{
	return m_bitsInType;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}//namespace advcpp
#endif //#ifndef __BIT_MANIP_H__



