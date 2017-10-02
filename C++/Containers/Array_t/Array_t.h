#ifndef __ARRAY_T_H__
#define __ARRAY_T_H__

#include "../Container_t/Container_t.h"

template <class elementType> 
class Array_t:public Container_t<elementType>
{
	public:
		Array_t();
		
		Array_t(Array_t const& _array);
		
		Array_t& operator= (Array_t const& _array);
		
		virtual ~Array_t();
		
//		virtual bool Append(elementType* const _element, size_t index);
//		
//		virtual bool Prepend(elementType* const _element, size_t index);
//		
//		virtual bool Insert(elementType* const _element, size_t index);
//		
//		virtual elementType* Remove(elementType const& _element);
//		
//		virtual bool RemoveAll(); /* TODO: Need to return all elements ?? */
//		
//		virtual elementType* RemoveAndDelete(elementType const& _element);
//		
//		virtual bool RemoveAndDeleteAll(); 
//		
//		virtual bool Contains(elementType const& _element) const;
//		
//		virtual elementType* Find(elementType const& _element) const;
//		
//		virtual size_t GetElementIndex(elementType* const _element) const;



		/***********************
		Inherited from Container_t:
		
		Size_t Count() const;
		bool IsEmpty() const;
		************************/
		
	protected:
		/***********************
		Inherited from Container_t:
		
		size_t m_numOfElements;
		***********************/   
		
	private:			
		size_t 			m_blockSize;	
		
		size_t 			m_capacity;  
		         	       	
		elementType** 	m_items;
		
		void			InitArrayAttributes(size_t _numOfElements, size_t _capacity, size_t m_blockSize);
		
		void			CopyAllElements(Array_t const& _array);
		 	
};



//const size_t initCapacity = 10; /*TODO: expected initializer before ‘initCapacity’ const size_t initCapacity = 10;*/
//const size_t blockSize = 5;


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





/***********************
***********************
public member functions
***********************
************************/
template <class elementType>
Array_t<elementType>::Array_t()
{
	InitArrayAttributes(0, 10, 5);
	
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








































#endif /* #ifndef __ARRAY_T_H__ */



