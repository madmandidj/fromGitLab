#ifndef __BITCONTAINER_H__
#define __BITCONTAINER_H__

namespace advcpp
{

template<class T>
class BitContainer
{
public:
	~BitContainer();
	BitContainer(T* _bitsPtr); //Throws
	void Set(size_t _index);
	void Clear(size_t _index);
	bool Get(size_t _index);
protected:

private:
	BitContainer();
	T* 		m_bitsPtr;
	size_t 	m_numOfBits;
};

template<class T>
std::ostream& operator<<(std::ostream& _os, const BitContainer<T>& _bitCont)
{
	T tempT = 1;
	for (size_t index = 1; index <= SIZE; ++index)
	{
		_os << (_bitCont.Get(index - 1));
	}
	return _os;
}

template<class T>
BitContainer<T>::~BitContainer()
{
	//Empty
}

template<class T>
BitContainer<T>::BitContainer(T* _bitsPtr)
{
	if (0 == _bitsPtr)
	{
		throw std::runtime_error("BitContainer<T>::BitContainer(T* _bitsPtr), invalid parameter");
	}
	
	m_numOfBits = sizeof(T) * CHAR_BIT;
	m_bitsPtr = _bitsPtr;
}

template<class T>
void BitContainer<T>::Set(size_t _index)
{
	if (index >= m_numOfBits)
	{
		throw std::runtime_error("void BitContainer<T>::Set(size_t _index), invalid index");
	} 
	
	T bitMask = 1;
	size_t index =0;
	for (index = 0; index < _index; ++index)
	{
		bitMask = bitMask << 1;
//		std::cout << bitMask << std::endl;
	}
//	size_t containerIndex = 0;
//	while(_bitIndex >= (CHAR_BIT * sizeof(T)))
//	{
//		++containerIndex;
//		_bitIndex -= (CHAR_BIT * sizeof(T));
//	}
//	m_bitContainerArray[containerIndex] = m_bitContainerArray[containerIndex] | bitMask;
	*m_bitsPtr = *m_bitsPtr | bitMask; 
	return;
}

}//namespace advcpp
#endif //#ifndef __BITCONTAINER_H__



