#ifndef __BIT_SET_HELPER__
#define __BIT_SET_HELPER__

#include "BitSet.h"
#include<iostream>



namespace advcpp
{
template<size_t SIZE, class T> //Forward declaration for BitSet
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
//BITSETOPS CLASS
template<size_t SIZE, class T>
class BitSetOps
{
public:
	friend advcpp::BitSet<SIZE, T>;
	BitSetOps();
	inline static bool Do_Bit_And(const advcpp::BitSet<SIZE, T>& _thisBS, const advcpp::BitSet<SIZE, T>& _otherBS);
	inline static T* Do_Element_And(const advcpp::BitSet<SIZE, T>& _thisBS, const advcpp::BitSet<SIZE, T>& _otherBS);
	inline static advcpp::BitSet<SIZE, T> Do_BitSet_And(const advcpp::BitSet<SIZE, T>& _thisBS, const advcpp::BitSet<SIZE, T>& _otherBS);
};


template<size_t SIZE, class T>
inline static advcpp::BitSet<SIZE, T> Do_BitSet_And(const advcpp::BitSet<SIZE, T>& _thisBS, const advcpp::BitSet<SIZE, T>& _otherBS)
{
	BitSet<SIZE, T> bitSet;
	bool thisBitState;
	bool otherBitState;
	bool newBitState;
	for (size_t index = 0; index < SIZE; ++index)
	{
		thisBitState = _thisBS[index];
		otherBitState = _otherBS[index];
		newBitState = thisBitState & otherBitState;
		bitSet[index] = newBitState;	
	}
	
	return bitSet;
}
//////////////////////////////////////////////////////////////////
//BITSET_OP_AND CLASS
//template<size_t ELEMENT_SIZE, class T>
//class BitSet_Op_AND
//{
//public:
//	inline BitSet_Op_AND();
//	inline T operator()(T& _arg1, T& _arg2);
//};

//template<size_t ELEMENT_SIZE, class T>
//inline BitSet_Op_AND<ELEMENT_SIZE, T>::BitSet_Op_AND()
//{
//	//Empty
//}

//template<size_t ELEMENT_SIZE, class T>
//inline T BitSet_Op_AND<ELEMENT_SIZE, T>::operator()(T& _arg1, T& _arg2)
//{
//	std::cout << "yo" << std::endl;
//	return _arg1 & _arg2;
//}
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
	std::cout << "yo" << std::endl;
	return _arg1 & _arg2;
}
//////////////////////////////////////////////////////////////////
//BIT_OP_AND CLASS
template<size_t ELEMENT_SIZE, class T>
class Bit_Op_AND
{
public:
	inline Bit_Op_AND();
	inline T operator()(T& _arg1, T& _arg2);
};






/*
//TEST SPECIALIZATIONS
template<typename T>
void print(T)
{
	std::cout << "Not Allowed type" << std::endl;
}

template<>
void print(char _yo)
{
	std::cout << _yo << std::endl;
}
*/







}//namespace advcpp
#endif //#ifndef __BIT_SET_HELPER__
