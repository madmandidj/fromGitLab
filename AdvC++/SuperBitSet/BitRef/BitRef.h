#ifndef __BIT_REF_H__
#define __BIT_REF_H__

#include"../BitManip/BitManip.h"
#include<iostream>

namespace advcpp
{

///////////////////////////////////////////////////////////////////////////////
//CLASS DEFINTION
template<class T>
class BitRef
{
public:
	inline ~BitRef();
	BitRef(){}
	inline explicit BitRef(T* _bitsPtr, size_t _bitIndex); 	//Throws
	inline BitRef(BitRef& _bitRef); 						//Throws
	inline BitRef(const BitRef& _bitRef); 					//Throws
	inline BitRef<T>& operator=(const BitRef& _bitRef);		//Throws
	inline BitRef<T>& operator=(bool _bitState);			//Throws
	inline bool operator==(const BitRef& _bitRef);			//Throws
	inline bool operator==(bool _bitState);					//Throws
	inline void Set();										//Throws
	inline void Clear(); 									//Throws
	inline bool Get() const; 								//Throws
	inline size_t GetBitIndex() const;

private:
	BitManip<T> m_bitManip;
	const size_t m_bitIndex;
};

///////////////////////////////////////////////////////////////////////////////
//STATIC DATA INITIALIZATION AND AUX FUNCTION DECLERATIONS
template<class T>
inline std::ostream& operator<<(std::ostream& _os, const BitRef<T>& _bitRef);
template<class T>
inline std::ostream& operator<<(std::ostream& _os, BitRef<T>& _bitRef);

///////////////////////////////////////////////////////////////////////////////
//AUX FUNCTION DEFINITIONS
template<class T>
inline std::ostream& operator<<(std::ostream& _os, const BitRef<T>& _bitRef)
{
	_os << (_bitRef.Get());
	
	return _os;
}

///////////////////////////////////////////////////////////////////////////////
//PRIVATE MEMBER FUNCTION DEFINITIONS

///////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTION DEFINITIONS
template<class T>
inline BitRef<T>::~BitRef()
{
	//Empty
}

template<class T>
inline BitRef<T>::BitRef(T* _bitsPtr, size_t _bitIndex) : m_bitManip(_bitsPtr), m_bitIndex(_bitIndex)
{
	if(m_bitManip.GetBitsInType() <= m_bitIndex)
	{
		throw std::runtime_error("BitRef<T>::BitRef(T* _bitsPtr, size_t _bitIndex), invalid index");
	}
}


template<class T>
inline BitRef<T>::BitRef(BitRef& _bitRef) : m_bitManip(_bitRef.m_bitManip), m_bitIndex(_bitRef.m_bitIndex)
{
	if(m_bitManip.GetBitsInType() <= m_bitIndex)
	{
		throw std::runtime_error("BitRef<T>::BitRef(BitRef& _bitRef), invalid index");
	}
	
	//_bitRef.m_bitManip; //TODO: Ask why is this possible? _bitRef is parameter, yet i can access private member???!!!???!!!
}

template<class T>
inline BitRef<T>::BitRef(const BitRef& _bitRef) : m_bitManip(_bitRef.m_bitManip), m_bitIndex(_bitRef.m_bitIndex)
{
	if(m_bitManip.GetBitsInType() <= m_bitIndex)
	{
		throw std::runtime_error("BitRef<T>::BitRef(const BitRef& _bitRef), invalid index");
	}
}

template<class T>
inline BitRef<T>& BitRef<T>::operator=(bool _bitState)
{
	if (true == _bitState)
	{
		Set();
		return *this;
	}
	Clear();
	return *this;
}

template<class T>
inline BitRef<T>& BitRef<T>::operator=(const BitRef& _bitRef)
{
	*this = _bitRef.Get();
	return *this;
}

template<class T>
inline bool BitRef<T>::operator==(const BitRef& _bitRef)
{
	return (Get() == _bitRef.Get());
}

template<class T>
inline bool BitRef<T>::operator==(bool _bitState)
{
	return (Get() == _bitState);
}

template<class T>
inline void BitRef<T>::Set()
{
	m_bitManip.Set(m_bitIndex);
	
	return; 
}

template<class T>
inline void BitRef<T>::Clear()
{
	m_bitManip.Clear(m_bitIndex);
	
	return; 
}

template<class T>
inline bool BitRef<T>::Get() const
{	
	return m_bitManip.Get(m_bitIndex);
}

template<class T>
inline size_t BitRef<T>::GetBitIndex() const
{	
	return m_bitIndex;
}




















} // namespace advcpp
#endif //#ifndef __BIT_REF_H__

