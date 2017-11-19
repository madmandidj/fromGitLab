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
	inline static advcpp::BitSet<SIZE, T> Do_Bit_And(const advcpp::BitSet<SIZE, T>& _thisBS, const advcpp::BitSet<SIZE, T>& _otherBS);
};


template<size_t SIZE, class T>
inline static advcpp::BitSet<SIZE, T> Do_Bit_And(const advcpp::BitSet<SIZE, T>& _thisBS, const advcpp::BitSet<SIZE, T>& _otherBS)
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








}//namespace advcpp
#endif //#ifndef __BIT_SET_HELPER__
