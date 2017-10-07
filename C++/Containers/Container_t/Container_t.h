#ifndef __CONTAINER_T_H__
#define __CONTAINER_T_H__

#include <stddef.h>

template <class elementType> 
class Container_t
{
	public:
		Container_t();
		
		Container_t(Container_t const& _container);
		
		Container_t& operator= (Container_t const&  _container);
		
		virtual ~Container_t();
		
		virtual bool Insert(elementType* const _element) = 0;
		
		virtual bool Append(elementType* const _element, size_t index) = 0;
		
		virtual bool Prepend(elementType* const _element, size_t index) = 0;
		
		virtual elementType* Remove(const elementType& _element) = 0;
		
//		virtual bool RemoveAll() = 0; /* TODO: Need to return all elements ?? */
		
//		virtual elementType* RemoveAndDelete(elementType const& _element) = 0;
		
//		virtual bool RemoveAndDeleteAll() = 0;
		
		virtual bool Contains(elementType const& _element) const = 0;
		
		virtual elementType* Find(const elementType& _element) const = 0;
		
		virtual int GetElementIndex(elementType* const _element) const = 0;
		
		size_t Count() const;
		
		bool IsEmpty() const;
		
	protected:
		size_t m_numOfElements;
};


template <class elementType>
Container_t<elementType>::Container_t(): m_numOfElements(0){}


template <class elementType>
Container_t<elementType>::Container_t(Container_t const& _container): m_numOfElements(0){}


template <class elementType>
Container_t<elementType>& Container_t<elementType>:: operator= (Container_t const& _container)
{
	m_numOfElements = 0;
}


template <class elementType>
Container_t<elementType>::~Container_t(){}


template <class elementType>
size_t Container_t<elementType>::Count() const
{
	return m_numOfElements;
}


template <class elementType>
bool Container_t<elementType>::IsEmpty() const
{
	return 0 == m_numOfElements ? true : false;
}




#endif /* #ifndef __CONTAINER_T_H__ */



