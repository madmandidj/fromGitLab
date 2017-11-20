#ifndef __BIT_SET_HELPER__
#define __BIT_SET_HELPER__

#include<iostream>
#include<algorithm>
namespace advcpp
{
//////////////////////////////////////////////////////////////////
//BITSET FORWARD DECLARATION
template<size_t SIZE, class T> 
class BitSet;
//////////////////////////////////////////////////////////////////
//PRINTER CLASS
template<size_t ELEMENT_SIZE, class T>
class Printer
{
public:
	Printer();
	void operator()(T _arg);
};

template<size_t ELEMENT_SIZE, class T>
inline Printer<ELEMENT_SIZE, T>::Printer()
{
	//Empty
}

template<size_t ELEMENT_SIZE, class T>
inline void Printer<ELEMENT_SIZE, T>::operator()(T _arg)
{
	T mask1;
	for (size_t index = 0; index < ELEMENT_SIZE; ++index)
	{
		mask1 = 1;
		mask1 = mask1 << index;
		std::cout << (bool)(_arg & mask1);
	}
	std::cout << "_";
}
//////////////////////////////////////////////////////////////////
//BITSET_OP CLASS
//template<class T>
//class BitSet_Op
//{
//public:
//	virtual ~BitSet_Op() = 0;
//	inline BitSet_Op(){}
//};
//////////////////////////////////////////////////////////////////
//DO_BITSET_OP FUNCTION
template<size_t SIZE, class T, class BitSet_OP> 
inline void Do_BitSet_OP(T* _thisArr, T* _otherArr, T* _destArr, size_t _numOfElems, size_t _elemSize, BitSet_OP _bitSetOp)
{
//	BitSet<SIZE, T> bs;
//	size_t numOfBitsInLastElem = SIZE % _elemSize;
//	
//	if (0 != numOfBitsInLastElem)
//	{
		std::transform (_thisArr, _thisArr + _numOfElems - 1, _otherArr, _destArr, _bitSetOp);
		
//		for (size_t index = SIZE - numOfBitsInLastElem ; index < SIZE ; ++index)
//		{		
//			(bs)[index] = _bitSet[index];
//		}
//	}
//	else
//	{
//		std::transform (_thisArr, _thisArr + _numOfElems, _otherArr, _destArr, _bitSetOp);
//	}
	
//	return bs;
}
//////////////////////////////////////////////////////////////////
//BITSET_OP_AND CLASS
template<class T>
class BitSet_Op_AND
{
public:
	inline BitSet_Op_AND();
	inline T operator()(T& _arg1, T& _arg2);
};

template<class T>
inline BitSet_Op_AND<T>::BitSet_Op_AND()
{
	//Empty
}

template<class T>
inline T BitSet_Op_AND<T>::operator()(T& _arg1, T& _arg2)
{
	return _arg1 & _arg2;
}
//////////////////////////////////////////////////////////////////
//BITSET_OP_OR CLASS
template<class T>
class BitSet_Op_OR
{
public:
	inline BitSet_Op_OR();
	inline T operator()(T& _arg1, T& _arg2);
};

template<class T>
inline BitSet_Op_OR<T>::BitSet_Op_OR()
{
	//Empty
}

template<class T>
inline T BitSet_Op_OR<T>::operator()(T& _arg1, T& _arg2)
{
	return _arg1 | _arg2;
}
//////////////////////////////////////////////////////////////////
//BITSET_OP_ISEQUAL CLASS
template<class T>
class BitSet_Op_ISEQUAL
{
public:
	inline BitSet_Op_ISEQUAL();
	inline bool operator()(T& _arg1, T& _arg2);
};

template<class T>
inline BitSet_Op_ISEQUAL<T>::BitSet_Op_ISEQUAL()
{
	//Empty
}

template<class T>
inline bool BitSet_Op_ISEQUAL<T>::operator()(T& _arg1, T& _arg2)
{
	return _arg1 == _arg2;
}


}//namespace advcpp
#endif //#ifndef __BIT_SET_HELPER__
