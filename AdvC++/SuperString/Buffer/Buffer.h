#ifndef __BUFFER_H__
#define __BUFFER_H__
#include<stddef.h>
#include<exception>
#include<tr1/memory>
#include<iostream>
#include<cstring>

/*
Need:
-----
Buffer(cap)
Set/get element
Set/get ptr to mem
get capacity (value given)
get size (value asked for)
set size / ensure capacity
*/
namespace advcpp
{



template <class T> 
class Buffer
{
public:
	class BufferDeleter
	{
	public:
		void operator()(T* _deleteThis);
	};
	virtual ~Buffer();
	Buffer();
	Buffer(size_t _capacity);
	Buffer(const Buffer& _buf);
	Buffer& operator=(const Buffer& _buf);
	bool SetBuffer(const T* _data, size_t _dataSize);
	const T* GetBuffer() const;
	bool SetElement(const T& _element, size_t _index);
	const T& GetElement(size_t _index) const;
	inline size_t GetCapacity() const;
	inline size_t GetSize() const;
	
	
//		Buffer& Buffer(const Buffer& _buf);
//		Buffer& operator=(const Buffer& _buf);
protected:

private:
	std::tr1::shared_ptr<T> m_buf;
	size_t 					m_capacity;
	size_t 					m_size;
};


template <class T> 
void Buffer<T>::BufferDeleter::operator()(T* _deleteThis)
{
	delete[] _deleteThis;
	_deleteThis = 0;
	std::cout << "In BufferDeleter" << std::endl;
}


template <class T> 
Buffer<T>::~Buffer()
{
	//Empty
	std::cout << "In ~Buffer" << std::endl;
}

template <class T> 
Buffer<T>::Buffer() : m_size(0), m_capacity(1)
{	
	std::tr1::shared_ptr<T> buffer (new T[m_capacity], BufferDeleter ());
	m_buf = buffer;
}

template <class T> 
Buffer<T>::Buffer(size_t _capacity) : m_size(0), m_capacity(_capacity)
{	
	std::tr1::shared_ptr<T> buffer (new T[m_capacity], BufferDeleter ());
	m_buf = buffer;
}

template <class T> 
bool Buffer<T>::SetBuffer(const T* _data, size_t _dataSize)
{
	if(0 == _data)
	{
		return false;
	}
	
	size_t newCapacity = 1;
	while(newCapacity < _dataSize)
	{
		newCapacity *= 2;
	}
	
	std::tr1::shared_ptr<T> buffer (new T[newCapacity], BufferDeleter ());
	m_buf = buffer;
	m_capacity = newCapacity;
	m_size = _dataSize;
	try
	{
		std::copy(_data, _data + m_size, m_buf.get());	
	}
	catch(std::exception& _exc)
	{
		throw;
	}
	
	return true;
}

template <class T> 
const T* Buffer<T>::GetBuffer() const
{
	return m_buf.get();
}

template <class T> 
bool Buffer<T>::SetElement(const T& _data, size_t _index)
{
	if (m_capacity <= _index)
	{
		throw std::runtime_error("Buffer::SetElement, invalid index");
	}
	
	m_buf.get()[_index] = _data;
	
	return true;
}

template <class T> 
const T& Buffer<T>::GetElement(size_t _index) const
{
	if (m_capacity <= _index)
	{
		throw std::runtime_error("Buffer::GetElement, invalid index");
	}
	
	return m_buf.get()[_index];
}

template <class T> 
inline size_t Buffer<T>::GetCapacity() const
{	
	return m_capacity;
}

template <class T> 
inline size_t Buffer<T>::GetSize() const
{	
	return m_size;
}


} //namespace advcpp
#endif //#ifndef __BUFFER_H__


