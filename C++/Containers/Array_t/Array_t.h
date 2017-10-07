#ifndef __ARRAY_T_H__
#define __ARRAY_T_H__

#include "../Container_t/Container_t.h"

template <class elementType> 
class Array_t:public Container_t<elementType>
{
	public:
		Array_t(size_t _numOfElements = 0, size_t _initCapacity = 10, size_t _blockSize = 5);
		
		Array_t(Array_t const& _array);
		
		Array_t& operator= (Array_t const& _array);
		
		virtual ~Array_t();
		
		virtual bool Insert(elementType* const _element);
		
//		virtual bool Append(elementType* const _element, size_t _index);
		
		virtual bool Prepend(elementType* const _element, size_t _index);
		
		virtual elementType* Remove(const elementType& _element);
		
//		virtual bool RemoveAll(); /* TODO: Need to return all elements ?? */
		
//		virtual elementType* RemoveAndDelete(elementType const& _element);
		
//		virtual bool RemoveAndDeleteAll(); 
		
		virtual bool Contains(elementType const& _element) const;
		
		virtual elementType* Find(elementType const& _element) const;
		
		virtual int GetElementIndex(elementType* const _element) const;

	public:
		/***********************
		Inherited from Container_t:
		
		Size_t 	Count() const;
		bool 	IsEmpty() const;
		************************/
		
	protected:
		/***********************
		Inherited from Container_t:
		
		size_t m_numOfElements;
		***********************/   
		
	private:
		void InitArrayAttributes(size_t _numOfElements, size_t _capacity, size_t m_blockSize);
		
		void CopyAllElements(Array_t const& _array);
		
		void Resize();
		
	private:			
		size_t 			m_blockSize;	
		
		size_t 			m_capacity;  
		         	       	
		elementType** 	m_items;
		
	
		 	
};




/***********************
***********************
public member functions
***********************
************************/
template <class elementType>
Array_t<elementType>::Array_t(size_t _numOfElements, size_t _initCapacity, size_t _blockSize)
{
	InitArrayAttributes(_numOfElements, _initCapacity, _blockSize); /*TODO: set explicit values as consts */
	
	m_items = new elementType*[m_capacity];
	
	if (NULL == m_items)
	{
		/*TODO: Handle new exception*/
	}
}


template <class elementType>
Array_t<elementType>::Array_t(Array_t const& _array)
{
	InitArrayAttributes(_array.m_numOfElements, _array.m_capacity, _array.blockSize);
	
	m_items = new elementType*[m_capacity];
	
	if (NULL == m_items)
	{
		/*TODO: Handle new exception*/
	}
	
	CopyAllElements(_array);
}


template <class elementType>
Array_t<elementType>& Array_t<elementType>::operator= (Array_t const& _array)
{
	InitArrayAttributes(_array.m_numOfElements, _array.m_capacity, _array.blockSize);
	
	CopyAllElements(_array);
}



template <class elementType>
Array_t<elementType>::~Array_t()
{
//	RemoveAndDeleteAll();	
	
	delete[] m_items;
}


template <class elementType>
bool Array_t<elementType>::Insert(elementType* const _element)
{
	if (0 == _element)
	{
		/*TODO: handle new exception*/
		return false;
	}
	
	Resize();
	
	m_items[this->m_numOfElements] = _element;
	
	this->m_numOfElements += 1;
	
	return true;
}


template <class elementType>
bool Array_t<elementType>::Prepend(elementType* const _element, size_t _index)
{
	if (this->m_numOfElements <= _index)
	{
		return false;
	}
	
	size_t index;
	
	Resize();
	
	for (index = this->m_numOfElements; index > _index; --index)
	{
		m_items[index] = m_items[index - 1];
	}
	
	m_items[_index] = _element;
	
	this->m_numOfElements += 1;
}


template <class elementType>
elementType* Array_t<elementType>::Remove(const elementType& _element)
{
	size_t index;
	
	elementType* elemPtr;
	
	size_t removeIndex;
	
	elemPtr = Find(_element);
	
	if (0 != elemPtr)
	{
		removeIndex = GetElementIndex(elemPtr);
	
		for (index = removeIndex; index < this->m_numOfElements - 1; ++index)
		{
			m_items[index] = m_items[index + 1];
		}
	
		this->m_numOfElements -= 1;
	}
	
	return elemPtr;
}


template <class elementType>
bool Array_t<elementType>::Contains(const elementType& _element) const
{
	size_t index;
	
	return 0 != Find(_element) ? true : false;
}


template <class elementType>
elementType* Array_t<elementType>::Find(const elementType& _element) const
{
	size_t index;
	
	for(index = 0; index < this->m_numOfElements; ++index)
	{
		if (_element == *m_items[index])
		{
			break;
		}
	}
	
	return this->m_numOfElements == index ? 0 : m_items[index];
}


template <class elementType>
int Array_t<elementType>::GetElementIndex(elementType* const _element) const
{
	size_t index;
	
	for(index = 0; index < this->m_numOfElements; ++index)
	{
		if (_element == m_items[index])
		{
			break;
		}
	}
	
	return this->m_numOfElements == index ? -1 : index;
}




/***********************
***********************
private member functions
***********************
************************/
template <class elementType>
void Array_t<elementType>::InitArrayAttributes(size_t _numOfElements, size_t _capacity, size_t _blockSize)
{
	this->m_numOfElements = _numOfElements;
	
	m_capacity = _capacity;
	
	m_blockSize = _blockSize;
}


template <class elementType>
void Array_t<elementType>::CopyAllElements(Array_t const& _array)
{
	size_t index;

	for(index = 0; index < this->m_numOfElements; ++index)
	{
		m_items[index] = _array.m_items[index];
	}
}


template <class elementType>
void Array_t<elementType>::Resize()
{
	if (this->m_numOfElements + 1 > m_capacity)
	{
		m_capacity += m_blockSize;
		
		elementType** tempItems = new elementType*[m_capacity];
		
		if(0 == tempItems)
		{
			/*TODO: handle new exception*/
		} 
		
		for (size_t index = 0; index < this->m_numOfElements; ++index)
		{
			tempItems[index] = m_items[index];
		}
		
		delete[] m_items;
		
		m_items = tempItems;
	}
}




















#endif /* #ifndef __ARRAY_T_H__ */



