#ifndef __BUFFER_H__
#define __BUFFER_H__
//namespace advcpp
//{


#include<stddef.h>
#include<exception>

template <class T> 
class Buffer
{
//	class BufferDeleter
//	{
//	public:
//		void operator()(std::tr1::shared_ptr<T> _deleteThis) const
//		{
//			delete[] _deleteThis;
//		}
//	};	

public:
	virtual ~Buffer();
	Buffer(size_t _capacity = 10);
	Buffer(const Buffer& _buf);
	Buffer& operator=(const Buffer& _buf);
	size_t Length();
	SetBuffer(const T* _data);
	const T* GetBuffer() const;
	
	
//		Buffer& Buffer(const Buffer& _buf);
//		Buffer& operator=(const Buffer& _buf);
protected:
	//TODO: static SetDefaultCapacity(size_t);
private:
	T*			m_buf;
	size_t 		m_length;
	size_t 		m_capacity;
	//TODO: static size_t 	m_defaultCapacity;
};

template <class T> 
Buffer<T>::~Buffer()
{
	delete[] m_buf;
}


template <class T> 
Buffer<T>::Buffer(size_t _capacity) : m_length(0), m_capacity(_capacity)
{
	m_buf = new char[_capacity]; // Throws!!
		
//	std::tr1::shared_ptr<T> array (new T[_capacity], ArrayDeleter<T> ());
}

























//} //namespace advcpp
#endif //#ifndef __BUFFER_H__


