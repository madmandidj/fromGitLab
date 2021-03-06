#ifndef __BUFFER_H__
#define __BUFFER_H__
#include<stddef.h>
#include<exception>
#include<tr1/memory>
#include<iostream>
#include<cstring>
#include<math.h>

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
	typedef enum ResizeMode
	{
		Double,
		TenPercent	
	}ResizeMode;
	virtual ~Buffer();
	explicit Buffer();
	explicit Buffer(size_t _capacity);
	bool SetBuffer(const T* _data, size_t _dataSize);
	const T* GetBuffer() const;
	bool SetElement(const T& _element, size_t _index);
	const T& GetElement(size_t _index) const;
	inline size_t GetCapacity() const;
	inline size_t GetSize() const;
	inline void	SetResizeMode(ResizeMode _mode);
	inline int GetResizeMode() const; //TODO: why does not like return ResizeMode here?
	size_t EnsureCapacity(size_t _dataSize);
	//TODO: AppendElement
	//TODO: EnsureCapacity
	//TODO: SetResizeMode //capacity grows by nearest larger multiple of 2 or by percentage
	
protected:
	
private:
	Buffer(const Buffer& _buf);
	Buffer& operator=(const Buffer& _buf);
	std::tr1::shared_ptr<T> m_data;
	size_t 					m_capacity;
	size_t 					m_size;
	ResizeMode				m_resizeMode;
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
	std::cout << "In ~Buffer" << std::endl;
}

template <class T> 
Buffer<T>::Buffer() : m_capacity(1), m_size(0), m_resizeMode(Double)
{	
	std::tr1::shared_ptr<T> data (new T[m_capacity], BufferDeleter ());
	m_data = data;
}

template <class T> 
Buffer<T>::Buffer(size_t _capacity) :m_capacity(_capacity), m_size(0), m_resizeMode(Double)
{	
	std::tr1::shared_ptr<T> data (new T[m_capacity], BufferDeleter());
	m_data = data;
}



template <class T> 
size_t Buffer<T>::EnsureCapacity(size_t _dataSize)
{	
	size_t newCapacity = 1;

	if(_dataSize > m_capacity)
	{
		switch (m_resizeMode)
		{
			case Double:
				newCapacity = 1;
				while(newCapacity < _dataSize)
				{
					newCapacity *= 2;
				}
				break;
			
			case TenPercent:
				newCapacity = _dataSize;
				while(newCapacity < _dataSize)
				{
					newCapacity = (size_t)ceil(newCapacity * 1.1) ;
				}
				break;
		}
	
		std::tr1::shared_ptr<T> data (new T[newCapacity], BufferDeleter ()); //TODO: DoIfFail
		try
		{
			std::copy(m_data.get(), m_data.get() + m_size, data.get());	
		}
		catch(std::exception& _exc)
		{
			throw;
		} 
		m_data = data;
		m_capacity = newCapacity;
	}
	
	return m_capacity;
}


template <class T> 
bool Buffer<T>::SetBuffer(const T* _data, size_t _dataSize)
{
	if(0 == _data)
	{
		return false;
	}
	
//	if(_dataSize > m_capacity)
//	{
//		size_t newCapacity = 1;
//		while(newCapacity < _dataSize)
//		{
//			newCapacity *= 2;
//		}
//		std::tr1::shared_ptr<T> data (new T[newCapacity], BufferDeleter ()); //TODO: DoIfFail
//		m_data = data;
//		m_capacity = newCapacity;
//		m_size = _dataSize;
//		try
//		{
//			std::copy(_data, _data + m_size, m_data.get());	
//		}
//		catch(std::exception& _exc)
//		{
//			throw;
//		}

//		return true;
		EnsureCapacity(_dataSize);
//	}
	
	try
	{
		std::copy(_data, _data + _dataSize, m_data.get());	
	}
	catch(std::exception& _exc)
	{
		throw;
	}

	m_size = _dataSize;
	
	return true;
}

template <class T> 
const T* Buffer<T>::GetBuffer() const
{
	return m_data.get();
}

template <class T> 
bool Buffer<T>::SetElement(const T& _data, size_t _index)
{
	if (m_capacity <= _index)
	{
		throw std::runtime_error("Buffer::SetElement, invalid index");
	}
	
	m_data.get()[_index] = _data;
	
	return true;
}

template <class T> 
const T& Buffer<T>::GetElement(size_t _index) const
{
	if (m_capacity <= _index)
	{
		throw std::runtime_error("Buffer::GetElement, invalid index");
	}
	
	return m_data.get()[_index];
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

template <class T> 
inline void Buffer<T>::SetResizeMode(ResizeMode _mode)
{	
	m_resizeMode = _mode;
	return;
}

template <class T> 
inline int Buffer<T>::GetResizeMode() const 
{	
	return m_resizeMode;
}


} //namespace advcpp
#endif //#ifndef __BUFFER_H__


