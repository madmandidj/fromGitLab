#include "memPage_t.h"
#include <string.h> 	/* memcpy */


size_t memPage_t::m_defaultCap = 10;


memPage_t::memPage_t()
{	
//	if (0 == _capacity)
//	{
//		m_capacity = 1;
//	}
//	else
//	{
//		m_capacity = _capacity;
//	}

	m_capacity = memPage_t::GetDefaultCapacity();
	
	m_buf = new char[m_capacity];
	
	if (0 == m_buf)
	{
		/*TODO: handle 'new' exception */
	}
	
	m_size = 0;
	
	m_position = 0;
}



memPage_t::~memPage_t()
{
	delete[] m_buf;
}



size_t memPage_t::Read(void* _data, size_t _dataSize)
{
	return Read(_data, _dataSize, m_position);
}



size_t memPage_t::Read(void* _data, size_t _dataSize, size_t _position)
{
	if (NULL == _data || 0 == _dataSize || _position >= m_size)
	{
		return 0;
	}
		
	if (_position + _dataSize > m_size)
	{
//		size_t numOfBytesToRead = m_size - _dataSize;
		size_t numOfBytesToRead = m_size - _position;
		
		memcpy(_data, m_buf + _position, numOfBytesToRead);
		
		m_position = m_size;
		
		return numOfBytesToRead; /* return amount of bytes read */
	}
	
	memcpy(_data, m_buf + _position, _dataSize);
	
	m_position = _position + _dataSize;
	
	return _dataSize; /* return amount of bytes read */	
}



size_t memPage_t::Write(const void* _data, size_t _dataSize)
{
	return Write(_data, _dataSize, m_position);
}



size_t memPage_t::Write(const void* _data, size_t _dataSize, size_t _position)
{

	if (NULL == _data || 0 == _dataSize || _position > m_size || _position >= m_capacity)
	{
		return 0;
	}
		
	if (_position + _dataSize > m_capacity)
	{
		size_t numOfBytesToWrite = (_position + _dataSize) - m_capacity;
		
		memcpy(m_buf + _position, _data, numOfBytesToWrite);
		
		m_position = m_capacity;
		
		m_size = m_capacity;
		
		return numOfBytesToWrite; /* return amount of bytes written */
	}
	
	memcpy(m_buf + _position, _data, _dataSize);
	
	m_position = _position + _dataSize;
	
	if (m_position > m_size)
	{
		m_size = m_position;
	}
	
	return _dataSize; /* return amount of bytes written */	
}



//size_t memPage_t::GetPosition() const
//{
//	return m_position;
//}



//bool memPage_t::SetPosition(size_t _index)
//{
//	if (_index > m_size || _index >= m_capacity)
//	{
//		return false;
//	}
//	
//	m_position = _index;
//	
//	return true;
//}



//size_t memPage_t::GetSize() const
//{
//	return m_size;
//}



//bool memPage_t::IsEmpty() const
//{
//	/*TODO: implement*/
//	return true;
//}


size_t memPage_t::GetCapacity()
{
	return m_capacity;
}



size_t memPage_t::GetDefaultCapacity()
{
	return m_defaultCap;
}



void memPage_t::SetDefaultCapacity(size_t _newPageSize)
{
	if (0 == _newPageSize)
	{
		m_defaultCap = 1;
	}
	else
	{
		m_defaultCap = _newPageSize;
	}
	
	return;
}



